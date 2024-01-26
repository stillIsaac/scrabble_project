#include <iostream>
#include <bits/stdc++.h>

void cot(std::string word) {
    std::cout << word;
};

void cote(std::string word) {
    std::cout << word << std::endl;
};

int main() {
    cote("Welcome to Scrabble the game of words and creativity!");
    bool control = false;
    std::string comand;
    while(!control) {

        cote("please add a command");
        cot("$ ");
        std::cin>>comand;

        if(comand == "salir") {
        
            cote("Gracias por jugar, vuelve pronto");
            control = true;
        }


    }

}