// ConsoleApplication1.cpp�: d�finit le point d'entr�e pour l'application console.
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

