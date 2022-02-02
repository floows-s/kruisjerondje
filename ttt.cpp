#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
typedef char _TCHAR;
#define _tmain main
#endif

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>

//in de globale scope zo dat elke functie er makelijk bij kan.
std::string speler1 = "Speler 1";
std::string speler2 = "Speler 2";
char array[3][3]{'.', '.', '.', '.', '.', '.', '.', '.', '.'};
bool gewonnen = false;	//waneer iemand gewonnen heeft
bool gewonnen1 = false; //waneer speler 1 gewonnen heeft
bool gewonnen2 = false; //waneer speler 2 gewonnen heeft
int beurten = 0;		//hoeveel beurten er voor bijzijn
int wins1;
int wins2;

void checkWin()
{
	//speler 1

	//vertical
	if ((array[0][0] == 'X') && (array[1][0] == 'X') && (array[2][0] == 'X'))
	{
		gewonnen1 = true;
	}
	if ((array[0][1] == 'X') && (array[1][1] == 'X') && (array[2][1] == 'X'))
	{
		gewonnen1 = true;
	}
	if ((array[0][2] == 'X') && (array[1][2] == 'X') && (array[2][2] == 'X'))
	{
		gewonnen1 = true;
	}
	//horizontaal
	if ((array[0][0] == 'X') && (array[0][1] == 'X') && (array[0][2] == 'X'))
	{
		gewonnen1 = true;
	}
	if ((array[1][0] == 'X') && (array[1][1] == 'X') && (array[1][2] == 'X'))
	{
		gewonnen1 = true;
	}
	if ((array[2][0] == 'X') && (array[2][1] == 'X') && (array[2][2] == 'X'))
	{
		gewonnen1 = true;
	}
	//diagonaal
	if ((array[0][0] == 'X') && (array[1][1] == 'X') && (array[2][2] == 'X'))
	{
		gewonnen1 = true;
	}
	if ((array[0][2] == 'X') && (array[1][1] == 'X') && (array[2][0] == 'X'))
	{
		gewonnen1 = true;
	}

	//speler 2

	//vertical
	if ((array[0][0] == 'O') && (array[1][0] == 'O') && (array[2][0] == 'O'))
	{
		gewonnen2 = true;
	}
	if ((array[0][1] == 'O') && (array[1][1] == 'O') && (array[2][1] == 'O'))
	{
		gewonnen2 = true;
	}
	if ((array[0][2] == 'O') && (array[1][2] == 'O') && (array[2][2] == 'O'))
	{
		gewonnen2 = true;
	}
	//horizontaal
	if ((array[0][0] == 'O') && (array[0][1] == 'O') && (array[0][2] == 'O'))
	{
		gewonnen2 = true;
	}
	if ((array[1][0] == 'O') && (array[1][1] == 'O') && (array[1][2] == 'O'))
	{
		gewonnen2 = true;
	}
	if ((array[2][0] == 'O') && (array[2][1] == 'O') && (array[2][2] == 'O'))
	{
		gewonnen2 = true;
	}
	//diagonaal
	if ((array[0][0] == 'O') && (array[1][1] == 'O') && (array[2][2] == 'O'))
	{
		gewonnen2 = true;
	}
	if ((array[0][2] == 'O') && (array[1][1] == 'O') && (array[2][0] == 'O'))
	{
		gewonnen2 = true;
	}
}

void raster()
{
	std::cout << " -----------\n";
	std::cout << "|" << std::setw(2) << array[0][0] << std::setw(2) << "|" << std::setw(2) << array[0][1] << std::setw(2) << "|" << std::setw(2) << array[0][2] << " |" << std::endl;
	std::cout << "|---+---+---|\n";
	std::cout << "|" << std::setw(2) << array[1][0] << std::setw(2) << "|" << std::setw(2) << array[1][1] << std::setw(2) << "|" << std::setw(2) << array[1][2] << " |" << std::endl;
	std::cout << "|---+---+---|\n";
	std::cout << "|" << std::setw(2) << array[2][0] << std::setw(2) << "|" << std::setw(2) << array[2][1] << std::setw(2) << "|" << std::setw(2) << array[2][2] << " |" << std::endl;
	std::cout << " -----------\n";
}

void invoer1()
{
	int rij = 0;
	int kolom = 0;
	//speler 1
rijvraag1:
	std::cout << speler1 << " welke rij: ";
	std::cin >> rij;
	//waneer er minder dan 1 of meer dan 3 wordt ingevoerd
	if (rij < 1 || rij > 3)
	{
		std::cout << "!Kies 1 van de 3 rijen!\n";
		std::cin.clear();
		std::cin.ignore();
		goto rijvraag1;
	}
	rij--; //de array begint met tellen bij 0, waar dus rij 1 word ingevuld.
	if (array[rij][0] != '.' && array[rij][1] != '.' && array[rij][2] != '.')
	{
		std::cout << "Die rij is al bezet!\n";
		goto rijvraag1;
	}

	std::cin.ignore();
kolomvraag1:
	std::cout << speler1 << " welke kolom: ";
	std::cin >> kolom;
	//waneer er minder dan 1 of meer dan 3 wordt ingevoerd
	if (kolom < 1 || kolom > 3)
	{
		std::cout << "!Kies 1 van de 3 kolommen!\n";
		std::cin.clear();
		std::cin.ignore();
		goto kolomvraag1;
	}
	kolom--; //de array begint met tellen bij 0, waar dus rij 1 word ingevuld.
	if (array[rij][kolom] != '.')
	{
		std::cout << "Die plek is al bezet!\n";
		goto kolomvraag1;
	}

	std::cin.ignore();
	array[rij][kolom] = 'X';

	//raster laten zien om te kijken wat speler 1 heeft gedaan
	system("CLS");
	raster();
	beurten++; // 1 beurt voorbij
}

void invoer2()
{
	int rij = 0;
	int kolom = 0;

	//speler 2
rijvraag2:
	std::cout << speler2 << " welke rij: ";
	std::cin >> rij;
	//waneer er minder dan 1 of meer dan 3 wordt ingevoerd
	if (rij < 1 || rij > 3)
	{
		std::cout << "!Kies 1 van de 3 rijen!\n";
		std::cin.clear();
		std::cin.ignore();
		goto rijvraag2;
	}
	rij--; //de array begint met tellen bij 0, waar dus rij 1 word ingevuld.
	if (array[rij][0] != '.' && array[rij][1] != '.' && array[rij][2] != '.')
	{
		std::cout << "Die rij is al bezet!\n";
		goto rijvraag2;
	}

	std::cin.ignore();
kolomvraag2:
	std::cout << speler2 << " welke colom: ";
	std::cin >> kolom;
	//waneer er minder dan 1 of meer dan 3 wordt ingevoerd
	if (kolom < 1 || kolom > 3)
	{
		std::cout << "!Kies 1 van de 3 kolommen!\n";
		std::cin.clear();
		std::cin.ignore();
		goto kolomvraag2;
	}
	kolom--; //de array begint met tellen bij 0, waar dus rij 1 word ingevuld.
	if (array[rij][kolom] != '.')
	{
		std::cout << "Die plek is al bezet.\n";
		goto kolomvraag2;
	}

	std::cin.ignore();
	array[rij][kolom] = 'O';
	beurten++; // 1 beurt voorbij
}

int main()
{
	int spelen = 0;
	int activespel = 1;

	while (activespel == 1)
	{

		//Main menu
		int menuinput = 0;
		std::cout << "Kruisje Rondje\n\n";
		std::cout << "1. Spel spelen\n\n";
		std::cout << "2. Score bekijken\n\n";
		std::cout << "3. Credits\n\n";
		std::cout << "4. Exit\n\n\n";
		std::cin >> menuinput;

		while (menuinput != 1 && menuinput != 2 && menuinput != 3 && menuinput != 4)
		{
			std::cout << "Kruisje Rondje\n\n";
			std::cout << "Vul graag een van de opties in, dus bijv. (1,2 of 3)\n\n";
			std::cout << "1. Spel spelen\n\n";
			std::cout << "2. Score bekijken\n\n";
			std::cout << "3. Credits\n\n";
			std::cout << "4. Exit\n\n\n";
			std::cin >> menuinput;
		}
		if (menuinput == 1)
		{
			spelen = 1;
		}

		else if (menuinput == 2)
		{
			std::cout << "-----------------------Score---------------------------\n";
			std::cout << "Speler 1 heeft op dit moment " << wins1 << " keer gewonnen\nSpeler 2 heeft op dit moment " << wins2 << " keer gewonnen\n";
			std::cout << "-------------------------------------------------------\n\n";
		}
		else if (menuinput == 3)
		{
			std::cout << "Dit komt allemaal van internet\n\n";
		}
		else
		{
			return 0;
			std::exit;
		}

		while (spelen == 1)
		{

			//namen in vullen van de spelers
			std::cout << "Wat is de naam van speler 1: ";
			std::cin >> speler1;
			std::cin.ignore();
			std::cout << "Wat is de naam van speler 2: ";
			std::cin >> speler2;
			std::cin.ignore();
			while (speler2 == speler1)
			{
				std::cout << "Speler2 kies aub een andere naam dan speler1: ";
				std::cin >> speler2;
				std::cin.ignore();
			}
			system("CLS");

			while (gewonnen1 != true)
			{
				raster();
				invoer1();
				checkWin();
				if (gewonnen1 == true || gewonnen2 == true)
				{
					break;
				} //check in de loop
				if (beurten == 9)
				{
					break;
				} //check in de loop
				invoer2();
				checkWin();
				if (gewonnen1 == true || gewonnen2 == true)
				{
					break;
				} //check in de loop
				system("CLS");
			}
			if (gewonnen1 == true)
			{
				wins1++;
				std::cout << speler1 << " heeft gewonnen\n";
			}
			else if (gewonnen2 == true)
			{
				wins2++;
				std::cout << speler2 << " heeft gewonnen\n";
			}
			else
			{
				wins1++;
				wins2++;
				std::cout << "gelijk spel\n";
			}
			std::cout << "Wil je opnieuw beginnen?\n 1. Ja, overnieuw \n 0. Nee, stop\n";
			std::cin >> spelen;
			if (spelen != 1 && spelen != 0)
			{
				std::cout << "Dit klopt niet wat je hebt ingevuld, ik start het spel opnieuw\n\n";
				spelen = 1;
			}
		}
	}

	getchar();
	return 0;
}
