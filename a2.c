// author : Jinlong Lin


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>



void MainMenu();
int ShapePrinter(char s, int h, int w);
int CircularChars(char c);
int Factors(int i, int j);
void Exit();

int ShapePrinter(char s, int h, int w) {

	if (w <= 0 || h <= 0) {

		fprintf(stderr, "Illegal size of shape");

	}
	else {

		if (s == 's') {

			int k = h;
			int g = h;
			for (k = h; k > 0; k--) {
				for (g = h; g > 0; g--) {
					printf("*");
				}
				printf("\n");
			}

		}
		else if (s == 't') {

			int i, j;
			for (i = 1; i <= h; ++i) {
				for (j = 1; j <= i; ++j) {
					printf("*");
				}
				printf("\n");
			}

		}
		else if(s == 'r') {
			int f = 0, v = 0;
			for (f = 0; f < h; f++) {
				for (v = 0; v < w; v++) {
					printf("*");
				}
				printf("\n");
			}
		}else{
			fprintf(stderr, "Illegal shape: the input of shape cannot be supported \n");
		}
	}

	return 0;
}

int CircularChars(char c) {
	char f = 'a';
	char d = 'a';

	if (c >= 48 && c <= 57) {

		for (f = c; f <= '9'; ++f) {
			printf("%c", f);
		}
		for (d = '0'; d < c; ++d) {
			printf("%c", d);
		}
		printf("\n");
		//return 0;

	}
	else if (c >= 65 && c <= 90) {

		for (f = c; f <= 'Z'; ++f) {
			printf("%c", f);
		}
		for (d = 'A'; d < c; ++d) {
			printf("%c", d);
		}
		printf("\n");
		//return 0;

	}
	else if (c >= 97 && c <= 122) {

		for (f = c; f <= 'z'; ++f) {
			printf("%c", f);
		}
		for (d = 'a'; d < c; ++d) {
			printf("%c", d);
		}
		printf("\n");
		//return 0;

	}
	else {
		fprintf(stderr, "Illegal characte %c, pleace try again\n ", c);
		MainMenu();
	}

	return 0;


}


int  Factors(int i, int j) {
	int p = i;
	int k = 0;

	if (j < i || i <= 1 || j <= 1) {
		fprintf(stderr, "Illegal input number %d, %d, pleace try again\n ", i, j);
	}
	else {
		int count = 0;
		for (p = i; p < j; ++p) {
			count = 0;
			for (k = 2; k < p; ++k) {
				if (p % k == 0) {
					count++;
				}
				if(p/k == k && (p%k) == 0){
					count = 0;
					break;
				}
			}
			if (count == 2) {
				printf("%d\n", p);
				count = 0;
			}
		}
	}
    return 0;
}

void MainMenu() {

	printf("1. Shape Printer\n");
	printf("2. Circular Chars\n");
	printf("3. Factors\n");
	printf("4. Exit\n");
	printf("What would you like to do? \n");

}


int main() {

	int character = 0;
	char s = 'a';
	int h = 1, w = 1;

	//while (character != 4) {
		MainMenu();
	while((	scanf(" %d", &character)) != EOF){
		if (character == 1) {
			scanf(" %c %d", &s, &h);
			if (s == 'r') {
				scanf(" %d", &w);
			}
			ShapePrinter(s, h, w);
		}
		else if (character == 2) {
			scanf(" %c", &s);
			CircularChars(s);
		}
		else if (character == 3) {
			scanf(" %d %d", &h, &w);
			Factors(h, w);
		}else if(character == 4){
			return 0;
		}
		else {
			fprintf(stderr, "Illegal input number \n");
			MainMenu();
		}
		MainMenu();
	}

	return 0;

}

