#include "Automata.h"

using namespace std;

Automata::Automata(string menu[], int prices[], int size) {
	balance = 0;
	this->menu = menu;
	this->prices = prices;
	selected = -1;
	state = OFF;
	sizeMenu = size;
}

string Automata::On() {
	string strRes = "Cannot be performed\n";
	if (state == OFF) {
		state = WAIT;
		strRes = "The machine is turned on. Switching to standby mode.\n";
	}
	return strRes;
}

string Automata::Off() {
	string strRes = "Cannot be performed\n";
	if (state == WAIT) {
		state = OFF;
		strRes = "Shutdown\n";
	}
	return strRes;
}

string Automata::Coin(int money) {
	string strRes = "Cannot be performed\n";
	if (state == WAIT || state == ACCEPT) {
		state = ACCEPT;
		balance += money;
		strRes = "Received " + to_string(money) + " money.Balance " + to_string(balance) + "\n";
	}
	return strRes;
}

string Automata::etMenu() {
	string strRes = "\nMenu machine\n";
	for (int i = 0; i < sizeMenu; i++) {
		strRes += menu[i] + ": " + to_string(prices[i]) + " rubels\n";
	}
	return strRes + "\n";
}

string Automata::getState() {
	string strRes = "Cannot be performed\n";
	switch (state)
	{
	case Automata::OFF:
		strRes = "OFF";
		break;
	case Automata::WAIT:
		strRes = "WAIT";
		break;
	case Automata::ACCEPT:
		strRes = "ACCEPT";
		break;
	case Automata::CHECK:
		strRes = "CHECK";
		break;
	case Automata::COOK:
		strRes = "COOK";
		break;
	default:
		break;
	};
	return strRes;
}

string Automata::Ñhoice(int selected) {
	string strRes = "Cannot be performed\n";
	if (state == ACCEPT || state == CHECK) {
		state = CHECK;

		this->selected = selected;
		strRes = "Selected drink '" + menu[selected] + "'\n";
	}
	return strRes;
}

string Automata::Check() {
	string strRes = "Cannot be performed\n";
	if (state == CHECK) {
		if (prices[selected] <= balance) {
			state = COOK;
			strRes = "There is enough money on the balance sheet\n";
		}
		else {
			state = ACCEPT;
			strRes = "Not enough money on the balance sheet\n";
		}
	}
	return strRes;
}

string Automata::Cancel() {
	string strRes = "Cannot be performed\n";
	if (state == ACCEPT || state == CHECK || state == COOK) {
		state = WAIT;
		strRes = "Switching to standby mode\n";
	}
	return strRes;
}

string Automata::Cook() {
	string strRes = "Cannot be performed\n";
	if (state == COOK) {
		strRes = "Cooking cocktail '" + menu[selected] + "'\n";
		state = COLLECT;
	}

	return strRes;
}

string Automata::Finish() {
	string strRes = "Cannot be performed\n";
	if (state == COLLECT) {
		strRes = "Switching to standby mode\n";
		state = WAIT;
	}

	return strRes;
}


