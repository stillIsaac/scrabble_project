#ifndef _ARBOL_GENERAL_H
#define _ARBOL_GENERAL_H

#include <iostream>
#include "NodoGeneral.h"
#include <algorithm>

class ArbolGeneral {

    

    public:
        NodoGeneral* root;
        ArbolGeneral();

        void insert(std::string word);
        bool iniciarArbol(std::string archivo);
        bool iniciarArbolInverso(std::string archivo);
        std::list<std::string> obtenerPalabrasPorPrefijo(std::string prefix);
        std::list<std::string> obtenerPalabrasPorSufijo(std::string suffix);
        void get_words_from_node(NodoGeneral* node, std::string prefix, std::list<std::string>& words);
        void get_suffix_words(NodoGeneral* node,std::string suffix, std::list<std::string>& words);

};

//#include "ArbolGeneral.cxx"


#endif