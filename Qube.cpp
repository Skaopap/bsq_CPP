// ConsoleApplication1.cpp�: d�finit le point d'entr�e pour l'application console.
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

