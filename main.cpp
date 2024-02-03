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

// sacado de chatgpt: 
// revisa si hay caracteres especiales dentro de un string
bool specialChars( std::string& str) {

    bool special_char = false;
    for (char ch : str) {

        // Check if the character is not alphanumeric
        if (!std::isalnum(ch)) {

            special_char = true; // Found a special character
        }
    }

    return special_char; // No special characters found
};

bool hasNumber(std::string& str) {

    for (char ch : str) {

        if (std::isdigit(ch)) {

            return true; // Found a numeric digit
        }
    }
    
    return false; // No numeric digits found
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

                cot("el archivo no existe ");
                cote(comands[1]);
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

            if(specialChars(comands[1]) || hasNumber(comands[1])) { // palabra con carateres invalidos 

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

        else if( comands[0] == "iniciar_arbol") {
            

            if(comands[1] == "diccionario.txt") { // need to change this

                if(true) {

                    cote("El arbol del diccionario se ha inicializado correctamente");
                }
                else {

                    cote("El arbol del diccionario ya ha sido inicializado");
                }
            }
            else{

                cot("el nombre de archivo ");
                cot(comands[1]);
                cote(" no existe");
            }
        }

        else if( comands[0] == "iniciar_arbol_inverso") {
            

            if(comands[1] == "diccionario.txt") { // need to change this

                if(true) {

                    cote("El arbol del diccionario inverso se ha inicializado correctamente");
                }
                else {

                    cote("El arbol del diccionario inverso ya ha sido inicializado");
                }
            }
            else{

                cot("el nombre de archivo ");
                cot(comands[1]);
                cote(" no existe");
            }
        }

        else if(comands[0] == "palabras_por_prefijo") {

             if(specialChars(comands[1]) || hasNumber(comands[1])) { // o no se encuentra en el diccionario 

                cote("El prefijo nose pudo encontrarse en el diccionario");
             }

             else {

                cote("Las palabras que inician con este prefijo son: ");
             }
        }

        else if(comands[0] == "palabras_por_sufijo") {

             if(specialChars(comands[1]) || hasNumber(comands[1])) { // o no se encuentra en el diccionario 

                cote("El sufijo nose pudo encontrarse en el diccionario");
             }

             else {

                cote("Las palabras que terminan con este sufijo son: ");
             }
        }

        else if(comand == "grafo_de_palabras") {

            if(true) {

                cote("Grafo construido correctamente");
            }

            else {

                cote("Problemas tecnicos, no se pudo construir el grafo");
            }
        }

        else if(comands[0] == "posibles_palabras") {
         
             if(specialChars(comands[1]) || hasNumber(comands[1])) { // o no se encuentra en el diccionario 

                cote("La cadena letras contiene simbolos invalidos");
             }

             else {

                cote("Las posibles palabras a construir con las letras letras son: ");
             }
        }

        else if (comands[0] == "ayuda") {

            if(comands[1] == "ayuda") {

                cote("esto lo esta poniendo mapu");
            }

            else if( comands[1] == "inicializar" ) {
                 
                 cote("mapu");
            }

            else if( comands[1] == "iniciar_inverso" ) {
                 
                 cote("mapu");
            }

            else if( comands[1] == "puntaje" ) {
                 
                 cote("mapu");
            }

            else if( comands[1] == "salir" ) {
                 
                 cote("mapu");
            }

            else if( comands[1] == "iniciar_arbol" ) {
                 
                 cote("mapu");
            }

            else if( comands[1] == "iniciar_arbol_inverso" ) {
                 
                 cote("mapu");
            }

            else if( comands[1] == "palabras_por_prefijo" ) {
                 
                 cote("mapu");
            }

            else if( comands[1] == "palabras_por_sufijo" ) {
                 
                 cote("mapu");
            }

            else if( comands[1] == "grafo_de_palabras" ) {
                 
                 cote("mapu");
            }

            else if( comands[1] == "posibles_palabras" ) {
                 
                 cote("esto es una explicacion de posibles palabras (toca cambiarlo)");
            }
        
        }



    }   



}

