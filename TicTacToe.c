#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define SIZE 3
#define _CRT_SECURE_NO_WARNINGS

void start(char* arr, unsigned int len, unsigned int len1);
char next_step(char* arr, unsigned int len, unsigned int len1);
void player_1(char* arr, unsigned int len, unsigned int len1);
void player_2(char* arr, unsigned int len, unsigned int len1);
char check_strike(char* arr, unsigned int len, unsigned int len1);


void main()
{
	char end;
	printf("******** Tik-Tak-Tok Game ********\n");
	char arr[SIZE][SIZE];
	start(arr, SIZE, SIZE);
	end = next_step(arr, SIZE, SIZE);
	if (end == 0)
		printf("it's a Tie.\n");
	else if (end == 1)
		printf("player 1 won the game\n");
	else if (end == 2)
		printf("player 2 won the game\n");

	return;
}

void start(char* arr, unsigned int len, unsigned int len1)
{
	for (int i = 0; i < (len * len); i++)
	{

		*(arr + i) = '?';
		printf("%c ", *(arr + i));
		if (i == 2 || i == 5)
			printf("\n");
	}
	printf("\n");
}

char next_step(char* arr, unsigned int len, unsigned int len1)
{
	int w = 0, turn = 0;
	while (1)
	{
		int c = 1;
		printf("free places is: ");
		for (int i = 0; i < (len * len); i++)
		{

			if (*(arr + i) == '?')
				printf("%d ", c);
			c++;
		}
		printf("\n");

		if (turn % 2 == 0)
			player_1(arr, len, len1);
		else
			player_2(arr, len, len1);

		turn++;

		w = check_strike(arr, len, len1);
		if (w == 1)
			return 1;
		else if (w == 2)
			return 2;
		else if ((turn == 9) && (w == 0))
			return 0;
	}
}

void player_1(char* arr, unsigned int len, unsigned int len1)
{
	int	place;
	printf("player 1 turn. choose place: ");
	scanf("%d", &place);
	while (((*(arr + place - 1) == 'X') || (*(arr + place - 1) == 'O')) ||
		(place > 9) || (place < 1))
	{
		printf("place is taken or invalid. please choose another place: ");
		scanf("%d", &place);
		printf("\n");
	}
	if (*(arr + place - 1) == '?')
		*(arr + place - 1) = 'X';
	for (int i = 0; i < (len * len); i++)
	{
		printf("%c ", *(arr + i));
		if (i == 2 || i == 5)
			printf("\n");
	}
	printf("\n");


}

void player_2(char* arr, unsigned int len, unsigned int len1)
{
	int	place2;
	printf("player 2 turn. choose place: ");
	scanf("%d", &place2);
	while ((*(arr + place2 - 1) == 'X') || (*(arr + place2 - 1) == 'O') ||
		(place2 > 9) || (place2 < 1))
	{
		printf("place is taken or invalid. please choose another place: ");
		scanf("%d", &place2);
	}
	if (*(arr + place2 - 1) == '?')
		*(arr + place2 - 1) = 'O';
	for (int i = 0; i < (len * len); i++)
	{
		printf("%c ", *(arr + i));
		if (i == 2 || i == 5)
			printf("\n");
	}
	printf("\n");

}

char check_strike(char* arr, unsigned int len, unsigned int len1)
{

	if (((*arr == 'X') && (*(arr + 1) == 'X') && (*(arr + 2) == 'X')) ||
		((*(arr + 3) == 'X') && (*(arr + 4) == 'X') && (*(arr + 5) == 'X')) ||
		((*(arr + 6) == 'X') && (*(arr + 7) == 'X') && (*(arr + 8) == 'X')))
		return 1;
	else if (((*arr == 'X') && (*(arr + 3) == 'X') && (*(arr + 6) == 'X')) ||
		((*(arr + 1) == 'X') && (*(arr + 4) == 'X') && (*(arr + 7) == 'X')) ||
		((*(arr + 2) == 'X') && (*(arr + 5) == 'X') && (*(arr + 8) == 'X')))
		return 1;
	else if (((*arr == 'X') && (*(arr + 4) == 'X') && (*(arr + 8) == 'X')) ||
		((*(arr + 2) == 'X') && (*(arr + 4) == 'X') && (*(arr + 6) == 'X')))
		return 1;

	else if (((*arr == 'O') && (*(arr + 1) == 'O') && (*(arr + 2) == 'O')) ||
		((*(arr + 3) == 'O') && (*(arr + 4) == 'O') && (*(arr + 5) == 'O')) ||
		((*(arr + 6) == 'O') && (*(arr + 7) == 'O') && (*(arr + 8) == 'O')))
		return 2;
	else if (((*arr == 'O') && (*(arr + 3) == 'O') && (*(arr + 6) == 'O')) ||
		((*(arr + 1) == 'O') && (*(arr + 4) == 'O') && (*(arr + 7) == 'O')) ||
		((*(arr + 2) == 'O') && (*(arr + 5) == 'O') && (*(arr + 8) == 'O')))
		return 2;
	else if (((*arr == 'O') && (*(arr + 4) == 'O') && (*(arr + 8) == 'O')) ||
		((*(arr + 2) == 'O') && (*(arr + 4) == 'O') && (*(arr + 6) == 'O')))
		return 2;
	else
		return 0;
}