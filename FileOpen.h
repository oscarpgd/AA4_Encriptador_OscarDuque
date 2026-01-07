#pragma once
#include <iostream>
#include <fstream>
#include <string>

bool ReadFile()
{
	std::ifstream file;
	file.open("file.txt");

	std::string content;
	std::string line;

	if (file)
	{
		while (std::getline(file, line))
		{
			content += line;
		}
		file.close();
	}

	if (content.empty()) return true; //Si esta vacio, proceso normal
	else return false; // sino, o se hace segun queramos eliminar o no (append || trunc)
}
void WriteFile(bool eraseContent)
{
	std::ofstream file;
	//Parte para ver si borramos el deste o lo mantenemos
	if (eraseContent == true) {
		file.open("file.txt", std::ios::trunc);
	}
	else if (eraseContent == false) {
		file.open("file.txt", std::ios::app);
	}

	std::cout << "Escribe tus palabras / frases, una vez escribas 'exit' y pulses enter, la ejecucion termina.\n";
	std::cout << "Debes escribir el 'Exit' en una fila aparte del resto del texto\n\n";

	std::string a; //String para captar el texto
	while (true) //Bucle par adetenernos cuando pongaos exit
	{
		std::getline(std::cin, a);
		if (a == "exit" || a == "EXIT" || a == "Exit")
			break;

		file << a << '\n';
	}
	file.close();
}