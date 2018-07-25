/**************************************************************************************************************************
*	Author: Jospeh Cox                                                                                   Dr. sun OOP      *
*	                                                                                                                      *
*	BlackJack.cpp                                                                                        12/3/17          *
*                                                                                                                         *
*                                                                                                                         *
*	@Def:Main Function to play non graphical version of Jack                                                              *
***************************************************************************************************************************/
#include <string>
#include <iostream>
#include <vector>
#include "Card.h"
#include "User.h"
#include "Dealer.h"
#include "Game.h"

using namespace std;


#define TRUE 1
#define FALSE 0

unsigned int Game::round=0;

int main(){

	// initilization for necessary variables and objects 
	vector <User> players; 
	int numPlayers{0}; // Total Number of players 
	vector<Card> Deck; // 52 Card Deck
	vector <User>::iterator it; // vector control variable 
	Dealer Bot{1000};
	Bot.makeDeck(Deck);// adds all the cards to the deck
	Bot.shuffle(Deck); // shuffles the deck
	int playAgain=2;

	while((numPlayers < 1) ||(numPlayers > 5 )){

		cout << "Please Enter the Number of Players [Must be between 1 and 5]:" << endl;
		cin >> numPlayers;

	}
		
	Game Game(players,numPlayers);// initilize the game
	

		while(Game.getGameEnd()==FALSE){

			Game.setAllBets(players,it); // good

			Game.dealRound(Bot, Deck, players, it); //good
  		
  			Game.dealRound(Bot, Deck, players,it); //good

			Game.displayGame(players,it,Bot); //good

			Game.play(Bot,Deck,players,it); // good

			cout<<"Round: "<<Game::getRound()<<" has ended"<<endl;

			Game.displayResult(players,it,Bot);
			while(playAgain!=1 && playAgain!=0){
				
				cout<<"Would you like to play another round: 0=No 1=Yes"<<endl;
				cin>>playAgain;
			}

			if(playAgain==0){

				Game.setGameEnd(TRUE);
			}
			else{
				Bot.clearHands(players, it);
				Bot.reFreshDeck(Deck);
			}
			playAgain=2;
		}

}




