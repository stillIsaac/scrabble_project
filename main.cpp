#include <iostream>
#include <bits/stdc++.h>


//cot es un cout sin endl

void cot(std::string word) {
    std::cout << word;
};


//cote es un cout con endl
void cote(std::string word) {
    std::cout << word << std::endl;
};

//Funcion basada en GeeksForGeeks
//Encargada de tokenizar strings
std::vector<std::string> tokenize(std::string line) {
  
    std::vector <std::string> tokens;
     
    // stringstream class check1
    std::stringstream check1(line);
     
    std::string intermediate;
     
    // Tokenizing w.r.t. space ' '
    while(getline(check1, intermediate, ' ')) {

        tokens.push_back(intermediate);
    }
     


    return tokens;
};

int main() {

    cote("Welcome to Scrabble the game of words and creativity!");
    bool control = false;
    std::string comand;
    while(!control) {

        cote("please add a command");
        cot("$ ");
        std::getline(std::cin,comand);
        std::vector<std::string> comands = tokenize(comand);

        if(comand == "salir") {
        
            cote("Gracias por jugar, vuelve pronto");
            control = true;
        }

       
        else if( comands[0] == "inicializar") {
            

            if(comands[1] == "diccionario.txt") { // need to change this

                if(true) {

                    cote("El diccionario se ha inicializado correctamente");
                }
                else {

                    cote("El diccionario ya ha sido inicializado");
                }
            }
            else{

                cote("el archivo no existe");
            }
        }

        else if(comands[0] == "iniciar_inverso") {

             if(comands[1] == "diccionario.txt") { // need to change this

                if(true) {

                    cote("El diccionario inverso se ha inicializado correctamente");
                }
                else {

                    cote("El diccionario inverso ya ha sido inicializado");
                }
            }
            else{

                cote("el archivo no existe");
            }
        }

        else if(comands[0] == "puntaje") {

            if(false) { // palabra con carateres invalidos 

                cote("La palabra contiene simbolos invalidos");
            }
            else if(false) { // palabra no existe

                cote("La palabra no existe en el diccionario");
            }
            else {

                cot("La palabra tiene un puntaje de: ");
                cote("tanto");
            }
        }
    }   



}

