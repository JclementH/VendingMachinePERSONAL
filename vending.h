#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

int main();
int showSelection ();
int selected(int selection);
int sellProduct (int selected, int quantity);
int tryAgain();

struct inventoryInDispenser {
	char nameOfItem[250];
	int numberOfItems;
	int cost;
};

struct inventoryInDispenser inv[4];
FILE *invRead;
FILE *invChange;
