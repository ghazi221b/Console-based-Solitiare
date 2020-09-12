#pragma once
#include <iostream>
#include "Deck.h"

using namespace std;


class Game
{
private:
	Deck pile[13];
public:
	Game();
	void draw();
	bool exist(int n, int s, int p);
	bool victoryche();
	void displaycall();
	void maindis();
	~Game();
};

