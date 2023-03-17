// Copyright 2022 UNN-IASR

#include "Automata.h"

Automata::Automata(std::string menu[], int prices[], int size) {
    balance = 0;
    this->menu = menu;
    this->prices = prices;
    selected = -1;
    state = OFF;
    sizeMenu = size;
}

std::string Automata::On() {
    std::string strRes = "Cannot be performed\n";
    if (state == OFF) {
        state = WAIT;
        strRes = "The machine is turned on. Switching to standby mode.\n";
    }
    return strRes;
}

std::string Automata::Off() {
    std::string strRes = "Cannot be performed\n";
    if (state == WAIT) {
        state = OFF;
        strRes = "Shutdown\n";
    }
    return strRes;
}

std::string Automata::Coin(int money) {
    std::string strRes = "Cannot be performed\n";
    if (state == WAIT || state == ACCEPT) {
        state = ACCEPT;
        balance += money;
        strRes = "Received " + std::to_string(money) +
            " money.Balance " + std::to_string(balance) + "\n";
    }
    return strRes;
}

std::string Automata::etMenu() {
    std::string strRes = "\nMenu machine\n";
    for (int i = 0; i < sizeMenu; i++) {
        strRes += menu[i] + ": " + std::to_string(prices[i]) + " rubels\n";
    }
    return strRes + "\n";
}

std::string Automata::getState() {
    std::string strRes = "Cannot be performed\n";
    switch (state) {
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
    case Automata::COLLECT:
        strRes = "COLLECT";
        break;
    default:
        break;
    }
    return strRes;
}

std::string Automata::Choice(int selected) {
    std::string strRes = "Cannot be performed\n";
    if (state == ACCEPT || state == CHECK) {
        state = CHECK;

        this->selected = selected;
        strRes = "Selected drink '" + menu[selected] + "'\n";
    }
    return strRes;
}

std::string Automata::Check() {
    std::string strRes = "Cannot be performed\n";
    if (state == CHECK) {
        if (prices[selected] <= balance) {
            state = COOK;
            strRes = "There is enough money on the balance sheet\n";
        } else {
            state = ACCEPT;
            strRes = "Not enough money on the balance sheet\n";
        }
    }
    return strRes;
}

std::string Automata::Cancel() {
    std::string strRes = "Cannot be performed\n";
    if (state == ACCEPT || state == CHECK || state == COOK) {
        state = WAIT;
        strRes = "Switching to standby mode\n";
    }
    return strRes;
}

std::string Automata::Cook() {
    std::string strRes = "Cannot be performed\n";
    if (state == COOK) {
        strRes = "Cooking cocktail '" + menu[selected] + "'\n";
        state = COLLECT;
    }

    return strRes;
}

std::string Automata::Finish() {
    std::string strRes = "Cannot be performed\n";
    if (state == COLLECT) {
        strRes = "Switching to standby mode\n";
        state = WAIT;
    }

    return strRes;
}


