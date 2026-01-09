#pragma once
#include <fstream>
#include <string>
#include <iostream>

//GESTION DEL NÚMERO DE VERIFICACIÓN

//Elimino el magin Number del código
#define cesarShift 26

//Encriptado básico
std::string CesarEncript(const std::string& text, int shift) 
{
    std::string result = text;

    for (char& c : result) //Ahora no se tampoco si se ha hecho este for, pero vamos, mejor que el de toda la vida
    {
        if (c >= 'a' && c <= 'z') 
        {
            c = 'a' + (c - 'a' + shift) % cesarShift;
        }
        else if (c >= 'A' && c <= 'Z') 
        {
            c = 'A' + (c - 'A' + shift) % cesarShift;
        }
    }
    return result;
}

//Lo mismo pero invierto el cesarShift
std::string CesarDecript(const std::string& text, int shift)
{
    return CesarEncript(text, cesarShift - (shift % cesarShift));
}

int CalcularCheckSum(const std::string& text) 
{
    int sum = 0;
    for (char c : text) 
    {
        sum += static_cast<int>(c);  
        //No se si esto se ha hecho en clase pero vamos, es lo que nos enseñaron en 2o y en el 2o cuatri de 1o
    }
    return sum;
}