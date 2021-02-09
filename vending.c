#include "vending.h"
#include "dispenser.h"

//------------

int main() {
	int selection, i = 0;
	char text[100];
	//
	invRead = fopen("inventory.txt", "r");
	//
	if(invRead == NULL) {
		printf("Error");
		return -1;
	}
	//
	
	strcpy(inv[0].nameOfItem, "candies");
	inv[0].cost = 10;
	//
	strcpy(inv[1].nameOfItem, "chips");
	inv[1].cost = 15;
	//
	strcpy(inv[2].nameOfItem, "cookies");
	inv[2].cost = 15;
	//
	strcpy(inv[3].nameOfItem, "soda");
	inv[3].cost = 25;
	//
	while(fgets(text, 100, invRead) != NULL) {
		fscanf(invRead, "%s", text);
		inv[i].numberOfItems = atoi(text);
		i++;
	}
	//
	selection = showSelection();
	//Check if selection is within bounds of valid integer inputs (from 1 to 5)
	if(selection <= 5) {
		selected(selection);
	} else {
		printf("Invalid selection. Try again:\n");
		return main();
	}
	//
	return 0;
}

int showSelection() {
	int selection;
	//Line break
	printf("-------------------\n");
	//Prompt and selection list
	printf("What would you like to buy?");
	printf("\n\n");
	printf("Selection\tAvailable\tPrice\n");
	printf("[1] Candies\t%i\t\tPhp 10\n", inv[0].numberOfItems);
	printf("[2] Chips\t%i\t\tPhp 15\n", inv[1].numberOfItems);
	printf("[3] Cookies\t%i\t\tPhp 15\n", inv[2].numberOfItems);
	printf("[4] Soda\t%i\t\tPhp 25\n", inv[3].numberOfItems);
	printf("[5] Quit");
	printf("\n\n");
	//Prompt to enter selection
	printf("Please enter your selection:\n");
	scanf("%i", &selection);
	//returns selection
	return selection;
}

int selected(int selection) {
	int quantity;
	//Cases of what was chosen and the proper prompts
	switch(selection) {
		//Chosen candies
		case 1	:	printf("How many candies do you want?\n");
					scanf("%i", &quantity);
					sellProduct(selection, quantity);
					break;
		//Chosen chips
		case 2	:	printf("How many chips do you want?\n");
					scanf("%i", &quantity);
					sellProduct(selection, quantity);
					break;
		//Chosen cookies
		case 3	:	printf("How many cookies do you want?\n");
					scanf("%i", &quantity);
					sellProduct(selection, quantity);
					break;
		//Chosen soda
		case 4	:	printf("How many sodas do you want?\n");
					scanf("%i", &quantity);
					sellProduct(selection, quantity);
					break;
		//Chosen quit
		case 5	:	printf("\nSee you again next time!");
					return 0;
					break;
	}
}

int sellProduct(int selected, int quantity) {
	getCount(selected, quantity);
	//returns 0 to exit
	return 0;
}

int tryAgain() {
	int selection;
	//
	printf("-------------------\n");
	printf("Would you like use the machine again?\n\n");
	printf("[1] yes\n");
	printf("[2] no\n");
	printf("-------------------\n");
	//
	scanf("%i", &selection);
	//
	switch(selection) {
		case 1	:	return main();
		case 2	:	printf("\nSee you again next time!");
					return 0;
		default	:	printf("Invalid selection, please try again");
					tryAgain();
	}
}
