#include <iostream>
#include <fstream>
#include <string>
#include "FileOpen.h"
#include "Encriptar.h"

//Diseño del main
void main() 
{
	//Fase 1, Comprobación de contenido
	int shift = 3;
	bool eraseContent = true;

	//Parte 2: bool ? Escritura y lectura normal : Preguntas y todo el rollo
	bool isEmpty = ReadFile();

	if (!isEmpty) 
	{
		// Verifica checksum.
		int storedCheck = ReadCheckNum();
		std::string encrypted = ReadContent();
		int calculatedCheck = CalcularCheckSum(encrypted);

		if (storedCheck != calculatedCheck) 
		{
			std::cout << "Aviso: Se ha modificado el archivo externamente\n\n";
		}

		std::cout << "Se ha detectado contenido en el archivo, quieres mantenerlo y escribir por encima, o borrar lo que ya hay y empezar de 0\n";
		std::cout << "Si quieres borrar, escribe 1, si quieres mantener escribe 0\n";
		std::cout << "En caso de mantenerlos, se mostraran a continuacion\n";

		int choice;
		std::cin >> choice;
		std::cin.ignore();  //Para evitar problemas, he encontrado que desps de un cin, en temas de archivos, mejor poner siempre un ignore justo detrás

		if (choice == 0) 
		{
			eraseContent = false;
			DisplayOldContent(shift);
		}
		else if (choice == 1) 
		{
			eraseContent = true;
		}
		else {
			std::cout << "Contenido Invalido\n";
			return;
		}
	}

	//Separación del código aqui que sino se me bugeaba
	WriteFile(eraseContent, shift);
	return;
}


