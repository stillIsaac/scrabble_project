#include "diccionario.h"
#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <string>

Diccionario::Diccionario() {

};

Diccionario::~Diccionario() {

};

bool Diccionario::inicializarDiccionario(std::string) {
    
    bool open = false;
    std::ifstream myfile; 
    myfile.open("diccionario.txt");
    std::string mystring;
    std::vector<std::string> vec;
    if(myfile.is_open()) {
        open = true;
        while(myfile.good()) {
            myfile >> mystring;
            
            vec.push_back(mystring);

        }
    }

    for(int i = 0; i < vec.size()-1; i++)
        std::cout << vec[i] << std::endl;

    return open;
    return false;
}

bool Diccionario::inicializarDiccionarioInverso(std::string) {

    return false;
}

std::vector<std::string>Diccionario::obtenerPalabrasPorSufijo(std::string palabra) {

    std::vector<std::string> palabrasSufijo;

    return palabrasSufijo;
};

bool Diccionario::buscarPalabrasPorNombre(std::string palabra) {

    return true;

};

    
std::vector<std::string>Diccionario::obtenerPalabrasPorPrefijo(std::string palabra) {

    std::vector<std::string> palabrasPrefijo;

    return palabrasPrefijo;

};