#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>

#define MAX 9


// string_array API 
//void display(char* array[]);
void display_game_board(char* game_board[]);
void init(char* array[]);
void insert(char* array[], int pos, char* word);
void replace(char* array[], int pos, char* word);
//void delete(char* array[], int pos);
//void reverse(char* array[]);
void remove_newline(char *str);

void search(char* array[], char* num, char* store_array[]);


void vs_player_or_computer(int *flag);
//void one_player();
char* two_player(char *players_piece);


int main(int argc, char **argv)
{
	char* array[MAX];
	int play_computer_flag = 0;
	char players_piece[5];
	char *store_array[MAX];
	char position[MAX];
	int game_flag = 1;
	int i;
	
	init(array);
	
	//Decide if it is a  PLAYER_vs_COMPUTER or PLAYER vs PLAYER game
	vs_player_or_computer(&play_computer_flag);
	//printf("what play_computer_flag is set to in main is set to: %d\n", play_computer_flag); 
	if(play_computer_flag == 1)
	{
		printf("\nA ONE player game against the computer has been selected\n");
		//one_player();
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
	
//******************************************

	printf("\nprinted from inside of main players_piece : %s\n", players_piece);

	
	printf("\n PLAYER ONE's turn\n");
	if(strcmp(players_piece, "O") == 0)
	{	
		//game_flag = 1;
		while(game_flag)
		{
			//int i;
			for(i = 0; i < MAX; i++)
			{
				printf("\n NEXT TURN\n");
				printf("\n pick the number of the grid you would like to place your %s in : ", players_piece);
				fgets(position, 10, stdin);
				remove_newline(position);
				replace(array, atoi(position), players_piece);
				display_game_board(array);
				
				if(strcmp(players_piece, "O") == 0)
				{
					*players_piece = 'X';
				}
				else if(strcmp(players_piece, "X") == 0)
				{
					*players_piece = 'O';
				}
				printf("HELLOOOOO!! %s ", players_piece);
				
			
			}	
	
			
			
		/*	
			printf("\n PLAYER TWO's turn\n");
			printf("\n pick the number of the grid you would like to place your X in : ");
			fgets(position, 10, stdin);
			remove_newline(position);
			replace(array, atoi(position), "X");
			display_game_board(array);
			*/
		
		
		}
	}
	else if(strcmp(players_piece, "X") == 0)
	{
		printf("\n XXX \n");	
	}
	else
	{
		printf("\n ELSE \n");
	}
	
		
	
	//replace(array, 6, "X");
	//replace(array, 8, "X");
	//display_game_board(array);
	
	//search(array, "X", &*store_array);
	

	
	//printf("\n%s\n", array[1]);
	//printf("\n%s\n", store_array[5]);
	
	return 0;
}
//********** END OF MAIN FUNCTION *************


// Function for player vs player game code 
char* two_player(char *players_piece)
{
	printf("\nA TWO player game has been selected\n");
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

// Fuction to establish if you want to pay against the computer or 2 player game.
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
	
	//printf("The play_against_computer flag is set to inside the function vs_player_or_computer: %d\n", *flag);
}


// Inititiate the string to and empty string
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

// Delete Element at a position into an array
/*void delete(char* array[], int pos)
{
	int idx;
	for(idx = pos; idx < MAX; idx++)
	{
		array[idx -1] = array[idx];
	}
	for(idx = MAX - 1; idx >= pos; idx--)
	{
		array[idx] = array[idx - 1];
	}
	array[idx] = 0;
}*/
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
void search(char* array[], char* num, char* store_array[])
{
	int idx;
	for(idx = 0; idx < MAX; idx++)
	{
		if(strcmp(array[idx], num) == 0)
		{
			printf("%s found in position %d\n", num, idx + 1 );
			store_array[idx] = num;
			
		}
	}
	
	if(idx == MAX)
	{
		printf("%s is an INVALID CELL! \nChoose another cell from the available numbers\n", num);
	}
}
//***************************


