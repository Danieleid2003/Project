#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Board_rows 6
#define Board_columns 7
#define FOUR 4
int bin = 0;
int board[Board_rows][Board_columns];
char name1[10];
char name2[10];
int player = 0;
/*Requires : nothing
    effect: initializes 2d array to 0's*/
void initializeBoard()
{
   for (int i = 0; i < Board_rows; i++)
   {
      for (int j = 0; j < Board_columns; j++)
      {
         board[i][j] = 0;
      }
   }
}
/*Requires : nothing
    effect: prints board to terminal*/
void printBoard()
{
   for (int i = 0; i < Board_rows; i++)
   {
      for (int j = 0; j < Board_columns; j++)
      {
         printf("|%d", board[i][j]);
      }
      printf("|\n");
   }
   printf("---------------\n");
}
/*Requires: nothing
    effect: fills column with variable player(Alternates)*/
void fill_bin()
{
   int level;

   for (level = Board_rows - 1; level >= 0; level--)
   {
      if (board[level][bin] == 0)
      {
         board[level][bin] = player;
         break;
      }
   }
}
/*Requires: nothing but input from user after printf ("\nChoose bin: ");
    effects :gives 6 bins that player chooses from then it calls fill_bin to fill out the bin chosen.
            If bin chosen is larger or less then 6 and 0 respectively then it prints board again for new input.
    Test case : Black box testing : Large numbers, negative numbers , 0 , string.
    */
void choose()
{
   int c;

   while (1)
   {
      
      fflush(stdin);
      printf("\nChoose bin: ");
      scanf("%d", &c);
      switch (c)
      {
      case 1:
         bin = 0;
         break;
      case 2:
         bin = 1;
         break;
      case 3:
         bin = 2;
         break;
      case 4:
         bin = 3;
         break;
      case 5:
         bin = 4;
         break;
      case 6:
         bin = 5;
         break;
      case 7:
         bin = 6;
         break;
      
      default:
         bin = 666;
         printf("\nWrong number! Try again.\n\n");
         printBoard(); 
         
      }
      if ((bin >= 0 && bin <= 6) && (board[0][bin] == 0))
      {
         fill_bin();
         player = (player == 1) ? 2 : 1;
         break;
      }
   }
}
/*Requires : player turn
    effects: Scans through the board to check if any of the player have one diagonally,horizontaly or vertically.
    No test case : Disc can either be 0 or 1 depending on srand();
    */

int check(int disc)
{
    int i, j, k;
    int count;
    int ways = 4;
    
    for (i = 0; i < Board_rows; ++i)
    {
        for (j = 0; j <= ways; ++j)
        {
            count = 0;
            for (k = 0; k < FOUR; ++k)
            {
                if (board[i][j + k] == disc) count++;
            }
            if (count == FOUR) return 1;
        }
    }
    
    
    ways = 3;
    
    for (j = 0; j < Board_columns; ++j)
    {
        for (i = 0; i < ways; ++i)
        {
            count = 0;
            for (k = 0; k < FOUR; ++k)
            {
                if (board[i + k][j] == disc) count++;
            }
            if (count == FOUR) return 1;
        }
    }
    
    int ii, jj;
    for (i = 1; i < Board_rows-1; i++)
    {
        for (j = 1; j < Board_columns-1; j++)
        {
            
            count = 0;
            for (ii = i, jj = j; (ii >= 0) || (jj >= 0); ii--, jj--)
            {
                if (board[ii][jj] == disc)
                {
                    count++;
                    if (count == FOUR) return 1;    
                }
                else
                    break;
            }
            count = 0;
            for (ii = i+1, jj = j+1; (ii <= Board_rows-1) || (jj <= Board_columns-1); ii++, jj++)
            {
                if (board[ii][jj] == disc)
                {
                    count++;
                    if (count == FOUR) return 1;
                }
                else
                    break;
            }
            
            
           count = 0;
      
            for (ii = i, jj = j; (ii <= Board_rows-1) || (jj >= 0); ii++, jj--)
            {
                if (board[ii][jj] == disc)
                {
                    count++;
                    if (count == FOUR) return 1;    
                }
                else
                    break;
            }
            count = 0;
            for (ii = i-1, jj = j+1; (ii >= 0) || (jj <= Board_columns-1); ii--, j++)
            {
                if (board[ii][jj] == disc)
                {
                    count++;
                    if (count == FOUR) return 1;
                }
                else
                    break;
            }
            
        }
    }
    return 0;
}
  int main() {
   printf("Enter the first player name : ");
   scanf("%9s", name1);
   printf("Enter the second player name : ");
   scanf("%9s", name2);
   initializeBoard();
   printBoard();
   srand(time(NULL));
   int i = rand() % 2;
   if (i == 0)
   {
      printf("player one starts\n");
      player = 1;
   }
   else
   {
      printf("player two starts\n");
      player = 2;
   }
   int counter = 0;
   while (counter != 42)
   {
       counter++;
      printf("Player %d, your turn!\n", player);
      choose();
      printf("\n\n");
      printBoard();
      if (check(1))
      {
         printf("\n\nPlayer 1 wins!\n\n");
         exit(1);
      }
      if (check(2))
      {
         printf("\n\nPlayer 2 wins!\n\n");
         exit(1);
      }
   }
   printf("It's a tie");
   return 0;
}

