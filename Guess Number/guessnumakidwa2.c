/* guessnumakidwa2.c
Write a program that interacts with the user, and predicts their final number!

Author: Abdullah Kidwai
Class: CS 141, Fall 2017, UIC
System: DevC++ on Windows

Sample Output:
Welcome to the number guessing game!
If you concentrate, sometimes you can connect to the electrons in the computer!
Let's try it.  Think of a three digit number.  (To make it harder, make the digits
all different from each other).  Type in your number: 725

I'll help you with the math.  Lets randomize those digits by reversing them, and do a subtraction:
725 (The original number)
- 527 (The reversed digits)
=====
198

Press 'Y' to continue or 'X' to exit... y
Now lets again scramble the numbers by reversing them, and adding them this time:
198
+ 891
=====
?

Before you continue, take a look at my number guess written down on paper.

Press 'D' to display the answer or 'X' to exit... D
Answer is 1089.

Press 'T' to test all possible combinations or 'X' to exit... T
For all numbers between 1..1000, the values that do not work are: 
  0   1   2   3   4   5   6   7   8   9  10  11  20  22  30  33  40  44  50  55  60  66  70  77  80  88
90  99 100 101 110 111 112 113 114 115 116 117 118 119 121 122 131 133 141 144 151 155 161 166 171 177
181 188 191 199 200 202 211 212 220 221 222 223 224 225 226 227 228 229 232 233 242 244 252 255 262 266 
272 277 282 288 292 299 300 303 311 313 322 323 330 331 332 333 334 335 336 337 338 339 343 344 353 355 
363 366 373 377 383 388 393 399 400 404 411 414 422 424 433 434 440 441 442 443 444 445 446 447 448 449 
454 455 464 466 474 477 484 488 494 499 500 505 511 515 522 525 533 535 544 545 550 551 552 553 554 555 
556 557 558 559 565 566 575 577 585 588 595 599 600 606 611 616 622 626 633 636 644 646 655 656 660 661 
662 663 664 665 666 667 668 669 676 677 686 688 696 699 700 707 711 717 722 727 733 737 744 747 755 757 
766 767 770 771 772 773 774 775 776 777 778 779 787 788 797 799 800 808 811 818 822 828 833 838 844 848 
855 858 866 868 877 878 880 881 882 883 884 885 886 887 888 889 898 899 900 909 911 919 922 929 933 939 
944 949 955 959 966 969 977 979 988 989 990 991 992 993 994 995 996 997 998 999 
There are 280 values that do not work. 

Thanks for playing!
*/
//--------------------------------------------------------------------------------
#include <stdio.h> #include <stdlib.h> #include <string.h> #include <ctype.h> #include <math.h>

//--------------------------------------------------------------------------------
// Display name and program information
void displayIdentifyingInformation() {
    printf("Author: Abdullah Kidwai\n"
      "Program: #1, TwentyFour\n"
      "TA: ------------\n"
      "Jan 23, 2017\n\n");
  } //end displayIdentifyingInformation()

//--------------------------------------------------------------------------------
// Display Instructions
void displayInstructions() {
    printf("Welcome to the number guessing game!\n"
      "If you concentrate, sometimes you can connect to the electrons in the computer!\n"
      "Let's try it.  Think of a three digit number.\n"
      "(To make it harder, make the digits all different from each other).\n\n"
      "Type in your number:");
  } //end displayInstructions()

//--------------------------------------------------------------------------------
// Get user input
int userInput(int x) { //takes in one integer
    scanf("%d", & x); //stores users input into variable
    return x; //returns users input
  } //end userInput

//--------------------------------------------------------------------------------
// Checks the user input and makes sure it falls within the game's criteria
int inputCheck(int x) { //takes in one integer
    int tryAgain = 0; //integer used for the loop
    int y; //stores the users input
    while (tryAgain != 1) { //start loop with condition
      y = userInput(x); //gets users input from function and stores it into an integer
      if (y > 0 && y < 1000) { //checks to see if the user input is between 0 and 1000
        int rightDigit = y % 10;
        int i = y / 10;
        int z = i;
        int middleDigit = z % 10;
        int leftDigit = z / 10;

        if (rightDigit == middleDigit) { //checks for repeating digit
          printf("*** All the digits must be different.\nTry again:");
          continue;
        } else if (rightDigit == leftDigit) { //checks for repeating digit
          printf("*** All the digits must be different.\nTry again:");
          continue;
        } else if (middleDigit == leftDigit) { //checks for repeating digit
          printf("*** All the digits must be different.\nTry again:");
          continue;
        } else {
          break;
        }
      } else {
        printf("*** Number must be less than 1000.\nTry again:");
        continue;
      }

    }

    return y; //returns the user input
  } //end inputCheck

//--------------------------------------------------------------------------------
// Takes the users input and reverses it
int reverseNumber(int x) { //takes in one integer
    int rightDigit = x % 10; // gets the right most digit
    x = x / 10; //gets the left and middle digit
    int y = x; //sets the new x value to y
    int middleDigit = y % 10; //gets the middle digit
    int leftDigit = y / 10; //gets the left digit

    int z = (rightDigit * 100) + (middleDigit * 10) + (leftDigit); //takes the three different numbers and stores them into one integer
    return z; //returns the reversed number
  } //end reverseNumber

//--------------------------------------------------------------------------------
// Changes the order of the user input and the reversed number so that the larger number appears first
void orderOfSubtraction(int x, int y) { //takes in two integers
    if (x > y) {
      printf("\nI'll help you with the math. Lets randomize those digits by reversing them, and do a subtraction:\n\n"
        "\t%.03d (The original number)\n", x);
      printf("      - %.3d (The reveresed number)\n", y);
      printf("      =====\n");
    } else {
      printf("\nI'll help you with the math. Lets randomize those digits by reversing them, and do a subtraction:\n\n"
        "\t%.03d (The reversed number)\n", y);
      printf("      - %.3d (The original number)\n", x);
      printf("      =====\n");
    }
  } //end orderOfSubtraction

//--------------------------------------------------------------------------------
// Subtracts two integers
int subtraction(int x, int y) { //takes in two integers
    int z; //create a new integer to store the difference
    if (x < y) {
      z = (y - x);
    } else {
      z = (x - y);
    }
    printf("        %.3d\n\n", z); //prints the difference
    return z; //returns the difference
  } //end subtraction

//--------------------------------------------------------------------------------
// Adds two integers
int addition(int x, int y) { //takes in two integers
    int z = x + y; //add the integers and puts the sum into a new integer
    return z; //returns the sum
  } //end addition

//--------------------------------------------------------------------------------
// Checks for all possible solutions that dont work
void incorrectSolutions() {
    int solution = 0;
    int counter = 0;
    int reverse_1; //stores the reverse of the the users input
    int difference; //stores the difference between the users input and its reverse
    int reverse_2; //stores the reverse of difference
    int sum; //stores the sum of difference and reverse_2
    int rightDigit; //stores right digit
    int i; //stores middle and left digit
    int z;
    int middleDigit; //stores middle digit
    int leftDigit; //stores left digit

    while (solution < 1000) {
      rightDigit = solution % 10;
      i = solution / 10;
      z = i;
      middleDigit = z % 10;
      leftDigit = z / 10;

      if (rightDigit == middleDigit) { //checks for repeating digit
        printf("%d ", solution);
        solution++;
        counter++;
      } else if (rightDigit == leftDigit) { //checks for repeating digit
        printf("%d ", solution);
        solution++;
        counter++;
      } else if (middleDigit == leftDigit) { //checks for repeating digit
        printf("%d ", solution);
        solution++;
        counter++;
      } else {
        solution++;
      }
    }
    printf("\n\nThere are %d values that do not work.\n\n", counter);
    printf("Thanks for playing!");
  } //end incorrectSolutions

//--------------------------------------------------------------------------------
//start main
int main() {
    displayIdentifyingInformation(); //print out header
    displayInstructions(); //print out the instructions
    int x; //integer used to pass through inputCheck
    int input; //stores users input
    char input_2; //stores users input when asked if they want to continue the game	
    char input_3; //stores users input when asked if they want to display the answer
    char input_4; //stores users input when asked if they want to display all the incorrect posibilities
    int exitGame = 0; //integer used for the loop condition

    while (exitGame != 1) { //start of while loop

      //gets the users input and checks to see if any of the digits are repeated
      input = inputCheck(x);

      //reverses the user input			
      int y = reverseNumber(input);

      //prints the numbers with the bigger number first
      orderOfSubtraction(input, y);

      //subtracts the two numbers	
      int z = subtraction(input, y);

      //reverses the new difference		
      int a = reverseNumber(z);

      //asks the user if they want to continue with the game			
      printf("Press 'Y' to continue or 'X' to exit...");
      //gets in users response
      scanf(" %c", & input_2);

      //makes a decision based off of the previous response
      if (input_2 == 'X' || input_2 == 'x') {
        break;
      } else if (input_2 == 'Y' || input_2 == 'y')

        printf("\nLets scramble the numbers agian by reversing them, and adding them this time:\n");
        printf("\t%.03d\n", z);
        printf("      + %.03d\n", a);
        printf("      =====\n          ?\n\n");

      //adds the difference with its reverse
      int b = addition(z, a);

      //asks the user if they want to see the answer
      printf("Before you continue, take a look at my number guess written down on paper.\n\n"
        "Press 'D' to display the answer or 'X' to exit...");
      //records the users input
      scanf(" %c", & input_3);

      //makes a decision based off of the previous response
      if (input_3 == 'X' || input_3 == 'x') {
        break;
      } else if (input_3 == 'D' || input_3 == 'd') {
        printf("\nAnswer is %d\n\n", b);
      }

      //ask the user if they want to see all the incorrect possible combinations
      printf("Press 'T' to test all possible combinations or 'X' to exit...");
      //record the users input
      scanf(" %c", & input_4);
      //makes a decision based off of the previous response
      if (input_4 == 'X' || input_4 == 'x') {
        printf("Thanks for playing!");
        break;
      } else if (input_4 == 'T' || input_4 == 't') {
        incorrectSolutions();
        break;
      }

    }
    return 0;
  } //end main
