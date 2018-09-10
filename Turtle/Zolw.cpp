#include "stdafx.h"
#include "Zolw.h"


Zolw::Zolw()
{
	_x = 0;
	_y = 0;
}

// otrzymuje dane poprzez referencje
void Zolw::getPosition(int &x, int &y) {
	x = _x;
	y = _y;
}

void Zolw::setPosition(int x, int y) {
	_x = x;
	_y = y;
}

Zolw::~Zolw()
{
}
