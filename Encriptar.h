#pragma once
#include <fstream>
#include <string>
#include <iostream>

std::string CesarEncript(std::string& text, int shift) {
	std::string result = text;
    int changeShift = 26;
    //Cifrado
	for (char& c : result) {
        if (c >= 'a' && c <= 'z')
        {
            c = 'a' + (c - 'a' + shift) % changeShift;
        }
        else if (c >= 'A' && c <= 'Z')
        {
            c = 'A' + (c - 'A' + shift) % changeShift;
        }
	}

    return result;
}

std::string CesarDecript(std::string& text, int shift) {
    int changeShift = 26;
    return CesarDecript(text, changeShift - (shift % changeShift));
}

int CalcularCheckSum(std::string& text) 
{
    int sum = 0;
    for (char c : text) {
        sum += static_cast<char>(c); //Esto no sé si se ha usado en clase, pero es la forma que se ha visto en 2o, que es un cast de toda la vida
    }
    return sum;
}
