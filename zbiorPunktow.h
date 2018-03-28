/**
* Name: zbiorPunktow.h
* Purpose: Tworzenie zbioru punktow plaszczyzny na ktorym mozna wykonywac rozne operacje *
* @author Mpuchals
* @version 1.0 28.03.2018
*/

#include <iostream>
#include<string>
class Punkt
{
private:
	int x;
	int y;
public:
	Punkt()
	{
		x = 0;
		y = 0;
	}
	Punkt(int xx, int yy)
	{
		x = xx;
		y = yy;

	}
	bool operator==(const Punkt punkt)const;
	Punkt operator=(const Punkt punkt);
	int wypiszX()
	{
		return x;
	}
	int wypiszY()
	{
		return y;
	}
	std::string wypiszXY()
	{
		std::string napis = "(";
		napis += std::to_string(x);
		napis += ",";
		napis += std::to_string(y);
		napis += ")";
		return napis;
	}

};

class ZbiorPunktow
{

private:
	Punkt * wszystkiePunkty;
	int liczbaPunkow;
public:
	ZbiorPunktow()
	{
		liczbaPunkow = 0;
		wszystkiePunkty = NULL;
	}
	ZbiorPunktow(const ZbiorPunktow &zbior);
	~ZbiorPunktow()
	{
		if (this->wszystkiePunkty != NULL)
		{
			delete[] wszystkiePunkty;
		}
	}
	ZbiorPunktow operator+(const ZbiorPunktow &zbior)const;
	ZbiorPunktow operator*(const ZbiorPunktow &zbior) const;
	ZbiorPunktow operator+=(const ZbiorPunktow &zbior);
	ZbiorPunktow operator*=(const ZbiorPunktow &zbior);
	ZbiorPunktow operator=(const ZbiorPunktow &zbior);
	void dodajPunkt(int x, int y);
	void najblizszePunkty();
	bool isEmpty();

	friend std::ostream&  operator<<(std::ostream &, const ZbiorPunktow &zbior);
};

void nowyZbior(int *liczbaZbiorow, ZbiorPunktow *&tabliczaZbiorow);
