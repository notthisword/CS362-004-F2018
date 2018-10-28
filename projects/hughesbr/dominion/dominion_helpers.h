#ifndef _DOMINION_HELPERS_H
#define _DOMINION_HELPERS_H

#include "dominion.h"

int drawCard(int player, struct gameState *state);
int updateCoins(int player, struct gameState *state, int bonus);
int discardCard(int handPos, int currentPlayer, struct gameState *state, 
		int trashFlag);
int gainCard(int supplyPos, struct gameState *state, int toFlag, int player);
int getCost(int cardNumber);
int cardEffect(int card, int choice1, int choice2, int choice3, 
	       struct gameState *state, int handPos, int *bonus);
int card_adventurer(int cardDrawn, int currentPlayer, int drawntreasure, int z, struct gameState *state, int temphand[]);
void card_great_hall(int currentPlayer, struct gameState *state, int handPos);
void card_smithy(int currentPlayer, struct gameState *state, int handPos);
void card_village(int currentPlayer, struct gameState *state, int handPos);
void card_council_room(int currentPlayer, struct gameState *state, int handPos);

#endif
