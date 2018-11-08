/*********************
 * Britany Hughes
 * CS 362 - Fall 2018
 * Assignment 4
 * 7 November 2018
 * Description: This is a random tester for the Adventurer card in
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
 * card_adventurer(int cardDrawn, int currentPlayer, int
		drawntreasure, int z, struct gameState *state, 
		int temphand[]
 * cardEffect(int card, int choice1, int choice2, int
		choice3, struct gameState *state, int handPos
		int *bonus)
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
	
	printf("Beginning tests for Adventurer card.\n\n");
	
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
			
			if (!cardEffect(adventurer, 0, 0, 0, &testGame, 0, 0))
			{
				printf("Test failed with the following criteria on Test %d:\n", c+1);
				printf("Player %d of %d, Seed: %d\n", p+1, playerCount, seed);
			}
		}
	}
	
	//Beginning tests: is adventurer card discarded.
	//reinitialize the test game
	memset(&testGame, 23, sizeof(struct gameState));
	initializeGame(playerCount, k, seed, &testGame);
	p = 0;
	
	//set all of the cards in the player's deck to something other than adventurer
	d = testGame.deckCount[p];
	for (c = 1; c < d; c++)
	{
		int tempCard = 7; //7 is adventurer card in enum list
		do 
		{
			//Note: rand() % (max - min + 1) + min
			tempCard = rand() % (26 - 0 + 1) + 0;
		}while (tempCard == 7);
		testGame.deck[p][c] = tempCard;
	}
	
	
	//set all of the cards in the player's hand to something other than adventurer except for one
	h = numHandCards(&testGame);
	testGame.hand[p][0] = adventurer;
	for (c = 1; c < h; c++)
	{
		tempCard = 7; //7 is adventurer card in enum list
		do 
		{
			//Note: rand() % (max - min + 1) + min
			tempCard = rand() % (26 - 0 + 1) + 0;
		}while (tempCard == 7);
		testGame.hand[p][c] = tempCard;
	}
	
	cardEffect(adventurer, 0, 0, 0, &testGame, 0, 0);
	
	//check to see if any of the cards in the hand is the adventurer card
	h = numHandCards(&testGame);
	for (c = 0; c < h; c++)
	{
		if (testGame.hand[p][c] == adventurer)
		{
			printf("Test failed: Adventurer card was not discarded.\n");
		}
	}
	
	printf("\nTests completed for Adventurer card.\n\n");
};