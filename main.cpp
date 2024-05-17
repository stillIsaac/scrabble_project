#include <iostream>
#include <bits/stdc++.h>
#include "scrabble.h"
#include "graph.h"



int main() {


    Grafo elGrafo(5);
    elGrafo.insert("pato");
    elGrafo.insert("pata");
    elGrafo.insert("patacom");
    elGrafo.insert("imita");
    elGrafo.insert("imitar");
    elGrafo.connect();
    elGrafo.printMAdyacencia();


    Scrabble scrabble;
    scrabble.terminal();

    return 0;

}

