#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>

#define MAX 9

//void display(char* array[]);
void display_game_board(char* game_board[]);
void init(char* array[]);
void insert(char* array[], int pos, char* word);
void replace(char* array[], int pos, char* word);
//void delete(char* array[], int pos);
//void reverse(char* array[]);

// ****** functions ******
void remove_newline(char *str);
int check_winner(char* array[], int *won);
int search(char* array[], char* num, char* store_array[], int *free);
void vs_player_or_computer(int *flag);
char* one_player(char *players_piece1);
char* two_player(char *players_piece);

// ****** stack API ******
void init_stack(struct stack *s);
void push(struct stack *s, int item);
int *pop(struct stack *s);


struct stack
{
	int array_stack[MAX];
	int top;
};
int main(int argc, char **argv)
{
	char* array[MAX];
	int play_computer_flag = 0;
	char players_piece[5];
	char players_piece1[5];
	char *store_array[MAX];
	char position[MAX];
	int game_flag = 1;
	int i;
	int won = 0;
	int free = 0;
	struct stack s;
	
	init_stack(&s);
	
	init(array);
	
	//Decide if it is a  PLAYER_vs_COMPUTER or PLAYER vs PLAYER game
	vs_player_or_computer(&play_computer_flag); 
	if(play_computer_flag == 1)
	{
		one_player(&*players_piece1);
	}
	else
	{
		two_player(&*players_piece);	
	}
	
	printf("\nprinted from inside of main players_piece : %c\n", players_piece[0]);
	
	
	
	insert(array, 1, "1");
	insert(array, 2, "2");
	insert(array, 3, "3");
	insert(array, 4, "4");
	insert(array, 5, "5");
	insert(array, 6, "6");
	insert(array, 7, "7");
	insert(array, 8, "8");
	insert(array, 9, "9");
	
	display_game_board(array);


	//printf("\n PLAYER ONE's turn\n");
	
	if(strcmp(players_piece, "O") == 0)
	{	// Game code if player one selects noughts
		while(game_flag)
		{
			//int i;
			for(i = 0; i < MAX; i++)
			{
				printf("\n NEXT TURN\n");
				printf("\n pick the number of the grid you would like to place your %s in : ", players_piece);
				fgets(position, 10, stdin);
				remove_newline(position);
				int new_position = atoi(position);
				replace(array, new_position, players_piece);
				display_game_board(array);
			
				check_winner(array, &won);
				if(won == 1)
				{
					break;
				}
				printf("\n NEXT TURN\n");
				printf("\n pick the number of the grid you would like to place your X in : ");
				fgets(position, 10, stdin);
				remove_newline(position);
				replace(array, atoi(position), "X");
				display_game_board(array);
				
				check_winner(array, &won);
				if(won == 1)
				{
					break;
				}		
			}	
		game_flag = 0;

		}
	}
	else if(strcmp(players_piece, "X") == 0)
	{	// Game code if player one selects crosses
		while(game_flag)
		{
			//int i;
			for(i = 0; i < MAX; i++)
			{
				printf("\n NEXT TURN\n");
				printf("\n pick the number of the grid you would like to place your %s in : ", players_piece);
				fgets(position, 10, stdin);
				remove_newline(position);
				int new_position = atoi(position);
				replace(array, new_position, players_piece);
				display_game_board(array);
			
				check_winner(array, &won);
				if(won == 1)
				{
					break;
				}
				printf("\n NEXT TURN\n");
				printf("\n pick the number of the grid you would like to place your O in : ");
				fgets(position, 10, stdin);
				remove_newline(position);
				replace(array, atoi(position), "O");
				display_game_board(array);
				
				check_winner(array, &won);
				if(won == 1)
				{
					break;
				}		
			}	
		game_flag = 0;

		}
	}
	else if(strcmp(players_piece1, "O") == 0)
	{	// Game code if player one selects noughts in PLAYER vs COMPUTER
		while(game_flag)
		{
			//int i;
			for(i = 0; i < MAX; i++)
			{
				printf("\n NEXT TURN\n");
				printf("\n pick the number of the grid you would like to place your %s in : ", players_piece1);
				fgets(position, 10, stdin);
				remove_newline(position);
				int new_position = atoi(position);
				replace(array, new_position, players_piece1);
				display_game_board(array);
			
				check_winner(array, &won);
				if(won == 1)
				{
					break;
				}
				printf("\n COMPUTERS TURN\n");
				
				
				search(array, "X", &*store_array, &free);
				
				
				replace(array, free, "X");
				display_game_board(array);
				
				check_winner(array, &won);
				if(won == 1)
				{
					break;
				}		
			}	
		game_flag = 0;

		}
	}
	else if(strcmp(players_piece1, "X") == 0)
	{// Game code if player one selects crosses in PLAYER vs COMPUTER
	while(game_flag)
	{
		//int i;
		for(i = 0; i < MAX; i++)
		{
			printf("\n NEXT TURN\n");
			printf("\n pick the number of the grid you would like to place your %s in : ", players_piece1);
			fgets(position, 10, stdin);
			remove_newline(position);
			int new_position = atoi(position);
			replace(array, new_position, players_piece1);
			display_game_board(array);
			
			check_winner(array, &won);
			if(won == 1)
			{
				break;
			}
			printf("\n COMPUTERS TURN\n");
				
				
			search(array, "O", &*store_array, &free);
				
				
			replace(array, free, "O");
			display_game_board(array);
				
			check_winner(array, &won);
			if(won == 1)
			{
				break;				}		
			}	
	game_flag = 0;
	
	}
}
	


}
//********** END OF MAIN FUNCTION *************
char* one_player(char *players_piece1)
{
	printf("\nA ONE player game vs the computer has been selected\n");
	printf("Do you want to play 0's or X's?\n");
	printf("\t\tselect O for 0's?\n");
	printf("\t\tselect X for X's?\n");
	printf("\t\t\t\t:");
	
	fgets(players_piece1, 10, stdin);
	int len = strlen(players_piece1);
	if(len > 0 && players_piece1[len-1] =='\n')
	{ 
		players_piece1[len-1] = '\0';
	}
	if(strcmp(players_piece1, "0") == 0 ||strcmp(players_piece1, "o") == 0 || strcmp(players_piece1, "O") == 0)
	{
		printf("\n PLAYER 1 has chosen: 0's - noughts - woop woop!!");
		*players_piece1 = 'O';
	}
	else if (strcmp(players_piece1, "x") == 0 || strcmp(players_piece1, "X") == 0)
	{
		printf("\n PLAYER 1 has chosen: X's - crosses - boom!!");
		*players_piece1 = 'X';
	}
	else
	{
		printf("INVALID COMMAND!!");
	}	
	return players_piece1;	
}

//***** Function for player vs player game code *****
char* two_player(char *players_piece)
{
	printf("\nA TWO PLAYER game has been selected\n\n");
	printf("Does PLAYER 1 want to play 0's or X's?\n");
	printf("\t\tselect O for 0's?\n");
	printf("\t\tselect X for X's?\n");
	printf("\t\t\t\t:");
	
	fgets(players_piece, 10, stdin);
	int len = strlen(players_piece);
	if(len > 0 && players_piece[len-1] =='\n')
	{ 
		players_piece[len-1] = '\0';
	}
	if(strcmp(players_piece, "0") == 0 ||strcmp(players_piece, "o") == 0 || strcmp(players_piece, "O") == 0)
	{
		printf("\n PLAYER 1 has chosen: 0's - noughts - woop woop!!");
		*players_piece = 'O';
	}
	else if (strcmp(players_piece, "x") == 0 || strcmp(players_piece, "X") == 0)
	{
		printf("\n PLAYER 1 has chosen: X's - crosses - boom!!");
		*players_piece = 'X';
	}
	else
	{
		printf("INVALID COMMAND!!");
	}	
	return players_piece;	
}
//*******************************************

//***** FUNCTION to check if a player has won ******
int check_winner(char* array[], int *won)
{
	if(strcmp(array[0], "O") == 0 && strcmp(array[1], "O") == 0 && strcmp(array[2], "O") == 0 
	|| strcmp(array[3], "O") == 0 && strcmp(array[4], "O") == 0 && strcmp(array[5], "O") == 0 
	|| strcmp(array[6], "O") == 0 && strcmp(array[7], "O") == 0 && strcmp(array[8], "O") == 0 
	|| strcmp(array[0], "O") == 0 && strcmp(array[3], "O") == 0 && strcmp(array[6], "O") == 0 
	|| strcmp(array[1], "O") == 0 && strcmp(array[4], "O") == 0 && strcmp(array[7], "O") == 0 
	|| strcmp(array[2], "O") == 0 && strcmp(array[5], "O") == 0 && strcmp(array[8], "O") == 0 
	|| strcmp(array[0], "O") == 0 && strcmp(array[4], "O") == 0 && strcmp(array[8], "O") == 0 
	|| strcmp(array[2], "O") == 0 && strcmp(array[4], "O") == 0 && strcmp(array[6], "O") == 0 ) 
	{
		printf("\n NOUGHTS WON!!!!!! CONGRATULATIONS");
		*won = 1;
			
	}else if(strcmp(array[0], "O") == 0 && strcmp(array[1], "O") == 0 && strcmp(array[2], "O") == 0 
	|| strcmp(array[3], "X") == 0 && strcmp(array[4], "X") == 0 && strcmp(array[5], "X") == 0 
	|| strcmp(array[6], "X") == 0 && strcmp(array[7], "X") == 0 && strcmp(array[8], "X") == 0 
	|| strcmp(array[0], "X") == 0 && strcmp(array[3], "X") == 0 && strcmp(array[6], "X") == 0 
	|| strcmp(array[1], "X") == 0 && strcmp(array[4], "X") == 0 && strcmp(array[7], "X") == 0 
	|| strcmp(array[2], "X") == 0 && strcmp(array[5], "X") == 0 && strcmp(array[8], "X") == 0 
	|| strcmp(array[0], "X") == 0 && strcmp(array[4], "X") == 0 && strcmp(array[8], "X") == 0 
	|| strcmp(array[2], "X") == 0 && strcmp(array[4], "X") == 0 && strcmp(array[6], "X") == 0 ) 
	{
		printf("\n CROSSES WON!!!!!! CONGRATULATIONS");
		*won =1;
	}
	return *won;	
}
//*********************************

// ****** Fuction to establish if you want to pay against the computer or 2 player game. *****
void vs_player_or_computer(int *flag)
{
	char choice[10];
	int flag2 = 1;
	
	while(flag2)
	{
		//printf("The play_against_computer flag is set to: %d\n", *flag);

		printf("\nDo you wnat to play against the computer? Y for yes N for no: ");
		
		fgets(choice, 10, stdin);
		int len = strlen(choice);
		if(len > 0 && choice[len-1] =='\n')
		{ 
			choice[len-1] = '\0';
		}
		// Decide if playing 2 player game or against computer!!
		if (strcmp(choice, "Y") == 0 || strcmp(choice, "y") == 0)
		{
			//printf("\nY has been inputted\n");
			*flag = 1;
			flag2 = 0;
			break;
		}
		else if(strcmp(choice, "N") == 0 || strcmp(choice, "n") == 0)
		{
			//printf("\nA human 2 player game has been selected\n");
			*flag = 0;
			flag2 = 0;
			break;
		}else
		{
			printf("\n********INVALID ENTRY**********\n\n");
			flag2 = 1;
			continue;
		}
	}
}
//****************************

// ***** Inititiate the string to and empty string *****
void init(char* array[])

{
	int idx;
	for(idx = 0; idx < MAX; idx ++)
	{
		array[idx] = " ";
	}
} 
//**************************

// Print the array to screen
void display(char* array[])
{
	int i;                            
    
    for (i = 0; i < MAX; i++) 
	{		
        printf (" array[%d] : %s\n", i, array[i]);
	}
	 printf (" \n");
}

// I think this will make my display layout????
void display_game_board(char* game_board[])
{	
	printf("\n\t\t\t  %s  ",game_board[0]);
	printf("|  %s  |",game_board[1]);
	printf("  %s",game_board[2]);
	printf("\n\t\t\t-----------------\n");
	printf("\t\t\t  %s  ",game_board[3]);
	printf("|  %s  |",game_board[4]);
	printf("  %s ",game_board[5]);
	printf("\n\t\t\t-----------------\n");
	printf("\t\t\t  %s  ",game_board[6]);
	printf("|  %s  |",game_board[7]);
	printf("  %s \n",game_board[8]);
}
//*****************

// Remove newline character
void remove_newline(char *str)
{
	int len = strlen(str);
	if(len > 0 && str[len-1] =='\n')
	{ 
		str[len-1] = '\0';
	}
}
//***************************

// Insert Element at a position into an array
void insert(char* array[], int pos, char* word)
{
	int idx;
	
	for(idx = MAX - 1; idx >= pos; idx--)
	{
		array[idx] = array[idx - 1];
	}
	array[idx] = word;
}
//********************

// Replace an element at a position at the array
void replace(char* array[], int pos, char* word)
{
	int idx;
	for(idx = pos; idx < MAX; idx++)
	{
		array[idx -1] = array[idx];
	}
	array[idx - 1] = 0;


	for(idx = MAX - 1; idx >= pos; idx--)
	{
		array[idx] = array[idx - 1];
	}
	array[idx] = word;
}
//************************

// Delete Element at a position into an array
void delete(char* array[], int pos)
{
	int idx;
	for(idx = pos; idx < MAX; idx++)
	{
		array[idx -1] = array[idx];
	}
	array[idx - 1] = 0;
}
//**************************

// Reversing the Elements in an array
void reverse(char* array[])
{
	int idx;
	for(idx = 0; idx < MAX/2; idx++)
	{
		char* temp = array[idx];
		array[idx] = array[MAX - 1 - idx];
		array[MAX - 1 - idx] = temp;
	}
}
//**************************

// Searching for an element in an array
int search(char* array[], char* num, char* store_array[],int *free)
{
	//int idx;
	for(*free = 0; *free < MAX; *free++)
	{
		if(strcmp(array[*free], num) == 0)
		{
			printf("\n%s found in position %d\n", num, *free + 1 );
			store_array[*free] = num;	
		}
	}
	
	if(*free == MAX)
	{
		printf("%s is an INVALID CELL! \nChoose another cell from the available numbers\n", num);
	}
	return *free;
}
//***************************

// ****** API Stack Functions *****
void init_stack(struct stack *s)
{
	s->top = -1;
}

void push(struct stack *s, int item)
{
	// Works out if the designated stack of MAX size is full
	if(s->top == MAX-1)
	{
		printf("Stack is full. Couldn't push '%d' onto stack\n", item);
		return;
	}
	s->top++;
	s->array_stack[s->top] = item;
}

int *pop(struct stack *s)
{
	int *data;
	if(s->top == -1)
	{
		printf("Stack is empty\n");
		return NULL;
	}
	data = &s->array_stack[s->top];
	s->top--;
	return data;
}
//************************
