/*********************
 * Britany Hughes
 * CS 362 - Fall 2018
 * Assignment 4
 * 7 November 2018
 * Description: This is a random tester for the Smithy card in
 * the dominion.c code.
 ********************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

/*********************
 * Reference Data
 * card_smithy(int currentPlayer, struct gameState *state,
		int handPos)
 * cardEffect(int card, int choice1, int choice2, int
		choice3, struct gameState *state, int handPos
		int *bonus)
 * drawCard(int player, struct gameState *state)
 * drawCard(currentPlayer, state)
 * discardCard(int handPos, int currentPlayer, struct
		gameState *state, int trashFlag)
 * discardCard(handPos, currentPlayer, state, 0)
 * int handCard(int handPos, struct gameState *state)
 * card = handCard(handPos, state)
 * int numHandCards(struct gameState *state)
 * 
 ********************/
 
 
 
 int main()
{
	//declare variables
	int k[10] = {adventurer, council_room, village, remodel, smithy, steward, great_hall, gardens, tribute, baron};
	struct gameState testGame;
	int playerCount = 4;
	int seed = 193;
	int tempCard = 0;

	//initialize counters
	int p = 0; //player
	int h = 0; //total cards in hand
	int d = 0; //deck count
	int c = 0;
	
	printf("Beginning tests for Smithy card.\n\n");
	
	//100 is an arbitrary value; can be changed
	for (c = 0; c < 25; c++)
	{
		//minimum player count is 2
		//Note: rand() % (max - min + 1) + min
		seed = rand() % (999 - 1 + 1) + 999;
		playerCount = rand() % (MAX_PLAYERS - 2 + 1) + 2;
		
		//initialize the test game
		initializeGame(playerCount, k, seed, &testGame);
		
		for (p = 0; p < playerCount; p++)
		{
			//reinitialize the test game on each loop through
			memset(&testGame, 23, sizeof(struct gameState));
			initializeGame(playerCount, k, seed, &testGame);
			
			if (!cardEffect(smithy, 0, 0, 0, &testGame, 0, 0))
			{
				printf("Test failed with the following criteria on Test %d:\n", c+1);
				printf("Player %d of %d, Seed: %d\n", p+1, playerCount, seed);
			}
		}
	}
	
	//Beginning tests: is smithy card discarded.
	//reinitialize the test game
	memset(&testGame, 23, sizeof(struct gameState));
	initializeGame(playerCount, k, seed, &testGame);
	p = 0;
	
	//set all of the cards in the player's deck to something other than smithy
	d = testGame.deckCount[p];
	for (c = 1; c < d; c++)
	{
		tempCard = 13; //13 is smithy card in enum list
		do 
		{
			//Note: rand() % (max - min + 1) + min
			tempCard = rand() % (26 - 0 + 1) + 0;
		}while (tempCard == 13);
		testGame.deck[p][c] = tempCard;
	}
	
	//set all of the cards in the player's hand to something other than smithy except for one
	h = numHandCards(&testGame);
	testGame.hand[p][0] = smithy;
	for (c = 1; c < h; c++)
	{
		tempCard = 13; //13 is smithy card in enum list
		do 
		{
			//Note: rand() % (max - min + 1) + min
			tempCard = rand() % (26 - 0 + 1) + 0;
		}while (tempCard == 13);
		testGame.hand[p][c] = tempCard;
	}
	
	cardEffect(smithy, 0, 0, 0, &testGame, 0, 0);
	
	//check to see if any of the cards in the hand is the smithy card
	h = numHandCards(&testGame);
	for (c = 0; c < h; c++)
	{
		if (testGame.hand[p][c] == smithy)
		{
			printf("Test failed: Smithy card was not discarded.\n");
		}
	}
	
	printf("\nTests completed for Smithy card.\n\n");
};