#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "prototypes.h"

void shuffle(char deck[][4])
{
	int i , z ; 
	char buff[SIZE] = ""; //a buffer used to swap cards
	const int MIN = 0 , MAX = SIZE-1; //minimum and maximum z values
	srand(time(NULL));
	for(i = 0 ; i < SIZE; i++)
	{	
	        	z = rand() % (MAX - MIN + 1) + MIN;
        		strcpy(buff, deck[z]);
        		strcpy(deck[z] , deck[i]);
        		strcpy(deck[i] , buff);
    	}
}
void distributer(char matrix[][4] , char deck1[][4] , char deck2[][4])
{
	int i = 0;
	for(i = 0 ; i < 5 ; i++)
	{
		strcpy(deck1[i] , matrix[0]);
		shift_deck(matrix);
	}
	for(i = 0 ; i < 5 ; i++)
	{
		strcpy(deck2[i] , matrix[0]);
		shift_deck(matrix);
	}
}
void matrix_initializer(char matrix[][4])
{
	int i;
	for(i = 0 ; i < SIZE ; i++)
		strcpy(matrix[i] , "");
}

void shift_deck(char deck[][4])
{
	int i;
	for(i = 0 ; i < SIZE ; i++)
		strcpy(deck[i] , deck[i + 1]);
}
void player_card_remover(char deck_ply[][4])
{
	int i ;
	for(i = 0 ; i < 40 ; i++)
		if(!strcmp(deck_ply[i] , "fl"))
		{
				for( ; i < SIZE ; i++)
					strcpy(deck_ply[i] , deck_ply[i + 1]);
				break;
		}
}
int comparison(char input[] , char ka3a_card[] )
{
	int int_input , int_ka3a_card;
	int_input = strtol(input , NULL , 10);
	int_ka3a_card = strtol(ka3a_card , NULL , 10);
	if(int_input == int_ka3a_card || strchr(ka3a_card , input[strlen(input) - 1]))
		return VALID;
	else
		return NOT_VALID;
}
