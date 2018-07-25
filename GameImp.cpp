#include "Game.h"
#include <vector>
#include <iostream>
#include "Card.h"
#include "User.h"
#include "Dealer.h"

#define TRUE 1
#define FALSE 0

using namespace std;


Game::Game(vector <User>& players, int numPlayers){

	switch(numPlayers)
		{
			case 1: 
			{	
				User playerOne{1000};
				players.push_back(playerOne);
				break;
			}


			case 2: 
			{
				User playerOne{1000}, playerTwo{1000};
				players.push_back(playerOne);
				players.push_back(playerTwo);
				break;
			}
			case 3:
			{
				User playerOne{1000}, playerTwo{1000}, playerThree{1000};
				players.push_back(playerOne);
				players.push_back(playerTwo);
				players.push_back(playerThree);
				break;
			}

			case 4:
			{
				User playerOne{1000}, playerTwo{1000}, playerThree{1000},
				playerFour{1000};
				players.push_back(playerOne);
				players.push_back(playerTwo);
				players.push_back(playerThree);
				players.push_back(playerFour);
				break;
			}
			case 5:
			{
				User playerOne{1000}, playerTwo{1000}, playerThree{1000},
				playerFour{1000}, playerFive{1000};
				players.push_back(playerOne);
				players.push_back(playerTwo);
				players.push_back(playerThree);
				players.push_back(playerFour);
				players.push_back(playerFive);
				break;
			}
		}

}

Game::~Game(){

	cout<<"The game has ended thank you for playing"<<endl;
}

void Game::setGameEnd(bool g){

	this->end=g;
}

bool Game::getGameEnd()const{

	return this->end;

}
void Game::askForAce(int k,vector <Card>& Hand, vector <Card>::iterator it){
	k=k+1;
	int i=0;
	it = Hand.begin();
	int selection = 2;
	while(it!=Hand.end()){
		if(Hand[i].getValue()==1){

			cout<<"Player "<<k<<": You have an ACE!!!"<<endl;
			cout<<"Check your Hand Value and see if you would like to make the Ace worth 11 instead of 1"<<endl;
			while(selection !=1 && selection!=0) {
					
					cout<<"Would you like to change the Value of this Ace? : 0 = NO, 1 = YES"<<endl;
					cin>>selection;

				} 


			switch(selection){

				case 0:
					break;

				case 1:
					Hand[i].setValue(11);
					break;
			}
		}
		it++;
		i++;
	}

}
unsigned int Game::getRound(){

	return ++round;
}

// -----------------------------------SETS--------------------------------------------------------------------------

void Game::setAllBets(vector <User>& players,vector <User>::iterator it){


	it =players.begin();
	int i=0;
	while(it != players.end())
	{
		double playerBet=0;
		while((playerBet < 5) || (playerBet > 100))
		{
			cout << "Player " << i + 1 << ": Please Enter your Bet [Must be between 5 & 100]" << endl;
			cin >> playerBet;
			
		}
		players[i].setBet(playerBet);
		it++;
		i++;
	}
	it=players.begin();
}


// ------------------------------------------------------DISPLAY-----------------------------------------------------------------

void Game::displayGame(vector <User>& players, vector <User>::iterator it, Dealer Bot){

	cout<<"***********************************************Current Game Status**************************************************"<<endl;
	it =players.begin();
	int i=0;

	cout << "Bot: \n";
	Bot.displayDealer();

	while(it != players.end())
	{
		cout<<"Player " << (i + 1) << ": \n";
		players[i].displayPlayer();
		it++;
		i++;

	}


	cout<<"***********************************************Current Game Status**************************************************"<<endl;

	it=players.begin();

}
void Game::displayResult(vector <User>& players, vector <User>::iterator it, Dealer Bot){

	cout<<"***********************************************Current Game Status**************************************************"<<endl;
	it =players.begin();
	int i=0;

	cout << "Bot: \n";
	Bot.displayPlayer();

	while(it != players.end())
	{
		cout<<"Player " << (i + 1) << ": \n";
		players[i].displayPlayer();
		it++;
		i++;

	}


	cout<<"***********************************************Current Game Status**************************************************"<<endl;

	it=players.begin();

}

//-------------------------------------------------DEALROUND--------------------------------------------------------------------

void Game::dealRound(Dealer& Bot, vector <Card>& Deck, vector <User>& players,vector <User>::iterator it ){
	int i =0;
	it=players.begin();

	while(it !=players.end())
	{
		Bot.dealCard(Deck, players[i].getHand());
		i++;
		it++;
	}

	Bot.dealCard(Deck, Bot.getHand());
	it=players.begin();
}

//-------------------------------------------------PLAY--------------------------------------------------------------------

void Game::play(Dealer& Bot, vector <Card>& Deck, vector <User>& players,vector <User>::iterator it)
{
	int blackJack=FALSE;
	int playOption = 0;
	it =players.begin();
	int i=0;
	vector <Card>::iterator cd;

	cout<<"Number of players = "<<players.size()<<"\n"<<endl;

	while(it!=players.end()){
		this->askForAce(i,players[i].getHand(),cd);
		it++;
		i++;
	}
	i=0;
	it=players.begin();
	while (it!=players.end())
	{	
	    //Hit = 1, Stand = 2, Double Down = 3, Surrender = 4, Split = 5
		playOption = 0;
		players[i].displayPlayer();
		while(!((playOption >= 1) && (playOption <= 5)) && it!=players.end() )
		{
			cout<<"Player "<<i+1<<", make your move."<<endl;
			cout<<"Your options are: Hit = 1, Stand = 2, Double Down = 3, Surrender = 4, Split = 5"<<endl;
			cin>>playOption;
		}

		players[i].setPlayerOption(playOption);
		if(players[i].getHandValue()>21){

			players[i].setPlayerOption(20);
			cout<<"Player "<< i+1 << " Your hand has busted."<<endl;

		}
		if(players[i].getHandValue()==21 && players[i].getHand().size()==2){

			players[i].setPlayerOption(6);
		}
		switch(players[i].getPlayerOption())
		{

			default: 
				cout<<"Player "<<i+1 <<" Your turn has been skipped."<<endl;
				break;

			case 1:// hit
				Bot.dealCard(Deck, players[i].getHand());
				this->askForAce(i,players[i].getHand(),cd);
				continue;

			case 2: // stand
				break;

			case 3: // double down
				if (players[i].getHand().size() == 2)
				{
					Bot.dealCard(Deck, players[i].getHand());
					this->askForAce(i,players[i].getHand(),cd);
					players[i].setBust();
					if(players[i].getBust()==TRUE){
						cout<<"Player "<<i+1<<" Your hand has busted"<<endl;
					}
					players[i].setBalance(players[i].getBet() + players[i].getBalance());
					players[i].setBet(2*players[i].getBet());
					players[i].displayPlayer();

				}
				else
				{
					cout << "Error: Cannot double down when you have more than 2 cards." << endl;
					continue;
				}
				break;

			case 4: // surrender 
				if (players[i].getHand().size() == 2)
				{
					players[i].setBalance(players[i].getBalance() + players[i].getBet());
					players[i].setBet( (players[i].getBet()) / 2 );
					players[i].displayPlayer();
				}
				else
				{
					cout << "Error: Cannot surrender when you have more than 2 cards."<< endl;
					continue;
				}
				break;

			case 5:// split 
					cout<<"You can not split at this time"<<endl;
					continue;

			case 6:

				cout<<"Player "<< i+1<<" You have a BlackJack!!! Your turn has been skipped"<<endl;
				break;

		}
		players[i].setBust();
		i++;
		it++;
	}

	i=0;
	it=players.begin();
	playOption=0;

	Bot.displayDealer();
	while (playOption==0){

		Bot.setBust();
		cout<<"Bot hand value: "<<Bot.getHandValue()<<endl;
		if(Bot.getHandValue()>=17 && Bot.getHandValue()<21){

			playOption=2; // stand
		}
		else if(Bot.getHandValue()<17){

			playOption=1;// Hit
		}
		else if(Bot.getHandValue()>21){
		
			playOption=3;

		}
		else if(Bot.getHandValue()==21){
			if(Bot.getHand().size()==2){

				playOption=4;
			}
			else{

				playOption=2;
			}
		}
		switch(playOption){

			case 1:
				cout<<"Dealer has hit"<<endl;
				Bot.dealCard(Deck,Bot.getHand());
				playOption=0;
				continue;

			case 2: // stand
				cout<<"Bot has stand"<<endl;
				break;

			case 3:
				cout<<"Bot has bust"<<endl;
				break;
			case 4:
				cout<<"Bot has Blacjkack!!!"<<endl;
				blackJack=TRUE;
				break;

		}

	}
	cout<<"Bot's full hand is revealed...\n"<<endl;
	Bot.displayPlayer();
	it=players.begin();
	i=0;
	while(it!=players.end()){

		players[i].setBust();
		Bot.setBust();
		switch(blackJack){

			case 1:
				if(players[i].getHand().size()==2 && players[i].getHandValue()==21){
					cout<<"The dealer also has a blackJack"<<endl;

					cout<<"Player "<<i+1<<" and the dealer have a draw no one gets paid "<<players[i].getBet()<<endl;
					players[i].setBalance(players[i].getBet() + players[i].getBalance());
				}
				else{
					cout<<"The Dealer has a blackJack you have lost to the dealer"<<endl;
					Bot.setBalance(Bot.getBalance()+players[i].getBet());
		
				}
				break;
			default:
				if(Bot.getBust()==TRUE){

					if(players[i].getBust()==TRUE){

						cout<<"Player "<< i+1<<". You and the Dealer both have busted you have a draw with the dealer. No one gets paid"<<endl;
						players[i].setBalance(players[i].getBet() + players[i].getBalance());
					}
					else{

						cout<<"Player "<<i+1<<". You have won; the Dealer has busted you will get paid "<<players[i].getBet()<<endl;
						players[i].setBalance(players[i].getBalance()+(2*players[i].getBet()));
					}
				}
				else if(players[i].getHandValue()> Bot.getHandValue()&& players[i].getHandValue()<=21){

						if(players[i].getHand().size()==2 && players[i].getHandValue()==21){

							cout<<"Player "<<i+1<< " You had blackJack!!! You have beaten the dealer, you get a bonus pay,\n"
								<<"Your pay winnings is "<<(((players[i].getBet()*3)/2)+players[i].getBet())<<endl;
							players[i].setBalance((((players[i].getBet()*3)/2)+players[i].getBet()));
						}
						else{
							
							cout<<"Player "<<i+1<<" You have won; your hand is greater than the dealers hand "<<players[i].getBet()<<endl;
							players[i].setBalance(players[i].getBalance()+(2*players[i].getBet()));
						}
				}
				else if(players[i].getHandValue()==Bot.getHandValue()){

						if(players[i].getHand().size()==2 && players[i].getHandValue()==21){
							cout<<"Player "<< i+1 <<" You have Blackjack and beat the dealers hand value of 21\n"
								<<"Your pay winnings is "<<(((players[i].getBet()*3)/2)+players[i].getBet())<<endl;
							players[i].setBalance((((players[i].getBet()*3)/2)+players[i].getBet()));
						}
						else{
							cout<<"Player "<<i+1<<" and the dealer have a draw no one gets paid "<<players[i].getBet()<<endl;
							players[i].setBalance(players[i].getBet() + players[i].getBalance());
						}

				}
				else{

					cout<<"Player "<<i+1<<" The dealer has beaten you. You will lose your bet"<<endl;
					Bot.setBalance(Bot.getBalance()+(players[i].getBet()));
				}
				break;

		}

		i++;
		it++;	


	}

}






