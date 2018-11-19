/*********************
 * Britany Hughes
 * CS 362 - Fall 2018
 * Assignment 3
 * 25 October 2018
 * Description: This is a unit test for the isGameOver function
 * in the dominion.c code.
*********************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

/*********************
 * Reference Data
 * int isGameOver(struct gameState *state)
 * 
*********************/

 bool assertEqual(int coinOne, int coinTwo)
 {
	 if (coinOne == coinTwo)
	 {
		 return true;
	 }
	 else
	 {
		 return false;
	 }
 }

/*********************
 * Objectives
 * Should return 0 if province not empty and not three supply
	piles empty
 * Should return 1 if province pile empty
 * Should return 1 if three supply piles empty
 *
*********************/

int main()
{
	//declare variables
	int k[10] = {adventurer, council_room, village, remodel, smithy, steward, great_hall, gardens, tribute, baron};
	struct gameState testGame;
	int playerCount = 4;
	int seed = 193;
	int result = -5;
	
	//declare our flags
	bool provFlag = false;
	
	//initialize counters
	int i = 0; //loop counter
	
	//initialize the test game
	printf("Initializing game with the following criteria:");
	printf("Players: %d, Seed: %d", playerCount, seed);
	
	initializeGame(playerCount, k, seed, &testGame);
	
	printf("\nBeginning tests...\n");
	
	
	/* Province Cards at 0 */
	
	//test with 0 Province cards in the supply pile
	testGame.supplyCount[province] = 0;
	result = isGameOver(&testGame);
	provFlag = assertEqual(1, result);
	if (!provFlag)
	{
		printf("Test Failed: Did not end game with 0 province cards in supply.\n");
	}
	
	
	printf("\nNote: A false positive might be received on some of the following\ntests due to not checking if the card is Province or not.\n");
	
	
	/* Three Supply cards at 0 */
	
	
	//value is 23 because 25 kingdom cards
	//we want 23 as max because i, i+1, i+2
	for (i = 0; i < 23; i++)
	{
		//reinitialize the test game on each loop through
		memset(&testGame, 23, sizeof(struct gameState));
		initializeGame(playerCount, k, seed, &testGame);
		
		testGame.supplyCount[i] = 0;
		testGame.supplyCount[i+1] = 0;
		testGame.supplyCount[i+2] = 0;
		
		result = isGameOver(&testGame);
		provFlag = assertEqual(1, result);
		if (!provFlag)
		{
			printf("Test %d Failed: Did not end game with three supply cards at 0.\n", i+1);
		}
	}
	
	
	/* Two Supply cards at 0 */
	
	
	//value is 24 because 25 kingdom cards
	//we want 24 as max because i, i+1
	for (i = 0; i < 24; i++)
	{
		//reinitialize the test game on each loop through
		memset(&testGame, 23, sizeof(struct gameState));
		initializeGame(playerCount, k, seed, &testGame);
		
		testGame.supplyCount[i] = 0;
		testGame.supplyCount[i+1] = 0;
		
		result = isGameOver(&testGame);
		provFlag = assertEqual(0, result);
		if (!provFlag)
		{
			printf("Test %d Failed: Ended game when only two supply cards were at 0.\n", i+1);
		}
	}
	
	
	/* One Supply card at 0 */
	//value is 25 because 25 kingdom cards
	//we want 25 as max because i
	for (i = 0; i < 25; i++)
	{
		//reinitialize the test game on each loop through
		memset(&testGame, 23, sizeof(struct gameState));
		initializeGame(playerCount, k, seed, &testGame);
		
		testGame.supplyCount[i] = 0;
		
		result = isGameOver(&testGame);
		provFlag = assertEqual(0, result);
		if (!provFlag)
		{
			printf("Test %d Failed: Ended game when only one supply card was at 0.\n", i+1);
		}
	}
	
	
	/* No cards at 0 */
	
	//reinitialize the test game
	memset(&testGame, 23, sizeof(struct gameState));
	initializeGame(playerCount, k, seed, &testGame);
	
	result = isGameOver(&testGame);
	provFlag = assertEqual(0, result);
	if (!provFlag)
	{
		printf("Test %d Failed: Ended game when no supply cards were at 0.\n", i+1);
	}
	
	return 0;
}