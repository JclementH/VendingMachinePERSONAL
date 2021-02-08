#include "cashregister.h"
#include "vending.h"

int currentBalance(int balance, int totalCost) {
	int nb, confirm;
	//
	printf("Deposit %i\n", totalCost - balance);
	scanf("%i", &nb);
	balance = balance + nb;
	//
	printf("-------------------\n");
	printf("Confirm deposit?\n\n");
	printf("[1] yes\n");
	printf("[2] no\n");
	printf("-------------------\n");
	//
	scanf("%i", &confirm);
	confirmation(confirm, balance, totalCost);
}

int confirmation(int confirm, int balance, int totalCost) {
	if(confirm == 1) {
		return change(balance, totalCost);
	} else {
		return currentBalance(0, totalCost);
	}
}

int change(int balance, int totalCost) {
	int change, added;
	//
	if(balance == totalCost) {
		acceptMoney();
	} else if(balance < totalCost) {
		printf("You have inputted less than your total cost. Please deposit more: \n");
		currentBalance(balance, totalCost);
	} else if(balance > totalCost) {
		change = balance - totalCost;
		printf("Your change is: %i", change);
		acceptMoney();
	}
	//
	return 0;
}

int acceptMoney() {
	printf("\nCollect your items at the bottom. Enjoy!\n");
	tryAgain();
}
