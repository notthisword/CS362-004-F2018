/*********************
 * Britany Hughes
 * CS 362 - Fall 2018
 * Assignment 3
 * 24 October 2018
 * Description: This is a unit test for the getCost function
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
 * int getCost(int cardNumber)
 * 
 * -1: default/error
 *  0: copper, curse
 *  1: 
 *  2: embargo, estate
 *  3: ambassador, great_hall, silver, steward, village
 *  4: baron, cutpurse, feast, gardens, remodel, 
 * 		salvager, sea_hag, smithy, treasure_map
 *  5: council_room, duchy, mine, minion, outpost, tribute
 *  6: adventurer, gold
 *  7: 
 *  8: province
 ********************/
 
 
 void costCheck(int card, int expected)
 {
	int test = getCost(card);
	if (test != expected)
	{
		printf("Test failed; expected %d for card %d. Returned value was %d.\n", expected, card, test);
	}
 }

/*********************
 * Objectives
 * Nonexistent card returns -1
 * Cards return appropriate cost values
 *
 ********************/

int main()
{
	//declare variables
	int expected = -4;
	
	printf("\nBeginning cost check verification tests.\n");

	
	/* Testing Cards with a Cost of 0 */
	expected = 0;
	
	//test copper
	costCheck(copper, expected);
	//test curse
	costCheck(curse, expected);
	
	
	/* Testing Cards with a Cost of 1 */
	expected = 1;
	//no cards with this cost currently exist
	
	
	/* Testing Cards with a Cost of 2 */
	expected = 2;
	
	//test embargo
	costCheck(embargo, expected);
	//test estate
	costCheck(estate, expected);
	
	
	/* Testing Cards with a Cost of 3 */
	expected = 3;
	
	//test ambassador
	costCheck(ambassador, expected);
	
	//test great_hall
	costCheck(great_hall, expected);
	
	//test silver
	costCheck(silver, expected);
	
	//test steward
	costCheck(steward, expected);
	
	//test village
	costCheck(village, expected);

	
	
	/* Testing Cards with a Cost of 4 */
	expected = 4;
	
	//test baron
	costCheck(baron, expected);
	
	//test cutpurse
	costCheck(cutpurse, expected);
	
	//test feast
	costCheck(feast, expected);
	
	//test gardens
	costCheck(gardens, expected);
	
	//test remodel
	costCheck(remodel, expected);
	
	//test salvager
	costCheck(salvager, expected);
	
	//test sea_hag
	costCheck(sea_hag, expected);
	
	//test smithy
	costCheck(smithy, expected);
	
	//test treasure_map
	costCheck(treasure_map, expected);
	
	
	/* Testing Cards with a Cost of 5 */
	expected = 5;
	
	//test council_room
	costCheck(council_room, expected);
	
	//test duchy
	costCheck(duchy, expected);
	
	//test mine
	costCheck(mine, expected);
	
	//test minion
	costCheck(minion, expected);
	
	//test outpost
	costCheck(outpost, expected);
	
	//test tribute
	costCheck(tribute, expected);
	
	
	
	/* Testing Cards with a Cost of 6 */
	expected = 6;
	
	//test adventurer
	costCheck(adventurer, expected);
	
	//test gold
	costCheck(gold, expected);
	
	
	/* Testing Cards with a Cost of 7 */
	expected = 7;
	//no cards with this cost currently exist
	
	
	/* Testing Cards with a Cost of 8 */
	expected = 8;
	
	//test province
	costCheck(province, expected);
	
	printf("\nIf no errors above, all tests passed.\n");
	
	return 0;
}