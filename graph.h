#ifndef _GRAFO_H
#define _GRAFO_H

#include <iostream>
#include <vector>
#include <queue>
#include <string>

class Grafo {
public:

    Grafo();
    Grafo(int vertices);
    std::vector<std::vector<bool>> mAdyacencia;
    std::vector<std::string> vs;


    bool insert(std::string valor);
    //bool addArista(std::string valor1, std::string valor2);
    bool deleteV(std::string valor);
    void printMAdyacencia(); 
    std::vector<std::string> retConexiones(std::string val);
    //void recursiveDFS(std::string valor);
    //void recursiveDFSHelper(std::string valor, std::vector<std::string>& visited);
    void connect();
    bool checkConnection(std::string val1,std::string val2, int index1, int index2 );
    std::vector<std::string> posibles_palabras(std::string letras);
    std::vector<std::string> subset(std::string letras);
    std::vector<std::string> recorridoPalabras(std::string subset);
    std::vector<std::string> sinDuplicados(std::vector<std::string> palabras);
    void generarSubsets(std::string &str, std::string current, int index, std::vector<std::string>&subsets);
    bool comparaCaracteres(std::string pal1, std::string pal2);
    void anadirComodin(std::vector<std::string> &conexiones, std::string palabra);
    void eliminarDuplicados(std::vector<std::string> & posibles);
    int diferenciaCadena(std::string conexion, std::string cadena);
    bool insertarDiccionario(std::vector<std::vector<std::string>> dic);
    void preResize(int vertices);
    void insert2(std::string cadena);

    bool insertarDiccionario2(std::vector<std::vector<std::string>> dic); 

};

#endif