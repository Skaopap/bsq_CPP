// ConsoleApplication1.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "FatTab.h"

int main()
{
	std::cout << "--- HELLO GUYS ---" << std::endl;
	FatTab* Jack = new FatTab(10);
	Jack->display();

	Jack->findThatSquare();

	std::cout << "--- LOOK THAT SQUARE ---" << std::endl;

	Jack->display();
	system("pause");

	return 0;
}

