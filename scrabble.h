#ifndef SCRABBLE_H
#define SCRABBLE_H
#include <iostream>
#include <bits/stdc++.h>
class Scrabble {

    public:
        Scrabble();
        ~Scrabble();
        void terminal();
        void cot(std::string word);
        void cote(std::string word);
        int puntajePalabra(std::string palabra);
        std::vector<std::string> tokenize(std::string line);
        bool specialChars( std::string& str);
        bool hasNumber(std::string& str);

};

#endif 