#include "stdafx.h"
#include "Kopiec.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "timer.h"
using namespace std;

//KLASA KOPIEC OBSLUGUJACA OPERACJE NA KOPCACH

Kopiec::Kopiec()
{
	rozmiar = 0;
	position = (int*)calloc(0, sizeof(int));
}


Kopiec::~Kopiec()
{
	delete [] position;
}

//metoda add dodajace element do kopca

void Kopiec::add(int liczba)
{
	rozmiar++;
	position = (int*)realloc(position, rozmiar * sizeof(int));
	position[rozmiar - 1] = liczba;
}

//metoda remove usuwajace element z kopca

void Kopiec::remove()
{
	rozmiar--;
	position = (int*)realloc(position, rozmiar * sizeof(int));
}

//metoda searchNumber sprawdzajaca czy podany element znajduje sie w kopcu

bool Kopiec::searchNumber(int liczba, int index)
{
	if (position[index] == liczba)
	{
		return true;
	}
	else if (position[index] < liczba)
	{
		return false;
	}
	else if (szukajSynaL(index) != 0 && searchNumber(liczba, szukajSynaL(index)))
	{
		return true;
	}
	else if (szukajSynaP(index) != 0 && searchNumber(liczba, szukajSynaP(index)))
	{
	return true;
	}
	else
	{
		return false;
	}
}

//metoda szukajSynaP wyszukujaca prawego syna danego wezla

int Kopiec::szukajSynaP(int fatherIndex)
{
	int sonIndex;
	sonIndex = 2 * fatherIndex + 2;
	if (sonIndex >= rozmiar)
	{
		return 0;
	}
	else
	{
		return sonIndex;
	}
}

//metoda szukajSynaP wyszukujaca lewego syna danego wezla

int Kopiec::szukajSynaL(int fatherIndex)
{
	int sonIndex;
	sonIndex = 2 * fatherIndex + 1;
	if (sonIndex >= rozmiar)
	{
		return 0;
	}
	else
	{
		return sonIndex;
	}
}

//metoda szukajOjca wyszukujaca ojca danego syna

int Kopiec::szukajOjca(int sonIndex)
{
	return((sonIndex - 1) / 2);
}

//metoda push dodajaca element do kopca i odtwarzajaca wlasciwosci kopca

void Kopiec::push(int liczba)
{
	add(liczba);
	int index;
	int zapas;
	index = rozmiar - 1;

	while (index != 0)
	{
		if (position[szukajOjca(index)] < position[index])
		{
			zapas = position[szukajOjca(index)];
			position[szukajOjca(index)] = position[index];
			position[index] = zapas;
			index = szukajOjca(index);
		}
		else
			break;
	}



}

//metoda searchIndex wyszukujaca indeks podanej liczby

int Kopiec::searchIndex(int liczba, int index)
{
	int searchingIndex = 0;
	if (position[index] == liczba)
	{
		searchingIndex = index;
	}
	if (position[index] < liczba)
	{
	}
	if (szukajSynaL(index) != 0 && searchIndex(liczba, szukajSynaL(index)))
	{
		searchingIndex = searchIndex(liczba, szukajSynaL(index));
	}
	if (szukajSynaP(index) != 0 && searchIndex(liczba, szukajSynaP(index)))
	{
		searchingIndex = searchIndex(liczba, szukajSynaP(index));
	}
	else
	{
	}
	return searchingIndex;
}

//metoda pop usuwajaca podany element i odtwarzaj¹ca wlasciwosci kopca

void Kopiec::pop(int liczba)
{
	if (rozmiar == 0)
		return;
	else
	{
		int index = searchIndex(liczba, 0);
		position[index] = position[rozmiar - 1];
		remove();
		int nodePosition = index;
		int zapas = 0;

		while (szukajSynaL(nodePosition) != 0 && szukajSynaP(nodePosition) != 0)
		{
			if (szukajSynaL(nodePosition) == 0)
			{
				if (position[nodePosition] < position[szukajSynaP(nodePosition)])
				{
					zapas = position[nodePosition];
					position[nodePosition] = position[szukajSynaP(nodePosition)];
					position[szukajSynaP(nodePosition)] = zapas;
				}
				break;
			}
			else if (szukajSynaL(nodePosition) == 0)
			{
				if (position[nodePosition] < position[szukajSynaL(nodePosition)])
				{
					zapas = position[nodePosition];
					position[nodePosition] = position[szukajSynaL(nodePosition)];
					position[szukajSynaL(nodePosition)] = zapas;
				}
				break;
			}
			else if (position[szukajSynaP(nodePosition)] <= position[szukajSynaL(nodePosition)])
			{
				if (position[nodePosition] < position[szukajSynaL(nodePosition)])
				{
					zapas = position[nodePosition];
					position[nodePosition] = position[szukajSynaL(nodePosition)];
					position[szukajSynaL(nodePosition)] = zapas;

					nodePosition = szukajSynaL(nodePosition);
				}
				else
				break;

			}
			else if (position[szukajSynaP(nodePosition)] > position[szukajSynaL(nodePosition)])
			{
				if (position[nodePosition] < position[szukajSynaP(nodePosition)])
				{
					zapas = position[nodePosition];
					position[nodePosition] = position[szukajSynaP(nodePosition)];
					position[szukajSynaP(nodePosition)] = zapas;

					nodePosition = szukajSynaP(nodePosition);
				}
				else
					break;

			}

		}

	}

}

//metoda print drukujaca kopiec zachowujac jego ksztalt

void Kopiec::print()
{
	int *index;
	index = position;
	
	for (int i = 0;i < rozmiar;i++)
	{
		cout << *index << " ";
		index++;
	}

	cout << endl << endl;
	int j = 1, width = 0, level = 0;

	while (j <= rozmiar)
	{
		j = j * 2;
		level++;
	}

	j = 0;

	while (j < level - 1)
	{
		width = width * 2 + 1;
		j++;
	}

	j = 2;
	
	index = position;

	for (int i = 0;i < rozmiar;i++)
	{
		if (i == j - 1)
		{
			cout << endl;
			j = j * 2;
			width--;
			width = width / 2;
		}
		cout << setw(width * 4) << "";
		cout << setw(4) << *index << setw(4)<<"";
		cout << setw(width * 4) << "";
		index++;
	}

}

//metoda readFromFile wczytujaca dane z pliku do kopca

void Kopiec::readFromFile(string file_name)
{
	fstream file;
	file.open(file_name, ios::in);
	int rozmiar = 0;
	int liczba;
	if (file.good() == true)
	{
		cout << "Uzyskano dostep do pliku" << endl;
		file >> rozmiar;

		for (int i = 0; i < rozmiar;i++)
		{
			file >> liczba;
			push(liczba);
		}
	}
	else
		cout << "Brak dostepu do pliku" << endl;
	file.close();
}

//metoda createRandom tworz¹ca tablicê z podanej ilosci losowych elementów
//oraz zwracaj¹ca czas tworzenia

float Kopiec::createRandom(int amount)
{
	timer*clock = new timer;
	clock->StartCounter();
	int rozmiar = 0;
	int liczba;
	
	rozmiar = amount;

		for (int i = 0; i < rozmiar;i++)
		{
			liczba = rand() % 100;
			push(liczba);
		}

	float buildTime = clock->GetCounter();
	clock = NULL;
	delete clock;
	return buildTime;

	
}

//metoda test s³u¿¹ca do obliczania czasów operacji

void Kopiec::test()
{
	int Menu, amount, repeat, place, number, pos;
	float buildTime = 0;
	cout << "Podaj liczbe elementow: ";
	cin >> amount;
	cout << endl << "Podaj liczbe powtorzen: ";
	cin >> repeat;
	cout << endl << "Add: ";
	timer*clock = new timer;
	clock->StartCounter();
	for (int i = 0;i < repeat;i++)
	{
		buildTime = buildTime + createRandom(amount);
		number = rand() % 100;
		add(number);
	}
	cout << (clock->GetCounter() - buildTime) / repeat << endl;
	//clock = 0;

	cout << endl << "Remove: ";
	buildTime = 0;
	clock->StartCounter();
	for (int i = 0;i < repeat;i++)
	{
		buildTime = buildTime + createRandom(amount);
		number = rand() % 100;
		remove();
	}
	cout << (clock->GetCounter() - buildTime) / repeat << endl;

	cout << endl << "Search: ";
	buildTime = 0;
	clock->StartCounter();
	for (int i = 0;i < repeat;i++)
	{
		buildTime = buildTime + createRandom(amount);
		number = rand() % 100;
		searchNumber(number,0);
	}
	cout << (clock->GetCounter() - buildTime) / repeat << endl << endl;

}
