#include "Automata.h"
#include <iostream>
#include <string>

using namespace std;
int main() {
	string menu[]{ "Hot Chokolate", "Hot water", "Herasima" };
	int prices[]{ 80, 20, 450 };


	Automata DrinkMachine(menu, prices, 3);
	cout << DrinkMachine.On();
	cout << DrinkMachine.etMenu();
	cout << DrinkMachine.Coin(50);
	cout << DrinkMachine.Ñhoice(1);
	cout << DrinkMachine.Ñhoice(0);
	cout << DrinkMachine.Coin(400);
	cout << DrinkMachine.Ñhoice(2);
	cout << DrinkMachine.Check();
	cout << DrinkMachine.Coin(400);
	cout << DrinkMachine.Ñhoice(2);
	cout << DrinkMachine.Check();
	cout << DrinkMachine.Cook();
	cout << DrinkMachine.Finish();
}