#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Encriptar.h"

//GESTION DEL TXT
bool ReadFile() 
{
	std::ifstream file("file.txt");
	if (!file) {
		std::cout << "No se ha podido abrir o recuperar el contenido del archivo\n";
		return true;
	}
		
	file.seekg(0, std::ios::end);
	bool empty = (file.tellg() == 0); 
	//Este es el mejor método que he encontrado para verificar simplemente si existe contenido
	//Rápido y sencillo dos líneas

	file.close();
	return empty; 
}

//Aqui vienen cambios, debido a los bugs del añadido del checkSum
//Funcion para leer todo despues del checksum.
std::string ReadContent() 
{  
	std::ifstream file("file.txt");
	std::string content;
	std::string line;
	if (file) 
	{
		std::getline(file, line);  // Ignora checksum (fuera de lbucle)

		while (std::getline(file, line)) 
		{
			content += line + "\n";  // Todo el resto.
		}
		file.close();
	}
	return content;
}

//Funcion simple para leer el numerito
int ReadCheckNum() {
	std::ifstream file("file.txt");
	int checkSum = 0;

	if (file) 
	{
		file >> checkSum;
		file.close();
	}
	return checkSum;
}

//Funcion para typear el texto que ya había antes en el txt
void DisplayOldContent(int shift) 
{  
	std::string encrypted = ReadContent();
	std::string decrypted = CesarDecript(encrypted, shift);
	std::cout << decrypted << std::endl;
}

//Debido a lo bugeado que estaba la funcion, he tenido que cambiarla bastante 
// y ordenar los pasos finales de forma clara para que no se me joda el ódigo
void WriteFile(bool eraseContent, int shift) 
{
	std::string oldContent = "";

	if (!eraseContent) 
	{
		oldContent = CesarDecript(ReadContent(), shift);  // Viejo en claro.
	}

	std::cout << "Escribe tus palabras / frases, una vez escribas 'exit' y pulses enter, la ejecucion termina.\n";
	std::cout << "Debes escribir el 'Exit' en una fila aparte del resto del texto\n\n";

	std::string newContent;
	std::string input;

	while (std::getline(std::cin, input)) 
	{
		if (input == "exit" || input == "EXIT" || input == "Exit") 
			break;

		newContent += input + "\n";
	}

	//Concatenación de los textos
	std::string totalClear = oldContent + newContent;
	//Encripta todo
	std::string totalEncrypted = CesarEncript(totalClear, shift); 
	//Gestion CheckSum
	int checkSum = CalcularCheckSum(totalEncrypted);
	//Cambio, ya que ahora hago un nuevo string con todo el texto, no hay que hacer el append
	std::ofstream file("file.txt", std::ios::trunc);  
	
	//Resultado en el txt
	file << checkSum << "\n";
	file << totalEncrypted;
	file.close();
}

//además he eliminado dos funciones ya que haciendolas bien las que tengo bastan