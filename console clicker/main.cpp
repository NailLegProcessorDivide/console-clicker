#include "stdio.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>

struct facility {
	const char *name;
	int owned;
	int unlockSci;
	int cost;
	int moneyPT;
	int sciPT;
};

int main() {
	int money = 0;
	int sci = 0;
	char buffer[32];
	const char* spaces = "                ";
	facility facilitys[10] = { {"conkers", 1, 0, 10, 1, 0}, { "coke and mentos", 0, 0, 5, 0, 1 }, { "card store", 0, 5, 5, 2, 0 },
	{ "chemistry set", 0, 15, 15, 0, 4 }, { "game developer", 0, 50, 75, 25, 10 }, { "\"chemistry lab\"", 0, 200, 600, 300, 20 }, { "crash", 0, 9999999, 5, 0, 1 } };
	while (true) {
		for (int i = 0; i < 10; i++) {//yes i kow this can be done better
			if (facilitys[i].unlockSci > sci)break;
			money += facilitys[i].moneyPT * facilitys[i].owned;
			sci += facilitys[i].sciPT * facilitys[i].owned;

		}
		printf("You have %i money.\n", money);
		printf("You have %i science.\n\n", sci);
		printf("|Name            |Cost    |Number Owned|Money PT  |Science PT|\n");
		for (int i = 0; i < 10; i++) {//yes i kow this can be done better
			if (facilitys[i].unlockSci > sci)break;
			//////////////////////////////////////
			printf("|");
			printf(spaces + strlen(facilitys[i].name));
			printf(facilitys[i].name);
			//////////////////////////////////////
			printf("|");
			_itoa(facilitys[i].cost, buffer, 10);
			printf(spaces + 8 + strlen(buffer));
			printf(buffer);
			///////////////////////////////////////
			printf("|");
			_itoa(facilitys[i].owned, buffer, 10);
			printf(spaces + 4 + strlen(buffer));
			printf(buffer);
			//////////////////////////////
			printf("|");
			_itoa(facilitys[i].moneyPT, buffer, 10);
			printf(spaces + 6 + strlen(buffer));
			printf(buffer);
			////////////////////////////
			printf("|");
			_itoa(facilitys[i].sciPT, buffer, 10);
			printf(spaces + 6 + strlen(buffer));
			printf(buffer);
			/////////////////////////////////
			printf("\n");//yes i kow this can be done better
		}
		std::cin.getline(buffer, 32);
		for (int i = 0; i < 10; i++) {//yes i kow this can be done better
			if (facilitys[i].unlockSci > sci)break;
			if (strcmp(buffer, facilitys[i].name)==0) {
				if (facilitys[i].cost <= money) {
					money -= facilitys[i].cost;
					facilitys[i].cost *= 1.5f;
					facilitys[i].cost += 1;
					facilitys[i].owned += 1;
				}
			}
		}
	}
}
