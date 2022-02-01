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
std::string player1 = "Player 1";
std::string player2 = "Player 2";
char array [3][3] {'.','.','.','.','.','.','.','.','.'};

void raster(){
	std::cout << " -----------\n";
	std::cout << "|" << std::setw(2) << array[0][0] << std::setw(2) << "|" << std::setw(2) << array[0][1] << std::setw(2) << "|" << std::setw(2) << array[0][2] << " |" << std::endl;
	std::cout << "|---+---+---|\n";
	std::cout << "|" << std::setw(2) << array[1][0] << std::setw(2) << "|" << std::setw(2) << array[1][1] << std::setw(2) << "|" << std::setw(2) << array[1][2] << " |" << std::endl;
	std::cout << "|---+---+---|\n";
	std::cout << "|" << std::setw(2) << array[2][0] << std::setw(2) << "|" << std::setw(2) << array[2][1] << std::setw(2) << "|" << std::setw(2) << array[2][2] << " |" << std::endl;
	std::cout << " -----------\n";
}

void invoer (){
int rij = 0;
int colom = 0;
//speler 1
std::cout << player1 << " welke rij: ";
std::cin >> rij;
//waneer er minder dan 1 of meer dan 3 wordt ingevoerd
if(rij<1 || rij>3) {
    while (std::cin.fail() || rij<1 || rij>3) {
    std::cout << "!Vul een getal in tussen de 1 en 3!\n";
    std::cout << player1 << " welke rij: ";
    std::cin.clear();
    std::cin.ignore(245,'n');
    std::cin >> rij;
    }
}
rij--; //de array begint met tellen bij 0, waar dus rij 1 word ingevuld.
std::cin.ignore();
std::cout << player1 << " welke colom: ";
std::cin >> colom;
//waneer er minder dan 1 of meer dan 3 wordt ingevoerd
if(colom<1 || colom>3) {
    while (std::cin.fail() || colom<1 || colom>3) {
    std::cout << "!Vul een getal in tussen de 1 en 3!\n";
    std::cout << player1 << " welke colom: ";
    std::cin.clear();
    std::cin.ignore(245,'n');
    std::cin >> colom;
    }
}
colom--; //de array begint met tellen bij 0, waar dus rij 1 word ingevuld.
std::cin.ignore();
array[rij][colom] = 'X';

//raster laten zien om te kijken wat speler 1 heeft gedaan
system("CLS");
raster();

//speler 2
std::cout << player2 << " welke rij: ";
std::cin >> rij;
//waneer er minder dan 1 of meer dan 3 wordt ingevoerd
if(rij<1 || rij>3) {
    while (std::cin.fail() || rij<1 || rij>3) {
    std::cout << "!Vul een getal in tussen de 1 en 3!\n";
    std::cout << player2 << " welke rij: ";
    std::cin.clear();
    std::cin.ignore(245,'n');
    std::cin >> rij;
    }
}
rij--; //de array begint met tellen bij 0, waar dus rij 1 word ingevuld.
std::cin.ignore();
std::cout << player2 << " welke colom: ";
std::cin >> colom;
//waneer er minder dan 1 of meer dan 3 wordt ingevoerd
if(colom<1 || colom>3) {
    while (std::cin.fail() || colom<1 || colom>3) {
    std::cout << "!Vul een getal in tussen de 1 en 3!\n";
    std::cout << player2 << " welke colom: ";
    std::cin.clear();
    std::cin.ignore(245,'n');
    std::cin >> colom;
    }
}
colom--; //de array begint met tellen bij 0, waar dus rij 1 word ingevuld.
std::cin.ignore();
array[rij][colom] = 'O';
}



int main()
{
	//namen in vullen van de spelers
	std::cout << "Wat is de naam van speler 1: ";
	std::cin >> player1;
	std::cin.ignore();
	std::cout << "Wat is de naam van speler 2: ";
	std::cin >> player2;
	std::cin.ignore();
	system("CLS");

	raster();
	invoer();
	system("CLS");
	raster();
	getchar();
	return 0;
}

