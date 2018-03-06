/*pegJumpakidwa2.c
Sample output
Author: Abdullah Kidwai
Assignment: 2, PegJump
TA: Nianzu Ma, Tue 5pm

This program represents the peg jumping puzzle.

The board starts out with a single blank position, represented by
the 'O'.  To make a move, select the letter of the peg to be moved,
then the letter of the destination position. (e.g. the first move
might be: d a, meaning we move peg ‘d’ into blank position ‘a’.)
A peg must be able to jump over an adjacent peg into a blank for a 
move to be valid.  The jumped peg is then removed from the board.  
The game is over when there are no valid moves left to be made, or
when there is a single peg left.

At any point enter 'x' to exit the program.
-----------------------
  Board    Positions
    o          A              
   + +        B C            
  + + +      D E F         
 + + + +    G H I J      
+ + + + +  K L M N O  

1. Enter your move: D a


-----------------------
  Board    Positions
    +          A              
   o +        B C            
  o + +      D E F         
 + + + +    G H I J      
+ + + + +  K L M N O  

2. Enter your move: K D


-----------------------
  Board    Positions
    +          A              
   o +        B C            
  + + +      D E F         
 o + + +    G H I J      
o + + + +  K L M N O  

3. Enter your move: i g


-----------------------
  Board    Positions
    +          A              
   o +        B C            
  + + +      D E F         
 + o o +    G H I J      
o + + + +  K L M N O  

4. Enter your move: n p
   *** Invalid destination.  Please retry ****
4. Enter your move: q n
   *** Invalid source.  Please retry ****
4. Enter your move: j h
   *** Must jump a piece.  Please retry. ***
4. Enter your move: b i
   *** Source must have a piece.  Please retry. ***
4. Enter your move: l n
   *** Destination must be empty.  Please retry. ***
4. Enter your move: g b

-----------------------
  Board    Positions
    +          A              
   + +        B C            
  o + +      D E F         
 o o o +    G H I J      
o + + + +  K L M N O  

5. Enter your move: a d


-----------------------
  Board    Positions
    o          A              
   o +        B C            
  + + +      D E F         
 o o o +    G H I J      
o + + + +  K L M N O  

6. Enter your move: c h 


-----------------------
  Board    Positions
    o          A              
   o o        B C            
  + o +      D E F         
 o + o +    G H I J      
o + + + +  K L M N O  

7. Enter your move: l e


-----------------------
  Board    Positions
    o          A              
   o o        B C            
  + + +      D E F         
 o o o +    G H I J      
o o + + +  K L M N O  

8. Enter your move: j c


-----------------------
  Board    Positions
    o          A              
   o +        B C            
  + + o      D E F         
 o o o o    G H I J      
o o + + +  K L M N O  

9. Enter your move: c h


-----------------------
  Board    Positions
    o          A              
   o o        B C            
  + o o      D E F         
 o + o o    G H I J      
o o + + +  K L M N O  

10. Enter your move: n l


-----------------------
  Board    Positions
    o          A              
   o o        B C            
  + o o      D E F         
 o + o o    G H I J      
o + o o +  K L M N O  

11. Enter your move: d m


-----------------------
  Board    Positions
    o          A              
   o o        B C            
  o o o      D E F         
 o o o o    G H I J      
o + + o +  K L M N O  

12. Enter your move: l n


-----------------------
  Board    Positions
    o          A              
   o o        B C            
  o o o      D E F         
 o o o o    G H I J      
o o o + +  K L M N O  

13. Enter your move: o m


-----------------------
  Board    Positions
    o          A              
   o o        B C            
  o o o      D E F         
 o o o o    G H I J      
o o + o o  K L M N O  


# left  Rating
------  ---------------
  >4    Dufus
  4     Poor
  3     Mediocre
  2     Good Job
  1     Awesome Genius!

You had 1 left.  Awesome Genius!

Thanks for playing.  Exiting...
*/
//--------------------------------------------------------------------------------
#include <stdio.h> #include <stdlib.h> #include <string.h> #include <ctype.h> #include <math.h> #pragma warning(disable: 4996)

//--------------------------------------------------------------------------------
//Displays the author and the assignment information
void displayIdentifyingInformation() {
    printf("Author: Abdullah Kidwai\n"
      "Program: #2, Peg Jump\n"
      "TA: Nianzu Ma, Tue 5pm\n"
      "Feb 8, 2017\n\n");
  } //end displayIdentifyingInformation()

//--------------------------------------------------------------------------------
//Displays the instructions
void displayInstructions() {
    printf("This program represents the peg jumping puzzle.\n\n"
      "The board starts out with a single blank position, represented by\n"
      "the 'O'.  To make a move, select the letter of the peg to be moved,\n"
      "then the letter of the destination position. (e.g. the first move\n"
      "might be: d a, meaning we move peg 'd' into blank position 'a'.)\n"
      "A peg must be able to jump over an adjacent peg into a blank for a\n"
      "move to be valid.  The jumped peg is then removed from the board.\n"
      "The game is over when there are no valid moves left to be made, or\n"
      "when there is a single peg left.\n\n"
      "At any point enter 'x' to exit the program.\n\n");
  } //end displayInstructions()

//--------------------------------------------------------------------------------
//Prints dashes to makes the program aesthetically pleasing
void printDashes() {
    printf("\n-----------------------\n");
  } //end printDashes

//--------------------------------------------------------------------------------
//Displays the board
void displayBoard(char p1, char p2, char p3, char p4, char p5, char p6, char p7, char p8, char p9, char p10, char p11, char p12, char p13, char p14, char p15) {
    //takes in 15 char values and prints out the board

    printf("   Board    Positions\n");
    printf("     %c          A\n", p1);
    printf("    %c %c        B C\n", p2, p3);
    printf("   %c %c %c      D E F\n", p4, p5, p6);
    printf("  %c %c %c %c    G H I J\n", p7, p8, p9, p10);
    printf(" %c %c %c %c %c  K L M N O\n", p11, p12, p13, p14, p15);
  } //end displayBoard

//--------------------------------------------------------------------------------
//Gets users first input
char userInput1(char input_1, int i) {
    //takes in two value. the first is the users first input. the second is a counter used for the move number

    printf("\n%d. Enter your move: ", i); //asks the user for their input
    scanf(" %c", & input_1); //gets the users first input
    input_1 = toupper(input_1); //takes the input and uppercases it

    return input_1; //returns the input uppercased
  } //end userInput1

//--------------------------------------------------------------------------------
//Gets users second input
char userInput2(char input_2) {
    //takes in one char value

    scanf(" %c", & input_2); //gets the users second input
    input_2 = toupper(input_2); //takes the second input and uppercases it

    return input_2; //returns the second input uppercased
  } //end userInput2

//--------------------------------------------------------------------------------
//Checks to see if the destination is not directly next to the source
int destinationCheck(char input_1, char input_2) {
    //takes in the two inputs
    if (input_1 == 'A') { //if the first input is 'A'
      if (input_2 == 'B' || input_2 == 'C') { //AND if the second input is either 'B' or 'C'
        printf("*** Destination cannot be directly next to source.  Please retry ****");
        return -1; //then return -1
      }
      //if the first if statement does not work then continue to check with the next letter and do similar checks as the previous if statement
    } else if (input_1 == 'B') {
      if (input_2 == 'A' || input_2 == 'C' || input_2 == 'E' || input_2 == 'D') {
        printf("*** Destination cannot be directly next to source.  Please retry ****");
        return -1;
      }
    } else if (input_1 == 'C') {
      if (input_2 == 'A' || input_2 == 'B' || input_2 == 'E' || input_2 == 'F') {
        printf("*** Destination cannot be directly next to source.  Please retry ****");
        return -1;
      }
    } else if (input_1 == 'D') {
      if (input_2 == 'B' || input_2 == 'E' || input_2 == 'H' || input_2 == 'G') {
        printf("*** Destination cannot be directly next to source.  Please retry ****");
        return -1;
      }
    } else if (input_1 == 'E') {
      if (input_2 == 'B' || input_2 == 'C' || input_2 == 'F' || input_2 == 'I' || input_2 == 'H' || input_2 == 'D') {
        printf("*** Destination cannot be directly next to source.  Please retry ****");
        return -1;
      }
    } else if (input_1 == 'F') {
      if (input_2 == 'C' || input_2 == 'E' || input_2 == 'I' || input_2 == 'J') {
        printf("*** Destination cannot be directly next to source.  Please retry ****");
        return -1;
      }
    } else if (input_1 == 'G') {
      if (input_2 == 'D' || input_2 == 'H' || input_2 == 'L' || input_2 == 'K') {
        printf("*** Destination cannot be directly next to source.  Please retry ****");
        return -1;
      }
    } else if (input_1 == 'H') {
      if (input_2 == 'D' || input_2 == 'E' || input_2 == 'I' || input_2 == 'M' || input_2 == 'L' || input_2 == 'G') {
        printf("*** Destination cannot be directly next to source.  Please retry ****");
        return -1;
      }
    } else if (input_1 == 'I') {
      if (input_2 == 'E' || input_2 == 'F' || input_2 == 'J' || input_2 == 'N' || input_2 == 'M' || input_2 == 'H') {
        printf("*** Destination cannot be directly next to source.  Please retry ****");
        return -1;
      }
    } else if (input_1 == 'J') {
      if (input_2 == 'F' || input_2 == 'I' || input_2 == 'N' || input_2 == 'O') {
        printf("*** Destination cannot be directly next to source.  Please retry ****");
        return -1;
      }
    } else if (input_1 == 'K') {
      if (input_2 == 'G' || input_2 == 'L') {
        printf("*** Destination cannot be directly next to source.  Please retry ****");
        return -1;
      }
    } else if (input_1 == 'L') {
      if (input_2 == 'K' || input_2 == 'G' || input_2 == 'H' || input_2 == 'M') {
        printf("*** Destination cannot be directly next to source.  Please retry ****");
        return -1;
      }
    } else if (input_1 == 'M') {
      if (input_2 == 'L' || input_2 == 'I' || input_2 == 'N' || input_2 == 'H') {
        printf("*** Destination cannot be directly next to source.  Please retry ****");
        return -1;
      }
    } else if (input_1 == 'N') {
      if (input_2 == 'M' || input_2 == 'I' || input_2 == 'J' || input_2 == 'O') {
        printf("*** Destination cannot be directly next to source.  Please retry ****");
        return -1;
      }
    } else if (input_1 == 'O') {
      if (input_2 == 'N' || input_2 == 'J') {
        printf("*** Destination cannot be directly next to source.  Please retry ****");
        return -1;
      }
    }
  } //end destinationCheck

//--------------------------------------------------------------------------------
//Count how many pegs are left
int pegCounter(char p1, char p2, char p3, char p4, char p5, char p6, char p7, char p8, char p9, char p10, char p11, char p12, char p13, char p14, char p15) {
    //takes in 15 char values

    int counter = 0; //initialize the counter
	
	//looks for a '+' at each position and adds one to the counter if the there is a '+'
    if (p1 == '+') {
      counter++;
    }
    if (p2 == '+') {
      counter++;
    }
    if (p3 == '+') {
      counter++;
    }
    if (p4 == '+') {
      counter++;
    }
    if (p5 == '+') {
      counter++;
    }
    if (p6 == '+') {
      counter++;
    }
    if (p7 == '+') {
      counter++;
    }
    if (p8 == '+') {
      counter++;
    }
    if (p9 == '+') {
      counter++;
    }
    if (p10 == '+') {
      counter++;
    }
    if (p11 == '+') {
      counter++;
    }
    if (p12 == '+') {
      counter++;
    }
    if (p13 == '+') {
      counter++;
    }
    if (p14 == '+') {
      counter++;
    }
    if (p15 == '+') {
      counter++;
    }
    return counter; //return the total number of '+' left on the board
  } //end pegCounter

//--------------------------------------------------------------------------------
//Displays your results
void resultDisplay(int counter) {
    //takes in one int value

    if (counter > 4) {
      printf("You had %d left. Dufus", counter);
    } else if (counter == 4) {
      printf("You had %d left. Poor", counter);
    } else if (counter == 3) {
      printf("You had %d left. Mediocre", counter);
    } else if (counter == 2) {
      printf("You had %d left. Good Job", counter);
    } else if (counter == 1) {
      printf("You had %d left. Awesome Genius!", counter);
    }
  } //end resultDisplay

//--------------------------------------------------------------------------------
//Print the rating table
void printRatingChart() {
    printf("\n\n\n# left  Rating\n"
      "------  ---------------\n"
      " > 4    Dufus\n"
      "   4    Poor\n"
      "   3    Mediocre\n"
      "   2    Good Job\n"
      "   1    Awesome Genius!\n\n");
  } //end printRatingChart

//--------------------------------------------------------------------------------
//start main
int main() {
    displayIdentifyingInformation(); //calls the function displayIdentifyingInformation()
    displayInstructions(); //calls the function displayInstructions()

    char p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15; //these chars hold either '+' or 'o'
    p1 = 'o'; //initialize p1 to equal 'o'
    p2 = p3 = p4 = p5 = p6 = p7 = p8 = p9 = p10 = p11 = p12 = p13 = p14 = p15 = '+'; //initialize the rest of the chars to equal '+'

    char input_1 = ' '; //this holds the users first input and initializes it 
    char input_2 = ' '; //this holds the users second input and initializes it 
    int gameOver = 0; //condition used for the while loop
    int i = 0; //initialize the counter used for the print statement that says which turn it is
    int checkDestination = 0; //stores the return value of the function destinationCheck when it is called
    int counter = 0; //stores the return value of the the function peg value
    char temp = 0; //temporarily stores the piece located at the source
    char temp2 = 0; //temporarily stores the piece located at the destination

	displayBoard(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15); //calls the board and passes the 15 parameters into it
	
    //start while loop 
    while (gameOver != 1) {
      i++; //increases the counter by 1
      input_1 = userInput1(input_1, i); //stores the return valueof the function userInput() into input_1

      //if statement used to check if the user inputed 'X' or 'x' to exit the game
      if (input_1 == 'X') {
        //if the input is 'X' or 'x' then the program breaks out of the while loop
        break;
      }

      input_2 = userInput2(input_2); //stores the return valueof the function userInput() into input_2

      //checks to see if the first input is greater than or equal to 'A' and less than or equal to 'O'
      if (input_1 < 'A' || input_1 > 'O') {
        printf("*** Invalid source.  Please retry ****");
        i--; //subtracts 1 from i so that the turn number does not increase when you have to retry
        continue; //restarts the loop
      }
      //checks to see if the first input is greater than or equal to 'A' and less than or equal to 'O'
      if (input_2 < 'A' || input_2 > 'O') {
        printf("*** Invalid destination.  Please retry ****");
        i--; //subtracts 1 from i so that the turn number does not increase when you have to retry
        continue; //restarts the loop
      }

      checkDestination = destinationCheck(input_1, input_2); //stores the return value of destinationCheck() into checkDestination 
      if (checkDestination == -1) {
        i--; //subtracts 1 from i so that the turn number does not increase when you have to retry
        continue; //restarts the loop
      }

      //if the first input is 'A'	
      if (input_1 == 'A') {
        //AND if the position is empty
        if (p1 == 'o') {
          printf("*** Source must have a piece.  Please retry. ***");
          i--; //subtracts 1 from i so that the turn number does not increase when you retry
          continue; //restart the loop
        }
        //if the second if statements condition is not true then 
        temp = p1; //store the piece of the position into temp
        p1 = 'o'; //change the piece into 'o'
        //now it checks the possible second inputs and does the similar steps when checking the first input
        if (input_2 == 'D') {
          if (p4 == '+') {
            printf("*** Destination must be empty.  Please retry. ***");
            i--;
            p1 = temp;
            continue;
          }
          temp2 = p4;
          p4 = '+';
          if (p2 == 'o') {
            printf("*** Must jump a piece.  Please retry. ***");
            i--;
            p1 = temp;
            p4 = temp2;
            continue;
          }
          p2 = 'o';
        } else if (input_2 == 'F') {
          if (p6 == '+') {
            printf("*** Destination must be empty.  Please retry. ***");
            i--;
            p1 = temp;
            continue;
          }
          temp2 = p6;
          p6 = '+';
          if (p3 == 'o') {
            printf("*** Must jump a piece.  Please retry. ***");
            i--;
            p1 = temp;
            p6 = temp2;
            continue;
          }
          //if the program makes it all the way down here then change the middle piece into 'o'
          p3 = 'o';
        }
      }
      //if the first if statement does not work then check if the input is the next letter in line and continue doing the same thing over and over again
      else if (input_1 == 'B') {
        if (p2 == 'o') {
          printf("*** Source must have a piece.  Please retry. ***");
          i--;
          continue;
        }
        temp = p2;
        p2 = 'o';
        if (input_2 == 'G') {
          if (p7 == '+') {
            printf("*** Destination must be empty.  Please retry. ***");
            i--;
            p2 = temp;
            continue;
          }
          temp2 = p7;
          p7 = '+';
          if (p4 == 'o') {
            printf("*** Must jump a piece.  Please retry. ***");
            i--;
            p2 = temp;
            p7 = temp2;
            continue;
          }
          p4 = 'o';
        } else if (input_2 == 'I') {
          if (p9 == '+') {
            printf("*** Destination must be empty.  Please retry. ***");
            i--;
            p2 = temp;
            continue;
          }
          temp2 = p9;
          p9 = '+';
          if (p5 == 'o') {
            printf("*** Must jump a piece.  Please retry. ***");
            i--;
            p2 = temp;
            p9 = temp2;
            continue;
          }
          p5 = 'o';
        }
      } else if (input_1 == 'C') {
        if (p3 == 'o') {
          printf("*** Source must have a piece.  Please retry. ***");
          i--;
          continue;
        }
        temp = p3;
        p3 = 'o';
        if (input_2 == 'H') {
          if (p8 == '+') {
            printf("*** Destination must be empty.  Please retry. ***");
            i--;
            p3 = temp;
            continue;
          }
          temp2 = p8;
          p8 = '+';
          if (p5 == 'o') {
            printf("*** Must jump a piece.  Please retry. ***");
            i--;
            p3 = temp;
            p8 = temp2;
            continue;
          }
          p5 = 'o';
        } else if (input_2 == 'J') {
          if (p10 == '+') {
            printf("*** Destination must be empty.  Please retry. ***");
            i--;
            p3 = temp;
            continue;
          }
          temp2 = p10;
          p10 = '+';
          if (p6 == 'o') {
            printf("*** Must jump a piece.  Please retry. ***");
            i--;
            p3 = temp;
            p10 = temp2;
            continue;
          }
          p6 = 'o';
        }
      } else if (input_1 == 'D') {
        if (p4 == 'o') {
          printf("*** Source must have a piece.  Please retry. ***");
          i--;
          continue;
        }
        temp = p4;
        p4 = 'o';
        if (input_2 == 'A') {
          if (p1 == '+') {
            printf("*** Destination must be empty.  Please retry. ***");
            i--;
            p4 = temp;
            continue;
          }
          temp2 = p1;
          p1 = '+';
          if (p2 == 'o') {
            printf("*** Must jump a piece.  Please retry. ***");
            i--;
            p4 = temp;
            p1 = temp2;
            continue;
          }
          p2 = 'o';
        } else if (input_2 == 'K') {
          if (p11 == '+') {
            printf("*** Destination must be empty.  Please retry. ***");
            i--;
            p4 = temp;
            continue;
          }
          temp2 = p11;
          p11 = '+';
          if (p7 == 'o') {
            printf("*** Must jump a piece.  Please retry. ***");
            i--;
            p4 = temp;
            p11 = temp2;
            continue;
          }
          p7 = 'o';
        } else if (input_2 == 'M') {
          if (p13 == '+') {
            printf("*** Destination must be empty.  Please retry. ***");
            i--;
            p4 = temp;
            continue;
          }
          temp2 = p13;
          p13 = '+';
          if (p8 == 'o') {
            printf("*** Must jump a piece.  Please retry. ***");
            i--;
            p4 = temp;
            p13 = temp2;
            continue;
          }
          p8 = 'o';
        } else if (input_2 == 'F') {
          if (p6 == '+') {
            printf("*** Destination must be empty.  Please retry. ***");
            i--;
            p4 = temp;
            continue;
          }
          temp2 = p6;
          p6 = '+';
          if (p5 == 'o') {
            printf("*** Must jump a piece.  Please retry. ***");
            i--;
            p4 = temp;
            p6 = temp2;
            continue;
          }
          p5 = 'o';
        }
      } else if (input_1 == 'E') {
        if (p5 == 'o') {
          printf("*** Source must have a piece.  Please retry. ***");
          i--;
          continue;
        }
        temp = p5;
        p5 = 'o';
        if (input_2 == 'L') {
          if (p12 == '+') {
            printf("*** Destination must be empty.  Please retry. ***");
            i--;
            p5 = temp;
            continue;
          }
          temp2 = p12;
          p12 = '+';
          if (p8 == 'o') {
            printf("*** Must jump a piece.  Please retry. ***");
            i--;
            p5 = temp;
            p12 = temp2;
            continue;
          }
          p8 = 'o';
        } else if (input_2 == 'N') {
          if (p14 == '+') {
            printf("*** Destination must be empty.  Please retry. ***");
            i--;
            p5 = temp;
            continue;
          }
          temp2 = p14;
          p14 = '+';
          if (p9 == 'o') {
            printf("*** Must jump a piece.  Please retry. ***");
            i--;
            p5 = temp;
            p14 = temp2;
            continue;
          }
          p9 = 'o';
        }
      } else if (input_1 == 'F') {
        if (p6 == 'o') {
          printf("*** Source must have a piece.  Please retry. ***");
          i--;
          continue;
        }
        temp = p6;
        p6 = 'o';
        if (input_2 == 'D') {
          if (p4 == '+') {
            printf("*** Destination must be empty.  Please retry. ***");
            i--;
            p6 = temp;
            continue;
          }
          temp2 = p4;
          p4 = '+';
          if (p5 == 'o') {
            printf("*** Must jump a piece.  Please retry. ***");
            i--;
            p6 = temp;
            p4 = temp2;
            continue;
          }
          p5 = 'o';
        } else if (input_2 == 'M') {
          if (p13 == '+') {
            printf("*** Destination must be empty.  Please retry. ***");
            i--;
            p6 = temp;
            continue;
          }
          temp2 = p13;
          p13 = '+';
          if (p9 == 'o') {
            printf("*** Must jump a piece.  Please retry. ***");
            i--;
            p6 = temp;
            p13 = temp2;
            continue;
          }
          p9 = 'o';
        } else if (input_2 == 'O') {
          if (p15 == '+') {
            printf("*** Destination must be empty.  Please retry. ***");
            i--;
            p6 = temp;
            continue;
          }
          temp2 = p15;
          p15 = '+';
          if (p10 == 'o') {
            printf("*** Must jump a piece.  Please retry. ***");
            i--;
            p6 = temp;
            p15 = temp2;
            continue;
          }
          p10 = 'o';
        } else if (input_2 == 'A') {
          if (p1 == '+') {
            printf("*** Destination must be empty.  Please retry. ***");
            i--;
            p6 = temp;
            continue;
          }
          temp2 = p1;
          p1 = '+';
          if (p3 == 'o') {
            printf("*** Must jump a piece.  Please retry. ***");
            i--;
            p6 = temp;
            p1 = temp2;
            continue;
          }
          p3 = 'o';
        }
      } else if (input_1 == 'G') {
        if (p7 == 'o') {
          printf("*** Source must have a piece.  Please retry. ***");
          i--;
          continue;
        }
        temp = p7;
        p7 = 'o';
        if (input_2 == 'B') {
          if (p2 == '+') {
            printf("*** Destination must be empty.  Please retry. ***");
            i--;
            p7 = temp;
            continue;
          }
          temp2 = p2;
          p2 = '+';
          if (p4 == 'o') {
            printf("*** Must jump a piece.  Please retry. ***");
            i--;
            p7 = temp;
            p2 = temp2;
            continue;
          }
          p4 = 'o';
        } else if (input_2 == 'I') {
          if (p9 == '+') {
            printf("*** Destination must be empty.  Please retry. ***");
            i--;
            p7 = temp;
            continue;
          }
          temp2 = p9;
          p9 = '+';
          if (p8 == 'o') {
            printf("*** Must jump a piece.  Please retry. ***");
            i--;
            p7 = temp;
            p9 = temp2;
            continue;
          }
          p8 = 'o';
        }
      } else if (input_1 == 'H') {
        if (p8 == 'o') {
          printf("*** Source must have a piece.  Please retry. ***");
          i--;
          continue;
        }
        temp = p8;
        p8 = 'o';
        if (input_2 == 'C') {
          if (p3 == '+') {
            printf("*** Destination must be empty.  Please retry. ***");
            i--;
            p8 = temp;
            continue;
          }
          temp2 = p3;
          p3 = '+';
          if (p5 == 'o') {
            printf("*** Must jump a piece.  Please retry. ***");
            i--;
            p8 = temp;
            p3 = temp2;
            continue;
          }
          p5 = 'o';
        } else if (input_2 == 'J') {
          if (p10 == '+') {
            printf("*** Destination must be empty.  Please retry. ***");
            i--;
            p8 = temp;
            continue;
          }
          temp2 = p10;
          p10 = '+';
          if (p9 == 'o') {
            printf("*** Must jump a piece.  Please retry. ***");
            i--;
            p8 = temp;
            p10 = temp2;
            continue;
          }
          p9 = 'o';
        }
      } else if (input_1 == 'I') {
        if (p9 == 'o') {
          printf("*** Source must have a piece.  Please retry. ***");
          i--;
          continue;
        }
        temp = p9;
        p9 = 'o';
        if (input_2 == 'B') {
          if (p2 == '+') {
            printf("*** Destination must be empty.  Please retry. ***");
            i--;
            p9 = temp;
            continue;
          }
          temp2 = p2;
          p2 = '+';
          if (p5 == 'o') {
            printf("*** Must jump a piece.  Please retry. ***");
            i--;
            p9 = temp;
            p2 = temp2;
            continue;
          }
          p5 = 'o';
        } else if (input_2 == 'G') {
          if (p7 == '+') {
            printf("*** Destination must be empty.  Please retry. ***");
            i--;
            p9 = temp;
            continue;
          }
          temp2 = p7;
          p7 = '+';
          if (p8 == 'o') {
            printf("*** Must jump a piece.  Please retry. ***");
            i--;
            p9 = temp;
            p7 = temp2;
            continue;
          }
          p8 = 'o';
        }
      } else if (input_1 == 'J') {
        if (p10 == 'o') {
          printf("*** Source must have a piece.  Please retry. ***");
          i--;
          continue;
        }
        temp = p10;
        p10 = 'o';
        if (input_2 == 'C') {
          if (p3 == '+') {
            printf("*** Destination must be empty.  Please retry. ***");
            i--;
            p10 = temp;
            continue;
          }
          temp2 = p3;
          p3 = '+';
          if (p6 == 'o') {
            printf("*** Must jump a piece.  Please retry. ***");
            i--;
            p10 = temp;
            p3 = temp2;
            continue;
          }
          p6 = 'o';
        } else if (input_2 == 'H') {
          if (p8 == '+') {
            printf("*** Destination must be empty.  Please retry. ***");
            i--;
            p10 = temp;
            continue;
          }
          temp2 = p8;
          p8 = '+';
          if (p9 == 'o') {
            printf("*** Must jump a piece.  Please retry. ***");
            i--;
            p10 = temp;
            p8 = temp2;
            continue;
          }
          p9 = 'o';
        }
      } else if (input_1 == 'K') {
        if (p11 == 'o') {
          printf("*** Source must have a piece.  Please retry. ***");
          i--;
          continue;
        }
        temp = p11;
        p11 = 'o';
        if (input_2 == 'D') {
          if (p4 == '+') {
            printf("*** Destination must be empty.  Please retry. ***");
            i--;
            p11 = temp;
            continue;
          }
          temp2 = p4;
          p4 = '+';
          if (p7 == 'o') {
            printf("*** Must jump a piece.  Please retry. ***");
            i--;
            p11 = temp;
            p4 = temp2;
            continue;
          }
          p7 = 'o';
        } else if (input_2 == 'M') {
          if (p13 == '+') {
            printf("*** Destination must be empty.  Please retry. ***");
            i--;
            p11 = temp;
            continue;
          }
          temp2 = p13;
          p13 = '+';
          if (p12 == 'o') {
            printf("*** Must jump a piece.  Please retry. ***");
            i--;
            p11 = temp;
            p13 = temp2;
            continue;
          }
          p12 = 'o';
        }
      } else if (input_1 == 'L') {
        if (p12 == 'o') {
          printf("*** Source must have a piece.  Please retry. ***");
          i--;
          continue;
        }
        temp = p12;
        p12 = 'o';
        if (input_2 == 'E') {
          if (p5 == '+') {
            printf("*** Destination must be empty.  Please retry. ***");
            i--;
            p12 = temp;
            continue;
          }
          temp2 = p5;
          p5 = '+';
          if (p8 == 'o') {
            printf("*** Must jump a piece.  Please retry. ***");
            i--;
            p12 = temp;
            p5 = temp2;
            continue;
          }
          p8 = 'o';
        } else if (input_2 == 'N') {
          if (p14 == '+') {
            printf("*** Destination must be empty.  Please retry. ***");
            i--;
            p12 = temp;
            continue;
          }
          temp2 = p14;
          p14 = '+';
          if (p13 == 'o') {
            printf("*** Must jump a piece.  Please retry. ***");
            i--;
            p12 = temp;
            p14 = temp2;
            continue;
          }
          p13 = 'o';
        }
      } else if (input_1 == 'M') {
        if (p13 == 'o') {
          printf("*** Source must have a piece.  Please retry. ***");
          i--;
          continue;
        }
        temp = p13;
        p13 = 'o';
        if (input_2 == 'D') {
          if (p4 == '+') {
            printf("*** Destination must be empty.  Please retry. ***");
            i--;
            p13 = temp;
            continue;
          }
          temp2 = p4;
          p4 = '+';
          if (p8 == 'o') {
            printf("*** Must jump a piece.  Please retry. ***");
            i--;
            p13 = temp;
            p4 = temp2;
            continue;
          }
          p8 = 'o';
        } else if (input_2 == 'O') {
          if (p15 == '+') {
            printf("*** Destination must be empty.  Please retry. ***");
            i--;
            p13 = temp;
            continue;
          }
          temp2 = p15;
          p15 = '+';
          if (p14 == 'o') {
            printf("*** Must jump a piece.  Please retry. ***");
            i--;
            p13 = temp;
            p15 = temp2;
            continue;
          }
          p14 = 'o';
        } else if (input_2 == 'F') {
          if (p6 == '+') {
            printf("*** Destination must be empty.  Please retry. ***");
            i--;
            p13 = temp;
            continue;
          }
          temp2 = p6;
          p6 = '+';
          if (p9 == 'o') {
            printf("*** Must jump a piece.  Please retry. ***");
            i--;
            p13 = temp;
            p6 = temp2;
            continue;
          }
          p9 = 'o';
        } else if (input_2 == 'K') {
          if (p11 == '+') {
            printf("*** Destination must be empty.  Please retry. ***");
            i--;
            p13 = temp;
            continue;
          }
          temp2 = p11;
          p11 = '+';
          if (p12 == 'o') {
            printf("*** Must jump a piece.  Please retry. ***");
            i--;
            p13 = temp;
            p11 = temp2;
            continue;
          }
          p12 = 'o';
        }
      } else if (input_1 == 'N') {
        if (p14 == 'o') {
          printf("*** Source must have a piece.  Please retry. ***");
          i--;
          continue;
        }
        temp = p14;
        p14 = 'o';
        if (input_2 == 'E') {
          if (p5 == '+') {
            printf("*** Destination must be empty.  Please retry. ***");
            i--;
            p14 = temp;
            continue;
          }
          temp2 = p5;
          p5 = '+';
          if (p9 == 'o') {
            printf("*** Must jump a piece.  Please retry. ***");
            i--;
            p14 = temp;
            p5 = temp2;
            continue;
          }
          p9 = 'o';
        } else if (input_2 == 'L') {
          if (p12 == '+') {
            printf("*** Destination must be empty.  Please retry. ***");
            i--;
            p14 = temp;
            continue;
          }
          temp2 = p12;
          p12 = '+';
          if (p13 == 'o') {
            printf("*** Must jump a piece.  Please retry. ***");
            i--;
            p14 = temp;
            p12 = temp2;
            continue;
          }
          p13 = 'o';
        }
      } else if (input_1 == 'O') {
        if (p15 == 'o') {
          printf("*** Source must have a piece.  Please retry. ***");
          i--;
          continue;
        }
        temp = p15;
        p15 = 'o';
        if (input_2 == 'M') {
          if (p13 == '+') {
            printf("*** Destination must be empty.  Please retry. ***");
            i--;
            p15 = temp;
            continue;
          }
          temp2 = p13;
          p13 = '+';
          if (p14 == 'o') {
            printf("*** Must jump a piece.  Please retry. ***");
            i--;
            p15 = temp;
            p13 = temp2;
            continue;
          }
          p14 = 'o';
        } else if (input_2 == 'F') {
          if (p6 == '+') {
            printf("*** Destination must be empty.  Please retry. ***");
            i--;
            p15 = temp;
            continue;
          }
          temp2 = p6;
          p6 = '+';
          if (p10 == 'o') {
            printf("*** Must jump a piece.  Please retry. ***");
            i--;
            p15 = temp;
            p6 = temp2;
            continue;
          }
          p10 = 'o';
        }
      }

      printDashes(); //calls the function to print dashes
      displayBoard(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15); //displays the board after the changes

      counter = pegCounter(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15); //calls the function pegCounter() into counter
      //if the number of pegs left is 1 then the program leaves the while loop
      if (counter == 1) {
        break;
      }
    } //end while loop

    counter = pegCounter(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15); //calls the function pegCounter() into counter after leaving the while loop
    printRatingChart(); //calls the function printRatingChart()
    resultDisplay(counter); //calls the function resultDisplay() passed with the number stored into counter

    return 0;
  } //end main
