#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int roll_dice(void);
bool play_game(void);
int main()
{
   int wins = 0;
   int losses = 0;	
   int userInput = 0;
   srand(time(0));
   printf("Hello! Welcome to the game of craps simulator\n");
   printf("Please press 1 to play or 0 to quit: "); 
   scanf("%d", &userInput);	
   while(userInput != 0)
   {
   	 if(userInput != 1)
   	 {
   	  printf("Your two choices are one and zero silly!\n ");	
	 }
	 if(play_game() == true)
	 {
	 	wins++;
	 }
	 else
	    losses++;
	 printf(" Do you want to play again?\n");
	 scanf("%d", &userInput);
   }
   printf("You won %d times and lost %d times ", wins, losses);  
	
}


int roll_dice(void)
{
	int dice_one = (rand() % 6 ) + 1;
	int dice_two = (rand() % 6 ) + 1;
	return dice_one + dice_two;
}

bool play_game(void)
{	
   int rollNumber = 1;
   int point = 0;
   int roll = roll_dice();
   
   printf("First dice roll! Here we go!\n");
   printf("you rolled %d\n", roll);
   if(rollNumber == 1)
   {
   	 if(roll == 7 || roll == 11)
   	 {
	   printf("Congrats you won! ");
	   return true;	
	 }
   	 else if(roll == 2 || roll == 3 || roll == 12)
   	 {
   	   printf("Aw shucks! You lost that round! ");
	   printf(" Better luck next time!");
	   return false;
     }
	 else 
	 {
	 	point = roll;
	 	printf("Your point is %d \n", point);
	 	rollNumber++;
	 } 	
	 	
   }
   if(rollNumber > 1)
   {
   	    for(bool i = true; i != false;)
        {
   	        roll = roll_dice();
   	        printf("Roll number %d! Your rolled %d\n", rollNumber, roll);
   	        if(roll == point)
   	        {
   	          printf("\nNice one! you won!"); 	
   	          i = false;	
			  return true;  
			}
			else if(roll == 7)
			{
			  printf("\nDang! you lost!");	
			  i = false;
			  return false;	
			}  
			else
			{
			  rollNumber++;	
			}
        }
   }
	
	
}

