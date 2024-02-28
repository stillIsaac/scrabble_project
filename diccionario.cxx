#include "diccionario.h"
#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include "scrabble.h"
Diccionario::Diccionario() {

};

Diccionario::~Diccionario() {

};


void Diccionario::insertarValoresLetra() {

    ValorLetra comodin;
    comodin.letra = 'e';
    comodin.puntaje = 1;
    valoresLetras.push_back(comodin);
    comodin.letra = 'a';
    comodin.puntaje = 1;
    valoresLetras.push_back(comodin);
    comodin.letra = 'i';
    comodin.puntaje = 1;
    valoresLetras.push_back(comodin);
    comodin.letra = 'o';
    comodin.puntaje = 1;
    valoresLetras.push_back(comodin);
    comodin.letra = 'n';
    comodin.puntaje = 1;
    valoresLetras.push_back(comodin);
    comodin.letra = 'r';
    comodin.puntaje = 1;
    valoresLetras.push_back(comodin);
    comodin.letra = 't';
    comodin.puntaje = 1;
    valoresLetras.push_back(comodin);
    comodin.letra = 'l';
    comodin.puntaje = 1;
    valoresLetras.push_back(comodin);
    comodin.letra = 's';
    comodin.puntaje = 1;
    valoresLetras.push_back(comodin);
    comodin.letra = 'u';
    comodin.puntaje = 1;
    valoresLetras.push_back(comodin);
    comodin.letra = 'd';
    comodin.puntaje = 2;
    valoresLetras.push_back(comodin);
    comodin.letra = 'g';
    comodin.puntaje = 2;
    valoresLetras.push_back(comodin);
    comodin.letra = 'b';
    comodin.puntaje = 3;
    valoresLetras.push_back(comodin);
    comodin.letra = 'c';
    comodin.puntaje = 3;
    valoresLetras.push_back(comodin);
    comodin.letra = 'm';
    comodin.puntaje = 3;
    valoresLetras.push_back(comodin);
    comodin.letra = 'p';
    comodin.puntaje = 3;
    valoresLetras.push_back(comodin);
    comodin.letra = 'f';
    comodin.puntaje = 4;
    valoresLetras.push_back(comodin);
    comodin.letra = 'h';
    comodin.puntaje = 4;
    valoresLetras.push_back(comodin);
    comodin.letra = 'v';
    comodin.puntaje = 4;
    valoresLetras.push_back(comodin);
    comodin.letra = 'w';
    comodin.puntaje = 4;
    valoresLetras.push_back(comodin);
    comodin.letra = 'y';
    comodin.puntaje = 4;
    valoresLetras.push_back(comodin);
    comodin.letra = 'k';
    comodin.puntaje = 5;
    valoresLetras.push_back(comodin);
    comodin.letra = 'j';
    comodin.puntaje = 8;
    valoresLetras.push_back(comodin);
    comodin.letra = 'x';
    comodin.puntaje = 8;
    valoresLetras.push_back(comodin);
    comodin.letra = 'q';
    comodin.puntaje = 10;
    valoresLetras.push_back(comodin);
    comodin.letra = 'z';
    comodin.puntaje = 10;
    valoresLetras.push_back(comodin);

};

bool Diccionario::inicializarDiccionario(std::string nombreArchivo) {
    
    bool open = false;
    std::ifstream myfile; 
    myfile.open("diccionario.txt");
    std::string mystring;
    std::vector<std::string> vec;
    if(myfile.is_open()) {

        open = true;
        while(myfile.good()) {
            

            myfile >> mystring;
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

std::vector<std::string>Diccionario::obtenerPalabrasPorSufijo(std::string palabra) {

    std::vector<std::string> palabrasSufijo;

    return palabrasSufijo;
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
