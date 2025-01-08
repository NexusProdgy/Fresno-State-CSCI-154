#include<iostream>
#include<string>
#include<time.h>
#include<algorithm>
#include<cstdlib>
#include<tuple>
#include<random>

using namespace std;
void createDeck(int[], string []);
void shuffle(int[], string[]);
int policy1(int[],string[],int[],string[], int, bool);
int policy2(int[],string[],int[],string[], int, bool);
int policy3(int[], string[], int[], string[], int, bool);
int policy4(int[], string[], int[], string[], int, bool);
int policy5(int[], string[], int[], string[], int, bool);
void displayHands(int[],string[],int[], string [], int,int);
float conditionreached=0;// get the amount of time we meet the policy, whether its a win or not
int Game = 0;
using namespace std;

int main()
{
	const  int sizeofDeck = 53;
	int deck[sizeofDeck];
	int playerHand[sizeofDeck];// dealerHand[sizeofDeck]; // the hands they currently hold
	string suitofCardDealt[sizeofDeck]; // if a SPADE/HEART/DIAMOND/CLUB was dealt
	string deckSuit[sizeofDeck];// Containing Spades,Clubs,Hearts, Diamond index should be the same as deck[]
	string  playerSuit[sizeofDeck], dealerSuit[sizeofDeck];
	float won=0.0;
	float loop1 = 10000;
	float probability = 0.0;
	bool singleDeck = true; // when false, then infinite deck
	

	//create deck
	createDeck(deck, deckSuit);
	shuffle(deck, deckSuit);

	
	

	//single Deck
	//POLICY1
	for(int i=0 ; i < loop1; i++)
	{ 
	won += policy1(playerHand, playerSuit, deck, deckSuit,sizeofDeck, singleDeck);
	shuffle(deck, deckSuit);
	}

	probability = (won / loop1) * 100;
	cout << "Single Deck with Policy 1 : games won = " << won << " amount of games = " << loop1 << endl;
	cout << won << "/" << loop1 << " = " << probability <<endl;

	won = 0;

	//Policy 2

	for (int i = 0; i < loop1; i++)
	{
	won += policy2(playerHand, playerSuit, deck, deckSuit, sizeofDeck, singleDeck);
		shuffle(deck, deckSuit);
	}

	probability = (won / loop1) * 100;
	cout << "\nSingle Deck with Policy 2 : games won = " << won << " amount of games = " << loop1 << endl;
	cout << won << "/" << loop1 << " = " << probability<<endl;

	won = 0;


	//Policy 3
	for (int i = 0; i < loop1; i++)
	{
		won += policy3(playerHand, playerSuit, deck, deckSuit, sizeofDeck,singleDeck);
		shuffle(deck, deckSuit);
	}

	probability = (won / loop1) * 100;
	cout << "\nSingle Deck with Policy 3 : games won = " << won << " amount of games = " << loop1 <<endl;
	cout << won << "/" << loop1 << " = " << probability << endl;


	won = 0;



	for (int i = 0; i < loop1; i++)
	{
		won += policy4(playerHand, playerSuit, deck, deckSuit, sizeofDeck, singleDeck);
		shuffle(deck, deckSuit);
	}

	probability = (won / loop1) * 100;
	cout << "\nSingle Deck with Policy 4 : games won = " << won << " amount of games = " << loop1 << endl;
	cout << won << "/" << loop1 << " = " << probability << endl;


	won = 0;



	for (int i = 0; i < loop1; i++)
	{
		won += policy5(playerHand, playerSuit, deck, deckSuit, sizeofDeck, singleDeck);
		shuffle(deck, deckSuit);
	}

	probability = (won / loop1) * 100;
	cout << "\nSingle Deck with Policy 5 : games won = " << won << " amount of games = " << loop1 << endl;
	cout << won << "/" << loop1 << " = " << probability << endl;


	won = 0;


	//---------------Infinite Deck-------------------------------//
	
	//POLICY1
	singleDeck = false;
	for (int i = 0; i < loop1; i++)
	{
		won += policy1(playerHand, playerSuit, deck, deckSuit, sizeofDeck, singleDeck);
		shuffle(deck, deckSuit);
	}

	probability = (won / loop1)*100;
	cout << "\n Infinite Deck with Policy 1 : games won = " << won << " amount of games = " << loop1 << endl;
	cout << won << "/" << loop1 << " = " << probability << endl;

	won = 0;

	//Policy 2

	for (int i = 0; i < loop1; i++)
	{
		won += policy2(playerHand, playerSuit, deck, deckSuit, sizeofDeck, singleDeck);
		shuffle(deck, deckSuit);
	}

	probability = (won / loop1) * 100;
	cout << "\n Infinite Deck with Policy 2 : games won = " << won << " amount of games = " << loop1 << endl;
	cout << won << "/" << loop1 << " = " << probability << endl;

	won = 0;


	//Policy 3
	for (int i = 0; i < loop1; i++)
	{
		won += policy3(playerHand, playerSuit, deck, deckSuit, sizeofDeck, singleDeck);
		shuffle(deck, deckSuit);
	}

	probability = (won / loop1) * 100;
	cout << "\n Infinite Deck with Policy 3 : games won = " << won << " amount of games = " << loop1 << endl;
	cout << won << "/" << loop1 << " = " << probability << endl;

	won = 0;


	for (int i = 0; i < loop1; i++)
	{
		won += policy4(playerHand, playerSuit, deck, deckSuit, sizeofDeck, singleDeck);
		shuffle(deck, deckSuit);
	}

	probability = (won / loop1) * 100;
	cout << "\Infinite Deck with Policy 4 : games won = " << won << " amount of games = " << loop1 << endl;
	cout << won << "/" << loop1 << " = " << probability << endl;


	won = 0;



	for (int i = 0; i < loop1; i++)
	{
		won += policy5(playerHand, playerSuit, deck, deckSuit, sizeofDeck, singleDeck);
		shuffle(deck, deckSuit);
	}

	probability = (won / loop1) * 100;
	cout << "\Infinite Deck with Policy 5 : games won = " << won << " amount of games = " << loop1 << endl;
	cout << won << "/" << loop1 << " = " << probability << endl;


	won = 0;



	return 0;
}




void createDeck(int deck[], string deckSuit[])
{
	int value=1;
	

	for (int i = 1; i < 53; i++)
	{
		// fills up deck from 0 to 51 
		//1 - 13 Hearts
		// 14 - 26 Clubs
		//27-39 Spade
		//40-52 Diamond 

		if (i <=10)
		{

			
			deck[i] = value;
			deckSuit[i] = "HEARTS";
			value++;


			//if (i == 1)
				//deckSuit[i] = "ACE OF HEARTS";
	
		}
		else if (i >= 11 && i <= 13  )
		{
			if (i == 11)
			{
				deck[i] = 10;
				deckSuit[i] = "JACK OF HEARTS";
				value++;

			}
			else if (i == 12)
			{
				deck[i] = 10;
				deckSuit[i] = "QUEEN OF HEARTS";
				value++;
			}
			else //i=13 
			{
				deck[i] = 10;
				deckSuit[i] = "KING OF HEARTS";
				value++;

			}
		}
		
		
		if ( i>=14 && i <=23) //CLUBS
		{

			deck[i] = value;
			deckSuit[i] = "CLUBS";
			value++;

			//if (i == 14)
				//deckSuit[i] = "ACE OF CLUBS";

		}
		else if (i >= 24 && i <= 26)
		{
			 if (i == 24)
			 {
				 deck[i] = 10;
				 deckSuit[i] = "JACK OF CLUBS";
				 value++;

			 }
			 else if (i == 25)
			 {
				 deck[i] = 10;
				 deckSuit[i] = "QUEEN OF CLUBS";
				 value++;
			 }
			 else //i=26
			 {
				 deck[i] = 10;
				 deckSuit[i] = "KING OF CLUBS";
				 value++;

			 }

		}
		
		else  if (i>=27 && i <= 36)
		 {
			 deck[i] = value;
			 deckSuit[i] = "SPADES";
			 value++;
			 //if (i == 27)
				// deckSuit[i] = "ACE OF SPADES";
		 }
		 else if (i >= 37 && i <= 39)
		 {
			 if (i == 37)
			 {
				 deck[i] = 10;
				 deckSuit[i] = "JACK OF SPADES";
				 value++;

			 }
			 else if (i == 38)
			 {
				 deck[i] = 10;
				 deckSuit[i] = "QUEEN OF SPADES";
				 value++;
			 }
			 else //i=39
			 {
				 deck[i] = 10;
				 deckSuit[i] = "KING OF SPADES";
				 value++;

			 }
		 }
		
		 
		 else if (i >= 40 && i <=49)
		 {
			 deck[i] = value;
			 deckSuit[i] = "DIAMONDS";
			 value++;

			 //if (i == 40)
				// deckSuit[i] = "ACE OF DIAMONDS";
		 }
		 else if (i >=50 && i <= 52)
		 {
			 if (i == 50)
			 {
				 deck[i] = 10;
				 deckSuit[i] = "JACK OF DIAMONDS";
				 value++;

			 }
			 else if (i == 51)
			 {
				 deck[i] = 10;
				 deckSuit[i] = "QUEEN OF DIAMONDS";
				 value++;
			 }
			 else // i=52
			 {
				 deck[i] = 10;
				 deckSuit[i] = "KING OF DIAMONDS";
				 value++;

			 }
		 }



		 

	
		if (i == 13 || i == 26 || i == 39 || i == 52) 
		{
			value = 1;

		}
	}
	
	


}


void shuffle(int deck[], string suitofDeck[])
{
	random_device rd;
	mt19937 gen(rd());
	//srand((time) (NULL));
	srand(time(0));
	for(int i=1; i <53; i++)
	{ 
	int r = i + (rd() % (53 - i));

	swap(deck[i], deck[r]);
	swap(suitofDeck[i], suitofDeck[r]);
	}

}



int policy1(int playerHand[], string playerSuit[], int deck[], string deckSuit[], int sizeofDeck, bool singleDeck)
{
	Game++;
	int total=0;
	bool softHand = false, dsoftHand=false; //dsoftHand is for dealer type of hand
	int dealerTotal=0, dealerHand[53];
	string dealerSuit[53];
	bool stick = false;
	int playercurrentcardsHolding=0, dealercardsHolding=0;
	int decreaseDeck = sizeofDeck-1;// decrease so we don't check which cards have already been played
	int playerindexAce = 0, dealerindexAce = 0;
	int tiebreaker=0;


	//deal two cards to player 
	for (int i = 1; i < 3; i++)
	{
		
		playerHand[i] = deck[decreaseDeck];


		if (singleDeck == true)
		{
			if (playerHand[i] == 1 && total < 11)// for a softHand ace is needed and total needs to be below 11 before ace 
			{
				softHand = true;
				playerHand[i] = 11;// replace one with 11 
				playerSuit[i] = deckSuit[decreaseDeck];
				total += 11;
				playerindexAce = i;
				decreaseDeck--;
				playercurrentcardsHolding++;
			}
			else
			{

				total += deck[decreaseDeck];
				playerSuit[i] = deckSuit[decreaseDeck];
				
				decreaseDeck--;

				playercurrentcardsHolding++;
			}
			

		}
		else // Then it is Infinite Deck
		{
			if (playerHand[i] == 1 && total < 11)// for a softHand ace is needed and total needs to be below 11 before ace 
			{
				softHand = true;
				playerHand[i] = 11;
				playerSuit[i] = deckSuit[decreaseDeck];
				total += 11;
				shuffle(deck, deckSuit);
				playercurrentcardsHolding++;
				playerindexAce = i;
			}
			else
			{
				total += deck[decreaseDeck];
				playerSuit[i] = deckSuit[decreaseDeck];
				shuffle(deck, deckSuit);
				playercurrentcardsHolding++;
				
			}
			
			
			
		
		
		}
		
	}

	

	//to dealer
	for (int i = 1; i < 3; i++)
	{
	
		dealerHand[i] = deck[decreaseDeck];	

		if (singleDeck == true)
		{
			if (dealerHand[i] == 1 && dealerTotal < 11) // if value is one then Ace
			{
				dsoftHand = true;
				dealerHand[i] = 11;// replace one with 11 
				dealerSuit[i] = deckSuit[decreaseDeck];
				dealerTotal += 11;
				dealerindexAce = i;
				decreaseDeck--;
				dealercardsHolding++;
			}
			else
			{

				dealerTotal += deck[decreaseDeck];
				dealerSuit[i] = deckSuit[decreaseDeck];

				decreaseDeck--;
				dealercardsHolding++;
			}


		}
		 else // Then it is Infinite Deck
		 {

			if (dealerHand[i] == 1 && dealerTotal < 11)// for a softHand ace is needed and total needs to be below 11 before ace 
			{
				dsoftHand = true;
				dealerHand[i] = 11;
				dealerSuit[i] = deckSuit[decreaseDeck];
				dealerTotal += 11;
				shuffle(deck, deckSuit);
				dealercardsHolding++;
				dealerindexAce = i;
			}
			else
			{
				dealerTotal += deck[decreaseDeck];
				dealerSuit[i] = deckSuit[decreaseDeck];
				shuffle(deck, deckSuit);
				dealercardsHolding++;
			}



		 }

	}

	
	
	while (stick != true )
	{

		if (total >= 17)
			stick = true;
		else 
		{
			
			if (singleDeck == true)
			{
				playercurrentcardsHolding++;
				playerHand[playercurrentcardsHolding] = deck[decreaseDeck];
				playerSuit[playercurrentcardsHolding] = deckSuit[decreaseDeck];


				if (playerHand[playercurrentcardsHolding] == 1 && total < 11)// softhand if it doesnt exceed 10 when drawing an ACE 
				{
					playerHand[playercurrentcardsHolding] = 11;
					total += 11;
					playerindexAce = playercurrentcardsHolding;
					softHand = true;
					//cout << "card drawn = " << playerHand[playercurrentcardsHolding] << " " << playerSuit[playercurrentcardsHolding]<<endl;

				}
				else
				{
					total += deck[decreaseDeck];
					//cout << "card drawn = " << playerHand[playercurrentcardsHolding] << " " << playerSuit[playercurrentcardsHolding] << endl;
				}

				if (total > 21 && softHand == true) //check the the current hand isn't exceeding 21 while having soft hand, if so change ace to value
				{
					//cout << "changed one ace from " << total;
					total -= 10;
					playerHand[playerindexAce] = 1; //set value back to one
					softHand = false;// softHand is now considered a hardHand
					//cout << "card drawn = " << playerHand[playercurrentcardsHolding] << " " << playerSuit[playercurrentcardsHolding] << endl;
				}

				decreaseDeck--;
				

			}
			else // Then it is Infinite Deck
			{
				
				playercurrentcardsHolding++;
				playerHand[playercurrentcardsHolding] = deck[decreaseDeck];
				playerSuit[playercurrentcardsHolding] = deckSuit[decreaseDeck];


				if (playerHand[playercurrentcardsHolding] == 1 && total < 11)// softhand if it doesnt exceed 10 when drawing an ACE 
				{
					playerHand[playercurrentcardsHolding] = 11;
					total += 11;
					playerindexAce = playercurrentcardsHolding;
					softHand = true;

				}
				else
				{
					total += deck[decreaseDeck];


				}
				//cout << "Here  the hand is " << softHand << " and the total is = " << total <<endl;
				if (total > 21 && softHand == true) //check the the current hand isn't exceeding 21 while having soft hand, if so change ace to value 1
				{
					//cout << "changed one ace from " << total;

					total -= 10;
					//cout <<"\nto "<<  total <<endl;
					playerHand[playerindexAce] = 1; //set value back to one
					softHand = false;// softHand is now considered a hardHand
				}

				shuffle(deck, deckSuit);


			}

		}
	}

	if (total > 21) 
	{
	
		return 0;
		
	}

	while (dealerTotal <= 16)
	{

		if (singleDeck == true)
		{
			dealercardsHolding++;
			dealerHand[dealercardsHolding] = deck[decreaseDeck];
			dealerSuit[dealercardsHolding] = deckSuit[decreaseDeck];
			dealerTotal += deck[decreaseDeck];
			


			if (dealerHand[dealercardsHolding] == 1 && dealerTotal < 11)// softhand if it doesnt exceed 10 when drawing an ACE 
			{
				dealerHand[dealercardsHolding] = 11;
				dealerTotal += 11;
				dealerindexAce = dealercardsHolding;
				dsoftHand = true;

			}
			else
			{
				dealerTotal += deck[decreaseDeck];
			}

			if (dealerTotal > 21 && dsoftHand == true) //check the the current hand isn't exceeding 21 while having soft hand, if so change ace to value 1
			{
				dealerTotal -= 10;
				dealerHand[playerindexAce] = 1; //set value back to one
				dsoftHand = false;// softHand is now considered a hardHand
			}

			decreaseDeck--;

		}
		else//infinite deck
		{
			
			dealercardsHolding++;
			dealerHand[dealercardsHolding] = deck[decreaseDeck];
			dealerSuit[dealercardsHolding] = deckSuit[decreaseDeck];


			if (dealerHand[dealercardsHolding] == 1 && dealerTotal < 11)// softhand if it doesnt exceed 10 when drawing an ACE 
			{
				dealerHand[dealercardsHolding] = 11;
				dealerTotal += 11;
				dealerindexAce = dealercardsHolding;
				dsoftHand = true;

			}
			else
			{
				dealerTotal += deck[decreaseDeck];


			}

			if (dealerTotal > 21 && dsoftHand == true) //check the the current hand isn't exceeding 21 while having soft hand, if so change ace to value 1
			{
				dealerTotal -= 10;
				dealerHand[dealerindexAce] = 1; //set value back to one
				dsoftHand = false;// softHand is now considered a hardHand
			}

			shuffle(deck, deckSuit);
		
		}


	}

	
	if (total == dealerTotal)
	{
		
		//cout << "A tie has occured player =  "  << total << "dealer= " << dealerTotal << endl;
		shuffle(deck, deckSuit);
		total = policy1(playerHand, playerSuit, deck, deckSuit, sizeofDeck, singleDeck);
		

		if (total == 1)
			return 1;
		else
			return 0;


	}


	if (dealerTotal > 21)
	{
		
		return 1; // dealers loss, so player wins
	}

	

	if (total > dealerTotal)
	{

		return 1;
	}


	if (dealerTotal > total)
	{
		
		return 0;
	}

}

int policy2(int playerHand[], string playerSuit[], int deck[], string deckSuit[], int sizeofDeck, bool singleDeck)
{

	int total = 0;
	bool softHand = false, dsoftHand = false; //dsoftHand is for dealer type of hand
	int dealerTotal = 0, dealerHand[53];
	string dealerSuit[53];
	bool stick = false;
	int playercurrentcardsHolding = 0, dealercardsHolding = 0;
	int decreaseDeck = sizeofDeck - 1;// decrease so we don't check which cards have already been played
	//int playertrackAce[22], dealertrackAce[22];
	int playerindexAce = 0, dealerindexAce = 0;


	for (int i = 1; i < 3; i++)
	{

		playerHand[i] = deck[decreaseDeck];


		if (singleDeck == true)
		{
			if (playerHand[i] == 1 && total < 11)// for a softHand ace is needed and total needs to be below 11 before ace 
			{
				softHand = true;
				playerHand[i] = 11;// replace one with 11 
				playerSuit[i] = deckSuit[decreaseDeck];
				total += 11;
				playerindexAce = i;
				decreaseDeck--;
				playercurrentcardsHolding++;
			}
			else
			{

				total += deck[decreaseDeck];
				playerSuit[i] = deckSuit[decreaseDeck];

				decreaseDeck--;

				playercurrentcardsHolding++;
			}


		}
		else // Then it is Infinite Deck
		{
			if (playerHand[i] == 1 && total < 11)// for a softHand ace is needed and total needs to be below 11 before ace 
			{
				softHand = true;
				playerHand[i] = 11;
				playerSuit[i] = deckSuit[decreaseDeck];
				total += 11;
				shuffle(deck, deckSuit);
				playercurrentcardsHolding++;
				playerindexAce = i;
			}
			else
			{
				total += deck[decreaseDeck];
				playerSuit[i] = deckSuit[decreaseDeck];
				shuffle(deck, deckSuit);
				playercurrentcardsHolding++;

			}



		}

	}





	//to dealer
	for (int i = 1; i < 3; i++)
	{

		dealerHand[i] = deck[decreaseDeck];

		if (singleDeck == true)
		{
			if (dealerHand[i] == 1 && dealerTotal < 11) // if value is one then Ace
			{
				dsoftHand = true;
				dealerHand[i] = 11;// replace one with 11 
				dealerSuit[i] = deckSuit[decreaseDeck];
				dealerTotal += 11;
				dealerindexAce = i;
				decreaseDeck--;
				dealercardsHolding++;
			}
			else
			{

				dealerTotal += deck[decreaseDeck];
				dealerSuit[i] = deckSuit[decreaseDeck];

				decreaseDeck--;
				dealercardsHolding++;
			}


		}
		else // Then it is Infinite Deck
		{

			//----------------------
			if (dealerHand[i] == 1 && dealerTotal < 11)// for a softHand ace is needed and total needs to be below 11 before ace 
			{
				dsoftHand = true;
				dealerHand[i] = 11;
				dealerSuit[i] = deckSuit[decreaseDeck];
				dealerTotal += 11;
				shuffle(deck, deckSuit);
				dealercardsHolding++;
				dealerindexAce = i;
			}
			else
			{
				dealerTotal += deck[decreaseDeck];
				dealerSuit[i] = deckSuit[decreaseDeck];
				shuffle(deck, deckSuit);
				dealercardsHolding++;
			}



		}

	}




	while (stick != true)
	{
		if (total == 21)
		{
			stick = true;
		}
		else if (total >= 17 && softHand == false)
			stick = true;
		else
		{



			if (singleDeck == true)
			{
				playercurrentcardsHolding++;
				playerHand[playercurrentcardsHolding] = deck[decreaseDeck];
				playerSuit[playercurrentcardsHolding] = deckSuit[decreaseDeck];


				if (playerHand[playercurrentcardsHolding] == 1 && total < 11)// softhand if it doesnt exceed 10 when drawing an ACE 
				{
					playerHand[playercurrentcardsHolding] = 11;
					total += 11;
					playerindexAce = playercurrentcardsHolding;
					softHand = true;

				}
				else
				{
					total += deck[decreaseDeck];
				}

				if (total > 21 && softHand == true) //check the the current hand isn't exceeding 21 while having soft hand, if so change ace to value
				{
					total -= 10;
					playerHand[playerindexAce] = 1; //set value back to one
					softHand = false;// softHand is now considered a hardHand
				}

				decreaseDeck--;

			}
			else // Then it is Infinite Deck
			{
				playercurrentcardsHolding++;
				playerHand[playercurrentcardsHolding] = deck[decreaseDeck];
				playerSuit[playercurrentcardsHolding] = deckSuit[decreaseDeck];


				if (playerHand[playercurrentcardsHolding] == 1 && total < 11)// softhand if it doesnt exceed 10 when drawing an ACE 
				{
					playerHand[playercurrentcardsHolding] = 11;
					total += 11;
					playerindexAce = playercurrentcardsHolding;
					softHand = true;

				}
				else
				{
					total += deck[decreaseDeck];


				}

				if (total > 21 && softHand == true) //check the the current hand isn't exceeding 21 while having soft hand, if so change ace to value 1
				{
					total -= 10;
					playerHand[playerindexAce] = 1; //set value back to one
					softHand = false;// softHand is now considered a hardHand
				}

				shuffle(deck, deckSuit);

			}
			

		}
	}

	if (total > 21) //player losses no need for dealer to draw
		return 0;
	

	while (dealerTotal <= 16)
	{

		if (singleDeck == true)
		{
			dealercardsHolding++;
			dealerHand[dealercardsHolding] = deck[decreaseDeck];
			dealerSuit[dealercardsHolding] = deckSuit[decreaseDeck];
			dealerTotal += deck[decreaseDeck];



			if (dealerHand[dealercardsHolding] == 1 && dealerTotal < 11)// softhand if it doesnt exceed 10 when drawing an ACE 
			{
				dealerHand[dealercardsHolding] = 11;
				dealerTotal += 11;
				dealerindexAce = dealercardsHolding;
				dsoftHand = true;

			}
			else
			{
				dealerTotal += deck[decreaseDeck];
			}

			if (dealerTotal > 21 && dsoftHand == true) //check the the current hand isn't exceeding 21 while having soft hand, if so change ace to value 1
			{
				dealerTotal -= 10;
				dealerHand[playerindexAce] = 1; //set value back to one
				dsoftHand = false;// softHand is now considered a hardHand
			}

			decreaseDeck--;

		}
		else//infinite deck
		{

			dealercardsHolding++;
			dealerHand[dealercardsHolding] = deck[decreaseDeck];
			dealerSuit[dealercardsHolding] = deckSuit[decreaseDeck];


			if (dealerHand[dealercardsHolding] == 1 && dealerTotal < 11)// softhand if it doesnt exceed 10 when drawing an ACE 
			{
				dealerHand[dealercardsHolding] = 11;
				dealerTotal += 11;
				dealerindexAce = dealercardsHolding;
				dsoftHand = true;

			}
			else
			{
				dealerTotal += deck[decreaseDeck];


			}

			if (dealerTotal > 21 && dsoftHand == true) //check the the current hand isn't exceeding 21 while having soft hand, if so change ace to value 1
			{
				dealerTotal -= 10;
				dealerHand[dealerindexAce] = 1; //set value back to one
				dsoftHand = false;// softHand is now considered a hardHand
			}

			shuffle(deck, deckSuit);

		}


	}





	if (total == dealerTotal)
	{

		
		shuffle(deck, deckSuit);
		total = policy2(playerHand, playerSuit, deck, deckSuit, sizeofDeck, singleDeck);


		if (total == 1)
			return 1;
		else
			return 0;


	}




	if (dealerTotal > 21)
	{
		return 1; // dealers loss, so player wins
	}


	if (total > dealerTotal)
	{
		return 1;
	}
	else if (dealerTotal > total)
		return 0;
	



}

int policy3(int playerHand[], string playerSuit[], int deck[], string deckSuit[], int sizeofDeck, bool singleDeck)
{
	int total = 0;
	bool softHand = false, dsoftHand = false; //dsoftHand is for dealer type of hand
	int dealerTotal = 0, dealerHand[53];
	string dealerSuit[53];
	bool stick = false;
	int playercurrentcardsHolding = 0, dealercardsHolding = 0;
	int decreaseDeck = sizeofDeck - 1;// decrease so we don't check which cards have already been played
	int playerindexAce = 0, dealerindexAce = 0;


	//deal two cards to player 
	for (int i = 1; i < 3; i++)
	{

		playerHand[i] = deck[decreaseDeck];


		if (singleDeck == true)
		{
			if (playerHand[i] == 1 && total < 11)// for a softHand ace is needed and total needs to be below 11 before ace 
			{
				softHand = true;
				playerHand[i] = 11;// replace one with 11 
				playerSuit[i] = deckSuit[decreaseDeck];
				total += 11;
				playerindexAce = i;
				decreaseDeck--;
				playercurrentcardsHolding++;
			}
			else
			{

				total += deck[decreaseDeck];
				playerSuit[i] = deckSuit[decreaseDeck];

				decreaseDeck--;

				playercurrentcardsHolding++;
			}


		}
		else // Then it is Infinite Deck
		{
			if (playerHand[i] == 1 && total < 11)// for a softHand ace is needed and total needs to be below 11 before ace 
			{
				softHand = true;
				playerHand[i] = 11;
				playerSuit[i] = deckSuit[decreaseDeck];
				total += 11;
				shuffle(deck, deckSuit);
				playercurrentcardsHolding++;
				playerindexAce = i;
			}
			else
			{
				total += deck[decreaseDeck];
				playerSuit[i] = deckSuit[decreaseDeck];
				shuffle(deck, deckSuit);
				playercurrentcardsHolding++;

			}





		}

	}



	//to dealer
	for (int i = 1; i < 3; i++)
	{
		dealerTotal += deck[decreaseDeck];
		dealerHand[i] = deck[decreaseDeck];

		dealerSuit[i] = deckSuit[decreaseDeck];

		if (singleDeck == true)
		{
			if (dealerHand[i] == 1 && dealerTotal < 11) // if value is one then Ace
			{
				dsoftHand = true;
				dealerHand[i] = 11;// replace one with 11 
				dealerSuit[i] = deckSuit[decreaseDeck];
				dealerTotal += 11;
				dealerindexAce = i;
				decreaseDeck--;
				dealercardsHolding++;
			}
			else
			{

				dealerTotal += deck[decreaseDeck];
				dealerSuit[i] = deckSuit[decreaseDeck];

				decreaseDeck--;
				dealercardsHolding++;
			}


		}
		else // Then it is Infinite Deck
		{
			if (dealerHand[i] == 1 && dealerTotal < 11)// for a softHand ace is needed and total needs to be below 11 before ace 
			{
				dsoftHand = true;
				dealerHand[i] = 11;
				dealerSuit[i] = deckSuit[decreaseDeck];
				dealerTotal += 11;
				shuffle(deck, deckSuit);
				dealercardsHolding++;
				dealerindexAce = i;
			}
			else
			{
				dealerTotal += deck[decreaseDeck];
				dealerSuit[i] = deckSuit[decreaseDeck];
				shuffle(deck, deckSuit);
				dealercardsHolding++;
			}
		}

	}
	//draw one card 
	while (stick != true)
	{
			

			playercurrentcardsHolding++;
			playerHand[playercurrentcardsHolding] = deck[decreaseDeck];
			playerSuit[playercurrentcardsHolding] = deckSuit[decreaseDeck];
			

			if (playerHand[playercurrentcardsHolding] == 1 && total < 11)
			{
				total +=11;
			}
			else
				total += deck[decreaseDeck];
			

			if (singleDeck == true)
			{
				decreaseDeck--;
				stick = true;
			}
			else 
			{
				shuffle(deck, deckSuit);
				stick = true;

			}
	}

	if (total > 21) //player losses no need for dealer to draw
		return 0;


	while (dealerTotal <= 16)
	{

		if (singleDeck == true)
		{
			dealercardsHolding++;
			dealerHand[dealercardsHolding] = deck[decreaseDeck];
			dealerSuit[dealercardsHolding] = deckSuit[decreaseDeck];
			dealerTotal += deck[decreaseDeck];



			if (dealerHand[dealercardsHolding] == 1 && dealerTotal < 11)// softhand if it doesnt exceed 10 when drawing an ACE 
			{
				dealerHand[dealercardsHolding] = 11;
				dealerTotal += 11;
				dealerindexAce = dealercardsHolding;
				dsoftHand = true;

			}
			else
			{
				dealerTotal += deck[decreaseDeck];
			}

			if (dealerTotal > 21 && dsoftHand == true) //check the the current hand isn't exceeding 21 while having soft hand, if so change ace to value 1
			{
				dealerTotal -= 10;
				dealerHand[playerindexAce] = 1; //set value back to one
				dsoftHand = false;// softHand is now considered a hardHand
			}

			decreaseDeck--;

		}
		else//infinite deck
		{

			dealercardsHolding++;
			dealerHand[dealercardsHolding] = deck[decreaseDeck];
			dealerSuit[dealercardsHolding] = deckSuit[decreaseDeck];


			if (dealerHand[dealercardsHolding] == 1 && dealerTotal < 11)// softhand if it doesnt exceed 10 when drawing an ACE 
			{
				dealerHand[dealercardsHolding] = 11;
				dealerTotal += 11;
				dealerindexAce = dealercardsHolding;
				dsoftHand = true;

			}
			else
			{
				dealerTotal += deck[decreaseDeck];


			}

			if (dealerTotal > 21 && dsoftHand == true) //check the the current hand isn't exceeding 21 while having soft hand, if so change ace to value 1
			{
				dealerTotal -= 10;
				dealerHand[dealerindexAce] = 1; //set value back to one
				dsoftHand = false;// softHand is now considered a hardHand
			}

			shuffle(deck, deckSuit);

		}


	}

	if (total == dealerTotal)
	{

		//cout << "A tie has occured player =  "  << total << "dealer= " << dealerTotal << endl;
		shuffle(deck, deckSuit);
		total = policy3(playerHand, playerSuit, deck, deckSuit, sizeofDeck, singleDeck);


		if (total == 1)
			return 1;
		else
			return 0;


	}

	if (dealerTotal > 21)
	{
		return 1; // dealers loss, so player wins
	}


	if (total > dealerTotal)
	{
		return 1;
	}
	else if (dealerTotal > total)
		return 0;


}



int policy4(int playerHand[], string playerSuit[], int deck[], string deckSuit[], int sizeofDeck, bool singleDeck)
{
	Game++;
	int total = 0;
	bool softHand = false, dsoftHand = false; //dsoftHand is for dealer type of hand
	int dealerTotal = 0, dealerHand[53];
	string dealerSuit[53];
	bool stick = false;
	int playercurrentcardsHolding = 0, dealercardsHolding = 0;
	int decreaseDeck = sizeofDeck - 1;// decrease so we don't check which cards have already been played
	//int playertrackAce[22], dealertrackAce[22];
	int playerindexAce = 0, dealerindexAce = 0;



	//deal two cards to player 
	for (int i = 1; i < 3; i++)
	{

		playerHand[i] = deck[decreaseDeck];


		if (singleDeck == true)
		{
			if (playerHand[i] == 1 && total < 11)// for a softHand ace is needed and total needs to be below 11 before ace 
			{
				softHand = true;
				playerHand[i] = 11;// replace one with 11 
				playerSuit[i] = deckSuit[decreaseDeck];
				total += 11;
				playerindexAce = i;
				decreaseDeck--;
				playercurrentcardsHolding++;
			}
			else
			{

				total += deck[decreaseDeck];
				playerSuit[i] = deckSuit[decreaseDeck];

				decreaseDeck--;

				playercurrentcardsHolding++;
			}


		}
		else // Then it is Infinite Deck
		{
			if (playerHand[i] == 1 && total < 11)// for a softHand ace is needed and total needs to be below 11 before ace 
			{
				softHand = true;
				playerHand[i] = 11;
				playerSuit[i] = deckSuit[decreaseDeck];
				total += 11;
				shuffle(deck, deckSuit);
				playercurrentcardsHolding++;
				playerindexAce = i;
			}
			else
			{
				total += deck[decreaseDeck];
				playerSuit[i] = deckSuit[decreaseDeck];
				shuffle(deck, deckSuit);
				playercurrentcardsHolding++;

			}





		}

	}


	//to dealer
	for (int i = 1; i < 3; i++)
	{

		dealerHand[i] = deck[decreaseDeck];

		if (singleDeck == true)
		{
			if (dealerHand[i] == 1 && dealerTotal < 11) // if value is one then Ace
			{
				dsoftHand = true;
				dealerHand[i] = 11;// replace one with 11 
				dealerSuit[i] = deckSuit[decreaseDeck];
				dealerTotal += 11;
				dealerindexAce = i;
				decreaseDeck--;
				dealercardsHolding++;
			}
			else
			{

				dealerTotal += deck[decreaseDeck];
				dealerSuit[i] = deckSuit[decreaseDeck];

				decreaseDeck--;
				dealercardsHolding++;
			}


		}
		else // Then it is Infinite Deck
		{

			if (dealerHand[i] == 1 && dealerTotal < 11)// for a softHand ace is needed and total needs to be below 11 before ace 
			{
				dsoftHand = true;
				dealerHand[i] = 11;
				dealerSuit[i] = deckSuit[decreaseDeck];
				dealerTotal += 11;
				shuffle(deck, deckSuit);
				dealercardsHolding++;
				dealerindexAce = i;
			}
			else
			{
				dealerTotal += deck[decreaseDeck];
				dealerSuit[i] = deckSuit[decreaseDeck];
				shuffle(deck, deckSuit);
				dealercardsHolding++;
			}



		}

	}



	//policy 4
	while (stick != true)
	{

		if (total>=12)
			stick = true;
		else
		{

			if (singleDeck == true)
			{
				playercurrentcardsHolding++;
				playerHand[playercurrentcardsHolding] = deck[decreaseDeck];
				playerSuit[playercurrentcardsHolding] = deckSuit[decreaseDeck];


				if (playerHand[playercurrentcardsHolding] == 1 && total < 11)// softhand if it doesnt exceed 10 when drawing an ACE 
				{
					playerHand[playercurrentcardsHolding] = 11;
					total += 11;
					playerindexAce = playercurrentcardsHolding;
					softHand = true;
					//cout << "card drawn = " << playerHand[playercurrentcardsHolding] << " " << playerSuit[playercurrentcardsHolding] << endl;

				}
				else
				{
					total += deck[decreaseDeck];
					//cout << "card drawn = " << playerHand[playercurrentcardsHolding] << " " << playerSuit[playercurrentcardsHolding] << endl;
				}

				if (total > 21 && softHand == true) //check the the current hand isn't exceeding 21 while having soft hand, if so change ace to value
				{
					total -= 10;
					playerHand[playerindexAce] = 1; //set value back to one
					softHand = false;// softHand is now considered a hardHand
					//cout << "card drawn = " << playerHand[playercurrentcardsHolding] << " " << playerSuit[playercurrentcardsHolding] << endl;
				}

				decreaseDeck--;


			}
			else // Then it is Infinite Deck
			{

				playercurrentcardsHolding++;
				playerHand[playercurrentcardsHolding] = deck[decreaseDeck];
				playerSuit[playercurrentcardsHolding] = deckSuit[decreaseDeck];


				if (playerHand[playercurrentcardsHolding] == 1 && total < 11)// softhand if it doesnt exceed 10 when drawing an ACE 
				{
					playerHand[playercurrentcardsHolding] = 11;
					total += 11;
					playerindexAce = playercurrentcardsHolding;
					softHand = true;

				}
				else
				{
					total += deck[decreaseDeck];


				}

				if (total > 21 && softHand == true) //check the the current hand isn't exceeding 21 while having soft hand, if so change ace to value 1
				{
					//cout << "changed one ace from " << total;

					total -= 10;
					//cout << "\nto " << total << endl;
					playerHand[playerindexAce] = 1; //set value back to one
					softHand = false;// softHand is now considered a hardHand
				}

				shuffle(deck, deckSuit);


			}

		}
	}
	
	//cout << "after drawing cards " << total << endl;

	
	if (total > 21) //player loss no need for dealer to draw
	{
		//cout << "player loss, curren handd =" << total << endl;
		return 0;

	}
	// dealer keeps drawing if he does not have 17 or higher
	while (dealerTotal <= 16)
	{

		if (singleDeck == true)
		{
			dealercardsHolding++;
			dealerHand[dealercardsHolding] = deck[decreaseDeck];
			dealerSuit[dealercardsHolding] = deckSuit[decreaseDeck];
			dealerTotal += deck[decreaseDeck];



			if (dealerHand[dealercardsHolding] == 1 && dealerTotal < 11)// softhand if it doesnt exceed 10 when drawing an ACE 
			{
				dealerHand[dealercardsHolding] = 11;
				dealerTotal += 11;
				dealerindexAce = dealercardsHolding;
				dsoftHand = true;

			}
			else
			{
				dealerTotal += deck[decreaseDeck];
			}

			if (dealerTotal > 21 && dsoftHand == true) //check the the current hand isn't exceeding 21 while having soft hand, if so change ace to value 1
			{
				dealerTotal -= 10;
				dealerHand[playerindexAce] = 1; //set value back to one
				dsoftHand = false;// softHand is now considered a hardHand
			}

			decreaseDeck--;

		}
		else//infinite deck
		{

			dealercardsHolding++;
			dealerHand[dealercardsHolding] = deck[decreaseDeck];
			dealerSuit[dealercardsHolding] = deckSuit[decreaseDeck];


			if (dealerHand[dealercardsHolding] == 1 && dealerTotal < 11)// softhand if it doesnt exceed 10 when drawing an ACE 
			{
				dealerHand[dealercardsHolding] = 11;
				dealerTotal += 11;
				dealerindexAce = dealercardsHolding;
				dsoftHand = true;

			}
			else
			{
				dealerTotal += deck[decreaseDeck];


			}

			if (dealerTotal > 21 && dsoftHand == true) //check the the current hand isn't exceeding 21 while having soft hand, if so change ace to value 1
			{
				dealerTotal -= 10;
				dealerHand[dealerindexAce] = 1; //set value back to one
				dsoftHand = false;// softHand is now considered a hardHand
			}

			shuffle(deck, deckSuit);

		}


	}



	if (total == dealerTotal)
	{

		//cout << "A tie has occured player =  "  << total << "dealer= " << dealerTotal << endl;
		shuffle(deck, deckSuit);
		total = policy4(playerHand, playerSuit, deck, deckSuit, sizeofDeck, singleDeck);


		if (total == 1)
			return 1;
		else
			return 0;


	}



	if (dealerTotal > 21)
	{
		//cout << "dealer BUSTED, player Total  before display Hand " << total <<  "Amount of cards player holding = " << playercurrentcardsHolding << endl;
		//displayHands(playerHand, playerSuit, dealerHand, dealerSuit, playercurrentcardsHolding, dealercardsHolding);
		return 1; // dealers loss, so player wins
	}



	if (total > dealerTotal)
	{
		//cout << "player won, Total  before display Hand " << total << "Amount of cards player holding = " << playercurrentcardsHolding << endl;
		//displayHands(playerHand, playerSuit, dealerHand, dealerSuit, playercurrentcardsHolding, dealercardsHolding);
		return 1;
	}
	else if (dealerTotal > total)
	{
		//cout << "dealer beat your current hand\n";
		//cout << "dealer = " << dealerTotal << " player=" << total << endl;
		return 0;
	}

}



int policy5(int playerHand[], string playerSuit[], int deck[], string deckSuit[], int sizeofDeck, bool singleDeck)
{
	Game++;
	int total = 0;
	bool softHand = false, dsoftHand = false; //dsoftHand is for dealer type of hand
	int dealerTotal = 0, dealerHand[53];
	string dealerSuit[53];
	bool stick = false;
	int playercurrentcardsHolding = 0, dealercardsHolding = 0;
	int decreaseDeck = sizeofDeck - 1;// decrease so we don't check which cards have already been played
	//int playertrackAce[22], dealertrackAce[22];
	int playerindexAce = 0, dealerindexAce = 0;



	//deal two cards to player 
	for (int i = 1; i < 3; i++)
	{

		playerHand[i] = deck[decreaseDeck];


		if (singleDeck == true)
		{
			if (playerHand[i] == 1 && total < 11)// for a softHand ace is needed and total needs to be below 11 before ace 
			{
				softHand = true;
				playerHand[i] = 11;// replace one with 11 
				playerSuit[i] = deckSuit[decreaseDeck];
				total += 11;
				playerindexAce = i;
				decreaseDeck--;
				playercurrentcardsHolding++;
			}
			else
			{

				total += deck[decreaseDeck];
				playerSuit[i] = deckSuit[decreaseDeck];

				decreaseDeck--;

				playercurrentcardsHolding++;
			}


		}
		else // Then it is Infinite Deck
		{
			if (playerHand[i] == 1 && total < 11)// for a softHand ace is needed and total needs to be below 11 before ace 
			{
				softHand = true;
				playerHand[i] = 11;
				playerSuit[i] = deckSuit[decreaseDeck];
				total += 11;
				shuffle(deck, deckSuit);
				playercurrentcardsHolding++;
				playerindexAce = i;
			}
			else
			{
				total += deck[decreaseDeck];
				playerSuit[i] = deckSuit[decreaseDeck];
				shuffle(deck, deckSuit);
				playercurrentcardsHolding++;

			}





		}

	}

	//cout << playerHand[1]<< " " << playerSuit[1] <<endl;
	//cout << playerHand[2]<< " " << playerSuit[2] <<endl;
	//cout << "Total after initial phase  : " << total << endl;

	//to dealer
	for (int i = 1; i < 3; i++)
	{

		dealerHand[i] = deck[decreaseDeck];

		if (singleDeck == true)
		{
			if (dealerHand[i] == 1 && dealerTotal < 11) // if value is one then Ace
			{
				dsoftHand = true;
				dealerHand[i] = 11;// replace one with 11 
				dealerSuit[i] = deckSuit[decreaseDeck];
				dealerTotal += 11;
				dealerindexAce = i;
				decreaseDeck--;
				dealercardsHolding++;
			}
			else
			{

				dealerTotal += deck[decreaseDeck];
				dealerSuit[i] = deckSuit[decreaseDeck];

				decreaseDeck--;
				dealercardsHolding++;
			}


		}
		else // Then it is Infinite Deck
		{

			if (dealerHand[i] == 1 && dealerTotal < 11)// for a softHand ace is needed and total needs to be below 11 before ace 
			{
				dsoftHand = true;
				dealerHand[i] = 11;
				dealerSuit[i] = deckSuit[decreaseDeck];
				dealerTotal += 11;
				shuffle(deck, deckSuit);
				dealercardsHolding++;
				dealerindexAce = i;
			}
			else
			{
				dealerTotal += deck[decreaseDeck];
				dealerSuit[i] = deckSuit[decreaseDeck];
				shuffle(deck, deckSuit);
				dealercardsHolding++;
			}



		}

	}



	while (stick != true)
	{

		if (total >= 20)
			stick = true;
		else
		{

			if (singleDeck == true)
			{
				playercurrentcardsHolding++;
				playerHand[playercurrentcardsHolding] = deck[decreaseDeck];
				playerSuit[playercurrentcardsHolding] = deckSuit[decreaseDeck];


				if (playerHand[playercurrentcardsHolding] == 1 && total < 11)// softhand if it doesnt exceed 10 when drawing an ACE 
				{
					playerHand[playercurrentcardsHolding] = 11;
					total += 11;
					playerindexAce = playercurrentcardsHolding;
					softHand = true;
					//cout << "card drawn = " << playerHand[playercurrentcardsHolding] << " " << playerSuit[playercurrentcardsHolding] << endl;

				}
				else
				{
					total += deck[decreaseDeck];
					//cout << "card drawn = " << playerHand[playercurrentcardsHolding] << " " << playerSuit[playercurrentcardsHolding] << endl;
				}

				if (total > 21 && softHand == true) //check the the current hand isn't exceeding 21 while having soft hand, if so change ace to value
				{
					total -= 10;
					playerHand[playerindexAce] = 1; //set value back to one
					softHand = false;// softHand is now considered a hardHand
					//cout << "card drawn = " << playerHand[playercurrentcardsHolding] << " " << playerSuit[playercurrentcardsHolding] << endl;
				}

				decreaseDeck--;


			}
			else // Then it is Infinite Deck
			{

				playercurrentcardsHolding++;
				playerHand[playercurrentcardsHolding] = deck[decreaseDeck];
				playerSuit[playercurrentcardsHolding] = deckSuit[decreaseDeck];


				if (playerHand[playercurrentcardsHolding] == 1 && total < 11)// softhand if it doesnt exceed 10 when drawing an ACE 
				{
					playerHand[playercurrentcardsHolding] = 11;
					total += 11;
					playerindexAce = playercurrentcardsHolding;
					softHand = true;

				}
				else
				{
					total += deck[decreaseDeck];


				}

				if (total > 21 && softHand == true) //check the the current hand isn't exceeding 21 while having soft hand, if so change ace to value 1
				{
					//cout << "changed one ace from " << total;

					total -= 10;
					//cout << "\nto " << total << endl;
					playerHand[playerindexAce] = 1; //set value back to one
					softHand = false;// softHand is now considered a hardHand
				}

				shuffle(deck, deckSuit);


			}

		}
	}
	//cout << "after drawing cards " << total << endl;

	if (total > 21) //player loss no need for dealer to draw
	{
		//cout << "player loss, curren handd =" << total << endl;
		return 0;

	}
	// dealer keeps drawing if he does not have 17 or higher
	while (dealerTotal <= 16)
	{

		if (singleDeck == true)
		{
			dealercardsHolding++;
			dealerHand[dealercardsHolding] = deck[decreaseDeck];
			dealerSuit[dealercardsHolding] = deckSuit[decreaseDeck];
			dealerTotal += deck[decreaseDeck];



			if (dealerHand[dealercardsHolding] == 1 && dealerTotal < 11)// softhand if it doesnt exceed 10 when drawing an ACE 
			{
				dealerHand[dealercardsHolding] = 11;
				dealerTotal += 11;
				dealerindexAce = dealercardsHolding;
				dsoftHand = true;

			}
			else
			{
				dealerTotal += deck[decreaseDeck];
			}

			if (dealerTotal > 21 && dsoftHand == true) //check the the current hand isn't exceeding 21 while having soft hand, if so change ace to value 1
			{
				dealerTotal -= 10;
				dealerHand[playerindexAce] = 1; //set value back to one
				dsoftHand = false;// softHand is now considered a hardHand
			}

			decreaseDeck--;

		}
		else//infinite deck
		{

			dealercardsHolding++;
			dealerHand[dealercardsHolding] = deck[decreaseDeck];
			dealerSuit[dealercardsHolding] = deckSuit[decreaseDeck];


			if (dealerHand[dealercardsHolding] == 1 && dealerTotal < 11)// softhand if it doesnt exceed 10 when drawing an ACE 
			{
				dealerHand[dealercardsHolding] = 11;
				dealerTotal += 11;
				dealerindexAce = dealercardsHolding;
				dsoftHand = true;

			}
			else
			{
				dealerTotal += deck[decreaseDeck];


			}

			if (dealerTotal > 21 && dsoftHand == true) //check the the current hand isn't exceeding 21 while having soft hand, if so change ace to value 1
			{
				dealerTotal -= 10;
				dealerHand[dealerindexAce] = 1; //set value back to one
				dsoftHand = false;// softHand is now considered a hardHand
			}

			shuffle(deck, deckSuit);

		}


	}

	if (total == dealerTotal)
	{

		//cout << "A tie has occured player =  "  << total << "dealer= " << dealerTotal << endl;
		shuffle(deck, deckSuit);
		total = policy5(playerHand, playerSuit, deck, deckSuit, sizeofDeck, singleDeck);


		if (total == 1)
			return 1;
		else
			return 0;


	}



	if (dealerTotal > 21)
	{
		//cout << "dealer BUSTED, player Total  before display Hand " << total <<  "Amount of cards player holding = " << playercurrentcardsHolding << endl;
		//displayHands(playerHand, playerSuit, dealerHand, dealerSuit, playercurrentcardsHolding, dealercardsHolding);
		return 1; // dealers loss, so player wins
	}



	if (total > dealerTotal)
	{
		//cout << "player won, Total  before display Hand " << total << "Amount of cards player holding = " << playercurrentcardsHolding << endl;
		//displayHands(playerHand, playerSuit, dealerHand, dealerSuit, playercurrentcardsHolding, dealercardsHolding);
		return 1;
	}
	else if (dealerTotal > total)
	{
		//cout << "dealer beat your current hand\n";
		//cout << "dealer = " << dealerTotal << " player=" << total << endl;
		return 0;
	}



}










void displayHands(int playerHand[], string playerSuit[], int dealerHand[], string dealerSuit[], int playeramountofCards, int dealeramoundofCards)
{
	int total=0, dtotal=0;
	cout << "IN GAME : " << Game << endl << endl;

	cout << "\nPlayers current Winning hand : \n";
	for (int i = 1; i <= playeramountofCards; i++)
	{ 
		total += playerHand[i];
		cout << playerHand[i] << " " << playerSuit[i] << endl;
	}
	cout << "Total = " << total <<endl;
	

	cout << "\nDealers current hands \n";
	for (int i = 1; i <= dealeramoundofCards; i++)
	{
		dtotal += dealerHand[i];
		cout << dealerHand[i] << " " << dealerSuit[i] << endl;
	}

	cout << " dealers Total = " << dtotal << endl;




}