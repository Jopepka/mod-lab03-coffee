// Copyright 2022 UNN-IASR

#pragma once
#include <string>
#include <map>

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
    std::string* menu;
    int* prices;
    STATES state;
    int sizeMenu;

 public:
    Automata(std::string menu[], int prices[], int size);

    std::string On();
    std::string Off();
    std::string Coin(int);
    std::string etMenu();
    std::string getState();
    std::string Choice(int);
    std::string Check();
    std::string Cancel();
    std::string Cook();
    std::string Finish();
};
