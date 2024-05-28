#include "scrabble.h"
#include "diccionario.h"
#include "ArbolGeneral.h"
#include <iostream>
#include <bits/stdc++.h>
#include "graph.h"
Scrabble::Scrabble() {

};


Scrabble::~Scrabble() {

};

//cot es un cout sin endl

void Scrabble::cot(std::string word) {
  
    std::cout << word;
};


//cote es un cout con endl
void Scrabble::cote(std::string word) {
    std::cout << word << std::endl;
};


//Funcion basada en GeeksForGeeks
//Encargada de tokenizar strings
std::vector<std::string> Scrabble::tokenize(std::string line) {
  
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
bool Scrabble::specialChars( std::string& str) {

    bool special_char = false;
    for (char ch : str) {

        // Check if the character is not alphanumeric
        if (!std::isalnum(ch)) {

            special_char = true; // Found a special character
        }
    }

    return special_char; // No special characters found
};


// La funcion revisa si una cadena de caracteres tiene numeros por dentro
bool Scrabble::hasNumber(std::string& str) {

    for (char ch : str) {

        if (std::isdigit(ch)) {

            return true; // Found a numeric digit
        }
    }
    
    return false; // No numeric digits found
};


int Scrabble::puntajePalabra(std::string palabra)
{
    int puntaje = 0;

    for (int i = 0; i < palabra.length(); i++){

        if(palabra[i] == 'e' || palabra[i] == 'a' || palabra[i] == 'i' || palabra[i] == 'o' || palabra[i] == 'n' || palabra[i] == 'r' || palabra[i] == 't' || palabra[i] == 'l' || palabra[i] == 's' || palabra[i] == 'u' )
        puntaje += 1;

        else if (palabra[i] == 'd' || palabra[i] == 'g')
        puntaje += 2;

        else if (palabra[i] == 'b' || palabra[i] == 'c' || palabra[i] == 'm' || palabra[i] == 'p')
        puntaje += 3;

        else if (palabra[i] == 'f' || palabra[i] == 'h' || palabra[i] == 'v' || palabra[i] == 'w' || palabra[i] == 'y')
        puntaje += 4;

        else if (palabra[i] == 'k')
        puntaje += 5;

        else if (palabra[i] == 'j' || palabra[i] == 'x')
        puntaje += 8;

        else if (palabra[i] == 'q' || palabra[i] == 'z')
        puntaje += 10;

        else{
            puntaje = -1;
            std::cout << "La palabra contiene un caracter no valido \0";
        }
    }

    return puntaje;
};




void Scrabble::terminal() {


    cote("Welcome to Scrabble the game of words and creativity!");
    bool control = false;
    std::string comand;
    Diccionario dic;
    Grafo grafo(5);
    while(!control) {

      
        cot("$ ");
        std::getline(std::cin,comand);
        std::vector<std::string> comands = tokenize(comand);

        if(comands.size()<2 && (comand != "salir") && ( comand != "grafo_de_palabras")) {

            cot("comando: ");
            cot(comand);
            cote( " faltan argumentos");
        }

        else if(comand == "salir") {
        
            cote("Gracias por jugar, vuelve pronto");
            control = true;
        }

       
        else if( comands[0] == "inicializar") {
            

            if(comands[1] == "diccionario.txt" || comands[1] == "diccionario2.txt") { //eed to change this

                if(dic.vec_palabras.size() <= 0) {

                    cote("El diccionario se ha inicializado correctamente");
                    dic.inicializarDiccionario( comands[1]);
                    //dic.mostraPalabras();
                    
                }
                else {

                    cote("El diccionario ya ha sido inicializado");
                }
            }
            else{

                cot("el archivo: ");
                cot(comands[1]);
                cote(" no existe por favor ingrese un nombre de archivo valido");
            }
        }

        else if(comands[0] == "iniciar_inverso") {

            if(comands[1] == "diccionario.txt") { // need to change this

                if(true) {

                    cote("El diccionario se ha inicializado correctamente");
                  //  dic.mostraPalabras();
                    dic.inicializarDiccionarioInverso( "diccionario.txt");
                    
                }
                else {

                    cote("El diccionario ya ha sido inicializado");
                }
            }
            else{

                cot("el archivo: ");
                cot(comands[1]);
                cote(" no existe por favor ingrese un nombre de archivo valido");
            }
        }

        else if(comands[0] == "puntaje") {

            if(specialChars(comands[1]) || hasNumber(comands[1])) { // palabra con carateres invalidos 

                cote("La palabra contiene simbolos invalidos");
            }
            else if( dic.buscarPalabrasPorNombre(comands[1]) == false) { // palabra no existe

                cote("La palabra no existe en el diccionario");
            }
            else {
                
                std::cout << "La palabra tiene un puntaje de: " << puntajePalabra(comands[1]) << std::endl;
            }
        }

        else if( comands[0] == "iniciar_arbol") {
            

            if(comands[1] == "diccionario.txt" || comands[1] == "diccionario2.txt") { // need to change this
                
                if(dic.iniciarArbol(comands[1])) {

                    cote("El arbol del diccionario se ha inicializado correctamente");
                }
                else {

                    cote("El arbol del diccionario ya ha sido inicializado");
                }
            }
            else{

                cot("el nombre de archivo: ");
                cot(comands[1]);
                cote(" no existe");
            }
        }

        else if( comands[0] == "iniciar_arbol_inverso") {
            

            if(comands[1] == "diccionario.txt") { // need to change this

                if(dic.iniciarArbolInverso(comands[1])) {

                    cote("El arbol del diccionario inverso se ha inicializado correctamente");
                }
                else {

                    cote("El arbol del diccionario inverso ya ha sido inicializado");
                }
            }
            else{

                cot("el nombre de archivo: ");
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
                std::list<std::string> prefijos =dic.obtenerPalabrasPorPrefijo(comands[1]); 
                std::list<std::string>::iterator itPrefijos;
                std::cout << "PALABRAS" << "\t"<< "    PUNTAJE"<< "\t" << "\t" << "CANT_LETRAS" << std::endl;
                for(itPrefijos = prefijos.begin(); itPrefijos != prefijos.end(); itPrefijos++ ) {

                    std::cout << *itPrefijos << "\t" << "\t"<< "\t" << this->puntajePalabra(*itPrefijos) << "      " <<"\t" << "\t"<<(*itPrefijos).size() << std::endl;
                } 
             }
        }

        else if(comands[0] == "palabras_por_sufijo") {

             if(specialChars(comands[1]) || hasNumber(comands[1])) { // o no se encuentra en el diccionario 

                cote("El sufijo pudo encontrarse en el diccionario");
             }

             else {

                cote("Las palabras que terminan con este sufijo son: ");
                std::list<std::string> sufijos = dic.obtenerPalabrasPorSufijo(comands[1]);
                std::list<std::string>::iterator itSufijos;
                std::cout << "PALABRAS" << "\t"<< "    PUNTAJE"<< "\t" << "\t" << "CANT_LETRAS" << std::endl;
                for(itSufijos = sufijos.begin(); itSufijos != sufijos.end(); itSufijos++ ) {

                    std::cout << *itSufijos << "\t" << "\t"<< "\t" << this->puntajePalabra(*itSufijos) << "      " <<"\t" << "\t"<<(*itSufijos).size() << std::endl;
                } 
             }
        }
        

        else if(comand == "grafo_de_palabras") {

            if(!dic.vec_palabras.empty()) {            
            
                if(grafo.insertarDiccionario(dic.vec_palabras)) {
                    

                    cote("Grafo construido correctamente");
                   grafo.connect(); 
                }

                else {

                    cote("Problemas tecnicos, no se pudo construir el grafo");
                }
            }

            else {

                cote("El diccionario no ha sido inicializado");
            }
        }

        else if(comands[0] == "posibles_palabras") {
         
             if( hasNumber(comands[1])) { // o no se encuentra en el diccionario 

                cote("La cadena letras contiene simbolos invalidos");
             }

             else {

                cote("Las posibles palabras a construir con las letras letras son: ");
                std::vector<std::string> posiblesPalabras = grafo.posibles_palabras(comands[1]);
                std::cout << "PALABRAS" << "\t"<< "    PUNTAJE"<< "\t" << "\t" << "CANT_LETRAS" << std::endl;
                for (int i = 0; i < posiblesPalabras.size(); i++) {
                
                    std::cout << posiblesPalabras[i] << "\t" << "\t"<< "\t" << this->puntajePalabra(posiblesPalabras[i]) << "      " <<"\t" << "\t"<<posiblesPalabras[i].size() << std::endl;
                }
                
             }
        }

        else if (comands[0] == "ayuda") {

            if(comands[1] == "ayuda") {

                cote("ayuda: Muestra una descripcion de la funcion del comando y la explicacion de sus [posibles salidas]");
            }

            else if( comands[1] == "inicializar" ) {
                 
                 cote(" inicializar: Inicializa el sistema a partir un archivo que contiene un diccionario de palabras aceptadas en inglés.");
                 cote("[Diccionario ya inicializado] Indica que el diccionario ya se ha inicializado previamente");
                 cote("[Archivo no existe] Indica que el archivo que contiene el diccionario no existe o no puede ser leído");
                 cote("[Resultado exitoso] Indica que el diccionario se ha inicializado correctamente.");
            }

            else if( comands[1] == "iniciar_inverso" ) {
                 
                 cote("iniciar_inverso: Inicializa el sistema a partir del archivo del diccionario almacenando las palabras en sentido inverso");
                 cote("[Diccionario ya inicializado] Indica que el diccionario ya se ha inicializado previamente");
                 cote("[Archivo no existe] Indica que el archivo que contiene el diccionario no existe o no puede ser leído");
                 cote("[Resultado exitoso] Indica que el diccionario se ha inicializado correctamente.");
            
            }

            else if( comands[1] == "puntaje palabra" ) {
                 
                 cote("puntaje palabra: Obtiene el puntaje de una palabra dada.");
                 cote("[Palabra no existe] Informa que la palabra no existe en el diccionario");
                 cote("[Letras invalidas] Informa que la palabra contiene simbolos invalidos");
                 cote("[Resultado exitoso] Muestra el puntaje de la palabra");
            }

            else if( comands[1] == "salir" ) {
                 
                 cote("salir: Termina la ejecucion de la aplicacion");
            }

            else if( comands[1] == "iniciar_arbol diccionario.txt" ) {
                 
                 cote("iniciar_arbol: Inicializa el sistema a partir del archivo del diccionario almacenando las palabras en uno o mas arboles de letras");
                 cote("[Arbol ya inicializado] Indica que el arbol del diccionario ya se ha inicializado");
                 cote("[Archivo no existe] El archivo del diccionario no existe o no puede ser leído");
                 cote("[Resultado exitoso] El arbol del diccionario se ha inicializado correctamente");
            }

            else if( comands[1] == "iniciar_arbol_inverso" ) {

                 cote("iniciar_arbol_inverso: Inicializa el sistema a partir del archivo del diccionario almacenando las palabras en arboles de letras en sentido inverso");
                 cote("[Arbol ya inicializado] Indica que el arbol del diccionario inverso ya se ha inicializado");
                 cote("[Archivo no existe] El archivo del diccionario no existe o no puede ser leído");
                 cote("[Resultado exitoso] El arbol del diccionario inverso se ha inicializado correctamente");
            
            }

            else if( comands[1] == "palabras_por_prefijo" ) {
                 
                 cote("palabras_por_prefijo: Busca todas las palabras que inician con un prefijo dado");
                 cote("[Prefijo invalido] El prefijo no pudo encontrarse en el diccionario");
                 cote("[Resultado exitoso] Muestra las palabras encontradas en el diccionario con ese prefijo");
                 
            }

            else if( comands[1] == "palabras_por_sufijo" ) {
                 
                 cote("palabras_por_sufijo: Busca todas las palabras que inician con un sufijo dado");
                 cote("[Prefijo invalido] El sufijo no pudo encontrarse en el diccionario");
                 cote("[Resultado exitoso] Muestra las palabras encontradas en el diccionario con ese sufijo");
                 
            }

            else if( comands[1] == "grafo_de_palabras" ) {
                 
                 cote("grafo_de_palabras: Construye un grafo de palabras, conectando palabras que difieren en una unica letra");
                 cote("[Resultado exitoso] Informa que el grafo se ha construido correctamente");
            }

            else if( comands[1] == "posibles_palabras" ) {
                 
                 cote("posibles_palabras: Muestra todas las posibles palabras validas a construir con la letras dadas");
                 cote("[Letras invalidas] La palabra contiene simbolos invalidos");
                 cote("[Resultado exitoso] Muestra las posibles palabras para construir con las letras dadas");
            }
        
        }



    }   


}


