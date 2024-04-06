#ifndef _ARBOL_GENERAL_H
#define _ARBOL_GENERAL_H
#include <iostream>
#include "NodoGeneral.h"
#include <algorithm>

class ArbolGeneral {

   public:
       NodoGeneral* raiz;
       ArbolGeneral();


       void insert(std::string palabra);
       bool iniciarArbol(std::string archivo);
       bool iniciarArbolInverso(std::string archivo);
       std::list<std::string> obtenerPalabrasPorPrefijo(std::string prefijo);
       std::list<std::string> obtenerPalabrasPorSufijo(std::string sufijo);
       void obtener_palabras_nodo(NodoGeneral* nodo, std::string prefijo, std::list<std::string>& palabras);
       void obtener_sufijo_palabras(NodoGeneral* nodo,std::string sufijo, std::list<std::string>& palabras);


};


//#include "ArbolGeneral.cxx"
#endif