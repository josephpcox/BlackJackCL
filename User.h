#ifndef USER_H
#define USER_H
#include "Card.h"
#include <vector>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0


using namespace std;


class User{

private:
	User* next=NULL; // linked list for the split

protected:
	vector<Card> Hand;

	int handValue=0;

	double balance=0;

	double profit=0;

	double bet=0;

	int playerOption=0;

	bool bust=FALSE;



public:

	User(double);

	~User();

// Set Functions

	void setBalance(double);// works

	void setHand(Card);// works

	void setHandValue(int);
	
	void setProfit(double);//works

	void setPlayerOption(int);

	void setBet(double);

	void setBust();


// Get Functions

	double getBalance();// works
	
	vector <Card>& getHand();// works

	double getProfit()const;// works

	int getPlayerOption()const;

	double getBet() const;

	int getHandValue();// Works

	bool getBust();

// Misc. Functions

	void printHand();// works

	void displayPlayer(); // Works



};
#endif
