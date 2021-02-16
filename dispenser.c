#include "dispenser.h"
#include "vending.h"
#include "cashregister.h"

int getCount(int selected, int quantity) {
	//read inventory.txt
	invChange = fopen("inventory.txt", "w");
	//cases from selected
	switch(selected) {
		case 1 :	if(inv[0].numberOfItems != 0 && inv[0].numberOfItems >= quantity) {
						inv[0].numberOfItems = inv[0].numberOfItems - quantity;
						//rewrite file ; change inventory 
						fprintf(invChange, "\n%i\n", inv[0].numberOfItems);
						fprintf(invChange, "%i\n", inv[1].numberOfItems);
						fprintf(invChange, "%i\n", inv[2].numberOfItems);
						fprintf(invChange, "%i\n", inv[3].numberOfItems);
						//proceed to getProductCost()
						getProductCost(inv[0].cost, quantity);
					} else if(inv[0].numberOfItems != 0 && inv[0].numberOfItems < quantity) {
						printf("Sorry! The dispenser does not have enough of this item (%s)\nto meet the quantity you have inputted. Please try again.\n", inv[0].nameOfItem);
						tryAgain();
					} else if(inv[0].numberOfItems == 0){
						printf("Sorry! This item (%s) is no longer available.\n", inv[0].nameOfItem);
						tryAgain();
					}
					break;
		case 2 :	if(inv[1].numberOfItems != 0 && inv[1].numberOfItems >= quantity) {
						inv[1].numberOfItems = inv[1].numberOfItems - quantity;
						//rewrite file ; change inventory 
						fprintf(invChange, "\n%i\n", inv[0].numberOfItems);
						fprintf(invChange, "%i\n", inv[1].numberOfItems);
						fprintf(invChange, "%i\n", inv[2].numberOfItems);
						fprintf(invChange, "%i\n", inv[3].numberOfItems);
						//proceed to getProductCost()
						getProductCost(inv[1].cost, quantity);
					} else if(inv[1].numberOfItems != 0 && inv[1].numberOfItems < quantity) {
						printf("Sorry! The dispenser does not have enough of this item (%s)\nto meet the quantity you have inputted. Please try again.\n", inv[1].nameOfItem);
						tryAgain();
					} else if(inv[1].numberOfItems == 0){
						printf("Sorry! This item (%s) is no longer available.\n", inv[1].nameOfItem);
						tryAgain();
					}
					break;
		case 3 :	if(inv[2].numberOfItems != 0 && inv[2].numberOfItems >= quantity) {
						inv[2].numberOfItems = inv[2].numberOfItems - quantity;
						//rewrite file ; change inventory
						fprintf(invChange, "\n%i\n", inv[0].numberOfItems);
						fprintf(invChange, "%i\n", inv[1].numberOfItems);
						fprintf(invChange, "%i\n", inv[2].numberOfItems);
						fprintf(invChange, "%i\n", inv[3].numberOfItems);
						fprintf(invChange, "%i\n", inv[2].numberOfItems);
						//proceed to getProductCost()
						getProductCost(inv[2].cost, quantity);
					} else if(inv[2].numberOfItems != 0 && inv[2].numberOfItems < quantity) {
						printf("Sorry! The dispenser does not have enough of this item (%s)\nto meet the quantity you have inputted. Please try again.\n", inv[2].nameOfItem);
						tryAgain();
					} else if(inv[2].numberOfItems == 0){
						printf("Sorry! This item (%s) is no longer available.\n", inv[2].nameOfItem);
						tryAgain();
					}
					break;
		case 4 :	if(inv[3].numberOfItems != 0 && inv[3].numberOfItems >= quantity) {
						inv[3].numberOfItems = inv[3].numberOfItems - quantity;
						//rewrite file ; change inventory
						fprintf(invChange, "\n%i\n", inv[0].numberOfItems);
						fprintf(invChange, "%i\n", inv[1].numberOfItems);
						fprintf(invChange, "%i\n", inv[2].numberOfItems);
						fprintf(invChange, "%i\n", inv[3].numberOfItems);
						fprintf(invChange, "%i\n", inv[3].numberOfItems);
						//proceed to getProductCost()
						getProductCost(inv[3].cost, quantity);
					} else if(inv[3].numberOfItems != 0 && inv[3].numberOfItems < quantity) {
						printf("Sorry! The dispenser does not have enough of this item (%s)\nto meet the quantity you have inputted. Please try again.\n", inv[3].nameOfItem);
						tryAgain();
					} else if(inv[3].numberOfItems == 0){
						printf("Sorry! This item (%s) is no longer available.\n", inv[3].nameOfItem);
						tryAgain();
					}
					break;
	}
	//close inventory.txt
	fclose(invChange);
	//return 0 to exit
	return 0;
}

int getProductCost (int cost, int quantity) {
	int totalCost;
	//Get total cost by multiplying cost with quantity
	totalCost = cost*quantity;
	makeSale(totalCost);
	//return 0 to exit
	return 0;
}

int makeSale(int totalCost) {
	//proceeds to currentBalance()
	currentBalance(0, totalCost);
	//return 0 to exit
	return 0;
}
