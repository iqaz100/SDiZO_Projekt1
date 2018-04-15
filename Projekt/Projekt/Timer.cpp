#include "stdafx.h"
#include <iostream>

#include "timer.h"

//KLASA TIMER OBLICZAJACA CZAS WYKONYWANYCH OPERACJI

using namespace std;

timer::timer()
{
}

timer::~timer()
{
}

void timer::StartCounter()
{
	LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&li))
		cout << "Blad licznika czasu\n";

	PCFreq = double(li.QuadPart) / 1000.0;

	QueryPerformanceCounter(&li);
	CounterStart = li.QuadPart;
}

double timer::GetCounter()
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	return double(li.QuadPart - CounterStart) / PCFreq;
}