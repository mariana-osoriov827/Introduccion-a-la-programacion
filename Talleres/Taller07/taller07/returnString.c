#include <stdio.h>

const char* printNames(const char *nom[], unsigned int n);

int main(void){
	const char *nombres[7] = {"JuanR", "MiguelP", "AnaM", "LuisG", "PedroJ", "LinaQ", "CarlosS"};

	printf("%s\n",printNames(nombres, 5));
}

const char* printNames(const char *nom[], unsigned int n){
	return nom[n];
}
