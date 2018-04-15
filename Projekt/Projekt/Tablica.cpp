#include "stdafx.h"
#include "Tablica.h"
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <conio.h>
#include <stdlib.h>
#include "timer.h"



using namespace std;


//KLASA TABLICA OBSLUGUJACA OPERACJE NA TABLICACH


Tablica::Tablica()
{
	tabSize = 0;
	tablica = (int*)calloc(0, sizeof(int));
	srand(time(NULL));
}


Tablica::~Tablica()
{
	delete[]tablica;
}

//metoda readFromFile wczytujaca dane z pliku do tablicy

void Tablica::readFromFile(string file_name)
{
	cout << "Podaj nazwe pliku" << endl;
	cin >> file_name;
	fstream file;
	file.open(file_name, ios::in);
	if (file.good() == true)
	{
		cout << "Uzyskano dostep do pliku" << endl;
		file >> tabSize;
		int * tmp = new int[tabSize];
		delete[] tablica;
		tablica = tmp;
		for (int i = 0; i < tabSize;i++)
		{
			file >> tablica[i];
		}
	}
	else
		cout << "Brak dostepu do pliku" << endl;
	file.close();
}

//metoda deleteObject usuwajaca element z tablicy na podanej pozycji

void Tablica::deleteObject(int deletingElement)
{
	if (deletingElement > tabSize-1)
	{
		deleteEnd();
		return;
	}

	if (deletingElement < 0)
	{
		deleteStart();
		return;
	}
	
	if (tablica == nullptr)
	{
		return;
	}

	tabSize--;
	int *tmp = new int[tabSize];
	memcpy(tmp, tablica, deletingElement * sizeof(int));
	memcpy(tmp + deletingElement, tablica + deletingElement + 1, (tabSize - deletingElement) * sizeof(int));
	delete[] tablica;
	tablica = tmp;

}

//metoda deleteStart usuwajaca element z poczatku tablicy


void Tablica::deleteStart()
{
	if (tablica == nullptr)
	{
		return;
	}

	tabSize--;

	if (tabSize == 0)
	{
		delete[]tablica;
		tablica = nullptr;
		return;
	}

	int*tmp = new int[tabSize];
	memcpy(tmp, tablica + 1, tabSize * sizeof(int));
	delete[] tablica;
	tablica = tmp;
}

//metoda deleteEnd usuwajaca element z konca tablicy


void Tablica::deleteEnd()
{
	if (tablica == nullptr)
	{
		return;
	}

	tabSize--;

	if (tabSize == 0)
	{
		delete[]tablica;
		tablica = nullptr;
		return;
	}

	int*tmp = new int[tabSize];
	memcpy(tmp, tablica, tabSize * sizeof(int));
	delete[] tablica;
	tablica = tmp;
}


//metoda addObjectEnd dodajaca element na koncu tablicy

void Tablica::addObjectEnd(int addingElement)
{
	tabSize++;
	if (tablica == NULL)
	{
		tablica = new int[tabSize];
		tablica[0] = addingElement;
		return;
	}

	int * tmp = new int[tabSize];
	tmp[tabSize - 1] = addingElement;
	memcpy(tmp, tablica, (tabSize - 1) * sizeof(int));
	delete[] tablica;
	tablica = tmp;
}

//metoda addObjectStart dodajaca element na poczatku tablicy

void Tablica::addObjectStart(int addingElement)
{
	tabSize++;
	if (tablica == NULL)
	{
		tablica = new int[tabSize];
		tablica[0] = addingElement;
		return;
	}

	int * tmp = new int[tabSize];
	tmp[0] = addingElement;
	memcpy(tmp + 1, tablica, (tabSize - 1) * sizeof(int));
	delete[] tablica;
	tablica = tmp;
}

//metoda addObjectPos dodajaca element na podanej przez uzytkownika pozycji

void Tablica::addObjectPos(int addingElement, int objPosition)
{

	if (objPosition > tabSize - 1)
	{
		addObjectEnd(addingElement);
		return;
	}

	if (objPosition < 0)
	{
		addObjectStart(addingElement);
		return;
	}

	tabSize++;

	if (tablica == NULL)
	{
		tablica = new int[tabSize];
		tablica[0] = addingElement;
		return;
	}

	int * tmp = new int[tabSize];
	tmp[objPosition] = addingElement;
	memcpy(tmp, tablica, objPosition * sizeof(int));
	memcpy(tmp + objPosition + 1, tablica + objPosition, (tabSize - objPosition - 1) * sizeof(int));
	delete[] tablica;
	tablica = tmp;
}

//metoda printTab drukujaca zawartosc tablicy

void Tablica::printTab()
{
	cout << "Zaladowana tablica to:" << endl;
	for (int i = 0;i < tabSize;i++)
	{
		cout << tablica[i]<< endl;
	}
}

//metoda findElementTab znajadujaca podany element w tablicy

bool Tablica::findElementTab(int liczba)
{
	for (int i = 0;i < tabSize ;i++)
	{
		if (tablica[i] == liczba)
		{
			return true;
			break;
		}
	}
	return false;
}

//metoda createRandom tworz¹ca tablicê z podanej ilosci losowych elementów
//oraz zwracaj¹ca czas tworzenia

float Tablica::createRandom(int amount)
{
	timer*clock = new timer;
	clock->StartCounter();
	tabSize = amount;
	int * tmp = new int[tabSize];
	delete[] tablica;
	tablica = tmp;
	for (int i = 0; i < tabSize;i++)
	{
		tablica[i]=rand() % 100;
	}
	float buildTime = clock->GetCounter();
	clock = NULL;
	delete clock;
	return buildTime;
}

//metoda simulation s³u¿¹ca do szczegó³owych obliczeñ czasowych

void Tablica::simulation()
{
	int Menu, amount, repeat, place, number,pos;
	float buildTime = 0;
	cout << "Podaj liczbe elementow: ";
	cin >> amount;
	cout << endl << "Podaj liczbe powtorzen: ";
	cin >> repeat;
	cout << "1.Dodawanie\n2.Usuwanie\n3.Przeszukiwanie\n4.Cofnij\n";
	cin >> Menu;
	system("cls");
	switch (Menu)
	{
	case 1:
		cout << "Wybierz miejsce dodania elementu:\n1.Poczatek \n2.Koniec\n3.Losowe miejsce\n";
		cin >> place;
		if (place == 1)
		{
			timer*clock = new timer;
			clock->StartCounter();
			for (int i = 0;i < repeat;i++)
			{
				buildTime=buildTime+ createRandom(amount);
				number = rand() % 100;
				addObjectStart(number);
			}
			cout << (clock->GetCounter()-buildTime) / repeat << endl;
			clock = NULL;
			delete clock;
			getchar();getchar();
		}
		if (place == 2)
		{
			timer*clock = new timer;
			clock->StartCounter();
			for (int i = 0;i < repeat;i++)
			{
				buildTime = buildTime + createRandom(amount);
				number = rand() % 100;
				addObjectEnd(number);
			}
			cout << (clock->GetCounter() - buildTime) / repeat << endl;
			clock = NULL;
			delete clock;
			getchar();getchar();
		}
		if (place == 3)
		{
			timer*clock = new timer;
			clock->StartCounter();
			for (int i = 0;i < repeat;i++)
			{
				buildTime = buildTime + createRandom(amount);
				pos = rand() % amount;
				number = rand() % 100;
				addObjectPos(number,amount);
			}
			cout << (clock->GetCounter() - buildTime) / repeat << endl;
			clock = NULL;
			delete clock;
			getchar();getchar();
		}
		break;
	case 2:
		cout << "Wybierz miejsce usuwania elementu: 1.Poczatek \n2.Koniec\n3.Losowe miejsce\n";
		cin >> place;
		if (place == 1)
		{
			timer*clock = new timer;
			clock->StartCounter();
			for (int i = 0;i < repeat;i++)
			{
				buildTime = buildTime + createRandom(amount);
				number = rand() % 100;
				addObjectStart(number);
			}
			cout << (clock->GetCounter() - buildTime) / repeat << endl;
			clock = NULL;
			delete clock;
			getchar();getchar();
		}
		if (place == 2)
		{
			timer*clock = new timer;
			clock->StartCounter();
			for (int i = 0;i < repeat;i++)
			{
				buildTime = buildTime + createRandom(amount);
				number = rand() % 100;
				addObjectEnd(number);
			}
			cout << (clock->GetCounter() - buildTime) / repeat << endl;
			clock = NULL;
			delete clock;
			getchar();getchar();
		}
		if (place == 3)
		{
			timer*clock = new timer;
			clock->StartCounter();
			for (int i = 0;i < repeat;i++)
			{
				buildTime = buildTime + createRandom(amount);
				pos = rand() % amount;
				number = rand() % 100;
				addObjectPos(number, amount);
			}
			cout << (clock->GetCounter() - buildTime) / repeat << endl;
			clock = NULL;
			delete clock;
			getchar();getchar();
		}
		break;
	case 3:
		timer*clock = new timer;
		clock->StartCounter();
		for (int i = 0;i < repeat;i++)
		{
			buildTime = buildTime + createRandom(amount);
			number = rand() % 100;
			findElementTab(number);
		}
		cout << (clock->GetCounter() - buildTime) / repeat << endl;
		clock = NULL;
		delete clock;

		getchar();getchar();
		break;

	//default:
		//break;
	}
}

//metoda test s³u¿¹ca do obliczania czasów operacji

void Tablica::test()
{
	int Menu, amount, repeat, place, number, pos;
	float buildTime = 0;
	cout << "Podaj liczbe elementow: ";
	cin >> amount;
	cout << endl << "Podaj liczbe powtorzen: ";
	cin >> repeat;
	cout <<endl<< "AddStart: ";
	timer*clock = new timer;
	clock->StartCounter();
	for (int i = 0;i < repeat;i++)
	{
		buildTime = buildTime + createRandom(amount);
		number = rand() % 100;
		addObjectStart(number);
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
		addObjectEnd(number);
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
		addObjectPos(number, pos);
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
		pos = rand() % amount;
		number = rand() % 100;
		deleteObject(pos);
	}
	cout << (clock->GetCounter() - buildTime) / repeat << endl;

	cout << endl << "Search: ";
	buildTime = 0;
	clock->StartCounter();
	for (int i = 0;i < repeat;i++)
	{
		buildTime = buildTime + createRandom(amount);
		number = rand() % 100;
		findElementTab(number);
	}
	cout << (clock->GetCounter() - buildTime) / repeat << endl<<endl;

}
