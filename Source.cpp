#include <iostream>
#include <ctime>
#include <iomanip>
#include "Deck.h"
#include "Game.h"

using namespace std;

int main()
{
	Game a;
	//a.maindis();
	int option = 100;
	while (option != 3)
	{
		system("cls");
		a.maindis();
		cout << endl;
		cout << "1 is Spades -> pile 8" << endl 
			<< "2 is Diamonds -> pile 9" << endl
			<< "3 is Clubs -> pile 10" << endl
			<< "4 is Hearts -> pile 11" << endl;

		cout << "1. Draw a card" << endl;
		cout << "2. Move a card" << endl;
		cout << "3. Quit" << endl;
		cin >> option;
		if (option == 1)
		{
			system("cls");
			a.draw();
			//a.displaycall();
			a.maindis();
		}
		else if (option == 2)
		{
			cout << "Enter card number followed by Suit and then the pile number you want to move it to." << endl;
			char n1;
			int n, s, p;
			cin >> n;
			cin >> s;
			cin >> p;
			

			bool che = a.exist(n, s, p);
			if (che == true)
			{
				cout << "exists" << endl;

			}
			else
			{
				cout << "nope" << endl;
			}

			system("cls");
			//a.displaycall();
			a.maindis();
			bool vic = a.victoryche();
			if (vic == true)
			{
				cout << "***** YOU WIN *****" << endl;
				option = 3;
			}


		}

	}
	//std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
