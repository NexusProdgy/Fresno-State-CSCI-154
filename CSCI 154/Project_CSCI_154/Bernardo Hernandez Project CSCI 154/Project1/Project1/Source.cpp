#include<iostream>
#include<string>
#include<time.h>
using namespace std;
class
{
public:


};
void createDeck(int[], const int);
bool checkCard(int[],int [], string[], string [], int, int);
//void deal(int[],int[], int);

void Policy1();
void Policy2();

int main()
{
	const int sizeofDeck = 52;
	int deck[sizeofDeck];
	string suit[4] = { "SPADE","HEART","CLUB","DIAMOND" };
	//int value = 0; // Value of the Card
	int random;
	int player, playerHand[sizeofDeck];
	int dealer, dealerHand[sizeofDeck];
	string  playerSuit[sizeofDeck], dealerSuit[sizeofDeck];
	bool checkR;// if card is repeated then switch to true if not stay false

	int indexofSuit;

	// will be used to ensure that card isnt picked again
	int cardsDealt[52];
	string suitofCardDealt[52]; // if a SPADE/HEART/DIAMOND/CLUB was dealth

	
	string typeofHand; // Hand is considered hard or soft; Soft if an ace is received, and hard if no ace
	srand((unsigned)time(NULL));


	//create deck	
	createDeck(deck,sizeofDeck);

	//deal hand  to dealer and player
	for (int i = 0; i < 52; i++)
	{
		random = rand() % sizeofDeck;
		playerHand[random] = deck[random];

		

		indexofSuit = rand() % 4;
		playerSuit[indexofSuit] = suit[indexofSuit];

		cout << playerHand[random];
		cout << playerSuit[indexofSuit] << endl;
		//the cards already deal go in here
		cardsDealt[random] = deck[random];
		suitofCardDealt[indexofSuit] = suit[indexofSuit];

		checkR = checkCard(playerHand,cardsDealt, suitofCardDealt, playerSuit, random, indexofSuit);
		while (checkR != true )
		{
			random = rand() % sizeofDeck;
			playerHand[i] = deck[random];

			indexofSuit = rand() % 4;
			playerSuit[i] = suit[indexofSuit];

			cardsDealt[random] = deck[random];
			suitofCardDealt[indexofSuit] = suit[indexofSuit];
			checkR = checkCard(playerHand, cardsDealt, suitofCardDealt, playerSuit, random, indexofSuit);
	

		}
	}




	return 0;
}

void createDeck(int deck[], const int S)
{
	int value=1;
	for (int i = 0; i < S; i++)
	{
		// fills up deck from 0 to 51 
		//0 - 12 Hearts
		// 13 - 25 Clubs
		//26-38 Spade
		//39-51 Diamond 
		deck[i] = value;
		value++;
		if (i == 12 || i == 25 || i == 38 || i == 51)
			value = 1;
	}


}

bool checkCard(int playerH[], int cardsDealt[], string suitofCardDealt[], string playerSuit[], int random, int indexofSuit)
{
	if (playerH[random] == cardsDealt[random] && playerSuit[indexofSuit] == suitofCardDealt[indexofSuit])
	{
		//if equal, they are repeated
		return true;

	}
	else
		false;
}



void Policy1()

{

}

void Policy2()
{

}

/*
for (int i = 0; i < sizeofDeck; i++)
{
	random = rand() % temp;
	deck[random];

	cout << deck[random] << " ";
	cout << suit[random % 4] << endl;

	if (deck[i]== 11 || deck[i] == 12 || deck[i]==13)
	{

	}

}
*/