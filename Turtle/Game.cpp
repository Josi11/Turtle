#include "stdafx.h"
#include "Game.h"
#include <string>
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <Windows.h>

using namespace std;

void Game::menu()
{
	int wybor;
	cout << "######################################" << endl;
	cout << "#  GRA - WYJSCIE ZOLWIA Z LABIRYNTU  #" << endl;
	cout << "######################################" << endl;
	cout << "#   Wybierz poziom trudnosci:        #" << endl;
	cout << "#   1. Hard                          #" << endl;
	cout << "#   2. Medium                        #" << endl;
	cout << "#   3. Easy                          #" << endl;
	cout << "######################################" << endl;

	cin >> wybor;

	if (wybor == 1) {
		hard();
	}
	if (wybor == 2) {
		medium();
	}
	if (wybor == 3) {
		easy();
	}
}

void Game::easy()
{
	Game game("poziom3.txt");
	game.playGame();

	char input;

	while (true) {
		input = _getch();
		cout << "Wcisnales: " << input << endl;
	}
}

void Game::medium()
{
	Game game("poziom2.txt");
	game.playGame();

	char input;

	while (true) {
		input = _getch();
		cout << "Wcisnales: " << input << endl;
	}
}

void Game::hard()
{
	Game game("poziom1.txt");
	game.playGame();

	char input;

	while (true) {
		input = _getch();
		cout << "Wcisnales: " << input << endl;
	}
}

Game::Game(string levelFileName)
{
	_poziom = new Poziom();
	_poziom->load(levelFileName, _zolw);
	_poziom->print();

	system("PAUSE");
}

Game::~Game()
{
	if (_poziom != nullptr)
		delete _poziom;
}

void Game::playGame() {
	bool ok = false;

	while (ok != true) {
		system("cls");
		_poziom->print();
		playerMove();

	}
}

void Game::playerMove() {
	char input;
	cout << "Klawisze do sterowania (w/s/a/d): ";
	input = _getch();
	
	_poziom->movePlayer(input, _zolw);

}