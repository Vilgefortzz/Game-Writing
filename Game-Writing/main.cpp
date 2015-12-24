#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <iomanip>
#include <cstdio>
#include <ctime>
using namespace std;

void menu_obsluga();
void tworzenie_tablicy_znakowej(char[]); // znaki jakie s¹ wykorzystane do stworzenia tekstu bazowego
string generator_tekstu_bazowego(char[]);
void writing(string);
	
int main()
{
	srand(time(NULL));
	menu_obsluga();
	system("pause");
}

void menu_obsluga()
{
	char tablica_znakow[95]; // 95 - liczba znaków jakie mo¿na napisaæ na klawiaturze

	tworzenie_tablicy_znakowej(tablica_znakow);
	string TEKST_BAZOWY = generator_tekstu_bazowego(tablica_znakow);

	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	
	SetConsoleTextAttribute(hOut, 0x0006);
	cout << "WITAJ W NAUCE PISANIA\n";
	Sleep(5000);
	SetConsoleTextAttribute(hOut, FOREGROUND_RED);
	cout << "PAMIETAJ LICZY SIE NIE TYLKO TWOJ [CZAS] ALE ROWNIEZ [ILOSC BLEDOW] KTORE ZROBISZ.\n";
	Sleep(4000);
	SetConsoleTextAttribute(hOut, FOREGROUND_RED);
	cout << "PAMIETAJ ZE TWOJ [CZAS] LICZY SIE OD MOMENTU POJAWIENIA SIE TEKSTU DO PRZEPISANIA.  GL :D";
	Sleep(4000); system("cls");
	SetConsoleTextAttribute(hOut, 0x0006);
	cout << "PRZYGOTUJ SIE TWOJ TEKST ZARAZ SIE POJAWI!!";
	Sleep(3000); system("cls");

	SetConsoleTextAttribute(hOut, 0x0007);
	cout << TEKST_BAZOWY << endl;
	writing(TEKST_BAZOWY);
}

void tworzenie_tablicy_znakowej(char tablica_znakow[])
{
	for (int i = 0; i < 95; i++)
	{
		tablica_znakow[i] = static_cast<char>(i+32); // dodanie 32, poniewa¿ od 32 zaczyna siê spacja w ASCII
	}
}

string generator_tekstu_bazowego(char t_znakow[])
{
	int dlugosc_tekstu = rand() % 100 + 15;
	string bazowy("", dlugosc_tekstu);
	
	for (int i = 0; i < dlugosc_tekstu; i++)
	{
		bazowy[i] = t_znakow[rand() % 95];
	}
	return bazowy;
}

void writing(string bazowy)
{
	string TWOJE("", bazowy.length()); // pisany tekst, który na koñcu bêdzie taki jak bazowy(o to tu chodzi)
	int ilosc_bledow = 0;

	int czas1 = clock()/CLOCKS_PER_SEC; // w³¹czenie stoperu

	for (int i = 0; i < bazowy.length(); i++)
	{
		TWOJE[i] = _getch();

		if (bazowy[i] == TWOJE[i])
		{
			cout << TWOJE[i];
		}
		else
		{
			do
			{
				ilosc_bledow++;
				TWOJE[i] = _getch();
			} while (bazowy[i] != TWOJE[i]);
			cout << TWOJE[i];
		}
	}

	int czas2 = clock()/CLOCKS_PER_SEC; // zatrzymanie stoperu
	int czas_wykonania_zadania = (czas2 - czas1);

	cout << "\n\nPODSUMOWANIE TWOJEJ NAUKI PISANIA:" << endl;
	cout << "CZAS: ";
	if (czas_wykonania_zadania >= 60)
	{
		int czas_min, czas_sec;
		czas_min = czas_wykonania_zadania % 60;
		czas_sec = czas_wykonania_zadania - czas_min * 60;
		cout << czas_min << " [min] " << czas_sec << " [sec]\n";
	}
	else
		cout << czas_wykonania_zadania << " [sec]\n";

	cout << "ILOSC BLEDOW: " << ilosc_bledow << endl << endl;
}
