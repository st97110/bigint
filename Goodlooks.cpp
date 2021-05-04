//
//
// 一定要先在main裡Goodlooks::printIndex()再用顏色函式 
//
//
#include "Goodlooks.h"

int Goodlooks::originalColor;
HANDLE Goodlooks::hConsole;

string  calculator[7][48]  =  {
	"■","■","■","  ","  ","■","■","■","  ","  ","■","  ","  ","  ","  ","■","■","■","  ","  ","■","  ","■","  ","  ","■","  ","  ","  ","  ","■","■","■","  ","  ","■","■","■","  ","  ","■","■","■","  ","  ","■","■","■",
	"■","  ","  ","  ","  ","■","  ","■","  ","  ","■","  ","  ","  ","  ","■","  ","  ","  ","  ","■","  ","■","  ","  ","■","  ","  ","  ","  ","■","  ","■","  ","  ","  ","■","  ","  ","  ","■","  ","■","  ","  ","■","  ","■",
	"■","  ","  ","  ","  ","■","  ","■","  ","  ","■","  ","  ","  ","  ","■","  ","  ","  ","  ","■","  ","■","  ","  ","■","  ","  ","  ","  ","■","  ","■","  ","  ","  ","■","  ","  ","  ","■","  ","■","  ","  ","■","  ","■",
	"■","  ","  ","  ","  ","■","■","■","  ","  ","■","  ","  ","  ","  ","■","  ","  ","  ","  ","■","  ","■","  ","  ","■","  ","  ","  ","  ","■","■","■","  ","  ","  ","■","  ","  ","  ","■","  ","■","  ","  ","■","■","■",
	"■","  ","  ","  ","  ","■","  ","■","  ","  ","■","  ","  ","  ","  ","■","  ","  ","  ","  ","■","  ","■","  ","  ","■","  ","  ","  ","  ","■","  ","■","  ","  ","  ","■","  ","  ","  ","■","  ","■","  ","  ","■","■","  ",
	"■","  ","  ","  ","  ","■","  ","■","  ","  ","■","  ","  ","  ","  ","■","  ","  ","  ","  ","■","  ","■","  ","  ","■","  ","  ","  ","  ","■","  ","■","  ","  ","  ","■","  ","  ","  ","■","  ","■","  ","  ","■","  ","■",
	"■","■","■","  ","  ","■","  ","■","  ","  ","■","■","■","  ","  ","■","■","■","  ","  ","■","■","■","  ","  ","■","■","■","  ","  ","■","  ","■","  ","  ","  ","■","  ","  ","  ","■","■","■","  ","  ","■","  ","■",
};

void Goodlooks::printIndex()
{
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO cbInfo;
	GetConsoleScreenBufferInfo(hConsole, &cbInfo);
	originalColor = cbInfo.wAttributes;

	cout << "\n\n";
	for (int i = 0; i < 7; i++)
	{
		cout << "\t";
		for (int j = 0; j < 48; j++)
		{
			SetConsoleTextAttribute(hConsole, 95);
			cout << calculator[i][j];
		}
		SetConsoleTextAttribute(hConsole, originalColor);
		cout << endl;
	}
	cout << "\n\n\t\t\t\t\t\t";
	Goodlooks::LightBlue(" 作者 ");
	cout << "\n\t\t\t\t\t\t";
	Goodlooks::LightBlue("蔡友崴");
	cout << "\n\t\t\t\t\t\t";
	Goodlooks::LightBlue("王程煜");
	cout << "\n\t\t\t\t\t\t";
	Goodlooks::LightBlue("吳茂勛");
	cout << "\n\n\n\t\t\t\t";
	Goodlooks::LightPurple("       Press any key to continue.");
	char useless = _getch();
}

void Goodlooks::Blue(string str)
{
	SetConsoleTextAttribute(hConsole, 1);
	cout << str << endl;
	SetConsoleTextAttribute(hConsole, originalColor);
}

void Goodlooks::Green(string str)
{
	SetConsoleTextAttribute(hConsole, 2);
	cout << str << endl;
	SetConsoleTextAttribute(hConsole, originalColor);
}

void Goodlooks::Aqua(string str)
{
	SetConsoleTextAttribute(hConsole, 3);
	cout << str << endl;
	SetConsoleTextAttribute(hConsole, originalColor);
}

void Goodlooks::Red(string str)
{
	SetConsoleTextAttribute(hConsole, 4);
	cout << str << endl;
	SetConsoleTextAttribute(hConsole, originalColor);
}

void Goodlooks::Purple(string str)
{
	SetConsoleTextAttribute(hConsole, 5);
	cout << str << endl;
	SetConsoleTextAttribute(hConsole, originalColor);
}

void Goodlooks::Yellow(string str)
{
	SetConsoleTextAttribute(hConsole, 6);
	cout << str << endl;
	SetConsoleTextAttribute(hConsole, originalColor);
}

void Goodlooks::White(string str)
{
	SetConsoleTextAttribute(hConsole, 7);
	cout << str << endl;
	SetConsoleTextAttribute(hConsole, originalColor);
}

void Goodlooks::Gray(string str)
{
	SetConsoleTextAttribute(hConsole, 8);
	cout << str << endl;
	SetConsoleTextAttribute(hConsole, originalColor);
}

void Goodlooks::LightBlue(string str)
{
	SetConsoleTextAttribute(hConsole, 9);
	cout << str << endl;
	SetConsoleTextAttribute(hConsole, originalColor);
}

void Goodlooks::LightGreen(string str)
{
	SetConsoleTextAttribute(hConsole, 10);
	cout << str << endl;
	SetConsoleTextAttribute(hConsole, originalColor);
}

void Goodlooks::LightAqua(string str)
{
	SetConsoleTextAttribute(hConsole, 11);
	cout << str << endl;
	SetConsoleTextAttribute(hConsole, originalColor);
}

void Goodlooks::LightRed(string str)
{
	SetConsoleTextAttribute(hConsole, 12);
	cout << str << endl;
	SetConsoleTextAttribute(hConsole, originalColor);
}

void Goodlooks::LightPurple(string str)
{
	SetConsoleTextAttribute(hConsole, 13);
	cout << str << endl;
	SetConsoleTextAttribute(hConsole, originalColor);
}

void Goodlooks::LightYellow(string str)
{
	SetConsoleTextAttribute(hConsole, 14);
	cout << str << endl;
	SetConsoleTextAttribute(hConsole, originalColor);
}

void Goodlooks::BrightWhite(string str)
{
	SetConsoleTextAttribute(hConsole, 15);
	cout << str << endl;
	SetConsoleTextAttribute(hConsole, originalColor);
}
