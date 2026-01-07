#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Encriptar.h"



bool ReadFile()
{
	std::ifstream file;
	file.open("file.txt");

	std::string content;
	std::string line;

	if (!file) {
		std::cout << "No se ha podido abrir o recuperar el contenido del archivo\n";
		return false;
	}
	else if (file)
	{
		std::getline(file, line); //Para ignorar la primera, así empezamos desde la 2a

		while (std::getline(file, line))
		{
			content += line;
		}
		file.close();
	}

	if (content.empty()) return true; //Si esta vacio, proceso normal
	else return false; // sino, o se hace segun queramos eliminar o no (append || trunc)
}

void WriteFile(bool eraseContent, int shift)
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

		a = CesarEncript(a, shift); //la otra línea confusa para aplicar

		int checkSum = CalcularCheckSum(a);
		file << checkSum << "\n\n";
		file << a << "\n";
	}
	file.close();
}

void WriteFromFile(int shift) {
	std::ifstream file;
	file.open("file.txt");

	std::string line;

	if (!file) {
		std::cout << "No se ha podido abrir o recuperar el contenido del archivo\n";
		return;
	}
	else if (file) {
		std::getline(file, line); //Para ignorar la primera, así empezamos desde la 2a

		while (std::getline(file, line)) {
			line = CesarEncript(line, shift); //Esta es la línea añadida, y esta también
			std::cout << line << std::endl;
		}
		file.close();
	}
}

int ReadCheckNum() {
	std::ifstream file;
	file.open("file.txt");

	int checkSum;
	file >> checkSum;
	file.close();
	return checkSum;
}

//Copia y pega de la de arriba pero en formato void
std::string ReadFile4CheckNum() {
	std::ifstream file;
	file.open("file.txt");

	std::string content;
	std::string line;

	if (!file) {
		std::cout << "No se ha podido abrir o recuperar el contenido del archivo\n";
	}
	else if (file)
	{
		std::getline(file, line); //Para ignorar la primera, así empezamos desde la 2a

		while (std::getline(file, line))
		{
			content += line;
		}
		file.close();
	}

	return content;
}