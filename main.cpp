#include <iostream>
#include <fstream>
#include <string>
#include "FileOpen.h"
#include "Encriptar.h"

void main() 
{
	bool eraseContent;
	int shift = 3;

	int storedCheckNum = -1;
	int fileCheckNum = -1;
	
	bool isEmpty = ReadFile(); //Comprobamos si esta vacio

	if (isEmpty) 
	{
		eraseContent = true; //Se hace automaticamente porque que mas da
		WriteFile(eraseContent, shift);
	}
	else if (!isEmpty) 
	{
		//Comprobacion del CheckNum
		storedCheckNum = ReadCheckNum();
		std::string tempContent = ReadFile4CheckNum();
		fileCheckNum = CalcularCheckSum(tempContent);

		if (storedCheckNum != fileCheckNum)
			std::cout << "Aviso: Se ha modificado el archivo externamente\n\n";

		//Vuelta a la lógica
		int i = 0;
		std::cout << "Se ha detectado contenido en el archivo, quieres mantenerlo y escribir por encima, o borrar lo que ya hay y empezar de 0\n";
		std::cout << "Si quieres borrar, escribe 1, si quieres mantener escribe 0\n";
		std::cout << "En caso de mantenerlos, se mostraran a continuacion\n";
		std::cin >> i;

		if (i == 0) {
			WriteFromFile(-shift); //En negativo porque sino sigue palante
			eraseContent = false;
			WriteFile(eraseContent, shift);
		}
		else if (i == 1)
		{
			eraseContent = true;
			WriteFile(eraseContent, shift);
		}
		else if (i != 0 && i != 1) {
			std::cout << "Eres gilipollas o que?, escribe bien locooo\n";
			return;
		}
	}
}

