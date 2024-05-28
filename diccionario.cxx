#include "diccionario.h"
#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include "scrabble.h"
#include <cctype>   
Diccionario::Diccionario() {

};

Diccionario::~Diccionario() {

};


bool Diccionario::inicializarDiccionario(std::string nombreArchivo) {
    
    bool open = false;
    std::ifstream myfile; 
    myfile.open(nombreArchivo);
    std::string mystring;
    std::vector<std::string> vec;
    if(myfile.is_open()) {

        open = true;
        while(myfile.good()) {
            

            myfile >> mystring;
            for (char& c : mystring) {
                c = std::tolower(c);
            }
            if(int(mystring[0])-96 > vec_palabras.size()) {
        
                this->vec_palabras.resize(int(mystring[0])-96);
            }
            
            this->vec_palabras[int(mystring[0])-97].push_back(mystring);
            
        }
    }

    return open;
};

void Diccionario::mostraPalabras() {

    for(int i = 0; i < vec_palabras.size(); i++) {

        for(int j = 0; j  < vec_palabras[i].size(); j++) {

            std::cout << vec_palabras[i][j] << std::endl;
        }    
    }
};


bool Diccionario::inicializarDiccionarioInverso(std::string nombreArchivo) {

    bool open = false;
    std::ifstream myfile; 
    myfile.open("diccionario.txt");
    std::string mystring;
    std::vector<std::string> vec;
    if(myfile.is_open()) {

        open = true;
        while(myfile.good()) {
            
            
            myfile >> mystring;
            reverse(mystring.begin(), mystring.end()); 
            if(int(mystring[0])-96 > vec_palabras.size()) {
        
                this->vec_palabras.resize(int(mystring[0])-97+1);
            }
            
            this->vec_palabras[int(mystring[0])-97].push_back(mystring);
            
        }
    }


    return open;
};

std::list<std::string>Diccionario::obtenerPalabrasPorSufijo(std::string palabra) {

    return arbolInverso.obtenerPalabrasPorSufijo(palabra);;
};

std::list<std::string>Diccionario::obtenerPalabrasPorPrefijo(std::string palabra) {

    return arbol.obtenerPalabrasPorPrefijo(palabra);;
};

bool Diccionario::buscarPalabrasPorNombre(std::string palabra) {

 
    bool existe = false;
    int left= 0;
    int right = vec_palabras.size()-1;
    if(int(palabra[0])-97 < vec_palabras.size()) {
        while(left <= right && !existe) {

            int mid = left + (right-left)/2;

            std::string palabra_evaluar = vec_palabras[mid][0];
               
            
            if(int(palabra_evaluar[0]) == int(palabra[0])) {
            
                for(int i = 0; i < vec_palabras[mid].size(); i++) {

                    if(vec_palabras[mid][i] == palabra) {

                        existe = true;
                    }
                }
                left = right;
                
            }

            else if(int(palabra_evaluar[0]) < int(palabra[0])){

                left = mid+1;
            }

            else {
            
                right = mid -1;
            }
        }
    }
    return existe;

};


bool Diccionario::iniciarArbol(std::string archivo) {

    return this->arbol.iniciarArbol(archivo);
}

bool Diccionario::iniciarArbolInverso(std::string archivo) {

    return this->arbolInverso.iniciarArbolInverso(archivo);
}