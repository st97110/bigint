#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
using namespace std;

class Goodlooks
{
public:
	static int originalColor;
	static HANDLE hConsole;
	static void printIndex();
	static void Green(string str);
	static void Blue(string str);
	static void Aqua(string str);
	static void Red(string str);
	static void Purple(string str);
	static void Yellow(string str);
	static void White(string str);
	static void Gray(string str);
	static void LightBlue(string str);
	static void LightGreen(string str);
	static void LightAqua(string str);
	static void LightRed(string str);
	static void LightPurple(string str);
	static void LightYellow(string str);
	static void BrightWhite(string str);
};
