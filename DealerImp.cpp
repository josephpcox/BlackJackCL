#include "Card.h"
#include "Dealer.h"
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#define true 1
#define false 0

using namespace std;


//***************************** Dealer Implimentation **********************************************************
Dealer::Dealer(double newBalance):User(newBalance){} // explicit constructor


void Dealer::dealCard(vector <Card>& Deck,vector<Card>& Hand){
	Card temp;

	cout<<"Dealt card. Deck Size in now "<<Deck.size()<<endl;

	int i = Deck.size();

	temp.setName(Deck[i-1].getName());

	temp.setValue(Deck[i-1].getValue());

	Hand.push_back(temp);
  
	Deck.pop_back();

}
Dealer::~Dealer(){

	cout<<" "<<endl;
}

void Dealer::shuffle(vector<Card>& Deck){

	Card temp;

	srand (time(NULL));// for random number seeding 

	temp.setValue(0);

	temp.setName("Empty");

	int indexOne = 0;

	int indexTwo = 0;

	for(int i=0; i<1000;i++){
		
		indexOne = (rand() % 52)+1;// random number 1-52

		indexTwo = (rand() % 52)+1;// random number 1-52

		temp = Deck[indexOne];

		Deck[indexOne]=Deck[indexTwo];

		Deck[indexTwo] = temp;
	}

}

void Dealer::clearHands(vector<User>& players, vector<User>::iterator it ){

	int i=0;
	it = players.begin();

	while(it!=players.end()){

		players[i].getHand().clear();
		i++;
		it++;

	}

	(this->Hand).clear();
	cout<<"Hands have been cleared"<<endl;


}

void Dealer::reFreshDeck(vector <Card>& Deck){
	cout<<"Dealer has collected all cards deck is being reshuffled"<<endl;
	Deck.clear();
	this->makeDeck(Deck);
	this->shuffle(Deck);
}

void Dealer::displayDealer(){
	cout << "Current Hand: 1)"<<this->Hand[0].getName()<<"      2)Face Down Card"<<endl;
 	cout << "\n\n";
 	cout << "Hand Value with 1 card: " << this->Hand[0].getValue() << " " << "\n"
 		<<"------------------------------------------------------"<<endl;
 	// set the hand value after every call to print 	
 	this->setHandValue(this->getHandValue());

}

void Dealer::makeDeck(vector <Card>& Deck){ // initilizes the deck to start the game
	Card temp;
// All 4 of the Kings ******************************************************	
	temp.setName("King of Diamonds"); // Dimonds 
	temp.setValue(10);
	Deck.push_back(temp);//1
	temp.setName("King of Hearts"); // Hearts 
	temp.setValue(10);
	Deck.push_back(temp);//2  
	temp.setName("King of Spades"); // Spades 
	temp.setValue(10);
	Deck.push_back(temp);//3
	temp.setName("King of Clubs"); // Clubs 
	temp.setValue(10);
	Deck.push_back(temp);//4

	// All 4 Queens**********************************************************
	temp.setName("Queen of Diamonds"); // Dimonds 
	temp.setValue(10);
	Deck.push_back(temp);//1
	temp.setName("Queen of Hearts"); // Hearts 
	temp.setValue(10);
	Deck.push_back(temp);//2
	temp.setName("Queen of Spades"); // Spades 
	temp.setValue(10);
	Deck.push_back(temp);//3
	temp.setName("Queen of Clubs"); // Clubs 
	temp.setValue(10);
	Deck.push_back(temp);//4

	// All 4 Jacks***********************************************************
	temp.setName("Jack of Diamonds"); // Dimonds 
	temp.setValue(10);
	Deck.push_back(temp);//1
	temp.setName("Jack of Hearts"); // Hearts 
	temp.setValue(10);
	Deck.push_back(temp);//2
	temp.setName("Jack of Spades"); // Spades 
	temp.setValue(10);
	Deck.push_back(temp);//3
	temp.setName("Jack of Clubs"); // Clubs 
	temp.setValue(10);
	Deck.push_back(temp);//4
	
// All 4 Tens*****************************************************************
	temp.setName("Ten of Diamonds"); // Dimonds 
	temp.setValue(10);
	Deck.push_back(temp);//1
	temp.setName("Ten of Hearts"); // Hearts 
	temp.setValue(10);
	Deck.push_back(temp);//2
	temp.setName("Ten of Spades"); // Spades 
	temp.setValue(10);
	Deck.push_back(temp);//3
	temp.setName("Ten of Clubs"); // Clubs 
	temp.setValue(10);
	Deck.push_back(temp);//4

// All 4 nines ***************************************************************
	temp.setName("Nine of Diamonds"); // Dimonds 
	temp.setValue(9);
	Deck.push_back(temp);//1
	temp.setName("Nine of Hearts"); // Hearts 
	temp.setValue(9);
	Deck.push_back(temp);//2
	temp.setName("Nine of Spades"); // Spades 
	temp.setValue(9);
	Deck.push_back(temp);//3
	temp.setName("Nine of Clubs"); // Clubs 
	temp.setValue(9);
	Deck.push_back(temp);//4
// All 4 Eights**************************************************************
	temp.setName("Eight of Diamonds"); // Dimonds 
	temp.setValue(8);
	Deck.push_back(temp);//1
	temp.setName("Eight of Hearts"); // Hearts 
	temp.setValue(8);
	Deck.push_back(temp);//2
	temp.setName("Eight of Spades"); // Spades 
	temp.setValue(8);
	Deck.push_back(temp);//3
	temp.setName("Eight of Clubs"); // Clubs 
	temp.setValue(8);
	Deck.push_back(temp);//4

// All 4 Sevens***************************************************************
	temp.setName("Seven of Diamonds"); // Dimonds 
	temp.setValue(7);
	Deck.push_back(temp);//1
	temp.setName("Seven of Hearts"); // Hearts 
	temp.setValue(7);
	Deck.push_back(temp);//2
	temp.setName("Seven of Spades"); // Spades 
	temp.setValue(7);
	Deck.push_back(temp);//3
	temp.setName("Seven of Clubs"); // Clubs 
	temp.setValue(7);
	Deck.push_back(temp);//4

// All 4 six******************************************************************
	temp.setName("Six of Diamonds"); // Dimonds 
	temp.setValue(6);
	Deck.push_back(temp);//1
	temp.setName("Six of Hearts"); // Hearts 
	temp.setValue(6);
	Deck.push_back(temp);//2
	temp.setName("Six of Spades"); // Spades 
	temp.setValue(6);
	Deck.push_back(temp);//3
	temp.setName("Six of Clubs"); // Clubs 
	temp.setValue(6);
	Deck.push_back(temp);//4

// All 4 Fives**************************************************************** 
	temp.setName("Five of Diamonds"); // Dimonds 
	temp.setValue(5);
	Deck.push_back(temp);//1
	temp.setName("Five of Hearts"); // Hearts 
	temp.setValue(5);
	Deck.push_back(temp);//2
	temp.setName("Five of Spades"); // Spades 
	temp.setValue(5);
	Deck.push_back(temp);//3
	temp.setName("Five of Clubs"); // Clubs 
	temp.setValue(5);
	Deck.push_back(temp);//4

// All 4 Fours*****************************************************************
	temp.setName("Four of Diamonds"); // Dimonds 
	temp.setValue(4);
	Deck.push_back(temp);//1
	temp.setName("Four of Hearts"); // Hearts 
	temp.setValue(4);
	Deck.push_back(temp);//2
	temp.setName("Four of Spades"); // Spades 
	temp.setValue(4);
	Deck.push_back(temp);//3
	temp.setName("Four of Clubs"); // Clubs 
	temp.setValue(4);
	Deck.push_back(temp);//4

	// All 4 Three************************************************************
	temp.setName("Three of Diamonds"); // Dimonds 
	temp.setValue(3);
	Deck.push_back(temp);//1
	temp.setName("Three of Hearts"); // Hearts 
	temp.setValue(3);
	Deck.push_back(temp);//2
	temp.setName("Three of Spades"); // Spades 
	temp.setValue(3);
	Deck.push_back(temp);//3
	temp.setName("Three of Clubs"); // Clubs 
	temp.setValue(3);
	Deck.push_back(temp);//4
	
	// All 4 Twos*************************************************************
	temp.setName("Two of Diamonds"); // Dimonds 
	temp.setValue(2);
	Deck.push_back(temp);//1
	temp.setName("Two of Hearts"); // Hearts 
	temp.setValue(2);
	Deck.push_back(temp);//2
	temp.setName("Two of Spades"); // Spades 
	temp.setValue(2);
	Deck.push_back(temp);//3
	temp.setName("Two of Clubs"); // Clubs 
	temp.setValue(2);
	Deck.push_back(temp);//4

	// All 4 Aces*************************************************************
	temp.setName("Ace of Diamonds"); // Dimonds 
	temp.setValue(1);
	Deck.push_back(temp);//1
	temp.setName("Ace of Hearts"); // Hearts 
	temp.setValue(1);
	Deck.push_back(temp);//2
	temp.setName("Ace of Spades"); // Spades 
	temp.setValue(1);
	Deck.push_back(temp);//3
	temp.setName("Ace of Clubs"); // Clubs 
	temp.setValue(1);
	Deck.push_back(temp);//4
}

