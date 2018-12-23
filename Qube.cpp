// ConsoleApplication1.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "FatTab.h"

int main()
{
	std::cout << "--- HELLO GUYS ---" << std::endl;
	FatTab* Jack = new FatTab(50);
	//Jack->display();

	Jack->findThatSquareBetter();

	std::cout << "--- LOOK THAT SQUARE ---" << std::endl;

	Jack->display();
	system("pause");

	return 0;
}

