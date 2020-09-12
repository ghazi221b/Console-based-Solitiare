#include "Game.h"
#include "Deck.h"



Game::Game()
{
	pile[0].makedeck();
	for (int i = 1; i < 8; i++)
	{
		pile[i].makepile(pile[0], i);

	}
}

void Game::draw()
{
	pile[12].wastepile(pile[0]);

}
bool Game::exist(int n, int s, int p)
{
	int x = 0;
	node *cardplace = NULL;
	for (int i = 1; i < 13; i++)
	{

		cardplace = pile[i].cardsearch(n, s);
		if (cardplace != NULL)
		{
			cout << i << "th pile" << endl;
			x = i;
			//return true;
			break;
		}

	}
	if (cardplace != NULL)
	{
		pile[p].cardreplace(cardplace, p, pile[x], s);

		return true;
	}
	else
	{
		return false;
	}


}
bool Game::victoryche()
{
	if (pile[8].gettail() != NULL && pile[9].gettail() != NULL && pile[10].gettail() != NULL && pile[11].gettail() != NULL)
	{
		if (pile[8].gettail()->num == 13 && pile[9].gettail()->num == 13 && pile[10].gettail()->num == 13 && pile[11].gettail()->num == 13)
		{
			return true;
		}
	}
	else
		return false;
}
void Game::displaycall()
{
	cout << "waste pile" << endl;
	pile[12].display();
	for (int i = 0; i < 8; i++)
	{
		cout << "pile: " << i << endl;
		pile[i].display();
	}


}
void Game::maindis()
{
	pile[0].maindis(pile);
}


Game::~Game()
{
}
