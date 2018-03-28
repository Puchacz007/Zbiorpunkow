/**
* Name: zbiorPunktow.cpp
* Purpose: Tworzenie zbioru punktow plaszczyzny na ktorym mozna wykonywac rozne operacje *
* @author Mpuchals
* @version 1.0 28.03.2018
*/
#include <iostream>
#include <cmath>
#include "zbiorPunktow.h"
using namespace std;
ZbiorPunktow ZbiorPunktow::operator=(const ZbiorPunktow &zbior)
{

	if (liczbaPunkow != zbior.liczbaPunkow)
	{

		liczbaPunkow = zbior.liczbaPunkow;
		delete[] wszystkiePunkty;
		this->wszystkiePunkty = new Punkt[zbior.liczbaPunkow];
	}
	for (int i = 0; i < zbior.liczbaPunkow; i++)
	{
		this->wszystkiePunkty[i] = zbior.wszystkiePunkty[i];
	}
	return *this;
}
ZbiorPunktow ZbiorPunktow::operator+(const ZbiorPunktow &zbior)const
{
	ZbiorPunktow sumaZbiorow;
	sumaZbiorow.liczbaPunkow = 0;
	sumaZbiorow.wszystkiePunkty = NULL;
	for (int i = 0; i < this->liczbaPunkow; i++)
	{
		sumaZbiorow.dodajPunkt(wszystkiePunkty[i].wypiszX(), wszystkiePunkty[i].wypiszY());
	}

	for (int i = 0; i < zbior.liczbaPunkow; i++)
	{

		for (int j = 0; j < this->liczbaPunkow; j++)
		{

			if (zbior.wszystkiePunkty[i] == wszystkiePunkty[j])
			{

				i++;
				if (i >= zbior.liczbaPunkow)break;
				j = -1;
			}
		}
		if (i < zbior.liczbaPunkow)
			sumaZbiorow.dodajPunkt(zbior.wszystkiePunkty[i].wypiszX(), zbior.wszystkiePunkty[i].wypiszY());
	}
	return ZbiorPunktow(sumaZbiorow);

}
ZbiorPunktow ZbiorPunktow::operator+=(const ZbiorPunktow &zbior)
{
	*this = *this + zbior;
	return *this;
}
ZbiorPunktow ZbiorPunktow::operator*(const ZbiorPunktow &zbior)const
{
	ZbiorPunktow iloczynZbiorow;
	iloczynZbiorow.liczbaPunkow = 0;
	iloczynZbiorow.wszystkiePunkty = NULL;
	for (int i = 0; i < liczbaPunkow; i++)
	{


		for (int j = 0; j < zbior.liczbaPunkow; j++)
		{
			if (wszystkiePunkty[i] == zbior.wszystkiePunkty[j])
			{
				iloczynZbiorow.dodajPunkt(wszystkiePunkty[i].wypiszX(), wszystkiePunkty[i].wypiszY());
				break;
			}

		}

	}
	return ZbiorPunktow(iloczynZbiorow);
}
ZbiorPunktow ZbiorPunktow::operator*=(const ZbiorPunktow &zbior)
{

	*this = *this * zbior;
	return *this;
}
ZbiorPunktow::ZbiorPunktow(const ZbiorPunktow &zbior)
{
	wszystkiePunkty = NULL;
	wszystkiePunkty = new  Punkt[zbior.liczbaPunkow];
	liczbaPunkow = zbior.liczbaPunkow;
	for (int i = 0; i < zbior.liczbaPunkow; i++)
	{
		wszystkiePunkty[i] = zbior.wszystkiePunkty[i];

	}
}

void ZbiorPunktow::dodajPunkt(int x, int y)
{
	for (int i = 0; i < liczbaPunkow; i++)
	{

		if (wszystkiePunkty[i] == Punkt(x, y))	return;
	}
	this->liczbaPunkow++;
	if (this->liczbaPunkow == 1)
	{
		this->wszystkiePunkty = new Punkt[1];

		this->wszystkiePunkty[0] = Punkt(x, y);
	}
	else
	{
		Punkt *temp = new  Punkt[this->liczbaPunkow];


		for (int i = 0; i < liczbaPunkow - 1; i++)
		{
			temp[i] = this->wszystkiePunkty[i];

		}
		delete[] this->wszystkiePunkty;
		this->wszystkiePunkty = temp;
		this->wszystkiePunkty[this->liczbaPunkow - 1] = Punkt(x, y);
	}
}
void ZbiorPunktow::najblizszePunkty()
{
	if (liczbaPunkow < 2)
	{
		cout << "Brak wystarczajacej liczby punktow do obliczenia nablizej lezacych siebie punktow" << endl;
		return;

	}
	double odleglosc, odlegloscMin;
	Punkt A, B; //zmienne do zapisu punktow lezacych najblizej siebie
	Punkt *punkty = NULL;
	int liczbaNajblizszychPunktow = 2;
	for (int i = 0; i < liczbaPunkow - 1; i++)
	{
		for (int j = i + 1; j < liczbaPunkow; j++)
		{

			odleglosc = sqrt(pow(wszystkiePunkty[i].wypiszX() - wszystkiePunkty[j].wypiszX(), 2) + pow(wszystkiePunkty[i].wypiszY() - wszystkiePunkty[j].wypiszY(), 2));//wzor na odleglosc punktow



			if (j == 1 || odleglosc < odlegloscMin)
			{
				delete[] punkty;
				punkty = new Punkt[2];
				punkty[0] = wszystkiePunkty[i];
				punkty[1] = wszystkiePunkty[j];
				liczbaNajblizszychPunktow = 2;
				odlegloscMin = odleglosc;
			}
			else if (odleglosc == odlegloscMin)
			{
				liczbaNajblizszychPunktow += 2;
				Punkt *temp = new Punkt[liczbaNajblizszychPunktow];
				for (int i = 0; i < liczbaNajblizszychPunktow - 2; i++)
				{
					temp[i] = punkty[i];
				}
				delete[] punkty;
				punkty = temp;
				punkty[liczbaNajblizszychPunktow - 2] = wszystkiePunkty[i];
				punkty[liczbaNajblizszychPunktow - 1] = wszystkiePunkty[j];
				odlegloscMin = odleglosc;
			}


		}

	}
	cout << "Najblizej siebie w odleglosci " << odlegloscMin << " leza punkty:" << endl;
	for (int i = 0; i < liczbaNajblizszychPunktow; i += 2)
	{
		cout << punkty[i].wypiszXY() << " i " << punkty[i + 1].wypiszXY() << endl;

	}

	delete[] punkty;
}
bool ZbiorPunktow::isEmpty()
{
	if (liczbaPunkow < 1)
		return true;
	else
		return false;
}

ostream &operator<<(ostream &wyjscie, const ZbiorPunktow &zbior)
{
	if (zbior.liczbaPunkow == 0)
	{
		wyjscie << "Zbior jest pusty" << endl;
	}
	else
	{
		wyjscie << "Do zbioru naleza punkty:" << endl;
		for (int i = 0; i < zbior.liczbaPunkow; i++)
		{
			wyjscie << zbior.wszystkiePunkty[i].wypiszXY() << endl;
		}
	}
	return wyjscie;
}

bool Punkt::operator==(const Punkt punkt) const
{
	if (x == punkt.x && y == punkt.y)
		return true;
	else return false;
}
Punkt Punkt::operator=(const Punkt punkt)
{
	x = punkt.x;
	y = punkt.y;
	return *this;
}

void nowyZbior(int *liczbaZbiorow, ZbiorPunktow *&tablicaZbiorow)
{

	*liczbaZbiorow = *liczbaZbiorow + 1;
	ZbiorPunktow *temp = new ZbiorPunktow[*liczbaZbiorow];
	for (int i = 0; i < (*liczbaZbiorow - 1); i++)
	{
		temp[i] = tablicaZbiorow[i];
	}
	delete[] tablicaZbiorow;
	tablicaZbiorow = temp;
	return;
}


