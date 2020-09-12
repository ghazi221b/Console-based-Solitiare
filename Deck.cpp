#include "Deck.h"
#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;


Deck::Deck()
{
	head = NULL;
	tail = NULL;
	size = 52;
}

void Deck::makedeck()
{
	srand(time(NULL));
	int checker = 0;
	while (checker != 52)
	{
		int n, s;
		bool trust = false;
		while (trust == false)
		{

			n = rand() % 13 + 1;
			s = rand() % 4 + 1;
			trust = validitycheck(s, n);
		}
		node* temp = new node;
		temp->face = false;
		temp->suit = s;
		temp->num = n;
		if (s == 4 || s == 2)
		{
			temp->color = 2;
		}
		else
		{
			temp->color = 1;
		}
		temp->next = NULL;
		temp->pre = NULL;
		if (head == NULL)
		{
			head = temp;
			tail = temp;

		}
		else
		{

			tail->next = temp;
			temp->pre = tail;
			tail = temp;
		}

		checker++;

	}
}
void Deck::display()
{

	node *temp = new node;
	temp = head;
	while (temp != NULL)
	{
		if (temp->face == true)
		{
			cout << temp->num << " " << temp->suit << endl;
			temp = temp->next;
		}
		else
		{
			cout << "xx" << endl;
			temp = temp->next;
		}
	}
	delete temp;
}
void Deck::dis()
{
	node*temp = new node;
	temp = tail;
	while (temp != NULL)
	{
		cout << temp->num << " " << temp->suit << endl;
		temp = temp->pre;
	}
}
bool Deck::validitycheck(int s, int n) {
	node*temp = new node;
	temp = head;
	while (temp != NULL)
	{

		if (temp->suit == s && temp->num == n)
		{

			return false;
		}
		temp = temp->next;
	}
	return true;

}
node* Deck::gethead()
{
	return head;
}
node* Deck::gettail()
{
	return tail;
}
void Deck::settail(node *a)
{
	tail = a;
}
int Deck::getsize()
{
	return size;
}
void Deck::makepile(Deck &n, int a)
{
	node *temp = n.gettail();
	tail = temp;
	tail->face = true;

	for (int i = 0; i < a; i++)
	{
		temp = temp->pre;

	}
	head = temp->next;
	head->pre = NULL;
	n.settail(temp);
	temp->next = NULL;
	n.size = n.size - a;


}
void Deck::wastepile(Deck &n)
{
	node *temp = n.gettail();

	if (temp != NULL)
	{

		if (head == NULL)
		{
			if (n.gethead() != n.gettail())
			{
				tail = temp;
				tail->face = true;
				temp = temp->pre;
				head = temp->next;
				head->pre = NULL;
				n.settail(temp);
				temp->next = NULL;
				n.size--;
			}
			else
			{
				if (n.gethead() != NULL && n.gettail() != NULL)
				{
					tail = temp;
					tail->face = true;
					head = temp;
					head->pre = NULL;
					temp->next = NULL;
					n.size--;
					n.head = NULL;
					n.tail = NULL;
				}

			}




		}
		else
		{
			if (n.gethead() != n.gettail())
			{
				tail->face = false;
				temp = temp->pre;
				tail->next = temp->next;
				temp->next = NULL;
				tail->next->pre = tail;
				tail = tail->next;
				n.settail(temp);
				tail->next = NULL;
				tail->face = true;
				n.size--;
			}
			else
			{
				if (n.gethead() != NULL && n.gettail() != NULL)
				{
					tail->face = false;
					tail->next = temp;
					temp->next = NULL;
					tail->next->pre = tail;
					tail = temp;
					tail->face = true;
					n.size--;
					n.head = NULL;
					n.tail = NULL;
				}
			}

		}
	}
	else
	{

		node *ptr = head;
		while (ptr != NULL) {
			node *tmp = ptr->next;
			ptr->next = ptr->pre;
			ptr->pre = tmp;
			if (tmp == NULL) {
				tail = head;
				head = ptr;
			}
			ptr = tmp;
		}
		head->face = false;
		n.head = head;
		n.tail = tail;
		head = NULL;
		tail = NULL;
	}
}
node* Deck::cardsearch(int n, int s)
{
	node*temp = new node;
	temp = head;
	while (temp != NULL)
	{
		if (temp->suit == s && temp->num == n && temp->face == true)
		{
			return temp;
		}
		temp = temp->next;
	}
	return NULL;
}
void Deck::cardreplace(node* card, int p, Deck &n, int s)
{
	if (p >= 1 && p <= 7)
	{
		if (head != NULL && tail != NULL)
		{
			if (tail->color != card->color)
			{
				if ((tail->num - 1) == card->num)
				{
					if (card->pre != NULL)
					{
						node *temp = new node;
						card->pre->next = NULL;
						card->pre->face = true;
						n.settail(card->pre);
						tail->next = card;
						card->pre = tail;
						temp = card;
						while (temp->next != NULL)
						{
							temp = temp->next;
						}
						tail = temp;
						tail->next = NULL;
					}
					else
					{
						n.head = NULL;
						n.tail = NULL;
						tail->next = card;
						card->pre = tail;
						node *temp = card;
						while (temp->next != NULL)
						{
							temp = temp->next;
						}
						tail = temp;
						tail->next = NULL;



					}
				}
			}
		}
		else
		{
			if (card->num == 13)
			{
				if (card->pre != NULL)
				{
					head = card;
					card->pre->next = NULL;
					card->pre->face = true;
					card->pre = NULL;
					node *temp = card;
					while (temp->next != NULL)
					{
						temp = temp->next;
					}
					tail = temp;
					tail->next = NULL;

				}
				else
				{
					n.head = NULL;
					n.tail = NULL;
					head = card;
					node *temp = card;
					while (temp->next != NULL)
					{
						temp = temp->next;
					}
					tail = temp;
					tail->next = NULL;


				}
			}
		}
	}
	else if (p == 8)
	{
		if (s == 1 && card->next == NULL)
		{
			if (head == NULL)
			{
				if (card->num == 1)
				{
					if (card->pre == NULL)
					{
						node *temp = card;
						head = temp;
						tail = temp;
						n.head = NULL;
						n.tail = NULL;

					}
					else
					{
						node *temp = card;
						head = temp;
						tail = temp;
						temp->pre->next = NULL;
						temp->pre->face = true;
						n.settail(card->pre);
						temp->pre = NULL;

					}
				}

			}
			else
			{
				if ((tail->num + 1) == card->num)
				{
					if (card->pre == NULL)
					{
						node* temp = card;
						tail->face = false;
						tail->next = temp;
						temp->pre = tail;
						tail = temp;
						n.head = NULL;
						n.tail = NULL;
					}
					else
					{
						node *temp = card;
						tail->face = false;
						temp->pre->next = NULL;
						temp->pre->face = true;
						n.settail(temp->pre);
						tail->next = temp;
						temp->pre = tail;
						tail = temp;

					}
				}
			}
		}

	}
	else if (p == 9)
	{
		if (s == 2 && card->next == NULL)
		{
			if (head == NULL)
			{
				if (card->num == 1)
				{
					if (card->pre == NULL)
					{
						node *temp = card;
						head = temp;
						tail = temp;
						n.head = NULL;
						n.tail = NULL;

					}
					else
					{
						node *temp = card;
						head = temp;
						tail = temp;
						temp->pre->next = NULL;
						temp->pre->face = true;
						n.settail(card->pre);
						temp->pre = NULL;

					}
				}

			}
			else
			{
				if ((tail->num + 1) == card->num)
				{
					if (card->pre == NULL)
					{
						node* temp = card;
						tail->next = temp;
						tail->face = false;
						temp->pre = tail;
						tail = temp;
						n.head = NULL;
						n.tail = NULL;
					}
					else
					{
						node *temp = card;
						temp->pre->next = NULL;
						temp->pre->face = true;
						tail->face = false;
						n.settail(temp->pre);
						tail->next = temp;
						temp->pre = tail;
						tail = temp;

					}
				}
			}
		}
	}
	else if (p == 10)
	{
		if (s == 3 && card->next == NULL)
		{
			if (head == NULL)
			{
				if (card->num == 1)
				{
					if (card->pre == NULL)
					{
						node *temp = card;
						head = temp;
						tail = temp;
						n.head = NULL;
						n.tail = NULL;

					}
					else
					{
						node *temp = card;
						head = temp;
						tail = temp;
						temp->pre->next = NULL;
						temp->pre->face = true;
						n.settail(card->pre);
						temp->pre = NULL;

					}
				}

			}
			else
			{
				if ((tail->num + 1) == card->num)
				{
					if (card->pre == NULL)
					{
						node* temp = card;
						tail->face = false;
						tail->next = temp;
						temp->pre = tail;
						tail = temp;
						n.head = NULL;
						n.tail = NULL;
					}
					else
					{
						node *temp = card;
						tail->face = false;
						temp->pre->next = NULL;
						temp->pre->face = true;
						n.settail(temp->pre);
						tail->next = temp;
						temp->pre = tail;
						tail = temp;

					}
				}
			}
		}

	}
	else if (p == 11)
	{
		if (s == 4 && card->next == NULL)
		{
			if (head == NULL)
			{
				if (card->num == 1)
				{
					if (card->pre == NULL)
					{
						node *temp = card;
						head = temp;
						tail = temp;
						n.head = NULL;
						n.tail = NULL;

					}
					else
					{
						node *temp = card;
						head = temp;
						tail = temp;
						temp->pre->next = NULL;
						temp->pre->face = true;
						n.settail(card->pre);
						temp->pre = NULL;

					}
				}

			}
			else
			{
				if ((tail->num + 1) == card->num)
				{
					if (card->pre == NULL)
					{
						node* temp = card;
						tail->face = false;
						tail->next = temp;
						temp->pre = tail;
						tail = temp;
						n.head = NULL;
						n.tail = NULL;
					}
					else
					{
						node *temp = card;
						tail->face = false;
						temp->pre->next = NULL;
						temp->pre->face = true;
						n.settail(temp->pre);
						tail->next = temp;
						temp->pre = tail;
						tail = temp;

					}
				}
			}
		}

	}





}
void Deck::maindis(Deck pile[])
{
	int v = 5;
	node * temp0 = pile[0].gethead();
	node * temp1 = pile[1].gethead();
	node * temp2 = pile[2].gethead();
	node * temp3 = pile[3].gethead();
	node * temp4 = pile[4].gethead();
	node * temp5 = pile[5].gethead();
	node * temp6 = pile[6].gethead();
	node * temp7 = pile[7].gethead();
	node * temp8 = pile[8].gethead();
	node * temp9 = pile[9].gethead();
	node * temp10 = pile[10].gethead();
	node * temp11 = pile[11].gethead();
	node * temp12 = pile[12].gethead();
	int che = 0;
	cout << setw(v) << " pile:1";
	cout << setw(v) << " pile:2";
	cout << setw(v) << " pile:3";
	cout << setw(v) << " pile:4";
	cout << setw(v) << " pile:5";
	cout << setw(v) << " pile:6";
	cout << setw(v) << " pile:7";
	cout << setw(v) << " pile:8";
	cout << setw(v) << " pile:9";
	cout << setw(v) << " pile:10";
	cout << setw(v) << " pile:11";
	cout << setw(v) << " pile:12";
	cout << setw(v) << " pile:0";
	cout << endl;
	while (temp1 != NULL || temp2 != NULL || temp3 != NULL || temp4 != NULL || temp5 != NULL || temp6 != NULL || temp7 != NULL || temp8 != NULL || temp9 != NULL || temp10 != NULL || temp11 != NULL || temp12 != NULL || temp0 != NULL)
	{
		if (temp1 != NULL)
		{
			if (temp1->face == true)
			{
				cout << setw(v) << temp1->num << " " << temp1->suit;
				temp1 = temp1->next;
			}
			else
			{
				cout << "   xxxx";
				temp1 = temp1->next;
			}
		}
		else
		{
			cout << "       ";
		}

		if (temp2 != NULL)
		{
			if (temp2->face == true)
			{
				cout << setw(v) << temp2->num << " " << temp2->suit;
				temp2 = temp2->next;
			}
			else
			{
				cout << "   xxxx";
				temp2 = temp2->next;
			}
		}
		else
		{
			//cout << setw(v)<<" ";
			cout << "       ";
		}
		if (temp3 != NULL)
		{
			if (temp3->face == true)
			{
				cout << setw(v) << temp3->num << " " << temp3->suit;
				temp3 = temp3->next;
			}
			else
			{
				cout << "   xxxx";
				temp3 = temp3->next;
			}
		}
		else
		{
			//cout << setw(v)<<" ";
			cout << "       ";
		}
		if (temp4 != NULL)
		{
			if (temp4->face == true)
			{
				cout << setw(v) << temp4->num << " " << temp4->suit;
				temp4 = temp4->next;
			}
			else
			{
				cout << "   xxxx";
				temp4 = temp4->next;
			}
		}
		else
		{
			//cout << setw(v) << " ";
			cout << "       ";
		}
		if (temp5 != NULL)
		{
			if (temp5->face == true)
			{
				cout << setw(v) << temp5->num << " " << temp5->suit;
				temp5 = temp5->next;
			}
			else
			{
				cout << "   xxxx";
				temp5 = temp5->next;
			}
		}
		else
		{
			//cout << setw(v) << " ";
			cout << "       ";
		}
		if (temp6 != NULL)
		{
			if (temp6->face == true)
			{
				cout << setw(v) << temp6->num << " " << temp6->suit;
				temp6 = temp6->next;
			}
			else
			{
				cout << "   xxxx";
				temp6 = temp6->next;
			}
		}
		else
		{
			//cout << setw(v) << " ";
			cout << "       ";
		}
		if (temp7 != NULL)
		{
			if (temp7->face == true)
			{
				cout << setw(v) << temp7->num << " " << temp7->suit;
				temp7 = temp7->next;
			}
			else
			{
				cout << "   xxxx";
				temp7 = temp7->next;
			}
		}
		else
		{
			//cout << setw(v) << " ";
			cout << "       ";
		}
		if (temp8 != NULL)
		{
			if (temp8->face == true)
			{
				cout << setw(v) << temp8->num << " " << temp8->suit;
				temp8 = temp8->next;
			}
			else
			{
				cout << "   xxxx";
				temp8 = temp8->next;
			}
		}
		else
		{
			//cout << setw(v) << " ";
			cout << "       ";
		}
		if (temp9 != NULL)
		{
			if (temp9->face == true)
			{
				cout << setw(v) << temp9->num << " " << temp9->suit;
				temp9 = temp9->next;
			}
			else
			{
				cout << "   xxxx";
				temp9 = temp9->next;
			}
		}
		else
		{
			//cout << setw(v) << " ";
			cout << "       ";
		}
		if (temp10 != NULL)
		{
			if (temp10->face == true)
			{
				cout << setw(v) << temp10->num << " " << temp10->suit;
				temp10 = temp10->next;
			}
			else
			{
				cout << "   xxxx";
				temp10 = temp10->next;
			}
		}
		else
		{
			//cout << setw(v) << " ";
			cout << "       ";
		}
		if (temp11 != NULL)
		{
			if (temp11->face == true)
			{
				cout << setw(v) << temp11->num << " " << temp11->suit;
				temp11 = temp11->next;
			}
			else
			{
				cout << "   xxxx";
				temp11 = temp11->next;
			}
		}
		else
		{
			//cout << setw(v) << " ";
			cout << "       ";
		}
		if (temp12 != NULL)
		{
			if (temp12->face == true)
			{
				cout << setw(v) << temp12->num << " " << temp12->suit;
				temp12 = temp12->next;
			}
			else
			{
				cout << "   xxxx";
				temp12 = temp12->next;
			}
		}
		else
		{
			//cout << setw(v) << " ";
			cout << "       ";
		}
		if (temp0 != NULL)
		{
			if (temp0->face == true)
			{
				cout << setw(v) << temp0->num << " " << temp0->suit;
				temp0 = temp0->next;
			}
			else
			{
				cout << "   xxxx";
				temp0 = temp0->next;
			}
		}
		else
		{
			//cout << setw(v) << " ";
			cout << "       ";
		}
		cout << endl;
	}
	cout << pile[0].getsize() << endl;
}

Deck::~Deck()
{
}
