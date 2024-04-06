#ifndef _NODO_GENERAL_H
#define _NODO_GENERAL_H


#include <list>


class NodoGeneral {
public:
    char data;
    std::list<NodoGeneral*> hijos;
    bool is_end_of_word;

    NodoGeneral(char c) : data(c), is_end_of_word(false) {}
};

#endif