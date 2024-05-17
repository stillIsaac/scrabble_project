#ifndef _GRAFO_H
#define _GRAFO_H

#include <iostream>
#include <vector>
#include <queue>
#include <string>

class Grafo {
public:
    Grafo(int vertices);
    std::vector<std::vector<bool>> mAdyacencia;
    std::vector<std::string> vs;
    bool insert(std::string valor);
    bool addArista(std::string valor1, std::string valor2);
    bool deleteV(std::string valor);
    void printMAdyacencia(); 
    void iterativeDFS(std::string valor);
    std::vector<std::string> retConexiones(std::string val);
    void recursiveDFS(std::string valor);
    void recursiveDFSHelper(std::string valor, std::vector<std::string>& visited);\
    void connect();
    bool checkConnection(std::string val1,std::string val2, int index1, int index2 );
};

#include "graph.hxx"
#endif
