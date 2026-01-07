#include <iostream>
#include <fstream>
#include <string>
#include "FileOpen.h"

void main() 
{
	bool eraseContent;
	bool isEmpty = ReadFile(); //Comprobamos si esta vacio

	if (isEmpty) 
	{
		eraseContent = true; //Se hace automaticamente porque que mas da
		WriteFile(eraseContent);
	}
	else if (!isEmpty) 
	{
		int i = 0;
		std::cout << "Se ha detectado contenido en el archivo, quieres mantenerlo y escribir por encima, o borrar lo que ya hay y empezar de 0\n";
		std::cout << "Si quieres borrar, escribe 1, si quieres mantener escribe 0\n";
		std::cin >> i;

		if (i == 0) {
			eraseContent = false;
			WriteFile(eraseContent);
		}
		else if (i == 1)
		{
			eraseContent = true;
			WriteFile(eraseContent);
		}
		else if (i != 0 && i != 1) {
			std::cout << "Eres gilipollas o que?, escribe bien locooo\n";
			return;
		}
		
	}
}

