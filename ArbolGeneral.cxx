#include "ArbolGeneral.h"
#include <iostream> // for testing purposes
#include <fstream>
#include <algorithm>
// Constructor
ArbolGeneral::ArbolGeneral() {
    raiz = new NodoGeneral('\0'); // Root node has null character data
}

// Insert function
void ArbolGeneral::insert(std::string word) {
    NodoGeneral* node = raiz;
    for (char c : word) {
        NodoGeneral* child = nullptr;
        for (auto it = node->children.begin(); it != node->children.end(); ++it) {
            if ((*it)->data == c) {
                child = *it;
                break;
            }
        }
        if (child == nullptr) {
            child = new NodoGeneral(c);
            node->children.push_back(child);
        }
        node = child;
    }
    node->is_end_of_word = true;
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
std::list<std::string> ArbolGeneral::obtenerPalabrasPorPrefijo(std::string prefix) {
    std::list<std::string> words;
    NodoGeneral* node = raiz;
    for (char c : prefix) {
        NodoGeneral* child = nullptr;
        for (auto it = node->children.begin(); it != node->children.end(); ++it) {
            if ((*it)->data == c) {
                child = *it;
                break;
            }
        }
        if (child == nullptr) {
            return words;
        }
        node = child;
    }
    obtener_palabras_nodo(node, prefix, words);
    return words;
}

// Recursive function to retrieve words from node
void ArbolGeneral::obtener_palabras_nodo(NodoGeneral* node, std::string prefix, std::list<std::string>& words) {
    if (node->is_end_of_word) {
        words.push_back(prefix);
    }
    for (auto child : node->children) {
        
        obtener_palabras_nodo(child, prefix + child->data, words);
    }
}

// Search suffix function
std::list<std::string> ArbolGeneral:: obtenerPalabrasPorSufijo(std::string suffix) {
    std::list<std::string> words;
    NodoGeneral* node = raiz;
    // Reverse the suffix
    std::string reversed_suffix = suffix;
    std::reverse(reversed_suffix.begin(), reversed_suffix.end());
    for (char c : reversed_suffix) {
        NodoGeneral* child = nullptr;
        for (auto it = node->children.begin(); it != node->children.end(); ++it) {
            if ((*it)->data == c) {
                child = *it;
                break;
            }
        }
        if (child == nullptr) {
            return words;
        }
        node = child;
    }
    obtener_sufijo_palabras(node, suffix, words);
    return words;
}

// Recursive function to retrieve suffix words from node
void ArbolGeneral::obtener_sufijo_palabras(NodoGeneral* node, std::string suffix, std::list<std::string>& words) {
    if (node->is_end_of_word) {
        // Reverse the suffix back to the original order
        //std::reverse(suffix.begin(), suffix.end());
        words.push_back(suffix);
    }
    for (auto child : node->children) {
        obtener_sufijo_palabras(child, child->data + suffix, words);
    }
}
