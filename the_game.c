#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "prototypes.h"
void play_game(void)
{
	int i , j = 0 , z , int_answer , checker , comp_checker = NOT_VALID , y;
	char deck[41][4] = {"1z" , "1f" , "1j" , "1s" , "2z" , "2f" , "2j" , "2s" , "3z" , "3f" , "3j" , "3s" , "4z" , "4f" , "4j" , "4s" , "5z" , "5f" , "5j" , "5s" , 
				"6z" , "6f" , "6j" , "6s" , "7z" , "7f" , "7j" , "7s" , "10z" , "10f" , "10j" , "10s" , "11z" , "11f" , "11j" , "11s" , "12z" , "12f" , "12j" , "12s" , ""};
	char types[4] = {'s' , 'z' , 'f' , 'j'};
	char used[SIZE][4]; /*all the ka3a card that have been replaced are copyed here so that when the players are out of card the content of this array is shuffled then copied to the deck*/
	char ka3a[4] = "";
	char deck_ply1[SIZE][4];	/*human player's deck*/
	char deck_computer[SIZE][4];	/*the computer's deck*/
	char answer[10];	/*the players choice*/
	char current_card[4];	
	char previously_played[5];
	/*------------INITIALIZING------------------------*/
	matrix_initializer(deck_ply1);
	matrix_initializer(deck_computer);
	matrix_initializer(used);
	/*-----------------------------------------------*/
	shuffle(deck);
	distributer(deck , deck_ply1 , deck_computer);
	/*choosing the ka3a card*/
	do
	{
		strcpy(ka3a , deck[0]);
		if(strchr(ka3a , '2') || strchr(ka3a , '7') || strchr(ka3a , '1'))
			if_special(ka3a , deck);
	}
	while(strchr(ka3a , '2') || strchr(ka3a , '7') || strchr(ka3a , '1'));
	shift_deck(deck);
	printf("The game has began\n\n");
	do
	{
		if(!element_num_counter(deck))
			case_empty(used , deck , j);
		do
		{
			if(strchr(previously_played , '2') && !strchr(previously_played , '1'))
			{
				for(z = 0 ; z < 2 ; z++)
				{
					for(y = 0 ; strcmp(deck_ply1[y] , "") ; y++)
                                        		;
                        		strcpy(deck_ply1[y] , deck[0]);
                        		shift_deck(deck);
				}
				printf("\n*you lift 2 cards*\n");
				strcpy(previously_played , "");
			}
			else if(strchr(previously_played , '1') && strstr(previously_played , "10") == NULL && strstr(previously_played , "11") == NULL && strstr(previously_played , "12") == NULL)
				strcpy(previously_played , "") , printf("\n*the computer made you skip a turn*\n");
			else
			{	
				printf("9a3a : %s\n\n" , ka3a);
				printf("Your cards: ");
				/*showing the cards of the human player*/
				for(i = 0 ; strcmp(deck_ply1[i] , "") ; i++)
					printf("%d/[ %s ]  " , i + 1 , deck_ply1[i]);
				printf("\n\nEnter the number of the card to play or \"add\" to take a card from the deck\n\n> ");
				fgets(answer , sizeof(answer) , stdin);
				nRemover(answer);
				int_answer = strtol(answer , NULL , 10);
				/*strtol returns 0 if answer is not a digit*/
				if(int_answer)
				{
					/*loop until we reach the card chosen by the player*/
					for(i = 0 ; strcmp(deck_ply1[i] , "") && i < int_answer ; i++)
						strcpy(current_card , deck_ply1[i]);
					/*compare it to the ka3a card , comparison() return 1 if the card is valid 0 if not*/
					if(comparison(current_card , ka3a))
					{
						strcpy(used[j++] , ka3a);
						strcpy(ka3a , current_card);
						strcpy(deck_ply1[i - 1] , "fl");
						strcpy(previously_played , current_card);
						player_card_remover(deck_ply1);
						checker = VALID;
					}
					else
					{
						printf("You can't do that ...\n");
						checker = NOT_VALID;
					}
				}
				else if(current_card[0] == 7)
				{
					char choice = 0;
					printf("Pick a Type >");
					fgets(&choice , 1 , stdin);
					ka3a[strlen(ka3a) - 1] == choice;
				}
				else if(!strcmp(answer , "add") || !strcmp(answer , "ADD"))
				{
					for(i = 0 ; strcmp(deck_ply1[i] , "") ; i++)
						;
					strcpy(deck_ply1[i] , deck[0]);
					shift_deck(deck);
					checker = VALID;
				}
				else
				{
					printf("You can't do that ...\n");
					checker = NOT_VALID;
				}
			}
		}
		/*loop while the entered character isn't valid*/
		while(!checker);
		/*the computer's turn begins here--------------------------------*/
		if(element_num_counter(deck_ply1))
		{
			if(strchr(previously_played , '2') && !strchr(previously_played , '1'))
			{
				for(z = 0 ; z < 2 ; z++)
				{
					for(y = 0 ; strcmp(deck_computer[y] , "") ; y++)
                                        		;
                        		strcpy(deck_computer[y] , deck[0]);
                        		shift_deck(deck);
				}
				printf("\n*the computer lift 2 cards*\n");
				strcpy(previously_played , "");
			}
			else if(strchr(previously_played , '1') && strstr(previously_played , "10") == NULL && strstr(previously_played , "11") == NULL && strstr(previously_played , "12") == NULL)
				strcpy(previously_played , "") , printf("\n*you made the computer skip 1 turn*\n");
			else if(previously_played[0] == 7)
			{
				int ran = 0;
				ran = rand() % sizeof(types);
				ka3a[strlen(ka3a) - 1] == types[ran];
			}
			else
			{
				for(y = 0 ; strcmp(deck_computer[y] , "") ; y++)
				{
					if(comparison(deck_computer[y] , ka3a))
					{
						strcpy(used[j++] , ka3a);
						strcpy(ka3a , deck_computer[y]);
						strcpy(previously_played , deck_computer[y]);
						strcpy(deck_computer[y] , "fl");
						player_card_remover(deck_computer);
						comp_checker = VALID;
						printf("\n*The computer played a card*\n");
						break;
					}
		
				}
				if(!comp_checker)
				{
					for(y = 0 ; strcmp(deck_computer[y] , "") ; y++)
                                        		;
                        		strcpy(deck_computer[y] , deck[0]);
                        		shift_deck(deck);
					printf("\n*the computer lift a card*\n");
				}
				comp_checker = NOT_VALID;
			}
		}
			/*and ends here--------------------------------------------------------*/
	
	}
	while(element_num_counter(deck_ply1) && element_num_counter(deck_computer));
	if(!element_num_counter(deck_ply1))
		printf("CONGRATULATIONS YOU HAVE WON\n");
	else if(!element_num_counter(deck_computer))
		printf("THE COMPUTER WON , YOU LOST\n");
}
