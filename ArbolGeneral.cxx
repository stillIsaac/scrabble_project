#include "ArbolGeneral.h"
#include <iostream> // for testing purposes
#include <fstream>
#include <algorithm>
#include <iterator>
// Constructor
ArbolGeneral::ArbolGeneral() {
    raiz = new NodoGeneral('\0'); // Root node has null character data
}

// Insert function
void ArbolGeneral::insert(std::string palabra) {
    NodoGeneral* nodo = raiz;
    for (char c : palabra) {

        NodoGeneral* hijo = nullptr;
        for (std::list<NodoGeneral*>::iterator it  = nodo->hijos.begin(); it != nodo->hijos.end(); ++it) {

            if ((*it)->data == c) {

                hijo = *it;
                break;
            }
        }
        if (hijo == nullptr) {

            hijo = new NodoGeneral(c);
            nodo->hijos.push_back(hijo);
        }
        nodo = hijo;
    }
    nodo->is_end_of_word = true;
}

bool ArbolGeneral::iniciarArbol(std::string archivo) {

    bool open = false;
    std::ifstream myfile; 
    myfile.open("diccionario.txt");
    std::string mystring;
    if(myfile.is_open()) {

        open = true;
        while(myfile.good()) {
    
            myfile >> mystring;
            this->insert(mystring);
        }
    }

    return open;
}


bool ArbolGeneral::iniciarArbolInverso(std::string archivo) {

    bool open = false;
    std::ifstream myfile; 
    myfile.open("diccionario.txt");
    std::string mystring;
    if(myfile.is_open()) {

        open = true;
        while(myfile.good()) {
    
            myfile >> mystring;
            reverse(mystring.begin(), mystring.end());
            this->insert(mystring);
        }
    }

    return open;
}



// Search prefix function
std::list<std::string> ArbolGeneral::obtenerPalabrasPorPrefijo(std::string prefijo) {
    std::list<std::string> words;
    NodoGeneral* nodo = raiz;
    for (char c : prefijo) {

        NodoGeneral* child = nullptr;
        for (std::list<NodoGeneral*>::iterator it = nodo->hijos.begin(); it != nodo->hijos.end(); it++) {

            if ((*it)->data == c) {
            
                child = *it;
                break;
            }
        }
        if (child == nullptr) {
            
            return words;
        }
        nodo = child;
    }
    obtener_palabras_nodo(nodo, prefijo, words);
    return words;
}

/*/ Recursive function to retrieve words from node
void ArbolGeneral::obtener_palabras_nodo(NodoGeneral* node, std::string prefijo, std::list<std::string>& palabras) {
    if (node->is_end_of_word) {
       
        palabras.push_back(prefijo);
    }
    std::list<NodoGeneral*>::iterator it = node->hijos.begin();
    for (; it != node->hijos.end(); it++) {
       
        obtener_palabras_nodo(*it, (*it)->data + prefijo, palabras);
    }
}*/

void ArbolGeneral::obtener_palabras_nodo(NodoGeneral* node, std::string prefijo, std::list<std::string>& palabras) {
    if (node->is_end_of_word) {
        palabras.push_back(prefijo);
    }
    for (NodoGeneral* child : node->hijos) {
        obtener_palabras_nodo(child, prefijo + child->data, palabras);
    }
}



// Search suffix function
std::list<std::string> ArbolGeneral:: obtenerPalabrasPorSufijo(std::string sufijo) {
    std::list<std::string> words;
    NodoGeneral* nodo = raiz;
    // Reverse the suffix
    std::string reversed_suffix = sufijo;
    std::reverse(reversed_suffix.begin(), reversed_suffix.end());
    for (char c : reversed_suffix) {

        NodoGeneral* child = nullptr;
        for (std::list<NodoGeneral*>::iterator it = nodo->hijos.begin(); it != nodo->hijos.end(); ++it) {

            if ((*it)->data == c) {
            
                child = *it;
                break;
            }
        }
        if (child == nullptr) {
            
            return words;
        }
        nodo = child;
    }
    obtener_sufijo_palabras(nodo, sufijo, words);
    return words;
}

// Recursive function to retrieve suffix words from node
void ArbolGeneral::obtener_sufijo_palabras(NodoGeneral* nodo, std::string sufijo, std::list<std::string>& palabras) {
    if (nodo->is_end_of_word) {
        // Reverse the suffix back to the original order
        //std::reverse(suffix.begin(), suffix.end());
        palabras.push_back(sufijo);
    }
    std::list<NodoGeneral*>::iterator it = nodo->hijos.begin();
    for (; it != nodo->hijos.end(); it++) {
        obtener_sufijo_palabras(*it, (*it)->data + sufijo, palabras);
    }
}
