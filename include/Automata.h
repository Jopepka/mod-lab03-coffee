#pragma once
#include <string>
#include <map>

using namespace std;

class Automata {
private:
	enum STATES {
		OFF,
		WAIT,
		ACCEPT,
		CHECK,
		COOK,
		COLLECT
	};

	int selected;

	int balance;
	string* menu;
	int* prices;
	STATES state;
	int sizeMenu;

public:
	Automata(string menu[], int prices[], int size);

	string On();
	string Off();
	string Coin(int);
	string etMenu();
	string getState();
	string Ñhoice(int);
	string Check();
	string Cancel();
	string Cook();
	string Finish();
};