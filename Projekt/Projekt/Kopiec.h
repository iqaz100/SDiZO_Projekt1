#pragma once
#include <string>

using namespace std;
class Kopiec
{
private:

	int *position;
	int rozmiar;

public:
	Kopiec();
	~Kopiec();

	void add(int liczba);
	void remove();
	bool searchNumber(int liczba, int index);
	
	int szukajSynaP(int fatherIndex);
	int szukajSynaL(int fatherIndex);
	int szukajOjca(int sonIndex);

	void push(int liczba);
	int searchIndex(int liczba, int index);
	void pop(int liczba);
	void print();
	void readFromFile(string file_name);

	float createRandom(int amount);
	void test();


};

