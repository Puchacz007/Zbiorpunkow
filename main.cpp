#include <iostream>
#include"zbiorPunktow.h"

using namespace std;

int main()
{
	ZbiorPunktow *tablicaZbiorow = NULL;
	int liczbaZbiorow = 0, x, y;
	while (1)
	{

		cout << "Podaj numer operacji do wykonania" << endl;
		int numer = 0, numer2 = 0, numer3 = 0;

		while (1)
		{
			cout << "1-Dodaj liczbe do zbioru" << endl << "2-Zwroc nablizsze punkty w zbiorze" << endl << "3-Suma dwoch zbiorow" << endl << "4-Iloczyn dwoch zbiorow" << endl << "5-Wypisz wszystkie zbiory" << endl << "6-Wczytaj i wypisz testowe zbiory" << endl << "7-Zakoncz dzialanie programu" << endl;
			cin >> numer;
			if (numer >= 1 && numer <= 7 && cin.good() == 1)break;
			cout << "Zly numer \nPodaj numer jeszcze raz" << endl;
			while (getchar() != '\n');

			cin.clear();
		}
		while (getchar() != '\n');
		switch (numer)
		{
		case 1:
			while (1)
			{
				cout << "Podaj wsporzedne calkowite punktu x i y (odzielone spacja)" << endl;
				cin >> x >> y;
				if (cin.good() == 1)break;
				while (getchar() != '\n');
				cin.clear();
				cout << "Podane wspolrzedne nie sa calkowite" << endl;
			}
			while (getchar() != '\n');
			if (tablicaZbiorow == NULL)
			{
				tablicaZbiorow = new ZbiorPunktow[1];
				tablicaZbiorow[0].dodajPunkt(x, y);
				liczbaZbiorow++;
				cout << "Punkty zostaly dodane do zbioru" << endl;
				break;
			}
			cout << "Wybierz numer zbioru do ktorego checesz dodac punkt lub numer operacji utworzenia nowego zbioru" << endl;

			for (int i = 0; i < liczbaZbiorow; i++)
			{
				cout << i + 1 << "-";
				cout << tablicaZbiorow[i] << endl;


			}
			cout << liczbaZbiorow + 1 << "-Utworz nowy zbior" << endl;
			while (1)
			{
				cin >> numer;
				if (numer >= 1 && numer <= (liczbaZbiorow + 1) && cin.good() == 1)break;
				cout << "Zly numer\nPodaj numer jeszcze raz\n";
				cin.clear();
				while (getchar() != '\n');

			}
			if (numer == liczbaZbiorow + 1)
			{
				nowyZbior(&liczbaZbiorow, tablicaZbiorow);
				tablicaZbiorow[liczbaZbiorow - 1].dodajPunkt(x, y);
				while (getchar() != '\n');
				break;
			}
			else
			{
				tablicaZbiorow[numer - 1].dodajPunkt(x, y);
				while (getchar() != '\n');
				break;
			}
			while (getchar() != '\n');
		case 2:
			if (liczbaZbiorow == 0)
			{
				cout << "Brak zbiorow" << endl;
				break;

			}
			cout << "Wybierz numer zbioru w ktorym chcesz znalezc najblizej lezace punkty i znajduja sie co najmniej dwa punkty" << endl;

			for (int i = 0; i < liczbaZbiorow; i++)
			{
				cout << "Zbior numer " << i + 1 << endl;
				cout << tablicaZbiorow[i] << endl;


			}
			while (1)
			{
				cin >> numer;
				if (numer >= 1 && numer <= (liczbaZbiorow) && cin.good() == 1)break;
				cout << "Zly numer\nPodaj numer jeszcze raz\n";
				while (getchar() != '\n');
				cin.clear();
			}
			while (getchar() != '\n');
			tablicaZbiorow[numer - 1].najblizszePunkty();
			break;
		case 3:
			if (liczbaZbiorow == 0)
			{
				cout << "Brak zbiorow" << endl;
				break;

			}
			cout << "Wybierz numery zbiorow ktore chcesz sumowac" << endl;
			for (int i = 0; i < liczbaZbiorow; i++)
			{
				cout << i + 1 << "-";
				cout << tablicaZbiorow[i] << endl;


			}
			while (1)
			{
				cin >> numer >> numer2;
				if (numer >= 1 && numer <= liczbaZbiorow && numer2 >= 1 && numer2 <= liczbaZbiorow)break;
				cout << "Zle numery zbiorow\nPodaj numery zbiorow jeszcze raz\n";
				while (getchar() != '\n');
				cin.clear();

			}
			while (getchar() != '\n');
			cout << "Zbior sumy\n" << tablicaZbiorow[numer - 1] + tablicaZbiorow[numer2 - 1] << endl;
			cout << "Czy chcesz zapisac ten zbior jako jeden z dodawanych zbiorow lub jako nowy zbior" << endl << "1-zapisz jako zbior podany w sumie jako pierwszy" << endl << "2-zapisz jako zbior podany w sumie jako drugi" << endl << "3-zapisz jako nowy zbior" << endl << "4-nie" << endl;
			while (1)
			{
				cin >> numer3;
				if (numer3 >= 1 && numer3 <= 4 && cin.good() == 1)break;
				cout << "Zly numer\nPodaj numer jeszcze raz\n";
				while (getchar() != '\n');
				cin.clear();
			}

			if (numer3 == 1) tablicaZbiorow[numer - 1] += tablicaZbiorow[numer2 - 1];
			else if (numer3 == 2)tablicaZbiorow[numer2 - 1] += tablicaZbiorow[numer - 1];
			else if (numer3 == 3)
			{
				nowyZbior(&liczbaZbiorow, tablicaZbiorow);
				tablicaZbiorow[liczbaZbiorow - 1] = tablicaZbiorow[numer - 1] + tablicaZbiorow[numer2 - 1];

			}

			while (getchar() != '\n');
			break;
		case 4:
			if (liczbaZbiorow == 0)
			{
				cout << "Brak zbiorow" << endl;
				break;

			}
			cout << "Wybierz numery zbiorow ktorych iloczyn chcesz przeprowadzic" << endl;
			for (int i = 0; i < liczbaZbiorow; i++)
			{
				cout << i + 1 << "-";
				cout << tablicaZbiorow[i] << endl;


			}
			while (1)
			{
				cin >> numer >> numer2;
				if (numer >= 1 && numer <= liczbaZbiorow && numer2 >= 1 && numer2 <= liczbaZbiorow)break;
				cout << "Zle numery zbiorow\nPodaj numery zbiorow jeszcze raz\n";
				while (getchar() != '\n');
				cin.clear();

			}
			while (getchar() != '\n');
			cout << "Zbior iloczynu\n" << tablicaZbiorow[numer - 1] * tablicaZbiorow[numer2 - 1] << endl;

			if ((tablicaZbiorow[numer - 1] * tablicaZbiorow[numer2 - 1]).isEmpty())break;
			cout << "Czy chcesz zapisac ten zbior jako jeden z mnozonych zbiorow lub jako nowy zbior" << endl << "1-zapisz jako zbior podany w iloczynie jako pierwszy" << endl << "2-zapisz jako zbior podany w iloczynie jako drugi" << endl << "3-zapisz jako nowy zbior" << endl << "4-nie" << endl;;
			while (1)
			{
				cin >> numer3;
				if (numer3 >= 1 && numer3 <= 4 && cin.good() == 1)break;
				cout << "Zly numer\nPodaj numer jeszcze raz\n ";
				while (getchar() != '\n');
				cin.clear();
			}

			if (numer3 == 1) tablicaZbiorow[numer - 1] *= tablicaZbiorow[numer2 - 1];
			else if (numer3 == 2)tablicaZbiorow[numer2 - 1] *= tablicaZbiorow[numer - 1];
			else if (numer3 == 3)
			{
				nowyZbior(&liczbaZbiorow, tablicaZbiorow);
				tablicaZbiorow[liczbaZbiorow - 1] = tablicaZbiorow[numer - 1] * tablicaZbiorow[numer2 - 1];
			}
			while (getchar() != '\n');
			break;
		case 5:
			if (liczbaZbiorow == 0)
			{
				cout << "Brak zbiorow" << endl;
				break;

			}
			for (int i = 0; i < liczbaZbiorow; i++)
			{
				cout << "Zbior nr " << i + 1 << endl;
				cout << tablicaZbiorow[i] << endl;

			}

			break;
		case 6:
			nowyZbior(&liczbaZbiorow, tablicaZbiorow);
			nowyZbior(&liczbaZbiorow, tablicaZbiorow);
			tablicaZbiorow[liczbaZbiorow - 2].dodajPunkt(2, 1);
			tablicaZbiorow[liczbaZbiorow - 2].dodajPunkt(3, 1);
			tablicaZbiorow[liczbaZbiorow - 2].dodajPunkt(7, 7);
			tablicaZbiorow[liczbaZbiorow - 2].dodajPunkt(2, 0);
			tablicaZbiorow[liczbaZbiorow - 2].dodajPunkt(2, 2);
			tablicaZbiorow[liczbaZbiorow - 1].dodajPunkt(5, 312);
			tablicaZbiorow[liczbaZbiorow - 1].dodajPunkt(2, 4);
			tablicaZbiorow[liczbaZbiorow - 1].dodajPunkt(2, 1);
			tablicaZbiorow[liczbaZbiorow - 1].dodajPunkt(7, 7);
			cout << "Zbior A\n" << tablicaZbiorow[liczbaZbiorow - 2] << endl << "Zbior B\n" << tablicaZbiorow[liczbaZbiorow - 1] << endl;
			cout << "Zbior dodawania" << endl << tablicaZbiorow[liczbaZbiorow - 2] + tablicaZbiorow[liczbaZbiorow - 1] << endl;
			cout << "Zbior mozenia" << endl << tablicaZbiorow[liczbaZbiorow - 2] * tablicaZbiorow[liczbaZbiorow - 1] << endl;
			break;
		case 7:
			delete[] tablicaZbiorow;
			return 0;


		}
	}
}