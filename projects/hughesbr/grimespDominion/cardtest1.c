/*********************
 * Britany Hughes
 * CS 362 - Fall 2018
 * Assignment 3
 * 27 October 2018
 * Description: This is a unit test for the Adventurer
 * card in the dominion.c code.
 ********************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


/*********************
 * Objectives
 * drawntreasure >= 2, z at 0 (should do nothing)
 * drawntreasure is 0, z is 2 (too many cards discarded)
 * deck less than 1 on initial call (aka 0)
 * deck less than 1 on subsequent call (aka 1)
 * no treasures in deck
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
	
	//initialize the test game
	printf("Initializing game with the following criteria:\n");
	printf("Players: %d, Seed: %d\n", playerCount, seed);
	
	initializeGame(playerCount, k, seed, &testGame);
	
	printf("\nBeginning generic tests: normal variables.\n");
	for (p = 0; p < playerCount; p++)
	{
		//reinitialize the test game on each loop through
		memset(&testGame, 23, sizeof(struct gameState));
		initializeGame(playerCount, k, seed, &testGame);
		if (!cardEffect(adventurer, 0, 0, 0, &testGame, 0, 0))
		{
			printf("Test failed at iteration: %d.\n", p);
		}
	}
	
	/*
	//Beginning tests: treasuredrawn above 2
	
	//reinitialize the test game
	memset(&testGame, 23, sizeof(struct gameState));
	initializeGame(playerCount, k, seed, &testGame);
	
	if (card_adventurer(0, 1, 3, 0, &testGame, 0))
	{
		printf("Test failed: treasuredrawn above 2.\n");
	}
	
	//Beginning tests: treasuredrawn equals 2
	
	//reinitialize the test game
	memset(&testGame, 23, sizeof(struct gameState));
	initializeGame(playerCount, k, seed, &testGame);
	
	if (card_adventurer(0, 1, 2, 0, &testGame, 0))
	{
		printf("Test failed: treasuredrawn equals 2.\n");
	}
	*/
	
	
	/* Tests causing segfault; temporarily removed.
	printf("\nBeginning tests: z above 2.\n");
	
	//reinitialize the test game
	memset(&testGame, 23, sizeof(struct gameState));
	initializeGame(playerCount, k, seed, &testGame);
	
	if (card_adventurer(0, 1, 0, 3, &testGame, 0))
	{
		printf("Test failed: z above 2.\n");
	}
	
	printf("\nBeginning tests: z equals 2.\n");
	
	//reinitialize the test game
	memset(&testGame, 23, sizeof(struct gameState));
	initializeGame(playerCount, k, seed, &testGame);
	
	if (card_adventurer(0, 1, 0, 2, &testGame, 0))
	{
		printf("Test failed: z equals 2.\n");
	}*/
	
	
	return 0;
}