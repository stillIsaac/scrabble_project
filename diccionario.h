#ifndef DICCIONARIO_H
#define DICCIONARIO_H
#include <iostream>
#include <bits/stdc++.h>
#include "ArbolGeneral.h"

class Diccionario {

    public: 
        Diccionario();
        ~Diccionario();
        std::vector <std::vector<std::string>> vec_palabras;
        ArbolGeneral arbol;
        ArbolGeneral arbolInverso;
        void mostraPalabras();
        bool inicializarDiccionario(std::string nombreArchivo);
        bool inicializarDiccionarioInverso(std::string nombreArchivo);
        bool buscarPalabrasPorNombre(std::string palabra);
        bool iniciarArbol(std::string archivo);
        bool iniciarArbolInverso(std::string archivo);
        std::list<std::string> obtenerPalabrasPorSufijo(std::string palabra);
        std::list<std::string> obtenerPalabrasPorPrefijo(std::string palabra);
};
/*TAD: Diccionario
Estado:
- vec_palabras, es un vector de cadenas de caracteres, almacena todas las palabras del juego (normales e inversas), cada palabra no puede contener números o caracteres especiales
Comportamiento:
- obtenerPalabraPorNombre(), palabra: booleano; esta operación busca una palabra específica en el arreglo y retorna true si existe o false en caso de que no exista
- obtenerPalabraPorSufijo(), sufijo: palabras_suf; esta operación recibe como parámetro un sufijo y busca todas las palabras dentro del vector que tengan este.
- obtenerPalabraPorPrefijo(), prefijo: palabras_suf; esta operación recibe como parámetro un prefijo y busca todas las palabras dentro del vector que tengan este.

*/
#endif 