#include <iostream>
#include <bits/stdc++.h>
#include "scrabble.h"
#include "graph.h"



int main() {


    Grafo elGrafo(5);
    std::cout << "Diferencia: " << elGrafo.diferenciaCadena("avionk", "vionarty") << std::endl;
    elGrafo.insert("gato");
    elGrafo.insert("pato");
    elGrafo.insert("rato");
    elGrafo.insert("gata");
    elGrafo.insert("mata"); 
 //   elGrafo.insert("iman");
   // elGrafo.insert("imitacion");
   // elGrafo.insert("casa");
   // elGrafo.insert("caso");
   // elGrafo.insert("ocaso");

    elGrafo.connect();
    elGrafo.printMAdyacencia();
    std::vector<std::string> palabras = elGrafo.posibles_palabras("agtopr??");
    std::cout << "a" << std::endl;
    for (int i = 0; i < palabras.size(); i++) {
    
        std::cout << palabras[i] << std::endl;
    }
    


    Scrabble scrabble;
    scrabble.terminal();

    return 0;

}

