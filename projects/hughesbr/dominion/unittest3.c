/*********************
 * Britany Hughes
 * CS 362 - Fall 2018
 * Assignment 3
 * 24 October 2018
 * Description: This is a unit test for the kingdomCards
 * function in the dominion.c code.
 ********************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

/*********************
 * Reference Data
 * int* kingdomCards(int k1, int k2, int k3, int k4, int k5, int k6,
	int k7, int k8, int k9, int k10)
 * 
 * Kingdom Cards: 
 * adventurer, ambassador, baron
 * council_room, cutpurse, embargo
 * feast, gardens, great_hall
 * mine, minion, outpost, remodel
 * salvager, sea_hag, smithy, steward
 * treasure_map, tribute, village
 ********************/

int cardSwitch(int card)
{
	switch (card)
	{
		case 0: 
			card = adventurer;
			return card;
		case 1: 
			card = ambassador;
			return card;
		case 2: 
			card = baron;
			return card;
		case 3: 
			card = council_room;
			return card;
		case 4: 
			card = cutpurse;
			return card;
		case 5: 
			card = embargo;
			return card;
		case 6: 
			card = feast;
			return card;
		case 7: 
			card = gardens;
			return card;
		case 8: 
			card = great_hall;
			return card;
		case 9: 
			card = mine;
			return card;
		case 10: 
			card = minion;
			return card;
		case 11: 
			card = outpost;
			return card;
		case 12: 
			card = remodel;
			return card;
		case 13: 
			card = salvager;
			return card;
		case 14: 
			card = sea_hag;
			return card;
		case 15: 
			card = smithy;
			return card;
		case 16: 
			card = steward;
			return card;
		case 17: 
			card = treasure_map;
			return card;
		case 18: 
			card = tribute;
			return card;
		case 19: 
			card = village;
			return card;
	}
	
	return -1;
}

/*********************
 * Objectives
 * Duplicate kingdom cards should return an error
 * Should require exactly 10 cards: not more, not less
 * Should return an error if card does not exist
 ********************/
 
 int main()
{
	//declare variables
	int total = 20; //total number of Kingdom cards
	int c; //the current card
	int ALPHABET = -3; //variable to mess with kingdom call function
	
	//declare the array
	int* k;
	
	//declare and initialize the counter
	int i = 0;
	
	//Duplicate cards return an error
	for (i = 0; i < total; i++)
	{
		c = cardSwitch(i);
		k = kingdomCards(c, c, c, c, c, c, c, c, c, c);
		
		if (*k == -1)
		{
			printf("Duplicate kingdom cards did not return an error for card %d.\n", c);
		}
	}
	
	/* COMPILER PREVENTED ERROR
	
	//More than 10 cards returns an error
	
	k = kingdomCards(adventurer, tribute, village, treasure_map, sea_hag, smithy, mine, minion, gardens, embargo, council_room);
	
	assert(k == -1);
	
	//Less than 10 cards returns an error
	
	k = kingdomCards(adventurer, tribute, village, treasure_map, sea_hag, smithy, mine, minion);
	
	assert(k == -1);
	
	COMPILER PREVENTED ERROR */
	
	
	//Returns an error if the card does not exist
	
	k = kingdomCards(adventurer, tribute, village, treasure_map, sea_hag, smithy, mine, minion, ALPHABET, council_room);
	
	if (*k != -1)
	{
		printf("Kingdom card initiatlization did not return error with bad card.\n");
	}
	
	//Returns an error if a non-kingdom card is provided
	
	k = kingdomCards(adventurer, tribute, village, treasure_map, sea_hag, smithy, mine, minion, silver, council_room); //silver
	
	if (*k != -1)
	{
		printf("Kingdom card initialization did not return an error with a non-kingdom card.\n");
	}
	
	return 0;
}