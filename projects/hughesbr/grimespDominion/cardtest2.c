/*********************
 * Britany Hughes
 * CS 362 - Fall 2018
 * Assignment 3
 * 27 October 2018
 * Description: This is a unit test for the Smithy card
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
 
 
 /*********************
 * Objectives
 * Player hand goes up by 3 cards
 * Smithy card is discarded
 * 
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
		if (!cardEffect(smithy, 0, 0, 0, &testGame, 0, 0))
		{
			printf("An error occurred at Iteration %d.\n", p);
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
		testGame.deck[p][c] = gold;
	}
	//set all of the cards in the player's hand to something other than smithy except for one
	h = numHandCards(&testGame);
	testGame.hand[p][0] = smithy;
	for (c = 1; c < h; c++)
	{
		testGame.hand[p][c] = gold;
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
	
	//Beginning tests: draw three cards.
	//reinitialize the test game
	memset(&testGame, 23, sizeof(struct gameState));
	initializeGame(playerCount, k, seed, &testGame);
	p = 0;
	d = testGame.deckCount[p];
	h = numHandCards(&testGame);
	
	//set one of the cards to smithy
	testGame.hand[p][0] = smithy;
	
	cardEffect(smithy, 0, 0, 0, &testGame, 0, 0);
	//increase h by the number of cards drawn minus one for the discarded smithy card (3 - 1 = 2)
	h += 2;
	if (h != numHandCards(&testGame))
	{
		printf("Test failed; number of cards was not correct after draw and discard.\n");
	}


	return 0;
 }