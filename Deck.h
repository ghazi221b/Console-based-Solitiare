#pragma once
#include <iostream>

using namespace std;

struct node
{
	int num;
	int suit;
	bool face;
	int color;
	node* pre;
	node* next;
};
class Deck
{
private:
	node *head;
	node *tail;
	int size;
public:
	Deck();
	void makedeck();
	void display();
	void dis();
	bool validitycheck(int s, int n);
	node* gethead();
	node* gettail();
	void settail(node *a);
	int getsize();
	void makepile(Deck &n, int a);
	void wastepile(Deck &n);
	node* cardsearch(int n, int s);
	void cardreplace(node* card, int p, Deck &n, int s);
	void maindis(Deck pile[]);

	~Deck();
};

