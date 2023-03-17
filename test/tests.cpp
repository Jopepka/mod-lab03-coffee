// Copyright 2022 GHA Test Team

#include "gtest/gtest.h"
#include "Automata.h"

TEST(Task1, TestOff_1) {
    std::string state = "OFF";
    std::string menu[]{ "Latte", "Hot milk", "Expresso" };
    int price[]{ 50, 60, 70 };

    Automata machine(menu, price, 3);

    EXPECT_EQ(machine.getState(), state);
}

TEST(Task2, TestWAIT_1) {
    std::string state = "WAIT";
    std::string menu[]{ "Latte", "Hot milk", "Expresso" };
    int price[]{ 50, 60, 70 };

    Automata machine(menu, price, 3);
    machine.On();

    EXPECT_EQ(machine.getState(), state);
}

TEST(Task2, TestWAIT_2) {
    std::string state = "WAIT";
    std::string menu[]{ "Latte", "Hot milk", "Expresso" };
    int price[]{ 50, 60, 70 };

    Automata machine(menu, price, 3);
    machine.On();
    machine.Cook();
    EXPECT_EQ(machine.getState(), state);
}

TEST(Task2, TestWAIT_3) {
    std::string state = "WAIT";
    std::string menu[]{ "Latte", "Hot milk", "Expresso" };
    int price[]{ 50, 60, 70 };

    Automata machine(menu, price, 3);
    machine.On();
    machine.Cook();
    EXPECT_EQ(machine.getState(), state);
}

TEST(Task2, TestWAIT_4) {
    std::string state = "WAIT";
    std::string menu[]{ "Latte", "Hot milk", "Expresso" };
    int price[]{ 50, 60, 70 };

    Automata machine(menu, price, 3);
    machine.On();
    machine.Check();
    EXPECT_EQ(machine.getState(), state);
}

TEST(Task2, TestWAIT_5) {
    std::string state = "WAIT";
    std::string menu[]{ "Latte", "Hot milk", "Expresso" };
    int price[]{ 50, 60, 70 };

    Automata machine(menu, price, 3);
    machine.On();
    machine.Coin(55);
    machine.Choice(2);
    machine.Choice(0);
    machine.Check();
    machine.Cook();
    machine.Finish();

    EXPECT_EQ(machine.getState(), state);
}

TEST(Task3, TestACCEPT_1) {
    std::string state = "ACCEPT";
    std::string menu[]{ "Latte", "Hot milk", "Expresso" };
    int price[]{ 50, 60, 70 };

    Automata machine(menu, price, 3);
    machine.On();
    machine.Coin(55);

    EXPECT_EQ(machine.getState(), state);
}

TEST(Task3, TestACCEPT_2) {
    std::string state = "ACCEPT";
    std::string menu[]{ "Latte", "Hot milk", "Expresso" };
    int price[]{ 50, 60, 70 };

    Automata machine(menu, price, 3);
    machine.On();
    machine.Coin(55);
    machine.Coin(20);

    EXPECT_EQ(machine.getState(), state);
}

TEST(Task3, TestACCEPT_3) {
    std::string state = "ACCEPT";
    std::string menu[]{ "Latte", "Hot milk", "Expresso" };
    int price[]{ 50, 60, 70 };

    Automata machine(menu, price, 3);
    machine.On();
    machine.Coin(55);
    machine.Choice(2);
    machine.Check();

    EXPECT_EQ(machine.getState(), state);
}

TEST(Task4, TestCHECK_1) {
    std::string state = "CHECK";
    std::string menu[]{ "Latte", "Hot milk", "Expresso" };
    int price[]{ 50, 60, 70 };

    Automata machine(menu, price, 3);
    machine.On();
    machine.Coin(55);
    machine.Choice(2);

    EXPECT_EQ(machine.getState(), state);
}

TEST(Task4, TestCHECK_2) {
    std::string state = "CHECK";
    std::string menu[]{ "Latte", "Hot milk", "Expresso" };
    int price[]{ 50, 60, 70 };

    Automata machine(menu, price, 3);
    machine.On();
    machine.Coin(55);
    machine.Choice(2);
    machine.Choice(0);

    EXPECT_EQ(machine.getState(), state);
}

TEST(Task5, TestCOOK_1) {
    std::string state = "COOK";
    std::string menu[]{ "Latte", "Hot milk", "Expresso" };
    int price[]{ 50, 60, 70 };

    Automata machine(menu, price, 3);
    machine.On();
    machine.Coin(55);
    machine.Choice(2);
    machine.Choice(0);
    machine.Check();

    EXPECT_EQ(machine.getState(), state);
}

TEST(Task6, TestCOLLECT_1) {
    std::string state = "COLLECT";
    std::string menu[]{ "Latte", "Hot milk", "Expresso" };
    int price[]{ 50, 60, 70 };

    Automata machine(menu, price, 3);
    machine.On();
    machine.Coin(55);
    machine.Choice(2);
    machine.Choice(0);
    machine.Check();
    machine.Cook();

    EXPECT_EQ(machine.getState(), state);
}
