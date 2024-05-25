#include "graph.h"
#include <vector>
#include <iterator>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
Grafo::Grafo(int vertices) {
    this->mAdyacencia.resize(vertices, std::vector<bool>(vertices, 0));
    this->vs.resize(vertices);
}

bool Grafo::insert(std::string valor) {
    bool insertado = false;
    // Caso grafo empty
    for (int i = 0; i < this->vs.size() && !insertado; i++) {
        if (vs[i] == std::string{}) {
            vs[i] = valor;
            insertado = true;
        }
    }

    if (!insertado) {
        this->vs.push_back(valor);
        this->mAdyacencia.resize(vs.size());
        for (int i = 0; i < this->mAdyacencia.size(); i++) {
            this->mAdyacencia[i].resize(vs.size(), 0);
        }
        insertado = true;
    }
    return insertado;
}

bool Grafo::addArista(std::string valor1, std::string valor2) {

    bool insertada = false;
    int indice1 = -1, indice2 = -1;
    for (int i = 0; i < this->vs.size(); i++) {

        if (valor1 == vs[i]) {

            indice1 = i;
        }
        if (valor2 == vs[i]) {

            indice2 = i;
        }
    }

    if (indice2 == -1 || indice1 == -1) {

        insertada = false;
    } 
    else {

        this->mAdyacencia[indice1][indice2] = true;
    }

    return insertada;
}

bool Grafo::deleteV(std::string valor) {
    bool eliminado = false;
    auto it = std::find(vs.begin(), vs.end(), valor);
    if (it != vs.end()) {
        int index = std::distance(vs.begin(), it);
        this->vs.erase(vs.begin() + index);

        mAdyacencia.erase(mAdyacencia.begin() + index);
        // Eliminar la columna de la matriz de adyacencia
        for (int i = 0; i < mAdyacencia.size(); i++) {
            mAdyacencia[i].erase(mAdyacencia[i].begin() + index);
        }

        eliminado = true;
    }
    return eliminado;
}

void Grafo::printMAdyacencia() {
    // Iterate over each row of the matrix
    for (const auto& row : mAdyacencia) {
        // Print the elements of the row
        for (bool connection : row) {
            std::cout << connection << " ";
        }
        std::cout << std::endl; // Print newline after each row
    }
}

void Grafo::iterativeDFS(std::string valor) {
    std::queue<std::string> pila1;
    std::vector<std::string> visitados;
    pila1.push(valor);
    while (!pila1.empty()) {
        std::string v = pila1.front();
        pila1.pop();
        bool visitado = false;
        for (int k = 0; k < visitados.size() && !visitado; k++) {
            if (visitados[k] == v) {
                visitado = true;
            }
        }

        if (!visitado) {
            std::cout << v << "-";
            visitados.push_back(v);
            std::vector<std::string> aristas = retConexiones(v);
            for (const auto& it : aristas) {
                pila1.push(it);
            }
        }
    }
}

std::vector<std::string> Grafo::retConexiones(std::string val) {
    int index;
    for (int i = 0; i < vs.size(); i++) {
        if (vs[i] == val) {
            index = i;
        }
    }

    std::vector<std::string> conexiones;
    for (int i = 0; i < vs.size(); i++) {
        if (this->mAdyacencia[index][i] == true) {
            conexiones.push_back(vs[i]);
        }
    }
    std::sort(conexiones.begin(), conexiones.end());

    return conexiones;
}

    void Grafo::recursiveDFS(std::string valor) {
        std::vector<std::string> visited;
        recursiveDFSHelper(valor, visited);
    }

    void Grafo::recursiveDFSHelper(std::string valor, std::vector<std::string>& visited) {
        visited.push_back(valor);
        std::cout << valor << " ";

        std::vector<std::string> conexiones = retConexiones(valor);
        for (const auto& conexion : conexiones) {
            if (std::find(visited.begin(), visited.end(), conexion) == visited.end()) {

                recursiveDFSHelper(conexion, visited);
            }
        }
    }



    void Grafo::connect() {

        for (int i = 0; i < vs.size(); i++) {

            for (int j = 0; j < vs.size(); j++) {

                if(!this->checkConnection(vs[i], vs[j], i, j)) {

                    this->mAdyacencia[i][j] = false;
                    this->mAdyacencia[j][i] = false;
                }
            }
        }
        
    }


    bool Grafo::checkConnection(std::string val1, std::string val2, int index1, int index2) {
        
        bool conectado = false;
        std::cout << val1 << "  " << val2 << std::endl;
        if(pow((double)val1.size()-val2.size(), 2) > 1) {

            conectado = false;
        }

       else if (std::abs((double)val1.size() - val2.size()) == 1) {
   
            std::string longer, shorter;
            if (val1.size() > val2.size()) {
   
                longer = val1;
                shorter = val2;
            }

            else {

                longer = val2;
                shorter = val1;
            }

            std::cout << "Checking strings of different lengths: " << longer << " (longer) and " << shorter << " (shorter)" << std::endl;

            bool escape = false;
            int i = 0, j = 0;
            while (i < longer.length() && j < shorter.length() && !escape) {

                std::cout << "Comparing characters: " << longer[i] << " and " << shorter[j] << std::endl;
                if (longer[i] != shorter[j]) {

                    if (i != j) {

                        escape = true;
                    }

                    i++;
                } 
                else {

                    i++;
                    j++;
                }
            }

            std::cout << "Escape status: " << escape << std::endl;

            if (!escape) {

                this->mAdyacencia[index1][index2] = true;
                this->mAdyacencia[index2][index1] = true;
                conectado = true;
            }
        }    

        else {
            
            int numDif = 0;
            for(int i = 0; i < val1.size(); i++) {

                if(val1[i] != val2[i]) {

                    numDif++;
                }
            }

            if (numDif <= 1) {

                this->mAdyacencia[index1][index2] = true;
                this->mAdyacencia[index2][index1] = true;
                conectado = true;
            }
            
        }
        
        
        return conectado;
    }



