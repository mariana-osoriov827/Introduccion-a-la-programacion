#include <stdio.h>

void printNames(const char *nom[], unsigned int n);

int main(void){
	const char *nombres[7] = {"JuanR", "MiguelP", "AnaM", "LuisG", "PedroJ", "LinaQ", "CarlosS"};

	printNames(nombres, 7);
}

void printNames(const char *nom[], unsigned int n){
	for(size_t i = 0; i < n; i++)
		printf("%s\n", nom[i]);
}
