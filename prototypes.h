#define VALID 1
#define NOT_VALID 0
#define SIZE 40
#define ERROR_HANDEL(item) if(item == NULL)\
			   {\
				perror(#item);\
				exit(-1);\
			   }
void menu(void);	/*show menu*/
void play_game(void);	/*the game itself*/
void nRemover(char s[]);	/*removes the newline character*/
void show_instructions(void);	/*shows the instruction (rules ..)*/
void show_credits(void);	/*shows the credits*/
void shuffle(char deck[][4]);	/*shuffle the deck*/
void error_handle(FILE* file);	/*handles file opening errors*/
void matrix_initializer(char matrix[][4]);	/*initializes all the matrixs*/
void distributer(char matrix[][4] , char deck1[][4] , char deck2[][4]);		/* distibutes the cards*/
int comparison(char input[] , char ka3a_card[] );	/*compares the card selected and the card of the ka3a*/
void shift_deck(char deck[][4]);	/*reorganizes the deck*/
void if_special(char ka3a[] , char deck[][4]);	/*if the ka3a card equals 2 or 7 or 1 put the card at the end of matrix*/
void player_card_remover(char deck_ply[][4]);	/*removes the card selected by player from the player's deck */
void case_empty(char source[][4] , char destination[][4] , int j); /*reloads the deck if it's empty*/
int element_num_counter(char matrix[][4]); /*counts the number of elements int a given matrix*/

