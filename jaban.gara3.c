#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "prototypes.h"

int main(void)
{
	int i;
	system("clear");
	for(i = 0 ; i < 34 ; i++)
		putchar(' ');
	printf("::::::::::::::::::::::::::\n");
	  for(i = 0 ; i < 34 ; i++)
                putchar(' ');
	printf("::Welcome to JABAN-GARA3::\n");
	 for(i = 0 ; i < 34 ; i++)
                putchar(' ');
	printf("::::::::::::::::::::::::::\n\n\n");
	menu();
	return 0;
}
/*menu : show the option menu */
void menu(void)
{
	char answer[3];
	int  int_answer = 0;
	printf("What do you wish to do ?\n");
	printf("1. Play game\n");
	printf("2. Instructions\n");
	printf("3. Credits\n");
	printf("> ");
	fgets(answer , sizeof(answer) , stdin);
	nRemover(answer);
	int_answer = (int) strtol(answer , NULL , 10);
	/*strtol return 0 if the first character isn't a number*/
	switch(int_answer)
	{
		case 1 :
			play_game();
			break;
		case 2 :
			show_instructions();
			break;
		case 3 :
			show_credits();
			break;
		default:
			printf("I didn't understand \n");
			menu();
			break;
	}
}
void show_instructions(void)
{
	char line[1000];
	FILE* inst = NULL;
	system("clear");
	inst = fopen("instructions" , "r");
	ERROR_HANDEL(inst);
	while(fgets(line , sizeof(line) , inst) != NULL)
		printf("%s" , line);
	printf("\n\n");
	menu();
}
void show_credits(void)
{
	char line[1000];
	FILE* credits = NULL;
	system("clear");
	credits = fopen("credits" , "r");
	ERROR_HANDEL(credits);
	while(fgets(line , sizeof(line) , credits) != NULL)
		printf("%s" , line);
	printf("\n\n");
	menu();
}
void nRemover(char s[])
{
	int i ;
	for(i = strlen(s) ; i > 0 ; i--)
		if(s[i] == '\n')
			s[i] = '\0';
}
void if_special(char ka3a[] , char deck[][4])
{
	int i;
	strcpy(deck[0] , "");
	shift_deck(deck);
	for(i = 0 ; strcmp(deck[i] , "") ; i++)
		;
	strcpy(deck[i] , ka3a);
}
void case_empty(char source[][4] , char destination[][4] , int j)
{
	int i , l;
	for(i = 0 ; i < SIZE ; i++)
		printf("\n%s " , source[i]);
	shuffle(source);
	for(i = l = 0 ; i < SIZE ;  i++)
		if(strcmp(source[i] , ""))
			strcpy(destination[l++] , source[i]);
	strcpy(destination[l] , "");
	for(i = 0 ; i < SIZE ; i++)
		printf("\n%s " , destination[i]);
	printf("\n*Deck reloaded*\n");
}
int element_num_counter(char matrix[][4])
{
	int i;
	for(i = 0 ; strcmp(matrix[i] , "") ; i++)
		;
	return i;
}
