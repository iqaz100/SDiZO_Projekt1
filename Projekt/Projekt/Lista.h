#pragma once
#include <string>

using namespace std;

class Lista
{
private:
	struct Lista_Dwukierunkowa
	{
		int number;
		Lista_Dwukierunkowa * next = nullptr;
		Lista_Dwukierunkowa * prev = nullptr;
	};

	Lista_Dwukierunkowa * position;

public:
	Lista();
	~Lista();

	void print();

	void addEnd(int number);
	void addStart(int number);
	void addAtPosition(int numList, int number);

	void deleteEnd();
	void deleteStart();
	void deleteAtPosition(int pos);

	void readFromFile(string file_name);
	bool searchNumber(int number);

	float createRandom(int amount);
	void test();


	
};

