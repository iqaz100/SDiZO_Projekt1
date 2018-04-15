#include "stdafx.h"
#include "Lista.h"
#include <iostream>
#include <string>
#include <fstream>
#include "timer.h"

//KLASA LISTA OBSLUGUJACA OPERACJE NA LISTACH

using namespace std;

Lista::Lista()
{
}


Lista::~Lista()
{
}

//metoda print drukujaca zawartosc listy

void Lista::print()
{
	if (position != nullptr)
	{
		Lista_Dwukierunkowa *index;
		index = position;
		while (index->next != nullptr)
		{
			cout << index->number << " ";
			index = index->next;
		}

		cout << index->number << " " << endl;

		while (index->prev != nullptr)
		{
			cout << index->number << " ";
			index = index->prev;
		}

		cout << index->number << " " << endl;
	}
}

//metoda addEnd dodajac element na koncu listy

void Lista::addEnd(int number)
{
	Lista_Dwukierunkowa*index,*newNumber;
	if (position == nullptr)
	{
		position = new Lista_Dwukierunkowa;
		position->number = number;
	}
	else
	{
		index = position;
		while (index->next != nullptr)
		{
			index = index->next;
		}
		newNumber = new Lista_Dwukierunkowa;
		newNumber->number = number;
		newNumber->prev = index;
		index->next = newNumber;
	}

}

//metoda addStart dodajaca element na poczatku listy

void Lista::addStart(int number)
{
	if (position != nullptr)									//*
	{
		Lista_Dwukierunkowa *index;
		position->prev = new Lista_Dwukierunkowa;
		index = position;
		position = index->prev;
		position->number = number;
		position->next = index;
	}
	else
	{
		position = new Lista_Dwukierunkowa;
		position->number = number;
	}
}

//metoda addAtPosition dodajace element do listy+ na pozycji podanej przez uzytkownika

void Lista::addAtPosition(int numList, int numberEnt)
{
	if (numList)												//dorobiæ funckje sprawdzajaca
	{
		Lista_Dwukierunkowa*index, *newNumber;
		index = position;
		while (index->next != nullptr)
		{
			if (index->number == numList)
			{
				break;
			}
			index = index->next;
		}
		if (index->next == nullptr)
		{
			addEnd(numberEnt);
		}
		else
		{
			newNumber = new Lista_Dwukierunkowa;
			newNumber->number = numberEnt;
			newNumber->next = index->next;
			newNumber->prev = index;

			index->next->prev = newNumber;
			index->next = newNumber;
		}
	}
	else
	{
		addEnd(numberEnt);
	}
}

//metoda deleteEnd usuwajaca element z konca listy

void Lista::deleteEnd()
{
	Lista_Dwukierunkowa*index;
	if (position != nullptr)
	{
		index = position;
		while (index->next != nullptr)
		{
			index = index->next;
		}

		if (index->prev != nullptr)
		{
			index = index->prev;
			free(index->next);					 //zwalnanie pamiêci
			index->next = nullptr;
		}
		else
		{
			free(position);						//zwalnanie pamieci
			position = nullptr;
		}
	}
}

//metoda deleteStart usuwajaca element z poczatku listy

void Lista::deleteStart()
{
	if (position != nullptr)
	{
		position = position->next;
		free(position->prev);
		position->prev = nullptr;
	}
	else
	{
		return;
	}
}

//metoda deleteAtPosition usuwajace element z pozycji podanej przez uzytkownika

void Lista::deleteAtPosition(int pos)
{
	if (searchNumber(pos) == true && position != nullptr)
	{
		//dodac warunek
		Lista_Dwukierunkowa*index;
		index = position;
		while (index->next != nullptr)
		{
			if (index->number == pos)
			{
				break;
			}
			index = index->next;
		}
		index->prev->next = index->next;
		index->next->prev = index->prev;
		free(index);									//zwalnanie pamiêci
	}
	else
		cout << "Podany element nie istnieje" << endl;
}

//metoda readFromFile wczytujaca dane z pliku do listy

void Lista::readFromFile(string file_name)
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
			addEnd(liczba);
		}
	}
	else
		cout << "Brak dostepu do pliku" << endl;
	file.close();
}

//metoda searchNumber sprawdzajaca czy podany element znajduje sie na liscie

bool Lista::searchNumber(int number)
{
	if (position != nullptr)
	{
		Lista_Dwukierunkowa*index;
		index = position;
		while (index->next != nullptr)
		{
			if (index->number == number)
			{
				return true;
			}
			index = index->next;
		}
		//if (index->number == number)
		//return true;
	}
	return false;
}

//metoda createRandom tworz¹ca tablicê z podanej ilosci losowych elementów
//oraz zwracaj¹ca czas tworzenia

float Lista::createRandom(int amount)
{
	timer*clock = new timer;
	clock->StartCounter();
	int liczba;
	int rozmiar;
	rozmiar = amount;

		for (int i = 0; i < rozmiar;i++)
		{
			liczba= rand() % 100;
			addEnd(liczba);
		}
	float buildTime = clock->GetCounter();
	clock = NULL;
	delete clock;
	return buildTime;
}

//metoda test s³u¿¹ca do obliczania czasów operacji

void Lista::test()
{
	int Menu, amount, repeat, place, number, pos;
	float buildTime = 0;
	cout << "Podaj liczbe elementow: ";
	cin >> amount;
	cout << endl << "Podaj liczbe powtorzen: ";
	cin >> repeat;
	cout << endl << "AddStart: ";
	timer*clock = new timer;
	clock->StartCounter();
	for (int i = 0;i < repeat;i++)
	{
		buildTime = buildTime + createRandom(amount);
		number = rand() % 100;
		addStart(number);
	}
	cout << (clock->GetCounter() - buildTime) / repeat << endl;
	//clock = 0;

	cout << endl << "AddEnd: ";
	buildTime = 0;
	clock->StartCounter();
	for (int i = 0;i < repeat;i++)
	{
		buildTime = buildTime + createRandom(amount);
		number = rand() % 100;
		addEnd(number);
	}
	cout << (clock->GetCounter() - buildTime) / repeat << endl;

	cout << endl << "AddPos: ";
	buildTime = 0;
	clock->StartCounter();
	for (int i = 0;i < repeat;i++)
	{
		buildTime = buildTime + createRandom(amount);
		pos = rand() % amount;
		number = rand() % 100;
		addAtPosition(number, amount);
	}
	cout << (clock->GetCounter() - buildTime) / repeat << endl;

	cout << endl << "DelStart: ";
	buildTime = 0;
	clock->StartCounter();
	for (int i = 0;i < repeat;i++)
	{
		buildTime = buildTime + createRandom(amount);
		number = rand() % 100;
		deleteStart();
	}
	cout << (clock->GetCounter() - buildTime) / repeat << endl;

	cout << endl << "DelEnd: ";
	buildTime = 0;
	clock->StartCounter();
	for (int i = 0;i < repeat;i++)
	{
		buildTime = buildTime + createRandom(amount);
		number = rand() % 100;
		deleteEnd();
	}
	cout << (clock->GetCounter() - buildTime) / repeat << endl;

	cout << endl << "DelPos: ";
	buildTime = 0;
	clock->StartCounter();
	for (int i = 0;i < repeat;i++)
	{
		buildTime = buildTime + createRandom(amount);
		pos = rand() % amount-1;
		number = rand() % 100;
		deleteAtPosition(pos);
	}
	cout << (clock->GetCounter() - buildTime) / repeat << endl;

	cout << endl << "Search: ";
	buildTime = 0;
	clock->StartCounter();
	for (int i = 0;i < repeat;i++)
	{
		buildTime = buildTime + createRandom(amount);
		number = rand() % 100;
		searchNumber(number);
	}
	cout << (clock->GetCounter() - buildTime) / repeat << endl << endl;

}