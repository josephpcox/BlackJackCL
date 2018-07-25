#include "Card.h"
#include "User.h"
#include <vector>
#include <stdlib.h>
#include <iostream>
#define TRUE 1
#define FALSE 0

using namespace std;



User::User(double newBalance):balance(newBalance){} // explicit constructor

// Set Functions
void User::setBalance(double newBalance){

	this->balance = newBalance;
}

void User::setHand(Card nextCard){

	this->Hand.push_back(nextCard);
}

void User::setHandValue(int value){

	this->handValue= value;
}

void User::setProfit(double newProfit){

	this->profit=newProfit;

}

void User::setPlayerOption(int newPlayerOption){

	this->playerOption =newPlayerOption;
}

void User::setBet(double newBet){

	this->bet=newBet;

	this->balance=this->balance-bet;
}

void User::setBust(){

		this->bust=FALSE;

		if(this->handValue >21){

			this->bust=TRUE;
		}
}

// Get Functions
double User::getBalance(){
	

	return this-> balance;

}

vector <Card>& User::getHand(){

	return (this->Hand);
}

double User::getProfit()const{

	return this->profit;
}

int User::getPlayerOption()const{

	return this->playerOption;
}

double User::getBet() const{
	return this->bet;
}

int User::getHandValue(){

	int sum=0;

	int k = (this->Hand.size());

	for (int i =0;i<k;i++){
		sum+=(this->Hand[i].getValue());
	}

	return sum;
}

bool User::getBust(){

	return this->bust;
}

// Misc. Functions
void User::printHand(){

	int k = this->Hand.size();

	for(int i = 0;i<k;i++){

		cout<<i+1<<")"<<this->Hand[i].getName()<<"     ";
	}
	cout<<endl;
}

void User::displayPlayer()
{	
 	cout << "Current Hand: ";
 	this->printHand();
 	cout << "\n\n";
 	cout << "Hand Value: " << this->getHandValue() << " "
 		<< "Current Balance: $" << this->getBalance() << " "
 		<<"Profit: "<<this->profit<<" "
 		<< "Bet: $" <<this->bet<< "\n"
 		<<"------------------------------------------------------"<<endl;
 	// set the hand value after every call to print 	
 	this->setHandValue(this->getHandValue());
}

User::~User(){}

