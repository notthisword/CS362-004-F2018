/*********************
 * Britany Hughes
 * CS 362 - Fall 2018
 * Assignment 3
 * 27 October 2018
 * Description: This is a unit test for the Great_Hall card
 * in the dominion.c code.
 ********************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
 * 
 ********************/
 
 
 /*********************
 * Objectives
 * Should increase hand by 1
 * Should increase actions by 1
 * Verify card is discarded at end
 ********************/
 
int main()
{
	//declare variables
	int k[10] = {adventurer, council_room, village, remodel, smithy, steward, great_hall, gardens, tribute, baron};
	struct gameState testGame;
	int playerCount = 4;
	int seed = 193;
	
	//initialize counters
	int p = 0; //player
	int c = 0; //counter
	int h = 0; //total cards in hand
	int d = 0; //deck count
	int a = 0; //number of actions
	
	//initialize the test game
	printf("Initializing game with the following criteria:\n");
	printf("Players: %d, Seed: %d\n", playerCount, seed);
	
	initializeGame(playerCount, k, seed, &testGame);
	
	printf("\nBeginning generic tests: normal variables, no crashes.\n");
	for (p = 0; p < playerCount; p++)
	{
		//reinitalize the test game on each loop through
		memset(&testGame, 23, sizeof(struct gameState));
		initializeGame(playerCount, k, seed, &testGame);
		if (!cardEffect(great_hall, 0, 0, 0, &testGame, 0, 0))
		{
			printf("Test failed at iteration: %d.\n", p);
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
		testGame.deck[p][c] = gold;
	}
	//set all of the cards in the player's hand to something other than great_hall except for one
	h = numHandCards(&testGame);
	testGame.hand[p][0] = great_hall;
	for (c = 1; c < h; c++)
	{
		testGame.hand[p][c] = gold;
	}
	
	cardEffect(great_hall, 0, 0, 0, &testGame, 0, 0);
	
	//check to see if any of the cards in the hand is the great_hall
	h = numHandCards(&testGame);
	for (c = 0; c < h; c++)
	{
		if (testGame.hand[p][c] == great_hall)
		{
			printf("Test failed: Great Hall card was not discarded.\n");
		}
	}
	
	
	//Beginning tests: draw a card
	//reinitialize the test game
	memset(&testGame, 23, sizeof(struct gameState));
	initializeGame(playerCount, k, seed, &testGame);
	p = 0;
	d = testGame.deckCount[p];
	h = numHandCards(&testGame);
	
	//set one of the cards to great_hall
	testGame.hand[p][0] = great_hall;
	
	cardEffect(great_hall, 0, 0, 0, &testGame, 0, 0);
	//increase h by the number of cards drawn minus one for the discarded great_hall card (1 - 1 = 0)
	h += 0;
	if (h != numHandCards(&testGame))
	{
		printf("Test failed; number of cards was not correct after draw and discard.\n");
	}
	
	
	//Beginning tests: extra action
	//reinitialize the test game
	memset(&testGame, 23, sizeof(struct gameState));
	initializeGame(playerCount, k, seed, &testGame);
	p = 0;
	d = testGame.deckCount[p];
	a = testGame.numActions;
	
	//set one of the cards to great_hall
	testGame.hand[p][0] = great_hall;
	
	cardEffect(great_hall, 0, 0, 0, &testGame, 0, 0);
	
	//increase a by the number of actions gained minus the one used to play the great_hall card (1 - 1 = 0)
	a += 0;
	if (a != testGame.numActions)
	{
		printf("Test failed: number of actions was not correct after card usage.\n");
	}
	
	
	return 0;
}