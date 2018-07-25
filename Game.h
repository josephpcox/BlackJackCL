#ifndef GAME_H
#define GAME_H
#include <vector>
#include <iostream>
#include "Card.h"
#include "User.h"
#include "Dealer.h"

#define TRUE 1
#define FALSE 0

class Game{

private:

	bool end=FALSE;

public:

	static unsigned int round;

	// constructor 
	Game(vector<User>&,int); // done

	void setAllBets(vector <User>& ,vector <User>::iterator);// done	

	// display function
	void displayGame(vector <User>& , vector <User>::iterator,Dealer); // done

	void displayResult(vector <User>& , vector <User>::iterator,Dealer); // done

	// deals the first card of the game
	void dealRound(Dealer&, vector <Card>&, vector <User>&, vector <User>::iterator);

	void play(Dealer&, vector <Card>&, vector <User>&,vector <User>::iterator);

	static unsigned int getRound();

	void askForAce(int, vector<Card>&, vector<Card>::iterator);

	void  setGameEnd(bool);

	bool getGameEnd()const;

	~Game(); // destructor

};
#endif


