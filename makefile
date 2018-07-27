OBJS= blackJackmain.o CardImp.o DealerImp.o GameImp.o UserImp.o
CC=g++ -std=c++14
FLAGS= -Wall -c -g

blackJack: $(OBJS)
	$(CC) -o blackJack $(OBJS) 

blackJackmain.o: blackJackmain.cpp
		$(CC) $(FLAGS) blackJackmain.cpp

CardImp.o: CardImp.cpp Card.h
		$(CC) $(FLAGS) CardImp.cpp

DealerImp.o: DealerImp.cpp Dealer.h
		$(CC) $(FLAGS) DealerImp.cpp

GameImp.o: GameImp.cpp Game.h
		$(CC) $(FLAGS) GameImp.cpp

UserImp.o: UserImp.cpp User.h
		$(CC) $(FLAGS) UserImp.cpp

clean:
	rm -r *.o blackJack
