// Copyright 2022 GHA Test Team

#include "gtest/gtest.h"
#include "Automata.cpp"

TEST(Task1, TestOff_1) {
	string state = "OFF";
	string menu[]{ "Latte", "Hot milk", "Expresso" };
	int price[]{ 50, 60, 70 };

	Automata machine(menu, price, 3);

	EXPECT_EQ(machine.getState(), state);
}

TEST(Task2, TestWAIT_1) {
	string state = "WAIT";
	string menu[]{ "Latte", "Hot milk", "Expresso" };
	int price[]{ 50, 60, 70 };

	Automata machine(menu, price, 3);
	machine.On();

	EXPECT_EQ(machine.getState(), state);
}

TEST(Task2, TestWAIT_2) {
	string state = "WAIT";
	string menu[]{ "Latte", "Hot milk", "Expresso" };
	int price[]{ 50, 60, 70 };

	Automata machine(menu, price, 3);
	machine.On();
	machine.Cook();
	EXPECT_EQ(machine.getState(), state);
}

TEST(Task2, TestWAIT_3) {
	string state = "WAIT";
	string menu[]{ "Latte", "Hot milk", "Expresso" };
	int price[]{ 50, 60, 70 };

	Automata machine(menu, price, 3);
	machine.On();
	machine.Cook();
	EXPECT_EQ(machine.getState(), state);
}

TEST(Task2, TestWAIT_4) {
	string state = "WAIT";
	string menu[]{ "Latte", "Hot milk", "Expresso" };
	int price[]{ 50, 60, 70 };

	Automata machine(menu, price, 3);
	machine.On();
	machine.Check();
	EXPECT_EQ(machine.getState(), state);
}

TEST(Task2, TestWAIT_5) {
	string state = "WAIT";
	string menu[]{ "Latte", "Hot milk", "Expresso" };
	int price[]{ 50, 60, 70 };

	Automata machine(menu, price, 3);
	machine.On();
	machine.Coin(55);
	machine.Ñhoice(2);
	machine.Ñhoice(0);
	machine.Check();
	machine.Cook();
	machine.Finish();

	EXPECT_EQ(machine.getState(), state);
}

TEST(Task3, TestACCEPT_1) {
	string state = "ACCEPT";
	string menu[]{ "Latte", "Hot milk", "Expresso" };
	int price[]{ 50, 60, 70 };

	Automata machine(menu, price, 3);
	machine.On();
	machine.Coin(55);

	EXPECT_EQ(machine.getState(), state);
}

TEST(Task3, TestACCEPT_2) {
	string state = "ACCEPT";
	string menu[]{ "Latte", "Hot milk", "Expresso" };
	int price[]{ 50, 60, 70 };

	Automata machine(menu, price, 3);
	machine.On();
	machine.Coin(55);
	machine.Coin(20);

	EXPECT_EQ(machine.getState(), state);
}

TEST(Task3, TestACCEPT_3) {
	string state = "ACCEPT";
	string menu[]{ "Latte", "Hot milk", "Expresso" };
	int price[]{ 50, 60, 70 };

	Automata machine(menu, price, 3);
	machine.On();
	machine.Coin(55);
	machine.Ñhoice(2);
	machine.Check();

	EXPECT_EQ(machine.getState(), state);
}

TEST(Task4, TestCHECK_1) {
	string state = "CHECK";
	string menu[]{ "Latte", "Hot milk", "Expresso" };
	int price[]{ 50, 60, 70 };

	Automata machine(menu, price, 3);
	machine.On();
	machine.Coin(55);
	machine.Ñhoice(2);

	EXPECT_EQ(machine.getState(), state);
}

TEST(Task4, TestCHECK_2) {
	string state = "CHECK";
	string menu[]{ "Latte", "Hot milk", "Expresso" };
	int price[]{ 50, 60, 70 };

	Automata machine(menu, price, 3);
	machine.On();
	machine.Coin(55);
	machine.Ñhoice(2);
	machine.Ñhoice(0);

	EXPECT_EQ(machine.getState(), state);
}

TEST(Task5, TestCOOK_1) {
	string state = "COOK";
	string menu[]{ "Latte", "Hot milk", "Expresso" };
	int price[]{ 50, 60, 70 };

	Automata machine(menu, price, 3);
	machine.On();
	machine.Coin(55);
	machine.Ñhoice(2);
	machine.Ñhoice(0);
	machine.Check();

	EXPECT_EQ(machine.getState(), state);
}

TEST(Task6, TestCOLLECT_1) {
	string state = "COLLECT";
	string menu[]{ "Latte", "Hot milk", "Expresso" };
	int price[]{ 50, 60, 70 };

	Automata machine(menu, price, 3);
	machine.On();
	machine.Coin(55);
	machine.Ñhoice(2);
	machine.Ñhoice(0);
	machine.Check();
	machine.Cook();

	EXPECT_EQ(machine.getState(), state);
}