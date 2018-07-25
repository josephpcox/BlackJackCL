#ifndef DEALER_H
#define DEALER_H
#include "Card.h"
#include "User.h"
#include <vector>
#include <stdlib.h>

// The Dealer is a special user that will inherit from the user class
class Dealer: public User{

public:
	// Functions that only the Dealer can use 
	Dealer(double);

	void shuffle(vector<Card>&); //works

	void makeDeck(vector <Card>&); // works

	void dealCard(vector <Card>&, vector <Card>&); //works

	void clearHands(vector<User>&,vector<User>::iterator);//works

	void reFreshDeck(vector <Card>&);//works

	void displayDealer();//works

	~Dealer();//works

};
#endif