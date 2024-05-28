#include "graph.h"
#include <vector>
#include <iterator>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>

Grafo::Grafo() {


}
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
/*
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
*/
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
/*
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


*/
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


            bool escape = false;
            int i = 0, j = 0;
            while (i < longer.length() && j < shorter.length() && !escape) {

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




std::vector<std::string> Grafo::posibles_palabras(std::string letras) {
    
    std::vector<std::string> subsets = subset(letras);
    int comodin = 0;
    for (int i = 0; i < letras.size(); i++) {
        
        if(letras[i] == '?') {

            comodin++;
        }

    }
    
    
    std::vector<std::string> posibles; 
    for (int i = 0; i < this->vs.size(); i++) {
        
        for(int j = 0; j < subsets.size(); j++ ) {


            if( this->vs[i].size() == subsets[j].size()) {
                 
                   
                std::vector<std::string> conexiones = this->retConexiones(vs[i]);
               // this->anadirComodin(conexiones, vs[i]);
                for (int k = 0; k < conexiones.size(); k++) {

                    if(diferenciaCadena(conexiones[k], letras) == 0) {
                        
                        posibles.push_back(conexiones[k]);
                    }

                    else if( diferenciaCadena(conexiones[k], letras) <= comodin) {

                        posibles.push_back(conexiones[k]);
                    
                    }
                                       
                    
                }
            }
        }
    }

   this->eliminarDuplicados(posibles);
   return posibles; 
}



void Grafo::generarSubsets(std::string &str, std::string current, int index, std::vector<std::string>&subsets) {

    if(index == str.length()) {

        if(current.length() >= 2) {
            subsets.push_back(current);
        }
        return;
    }

    this->generarSubsets(str, current, index+1, subsets);

    this->generarSubsets(str, current + str[index], index+1, subsets);
}



std::vector<std::string> Grafo::subset(std::string letras){

    std::vector<std::string>subs;
    this->generarSubsets(letras, "", 0, subs);
    
    return subs;
}



bool Grafo::comparaCaracteres(std::string pal1, std::string pal2) {

    int count = 0; bool si = false;

    for (int i = 0; i < pal1.size(); i++) {
        
        for (int j = 0; j < pal2.size(); j++) {
            
            if(pal1[i] == pal2[j]) {

                count++;
                break;
            }
        }
        
    }

    if(count == pal1.size()) {

        si = true;
    }

    return si;
    
}




void  Grafo::anadirComodin(std::vector<std::string> &conexiones, std::string palabra) {


    for (int i = 0; i < conexiones.size(); i++) {
        
        for (int j = 0; j < conexiones[i].size(); j++) {
            
           if( conexiones[i].size() > palabra.size()) {
                
                bool cambio = false;
                for (int k = 0; k < palabra.size(); k++) {
                
                    if(conexiones[i][k] != palabra[k]) {

                        conexiones[i][k] = '?';
                        cambio = true;
                    }
                }
                if(cambio == false) {

                    conexiones[i][conexiones[i].size()-1] = '?';
                }            

            }
            else {

                for (int k = 0; k < conexiones[i].size(); k++) {
                
                    if(conexiones[i][k] != palabra[k]) {

                        conexiones[i][k] = '?';
                    }
                }
                
            } 
        }
        
    }
    
}





void  Grafo::eliminarDuplicados(std::vector<std::string> & posibles) {

    std::vector<std::string> unique;
    for (int i = 0; i < posibles.size(); i++) {

        bool duplicado = false;
        for (int j = 0; j < unique.size(); j++) {

            if(unique[j] == posibles[i]) {

                duplicado = true;
            }
        }
        
        if(!duplicado) {

            unique.push_back(posibles[i]);
        }
    }
    posibles = unique;    
}






int Grafo::diferenciaCadena(std::string conexion, std::string cadena) {

    bool elBreak = false;
    for (int i = 0; i <conexion.size() && !elBreak; i++) {
    
        for (int j = 0; j < cadena.size() && !elBreak; j++) {
        
            if(conexion.size() == 0) {

                elBreak = true;
            }
            
            else if(conexion[i] == cadena[j]) {

                conexion.erase(i, 1);
                i--;
                cadena.erase(j,1);
                j--;
            }
        }
        
    }

    return conexion.size();
    
}

/*
 bool Grafo::insertarDiccionario(std::vector<std::vector<std::string>> dic) {

    bool insertado = false;
    int count = 0;
    for (int i = 0; i < dic.size(); i++) {
        count += dic[i].size();
        for (int j = 0; j < dic[i].size(); j++) {
        
            this->insert(dic[i][j]);
        }
        
    }
    insertado = true;


    return insertado;
 }

*/
void Grafo::preResize(int vertices) {

     this->mAdyacencia.resize(vertices, std::vector<bool>(vertices, 0));
     this->vs.resize(vertices);


}

void Grafo::insert2(std::string cadena) {

    bool insertado = false;
    for (int i = 0; i < this->vs.size() && !insertado; i++) {
        if (vs[i] == std::string{}) {
            vs[i] = cadena;
            insertado = true;
        }
    }
    
}

bool Grafo::insertarDiccionario(std::vector<std::vector<std::string>> dic) {

    bool insertado = false;
    int count = 0;
    for (int i = 0; i < dic.size(); i++) {
        count += dic[i].size();
        for (int j = 0; j < dic[i].size(); j++) {
        
            this->insert(dic[i][j]);
        }
        
    }
    insertado = true;


    return insertado;
}