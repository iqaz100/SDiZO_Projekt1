// Projekt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <windows.h> //czas
#include <stdio.h>
#include <fstream>
#include <string>
#include "Lista.h"
#include "Tablica.h"
#include "Kopiec.h"

//#include "profileapi.h"

//KLASA PROJEKT OBSLUGUJACA MENU PROGRAMU

using namespace std;

int main()
{
	int liczba;
	Tablica tablica;
	Lista lista;
	Kopiec kopiec;
	int Menu;
	int pozycja;
	system("cls");
	string name_file;

	while (true)
	{
		system("cls");
		cout << "1.Tablica\n2.Lista\n3.Kopiec\n4.Symulacja\n5.Zakoncz\n";
		cin >> Menu;
		switch (Menu)
		{
		case 1:																							//menu tablicy
			do
			{
				system("cls");
				cout << "1.Zbuduj z pliku\n2.Usun element\n3.Dodaj element\n4.Wyszukaj element\n5.Wyswietl\n6.Cofnij\n7.Zakoncz\n";
				cin >> Menu;
				system("cls");
				switch (Menu)
				{
				case 1:
					tablica.readFromFile(name_file);
					getchar();getchar();
					break;
				case 2:
					cout << "1.Usun na poczatku\n2.Usun na koncu\n3.Usun na podanej pozycji\n";
					cin >> Menu;
					system("cls");
					switch (Menu)
					{
					case 1:
						tablica.deleteStart();
						getchar();
						break;
					case 2:
						tablica.deleteEnd();
						getchar();
						break;
					case 3:
						cout << "Z jakiej pozycji chcesz usunac element" << endl;
						cin >> pozycja;
						tablica.deleteObject(pozycja);
						getchar();
						break;
					default:
						cout << "Wybrana opcja nie istnieje" << endl;
						getchar();getchar();
						break;
					}
					
					break;
				case 3:
					cout << "1.Dodaj na poczatku\n2.Dodaj na koncu\n3.Dodaj na podanej pozycji\n";
					cin >> Menu;
					system("cls");
					switch (Menu)
					{
					case 1:
						cout << "Jaki obiekt chcesz dodac na poczatku tablicy?" << endl;
						cin >> liczba;
						tablica.addObjectStart(liczba);
						getchar();
						break;
					case 2:
						cout << "Jaki obiekt chcesz dodac na koncu tablicy?" << endl;
						cin >> liczba;
						tablica.addObjectEnd(liczba);
						getchar();
						break;
					case 3:
						cout << "Jaki obiekt chcesz dodac?" << endl;
						cin >> liczba;
						cout << "Na jakiej pozycji chcesz dodac ten obiekt" << endl;
						cin >> pozycja;
						tablica.addObjectPos(liczba,pozycja);
						getchar();
						break;
					default:
						cout << "Wybrana opcja nie istnieje" << endl;
						getchar();getchar();
						break;
					}
					break;
				case 4:
					cout << "Podaj szukany element" << endl;
					cin >> liczba;
					if (tablica.findElementTab(liczba))
					{
						cout << "Podany element zostal znaleziony" << endl;
					}
					else
						cout << "Podany element nie zostal znaleziony" << endl;
					getchar();getchar();
					break;
				case 5:
					tablica.printTab();
					getchar();getchar();
					break;
				case 6:
					break;
				case 7:
					exit(0);
					break;
				default:
					cout << "Wybrana opcja nie istnieje" << endl;
					getchar();getchar();
					break;
				}
			} while (Menu != 6);
			break;
		case 2:																									//menu listy
			do
			{
				system("cls");
				cout << "1.Zbuduj z pliku\n2.Usun element\n3.Dodaj element\n4.Wyszukaj element\n5.Wyswietl\n6.Cofnij\n7.Zakoncz\n";
				cin >> Menu;
				system("cls");
				switch (Menu)
				{
				case 1:
					cout << "Podaj nazwe pliku" << endl;
					cin >> name_file;
					lista.readFromFile(name_file);
					getchar();getchar();
					break;
				case 2:
					cout << "1.Usun na poczatku\n2.Usun na koncu\n3.Usun na podanej pozycji\n";
					cin >> Menu;
					system("cls");
					switch (Menu)
					{
					case 1:
						lista.deleteStart();
						getchar();
						break;
					case 2:
						lista.deleteEnd();
						getchar();
						break;
					case 3:
						cout << "Z jakiej pozycji chcesz usunac element" << endl;
						cin >> pozycja;
						lista.deleteAtPosition(pozycja);
						getchar();
						break;
					default:
						cout << "Wybrana opcja nie istnieje" << endl;
						getchar();getchar();
						break;
					}
					break;
				case 3:
					cout << "1.Dodaj na poczatku\n2.Dodaj na koncu\n3.Dodaj na podanej pozycji\n";
					cin >> Menu;
					system("cls");
					switch (Menu)
					{
					case 1:
						cout << "Jaki obiekt chcesz dodac na poczatku tablicy?" << endl;
						cin >> liczba;
						lista.addStart(liczba);
						getchar();
						break;
					case 2:
						cout << "Jaki obiekt chcesz dodac na koncu tablicy?" << endl;
						cin >> liczba;
						lista.addEnd(liczba);
						getchar();
						break;
					case 3:
						cout << "Jaki obiekt chcesz dodac?" << endl;
						cin >> liczba;
						cout << "Na jakiej pozycji chcesz dodac ten obiekt" << endl;
						cin >> pozycja;
						lista.addAtPosition(liczba, pozycja);
						getchar();
						break;
					default:
						cout << "Wybrana opcja nie istnieje" << endl;
						getchar();
						break;
					}
					break;
				case 4:
					cout << "Podaj szukany element" << endl;
					cin >> liczba;
					lista.searchNumber(liczba);
					getchar();
					break;
				case 5:
					lista.print();
					getchar();getchar();
					break;
				case 6:
					break;
				case 7:
					exit(0);
					break;
				default:
					cout << "Wybrana opcja nie istnieje" << endl;
					getchar();
					break;
				}
			} while (Menu != 6);
			break;
		case 3:																													//menu kopca
			do
			{
				system("cls");
				cout << "1.Zbuduj z pliku\n2.Usun element\n3.Dodaj element\n4.Wyszukaj element\n5.Wyswietl\n6.Cofnij\n7.Zakoncz\n";
				cin >> Menu;
				system("cls");
				switch (Menu)
				{
				case 1:
					cout << "Podaj nazwe pliku" << endl;
					cin >> name_file;
					kopiec.readFromFile(name_file);
					getchar();getchar();
					break;
				case 2:
					cout << "Ktory element chcesz usunac?" << endl;
					cin >> liczba;
					kopiec.pop(liczba);
					getchar();getchar();
					break;
				case 3:
					cout << "Jaki element chcesz dodac?" << endl;
					cin >> liczba;
					kopiec.push(liczba);
					break;
				case 4:
					cout << "Podaj szukany element" << endl;
					cin >> liczba;
					if (kopiec.searchNumber(liczba, 0))
					{
						cout << "Podany element zostal znaleziony" << endl;
					}
					else
						cout<<"Podany element nie zostal znaleziony"<<endl;
					getchar();getchar();
					break;
				case 5:
					kopiec.print();
					getchar();getchar();
					break;
				case 6:
					break;
				case 7:
					exit(0);
					break;
				default:
					cout << "Wybrana opcja nie istnieje" << endl;
					getchar();getchar();
					break;
				}
			} while (Menu != 6);
			break;
			break;
		case 4:
			do
			{
				system("cls");
				cout << "1.Tablica\n2.Lista\n3.Kopiec\n4.Cofnij\n";
				cin >> Menu;
				system("cls");
				switch (Menu)
				{
				case 1:
					tablica.test();
					break;
				case 2:
					lista.test();
					break;
				case 3:
					kopiec.test();
					break;
				default:
					break;
				}
			}while (Menu != 4);
				break;
		case 5:
			exit(0);
			break;
		default:
			break;
		}
	}
	system("pause");
}

