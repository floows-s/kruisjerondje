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
char array [3][3] {'.','.','.','.','.','.','.','.','.'};
bool gewonnen = false; //waneer iemand gewonnen heeft
int beurten = 0; //hoeveel beurten er voor bijzijn

void raster(){
	std::cout << " -----------\n";
	std::cout << "|" << std::setw(2) << array[0][0] << std::setw(2) << "|" << std::setw(2) << array[0][1] << std::setw(2) << "|" << std::setw(2) << array[0][2] << " |" << std::endl;
	std::cout << "|---+---+---|\n";
	std::cout << "|" << std::setw(2) << array[1][0] << std::setw(2) << "|" << std::setw(2) << array[1][1] << std::setw(2) << "|" << std::setw(2) << array[1][2] << " |" << std::endl;
	std::cout << "|---+---+---|\n";
	std::cout << "|" << std::setw(2) << array[2][0] << std::setw(2) << "|" << std::setw(2) << array[2][1] << std::setw(2) << "|" << std::setw(2) << array[2][2] << " |" << std::endl;
	std::cout << " -----------\n";
}

void invoer1 ()
{
	int rij = 0;
	int kolom = 0;
	//speler 1
rijvraag1:
	std::cout << speler1 << " welke rij: ";
	std::cin >> rij;
	//waneer er minder dan 1 of meer dan 3 wordt ingevoerd
	if (rij<1 || rij>3)
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
	if (kolom<1 || kolom>3)
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

void invoer2(){
	int rij = 0;
	int kolom = 0;

	//speler 2
rijvraag2:
	std::cout << speler2 << " welke rij: ";
	std::cin >> rij;
	//waneer er minder dan 1 of meer dan 3 wordt ingevoerd
	if(rij<1 || rij>3)
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
	if(kolom<1 || kolom>3)
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

	//namen in vullen van de spelers
	std::cout << "Wat is de naam van speler 1: ";
	std::cin >> speler1;
	std::cin.ignore();
	std::cout << "Wat is de naam van speler 2: ";
	std::cin >> speler2;
	std::cin.ignore();
	system("CLS");

	while(gewonnen != true){
	raster();
	invoer1();
	if(beurten == 9){break;}
	invoer2();
	system("CLS");
	}
	std::cout << "spel is voorbij\n";
	getchar();
	return 0;
}
