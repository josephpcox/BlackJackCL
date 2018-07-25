#include "Card.h"
#include <string>
#include <iostream>
#include <vector>
#include "Dealer.h"

Card::Card(){
	this->value = 0;
	this->cardName= "empty";
}
// over loaded constructor 
Card::Card(string card , int cardValue){

	this->cardName = card;
	this->value = cardValue;
}

int Card::getValue()const{
	return value;
}
void Card::setValue(int newVal){

	this->value = newVal;
}

void Card::setName(string name){

	this->cardName = name;
}

string Card::getName()const{

	return this->cardName;
}

Card& Card::operator=(Card& two){ // for split function

	this->cardName = two.getName();
	this->value = two.getValue();

	return *this;
}

Card::~Card(){}