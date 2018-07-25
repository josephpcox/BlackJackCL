#ifndef CARD_H
#define CARD_H
#include <string>
using namespace std;

class Card{

private:

	 int value;
	 string cardName;

public:

	Card(); // Default constructor

	~Card();// default destructor

	Card(const string, const int);
	
	int getValue()const;

	void setValue(int);

	void setName(string);
	
	string getName()const;

	Card& operator=(Card&);


};
#endif

