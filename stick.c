// Venessa Kuchenik
// CSE 224
// 09/29/2022
// This is a stick game where the user plays against the computer and whoever takes the last stick wins
//*****************************************************************************************************
#include <stdio.h>

void sticksOnScreen( int j);    // a function that will print the sticks remaining onto the screen

void main( int argc, char **argv)
{
        int i, status, count = 0, flag_usr, sticks = 21, comp_move, usr_move;
        char notSticks[120],  input[120];

        if( argc > 2 )          // if there are more than 2 arguments in the command line program will quit
        {
                printf("Enter no more than two commands.\n");
                return;
        }

        if( argc == 2)          // if there are exactly two arguments than the program will check what the second arg is and store the input in sticks
        {

                status = sscanf( argv[1], "%d%s", &sticks, notSticks);  // using example code from class to check if usr input has strings or other chars
                if( status != 1 )
                {
                        printf("Please enter a valid number of sticks you would like to play with next time.\n");
                        return;
                }
                if( sticks < 0 )        // this makes sure usr didn't input a neg # of sticks to play with
                {
                        printf("I suppose you could owe me a few sticks.\n");
                        return;
                }

                if( sticks == 0 )       // makes sure usr isn't trying to play with nothing
                {
                        printf("Now how are we supposed to play with no sticks?\n");
                        return;
                }
        }
        // explaining basic rules of the game / intro
        printf("Welcome to the stick picking game!\n");
        printf("The rules are simple:\n");
        printf("You may only take one, two, or three sticks at a time.\n");
        printf("Two illegal enteries in a row and you forfeit.\n");
        printf("Whomever takes the last stick wins. Good luck and may the best algori- I mean person win!\n\n");

        sticksOnScreen( sticks );       // function prints sticks on screen

        while(sticks > 0)       // this is mostly just to keep the loop going but by the time sticks <= 0, the bottom if statements and flags will catch it
        {
                printf("\nChoose a number of sticks to take: 1, 2, or 3?\n");
                fgets( input, 120, stdin);
                status = sscanf( input, "%d%s", &usr_move, notSticks);  // note that i'm resusing the variables notSticks and status,
                                                                        // they are treated as temp variables and are always overwritten with newest values
                if( status != 1)        // makes sure user input is in correct format
                {
                        count++;        // keeps track of number of times usr inputs illegal entries
                        if( count == 2 )        // when count = 2, will end game
                        {
                                printf("That was two illegal enteries in a row. I knew I'd win, I just didn't think it'd be this easy!\n");
                                break;
                        }
                        printf("Enter a valid integer!\n");     // this is printed the first time an illegal entry is made
                }

                if( status == 1)        // program continues game if usr inputs are formatted correctly
                {
                        count = 0;      //reseting count everytime usr input is legal

                        sticks = sticks - usr_move;     //user move
                        sticksOnScreen( sticks);
                        flag_usr = ( sticks == 0 )? 1 : 0;      // a flag that keeps track of when the usr has taken the last stick and wins
                        if( flag_usr == 1 )
                        {
                                printf("You won a MILLION DOLLARS!\n...\nI'm just kidding, you actualy won a pile of sticks, congrats anyhow!\n");
                                break;
                        }

                        if( sticks <= 3 )       // bfr algorithm, do a simple check to see if there are less than 4 sticks remaining
                        {
                                sticks = sticks - sticks;       //in this case the computer will take the remaining sticks
                                printf("\nComputers takes %d.\n", sticks);
                                sticksOnScreen( sticks );
                                printf("Seems that I've won this round. Perhaps better luck next time!\n");
                                break;
                        }

                        comp_move = sticks % 4; //algorithm
                        if( comp_move == 0)
                        {
                                printf("\nComputer takes one.\n");
                                sticks = sticks - 1;    // copmuter move, take one when mod 4 = 0
                                sticksOnScreen( sticks );
                        }
                        else
                        {
                                printf("\nComputer takes %d.\n", comp_move);
                                sticks = sticks - comp_move; // computer move
                                sticksOnScreen( sticks );
                        }
                }
        }

        printf("Game over.\n");

        return;
}

void sticksOnScreen( int y )
{
        int x;

        for( x=y; x>0; x--)     //loops through to print the correct # of sticks on screen
        {
                printf("|");
                if( x == 1 )
                {
                        printf(" (%d)\n", y);   // on the last loop through, will also print the numeric value of sticks left
                }
        }
        return;
}