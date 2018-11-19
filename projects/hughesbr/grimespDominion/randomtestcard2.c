/*********************
 * Britany Hughes
 * CS 362 - Fall 2018
 * Assignment 4
 * 7 November 2018
 * Description: This is a random tester for the Great Hall card in
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
 * card_great_hall(int currentPlayer, struct gameState
		*state, int handPos)
 * cardEffect(int card, int choice1, int choice2, int
		choice3, struct gameState *state, int handPos
		int *bonus)
 * drawCard(int player, struct gameState *state)
 * drawCard(currentPlayer, state)
 * testGame.numActions++
 * discardCard(int handPos, int currentPlayer, struct
		gameState *state, int trashFlag)
 * discardCard(handPos, currentPlayer, state, 0)
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
	int c = 0;
	int h = 0; //total cards in hand
	int d = 0; //deck count
	
	printf("Beginning tests for Great Hall card.\n\n");
	
	//100 is an arbitrary value; can be changed
	for (c = 0; c < 100; c++)
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
			
			if (!cardEffect(great_hall, 0, 0, 0, &testGame, 0, 0))
			{
				printf("Test failed with the following criteria on Test %d:\n", c+1);
				printf("Player %d of %d, Seed: %d\n", p+1, playerCount, seed);
			}
		}
	}
	
	//Beginning tests: is great_hall card discarded.
	//reinitialize the test game
	memset(&testGame, 23, sizeof(struct gameState));
	initializeGame(playerCount, k, seed, &testGame);
	p = 0;
	
	//set all of the cards in the player's deck to something other than great_hall
	d = testGame.deckCount[p];
	for (c = 1; c < d; c++)
	{
		int tempCard = 16; //16 is great_hall card in enum list
		do 
		{
			//Note: rand() % (max - min + 1) + min
			tempCard = rand() % (26 - 0 + 1) + 0;
		}while (tempCard == 16);
		testGame.deck[p][c] = tempCard;
	}
	
	//set all of the cards in the player's hand to something other than great_hall except for one
	h = numHandCards(&testGame);
	testGame.hand[p][0] = great_hall;
	for (c = 1; c < h; c++)
	{
		tempCard = 16; //16 is great_hall card in enum list
		do 
		{
			//Note: rand() % (max - min + 1) + min
			tempCard = rand() % (26 - 0 + 1) + 0;
		}while (tempCard == 16);
		testGame.hand[p][c] = tempCard;
	}
	
	cardEffect(great_hall, 0, 0, 0, &testGame, 0, 0);
	
	//check to see if any of the cards in the hand is the great_hall card
	h = numHandCards(&testGame);
	for (c = 0; c < h; c++)
	{
		if (testGame.hand[p][c] == great_hall)
		{
			printf("Test failed: Great Hall card was not discarded.\n");
		}
	}
	
	printf("\nTests completed for Great Hall card.\n\n");
};