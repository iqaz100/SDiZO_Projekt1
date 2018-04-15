#pragma once
#include <string>

using namespace std;

class Tablica
{
private:
	int * tablica = new int[NULL];
	int tabSize = 0;
	int addingElement;
	int deletingElement;
	int objPosition;
	int counter = 0;

public:
	
	void readFromFile(string file_name);
	void deleteObject(int deletingElement);
	void deleteStart();
	void deleteEnd();
	void addObjectEnd(int addingElement);
	void addObjectStart(int addingElement);
	void addObjectPos(int addingElement, int objPosition);
	void printTab ();
	bool findElementTab(int liczba);
	float createRandom(int amount);
	void simulation();
	void test();

	Tablica();
	~Tablica();
};

