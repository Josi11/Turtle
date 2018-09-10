#pragma once
#include "Zolw.h"
#include "Poziom.h"
#include <string>

class Game
{
public:
	static void menu();
	static void easy();
	static void medium();
	static void hard();
private:
	IPoziomy * _poziom;
	Zolw _zolw;
public:
	Game() = default;
	Game(std::string levelFileName);
	~Game();

	void playGame();
	void playerMove();
};

