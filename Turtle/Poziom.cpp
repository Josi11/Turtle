#include "stdafx.h"
#include "Poziom.h"
#include <fstream>
#include <iostream>
#include <exception>
#include <ctype.h>

using namespace std;


Poziom::Poziom()
{
}

void Poziom::load(string fileName, Zolw &zolw) {
	ifstream file;

	file.open(fileName);
	if (file.fail()) {
		throw invalid_argument("Filename incorrect");
	}

	string linia;
	while (getline(file, linia)) {
		danePoziomu.push_back(linia);
	}
	file.close();
	char pozycja;

	for (int i = 0; i < danePoziomu.size(); i++) {
		for (int j = 0; j < danePoziomu[i].size(); j++) {
			pozycja = danePoziomu[i][j];

			switch (pozycja) {
			case 'O':
				zolw.setPosition(j, i);
				break;
			}
		}
	}
}

void Poziom::print() {
	for (int i = 0; i < danePoziomu.size(); i++) {
		printf("%s\n", danePoziomu[i].c_str()); // szybszy niz cout, Metoda c_str zwraca ³añcuch znaków tylko do odczytu
	}
	printf("\n");
}

void Poziom::movePlayer(char input, Zolw &zolw) {

	int zolwX;
	int zolwY;

	zolw.getPosition(zolwX, zolwY);
	char ruch;

	switch (tolower(input)) { //obsluga wielkich liter
	case 'w':
		processPlayerMove(zolw, zolwX, zolwY - 1);
		printf("GORA");
		break;
	case 's':
		processPlayerMove(zolw, zolwX, zolwY + 1);
		printf("DOL");
		break;
	case 'a':
		processPlayerMove(zolw, zolwX-1, zolwY);
		printf("LEWO");
		break;
	case 'd':
		processPlayerMove(zolw, zolwX + 1, zolwY);
		printf("PRAWO");
		break;
	default:
		printf("Zly klawisz!");
		system("PAUSE");
		break;
	}
}

char Poziom::pobierzPozycje(int x, int y) {
	return danePoziomu[y][x];
}

void Poziom::ustawPozycje(int x, int y, char pozycja) {
	danePoziomu[y][x] = pozycja;
}


// Ruch zolwia, zdarzenie po wejœciu w œcianê lub w wolne pole
void Poziom::processPlayerMove(Zolw &zolw, int nextX, int nextY) {
	
	int zolwX;
	int zolwY;
	zolw.getPosition(zolwX, zolwY);

	char ruch = pobierzPozycje(nextX, nextY);

	switch (ruch) {
	case '#':
		printf("Uderzyles w sciane!");
		//system("pause");
		break;
	case '.':
		zolw.setPosition(nextX, nextY);
		ustawPozycje(zolwX, zolwY, '.');
		ustawPozycje(nextX, nextY, 'O');
		break;
	case '_':
		printf("Wygrales! Kliknij enter zeby zakonczyc");
		getchar();
		getchar();
		exit(0);
		break;
	}
}