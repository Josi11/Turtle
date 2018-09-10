#pragma once
#include <vector>
#include <string>
#include "Zolw.h"


class IPoziomy
{
protected:
	std::vector <std::string> danePoziomu;

	virtual void processPlayerMove(Zolw &zolw, int nextX, int nextY) = 0;
public:
	IPoziomy()=default;
	virtual ~IPoziomy() = default;
	virtual void load(std::string fileName, Zolw &zolw)=0;
	virtual void print()=0;

	virtual void movePlayer(char input, Zolw &zolw)=0;
	virtual char pobierzPozycje(int x, int y)=0;
	virtual void ustawPozycje(int x, int y, char pozycja)=0;
};


class Poziom:public IPoziomy
{
private:
	void processPlayerMove(Zolw &zolw, int nextX, int nextY);
public:
	Poziom();
	~Poziom()= default;
	void load(std::string fileName, Zolw &zolw) override;
	void print() override;

	void movePlayer(char input, Zolw &zolw) override;
	char pobierzPozycje(int x, int y) override;
	void ustawPozycje(int x, int y, char pozycja) override;

};



