/*********************
 * Britany Hughes
 * CS 362 - Fall 2018
 * Assignment 3
 * 24 October 2018
 * Description: This is a unit test for the updateCoins
 * function in the dominion.c code.
 ********************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

/*********************
 * Reference Data
 * int updateCoins(int player, struct gameState *state,
	int bonus)
 * int initializeGame(int numPlayers, int kingdomCards[10],
	int randomSeed, struct gameState *state)
 * 
 ********************/

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
 * Copper adds 1
 * Silver adds 2
 * Gold adds 3
 * bonus is added
 ********************/

int main()
{
	//declare variables
	int k[10] = {adventurer, council_room, village, remodel, smithy, steward, great_hall, gardens, tribute, baron};
	struct gameState testGame;
	int playerCount = 4;
	int seed = 193;
	int maxBonus = 10;
	int coinTotal = 0;
	
	//declare our flags
	bool assertBool = false;
	bool randClearFlag = true;
	bool copperClearFlag = true;
	bool silverClearFlag = true;
	bool goldClearFlag = true;
	
	//create the arrays for the static tests
	int randHand[MAX_HAND];
	int copperHand[MAX_HAND];
	int silverHand[MAX_HAND];
	int goldHand[MAX_HAND];
	
	//initialize counters
	int p = 0; //player
	int h = 0; //hand
	int b = 0; //bonus
	int randHandCount = 0;
	int counter = 0;
	
	//Note: Slot 0 is copper, 1 is silver and 2 is gold
	int coinCount[3] = {0};
	
	//setup the arrays for the hands that are all one coin
	for (counter = 0; counter < MAX_HAND; counter++)
	{
		copperHand[counter] = copper;
		silverHand[counter] = silver;
		goldHand[counter] = gold;
	}
	
	//initialize the test game
	printf("Initializing game with the following criteria:\n");
	printf("Players: %d, Seed: %d\n", playerCount, seed);
	
	initializeGame(playerCount, k, seed, &testGame);
	
	printf("\nBeginning randomized tests. MAX_HAND is set to %d...\n", MAX_HAND);
	for (p = 0; p < playerCount; p++)
	{
		for (h = 1; h <= MAX_HAND; h++)
		{
			for (b = 0; b <= maxBonus; b++)
			{
				//reinitialize the test game on each loop through
				memset(&testGame, 23, sizeof(struct gameState));
				initializeGame(playerCount, k, seed, &testGame);
				testGame.handCount[p] = h;
				
				coinTotal = 0;
				randHandCount = MAX_HAND;
				coinCount[0] = rand() % randHandCount + 1;
				randHandCount -= coinCount[0];
				//make sure no divide by zero issues
				if (randHandCount == 0)
				{
					coinCount[1] = 0;
					coinCount[2] = 0;
				}
				else
				{
					coinCount[1] = rand() % randHandCount + 1;
					randHandCount -= coinCount[1];
					coinCount[2] = randHandCount;
				}
				
				//fill randHand with the proper coins
				counter = 0;
				if (coinCount[0] > 0)
				{
					for (counter = 0; counter < coinCount[0]; counter++)
					{
						randHand[counter] = copper;
					}
				}
				if (coinCount[1] > 0)
				{
					for (counter = 0; counter < (coinCount[1] + coinCount[0]); counter++)
					{
						randHand[counter] = silver;
					}
				}
				if (coinCount[2] > 0)
				{
					for (counter = 0; counter < MAX_HAND; counter++)
					{
						randHand[counter] = gold;
					}
				}
				
				//copy randHand into the player's hand
				memcpy(testGame.hand[p], randHand, sizeof(int) * randHandCount);
				
				//calculate the total
				coinTotal = ( (1 * coinCount[0]) + (2 * coinCount[1]) + (3 * coinCount[2]) + b);
				
				//call the updateCoins function
				updateCoins(p, &testGame, b);
				
				//call our assert function
				assertBool = assertEqual(testGame.coins, coinTotal);
				
				//print the results if false
				if (assertBool == false)
				{
					printf("Testing with %d copper coins, %d silver coins and %d gold coins: FAILED.\n", coinCount[0], coinCount[1], coinCount[2]);
					randClearFlag = false;
				}
			}
		}
	}
	
	printf("\nConcluded randomized tests. MAX_HAND is set to %d...\n", MAX_HAND);
	
	
	printf("\nBeginning static tests...\n");
				
	for (p = 0; p < playerCount; p++)
	{
		for (h = 1; h <= MAX_HAND; h++)
		{
			for (b = 0; b <= maxBonus; b++)
			{
				/* start the code for copper here */
				
				//reinitialize the test game on each loop through
				memset(&testGame, 23, sizeof(struct gameState));
				initializeGame(playerCount, k, seed, &testGame);
				testGame.handCount[p] = h;
				
				//copy the copper hand into the player's hand
				memcpy(testGame.hand[p], copperHand, sizeof(int)*h);
				
				//call the updateCoins function
				updateCoins(p, &testGame, b);
				
				//calculate the total
				coinTotal = 1 * h + b;
				
				//call our assert function
				assertBool = assertEqual(testGame.coins, coinTotal);
				
				//print the results if false
				if (assertBool == false)
				{
					printf("Testing with all copper coins: FAILED.\n");
					copperClearFlag = false;
				}
				
				
				/* start the code for silver here */
				
				
				//reinitialize the test game on each loop through
				memset(&testGame, 23, sizeof(struct gameState));
				initializeGame(playerCount, k, seed, &testGame);
				testGame.handCount[p] = h;
				
				//copy the silver hand into the player's hand
				memcpy(testGame.hand[p], silverHand, sizeof(int)*h);
				
				//call the updateCoins function
				updateCoins(p, &testGame, b);
				
				//calculate the total
				coinTotal = 2 * h + b;
				
				//call our assert function
				assertBool = assertEqual(testGame.coins, coinTotal);
				
				//print the results if false
				if (assertBool == false)
				{
					printf("Testing with all silver coins: FAILED.\n");
					silverClearFlag = false;
				}
				
				
				/* start the code for gold here */
				
				
				//reinitialize the test game on each loop through
				memset(&testGame, 23, sizeof(struct gameState));
				initializeGame(playerCount, k, seed, &testGame);
				testGame.handCount[p] = h;
				
				//copy the silver hand into the player's hand
				memcpy(testGame.hand[p], goldHand, sizeof(int)*h);
				
				//call the updateCoins function
				updateCoins(p, &testGame, b);
				
				//calculate the total
				coinTotal = 3 * h + b;
				
				//call our assert function
				assertBool = assertEqual(testGame.coins, coinTotal);
				
				//print the results if false
				if (assertBool == false)
				{
					printf("Testing with all gold coins: FAILED.\n");
					goldClearFlag = false;
				}
			}
		}
	}
	
	if (randClearFlag && copperClearFlag && silverClearFlag && goldClearFlag)
	{
		printf("\nAll tests passed.\n");
	}
	else if (copperClearFlag && silverClearFlag && goldClearFlag)
	{
		printf("\nAll static tests passed.\n");
	}
	
	return 0;
}