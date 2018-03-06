/* prog3Pentago_akidwa2_hqurai3.c

Program 3: Pentago
Authors: Abdullah Kidwai, Hamzah Quraishi
NetID: akidwa2,
CS 141
Professor: Dale Reed
Lab: 5pm, 2pm

Sample Output:
	Author: Dale Reed
	Program: #3, Pentago
	TA: Karla Templar, Tues 10
	Feb 5, 2017
	
	Play the two-player game of Pentago. Be the first to get 5 in a row.
	
	Pentago is played on a 6 by 6 board, divided into four 3 by 3
	quadrants.  There are two players, X and O, who alternate turns.
	The goal of each player is to get five of their pieces in a row,
	either horizontally, vertically, or diagonally.
	
	Players take turns placing one of their pieces into an empty
	space anywhere on the board, then choosing one of the four
	board quadrants to rotate 90 degrees left or right.
	
	If both players get five in a row at the same time, or the
	last move is played with no five in a row, the game is a tie.
	If a player makes five a row by placing a piece, there is no need
	to rotate a quadrant and the player wins immediately.
	
	Play online at:  https://perfect-pentago.net
	Purchase at:     www.mindtwisterusa.com
	
	For each move provide four inputs:
	row (A-F), column (1-6), quadrant (1-4), rotation direction (L or R)
	For instance input of B32R places the next piece at B3 and then
	would rotate quadrant 2 (upper-right) to the right (clockwise).
	
	At any point enter 'x' to exit the program.
	
	1   1 2 3 4 5 6   2
	-----------
	A:  . . . . . .  :A
	B:  . . . . . .  :B
	C:  . . . . . .  :C
	D:  . . . . . .  :D
	E:  . . . . . .  :E
	F:  . . . . . .  :F
	-----------
	3   1 2 3 4 5 6   4
	
	1. Enter row, column, quadrant, direction for X: c31r
	
	1   1 2 3 4 5 6   2
	-----------
	A:  . . . . . .  :A
	B:  . . . . . .  :B
	C:  X . . . . .  :C
	D:  . . . . . .  :D
	E:  . . . . . .  :E
	F:  . . . . . .  :F
	-----------
	3   1 2 3 4 5 6   4
	
	2. Enter row, column, quadrant, direction for O: A5 3R
	
	1   1 2 3 4 5 6   2
	-----------
	A:  . . . . O .  :A
	B:  . . . . . .  :B
	C:  X . . . . .  :C
	D:  . . . . . .  :D
	E:  . . . . . .  :E
	F:  . . . . . .  :F
	-----------
	3   1 2 3 4 5 6   4
	
	3. Enter row, column, quadrant, direction for X: G05h
	*** Invalid move row.  Please retry.
	3. Enter row, column, quadrant, direction for X: c05h
	*** Invalid move column.  Please retry.
	3. Enter row, column, quadrant, direction for X: c25h
	*** Selected quadrant is invalid.  Please retry.
	3. Enter row, column, quadrant, direction for X: c21h
	*** Quadrant rotation direction is invalid.  Please retry.
	3. Enter row, column, quadrant, direction for X: c2 1r
	
	1   1 2 3 4 5 6   2
	-----------
	A:  X . . . O .  :A
	B:  X . . . . .  :B
	C:  . . . . . .  :C
	D:  . . . . . .  :D
	E:  . . . . . .  :E
	F:  . . . . . .  :F
	-----------
	3   1 2 3 4 5 6   4
	
	4. Enter row, column, quadrant, direction for O: b 6 4 l
	
	1   1 2 3 4 5 6   2
	-----------
	A:  X . . . O .  :A
	B:  X . . . . O  :B
	C:  . . . . . .  :C
	D:  . . . . . .  :D
	E:  . . . . . .  :E
	F:  . . . . . .  :F
	-----------
	3   1 2 3 4 5 6   4
	
	5. Enter row, column, quadrant, direction for X: c53l
	
	1   1 2 3 4 5 6   2
	-----------
	A:  X . . . O .  :A
	B:  X . . . . O  :B
	C:  . . . . X .  :C
	D:  . . . . . .  :D
	E:  . . . . . .  :E
	F:  . . . . . .  :F
	-----------
	3   1 2 3 4 5 6   4
	
	6. Enter row, column, quadrant, direction for O: d6 3r
	
	1   1 2 3 4 5 6   2
	-----------
	A:  X . . . O .  :A
	B:  X . . . . O  :B
	C:  . . . . X .  :C
	D:  . . . . . O  :D
	E:  . . . . . .  :E
	F:  . . . . . .  :F
	-----------
	3   1 2 3 4 5 6   4
	
	7. Enter row, column, quadrant, direction for X: c41r
	
	1   1 2 3 4 5 6   2
	-----------
	A:  . X X . O .  :A
	B:  . . . . . O  :B
	C:  . . . X X .  :C
	D:  . . . . . O  :D
	E:  . . . . . .  :E
	F:  . . . . . .  :F
	-----------
	3   1 2 3 4 5 6   4
	
	8. Enter row, column, quadrant, direction for O: e14l
	
	1   1 2 3 4 5 6   2
	-----------
	A:  . X X . O .  :A
	B:  . . . . . O  :B
	C:  . . . X X .  :C
	D:  . . . O . .  :D
	E:  O . . . . .  :E
	F:  . . . . . .  :F
	-----------
	3   1 2 3 4 5 6   4
	
	9. Enter row, column, quadrant, direction for X: c6 2r
	
	1   1 2 3 4 5 6   2
	-----------
	A:  . X X X . .  :A
	B:  . . . X . O  :B
	C:  . . . X O .  :C
	D:  . . . O . .  :D
	E:  O . . . . .  :E
	F:  . . . . . .  :F
	-----------
	3   1 2 3 4 5 6   4
	
	10. Enter row, column, quadrant, direction for O: f2 3l
	O has won the game!
	
	1   1 2 3 4 5 6   2
	-----------
	A:  . X X X . .  :A
	B:  . . . X . O  :B
	C:  . . . X O .  :C
	D:  . . . O . .  :D
	E:  . . O . . .  :E
	F:  . O . . . .  :F
	-----------
	3   1 2 3 4 5 6   4
	
	Thanks for playing.  Exiting...
*/
#include <stdio.h>
#include <stdlib.h> 
#include <math.h> 
#include <string.h> 
#include <ctype.h>

//--------------------------------------------------------------------------------
//Displays the authors and the assignment name
  void info() {
    printf("Author: Hamzah Quraishi, Abdullah Kidwai\n"
      "Program: #3, Pentago\n"
      "TA:Mamouta Samanta, Tues 2:00\n"
      "Feb 26th, 2017\n\n");
  } //end info()


//--------------------------------------------------------------------------------
//Displays the instructions
void intro() {
    printf("Play the two-player game of Pentago. Be the first to get 5 in a row.\n\n"
      "Pentago is played on a 6 by 6 board, divided into four 3 by 3\n"
      "quadrants.There are two players, X and O, who alternate turns.\n"
      "The goal of each player is to get five of their pieces in a row,\n"
      "either horizontally, vertically, or diagonally.\n\n"
      "Players take turns placing one of their pieces into an empty\n"
      "space anywhere on the board, then choosing one of the four\n"
      "board quadrants to rotate 90 degrees left or right.\n\n"
      "If both players get five in a row at the same time, or the\n"
      "last move is played with no five in a row, the game is a tie.\n"
      "If a player makes five a row by placing a piece, there is no need\n"
      "to rotate a quadrant and the player wins immediately.\n\n"
      "Play online at:  https://perfect-pentago.net\n"
      "Purchase at:     www.mindtwisterusa.com\n\n"
      "For each move provide four inputs:\n"
      "row(A - F), column(1 - 6), quadrant(1 - 4), rotation direction(L or R)\n"
      "For instance input of B32R places the next piece at B3 and then\n"
      "would rotate quadrant 2 (lower - left) to the right(clockwise).\n\n"
      "At any point enter 'x' to exit the program.\n\n");
  } //end intro


//--------------------------------------------------------------------------------
//Displays the board
void displayBoard(char board[6][6]) {

    char firstA1 = 'A'; //To get the alphabets on the left of theboard
    char firstA2 = 'A'; //To get the alphabets on the right of the board.

    int i, j; //used for the loop conditions
    printf(" 1  1 2 3 4 5 6   2\n");
    printf("    -----------  \n");
    for (i = 0; i < 6; i++) { //therse are the number of rows

      if (firstA1 < 'G') {
        printf(" %c:", firstA1++); //prints the rows
      }
      for (j = 0; j < 6; j++) { //these are the number of columns om the board
        printf(" %c", board[i][j]);
      }
      if (firstA2 < 'G') {
        printf("  :%c", firstA2++); //prints the columns
      }
      printf("\n");
    }
    printf("    -----------  \n");
    printf(" 3  1 2 3 4 5 6   4\n");

  } //end displayBoard()


//--------------------------------------------------------------------------------
//Checks to see if the input is between the specific values
int inputValidation(char userRow, int userColumn, int userQuad, char userRot, char board[6][6]) {
    if (userRow < 'A' || userRow > 'F') { //checks to see if the row input is between A and F
      printf("*** Invalid move row. Please retry.\n");
      return -1;
    }
    if (userColumn < 1 || userColumn > 6) { //checks to see if the column input is between 1 and 6
      printf("*** Invalid move column. Please retry.\n");
      return -1;
    }
    if (userQuad < 1 || userQuad > 4) { //checks to see if the quadrant input is between 1 and 4
      printf("*** Selected quadrant is invalid. Please retry.\n");
      return -1;
    }
    if (userRot != 'R' && userRot != 'L') { //checks to see if the rotation input is either R or L
      printf("*** Quadrant rotation direction is invalid. Please retry.\n");
      return -1;
    }
  } //end inputValidation()


//--------------------------------------------------------------------------------
//converts the row input to a number and checks if the input position is empty
int spotCheck(char board[6][6], char userRow, int userColumn) {
    if (userRow == 'A') { //changes userinput A to 0 and does the similar things with the rest of the letters
      userRow = 0;
    } else if (userRow == 'B') {
      userRow = 1;
    } else if (userRow == 'C') {
      userRow = 2;
    } else if (userRow == 'D') {
      userRow = 3;
    } else if (userRow == 'E') {
      userRow = 4;
    } else if (userRow == 'F') {
      userRow = 5;
    }
    //if the postion has an X or an O then it returns a -1
    if (board[userRow][userColumn - 1] == 'X' || board[userRow][userColumn - 1] == 'O') {
      printf("*** Position must be empty. Please retry\n");
      return -1;
    }
  } //end spotCheck()


//--------------------------------------------------------------------------------
//rotates the quadrant to the right
void rightRotation(char board[6][6], int i, int j) {
    int temp; //temporarily hold the value for the starting array

    //these next instruction rotate a quadrant to the right starting with the corner pieces first then the middle ones
    temp = board[i][j];
    board[i][j] = board[i + 2][j];
    board[i + 2][j] = board[i + 2][j + 2];
    board[i + 2][j + 2] = board[i][j + 2];
    board[i][j + 2] = temp;
    temp = board[i][j + 1];
    board[i][j + 1] = board[i + 1][j];
    board[i + 1][j] = board[i + 2][j + 1];
    board[i + 2][j + 1] = board[i + 1][j + 2];
    board[i + 1][j + 2] = temp;

  } //end rightRotation()


//--------------------------------------------------------------------------------
//rotates the quadrant to the left
void leftRotation(char board[6][6], int i, int j) {
    int temp; //temporarily holds the value of the starting array

    //these next instructions rotate a quadrant to the left starting with the corner pieces first then the middle ones
    temp = board[i][j];
    board[i][j] = board[i][j + 2];
    board[i][j + 2] = board[i + 2][j + 2];
    board[i + 2][j + 2] = board[i + 2][j];
    board[i + 2][j] = temp;
    temp = board[i][j + 1];
    board[i][j + 1] = board[i + 1][j + 2];
    board[i + 1][j + 2] = board[i + 2][j + 1];
    board[i + 2][j + 1] = board[i + 1][j];
    board[i + 1][j] = temp;

  } //end leftRotation


//--------------------------------------------------------------------------------
//rotates a specific quadrant in the specific direction
void rotation(char userQuad, char userRot, char board[6][6]) {

    //takes in users input for the quadrant that needs to be rotated and in the direction
    if (userQuad == 1 && userRot == 'R') {
      rightRotation(board, 0, 0);
    }
    if (userQuad == 1 && userRot == 'L') {
      leftRotation(board, 0, 0);
    }
    if (userQuad == 2 && userRot == 'R') {
      rightRotation(board, 0, 3);
    }
    if (userQuad == 2 && userRot == 'L') {
      leftRotation(board, 0, 3);
    }
    if (userQuad == 3 && userRot == 'R') {
      rightRotation(board, 3, 0);
    }
    if (userQuad == 3 && userRot == 'L') {
      leftRotation(board, 3, 0);
    }
    if (userQuad == 4 && userRot == 'R') {
      rightRotation(board, 3, 3);
    }
    if (userQuad == 4 && userRot == 'L') {
      leftRotation(board, 3, 3);
    }
  } //end rotation()


//--------------------------------------------------------------------------------
//Places X in the position inputted by player O
void player1PositionInput(char userRow, char board[6][6], int userColumn) {

    //If the row entered is 'A', then it check for userColumn and changes it to X
    //does the similar steps according to the row input
    if (userRow == 'A') {
      board[0][userColumn - 1] = 'X';
    } else if (userRow == 'B') {
      board[1][userColumn - 1] = 'X';
    } else if (userRow == 'C') {
      board[2][userColumn - 1] = 'X';
    } else if (userRow == 'D') {
      board[3][userColumn - 1] = 'X';
    } else if (userRow == 'E') {
      board[4][userColumn - 1] = 'X';
    } else if (userRow == 'F') {
      board[5][userColumn - 1] = 'X';
    }
  } //end player1PositionInput()


//--------------------------------------------------------------------------------
//Places O in the position inputted by player O
void player2PositionInput(char userRow, char board[6][6], int userColumn) {

    //If the row entered is 'A', then it check for userColumn and changes it to O
    //does the similar steps according to the row input
    if (userRow == 'A') {
      board[0][userColumn - 1] = 'O';
    } else if (userRow == 'B') {
      board[1][userColumn - 1] = 'O';
    } else if (userRow == 'C') {
      board[2][userColumn - 1] = 'O';
    } else if (userRow == 'D') {
      board[3][userColumn - 1] = 'O';
    } else if (userRow == 'E') {
      board[4][userColumn - 1] = 'O';
    } else if (userRow == 'F') {
      board[5][userColumn - 1] = 'O';
    }
  } //end player2PositionInput()


//--------------------------------------------------------------------------------
//Checks for a win diagonally
int diagonalCheck(char board[6][6], char playerMove) {
    int i;
    int j = 0;
    int count = 0;
    for (i = 1; i < 6; i++) {
      if (board[i][j] == playerMove) { //if an 'O' or 'X' is found at the position then the count increases
        j++;
        count++;
      } else {
        j++;
      }
    }
    if (count == 5) { //if count equals 5 then return -1
      return -1;
    }
    //similar steps are done except for different possible diagonal wins
    //-----------------------------------------------------------------------------	
    j = 1;
    count = 0;
    for (i = 0; i < 6; i++) {
      if (board[i][j] == playerMove) {
        j++;
        count++;
      } else {
        j++;
      }
    }
    if (count == 5) {
      return -1;
    }

    //-----------------------------------------------------------------------------	
    j = 4;
    count = 0;
    for (i = 0; i < 5; i++) {
      if (board[i][j] == playerMove) {
        j--;
        count++;
      } else {
        j--;
      }
    }
    if (count == 5) {
      return -1;
    }

    //--------------------------------------------------------------------------------	
    j = 5;
    count = 0;
    for (i = 1; i < 6; i++) {
      if (board[i][j] == playerMove) {
        j--;
        count++;
      } else {
        j--;
      }
    }
    if (count == 5) {
      return -1;
    }

    //--------------------------------------------------------------------------------	
    j = 5;
    count = 0;
    for (i = 0; i < 6; i++) {
      if (board[i][j] == playerMove) {
        j--;
        count++;
      } else {
        j--;
      }
    }
    if (count == 5) {
      return -1;
    }
    
    //--------------------------------------------------------------------------------	
    j = 0;
    count = 0;
    for (i = 0; i < 6; i++) {
      if (board[i][j] == playerMove) {
        j++;
        count++;
      } else {
        j++;
      }
    }
    if (count == 5) {
      return -1;
    }
  } //end diagonalCheck()


//--------------------------------------------------------------------------------
//checks to see if there are 5 X or O in a row
int checkWinner(char board[6][6], char whichPlayer) {
    int count = 0;
    int returnValue = 0;
    int userRow, userColumn;
    // Check each of 6 rows:
    for (userRow = 0; userRow < 6; ++userRow) {
      count = 0;
      for (userColumn = 0; userColumn < 6; ++userColumn) {
        if (board[userRow][userColumn] == whichPlayer) {
          count++;
        }
      }
      if (count == 5 || count == -5) {
        return -1; // Return either 1 or -1
      }
    }
    // Check each of 6 columns.
    for (userColumn = 0; userColumn < 6; ++userColumn) {
      count = 0;
      for (userRow = 0; userRow < 6; ++userRow) {
        if (board[userRow][userColumn] == whichPlayer) {
          count++;
        }
      }
      if (count == 5 || count == -5) {
        return -1; // Return either 1 or -1
      }
    }
    returnValue = diagonalCheck(board, whichPlayer); //store return value from diagonalCheck() into returnValue
    if (returnValue == -1) {
      return -1;
    }
    return 0;

  } //end checkWinner


//--------------------------------------------------------------------------------
//checks to see if the game is a tie
int tieGame(char board[6][6], int win, int win2) {
    if ((win == -1 || win == 1) && (win2 == -1 || win2 == 1)) {
      printf("The game is a tie!\n");
      displayBoard(board);
      printf("Thank you for Playing. Exiting....\n");
      exit(0);
    }
    return 0;
  } //end tieGame()


//--------------------------------------------------------------------------------
//start main
int main() {
    char board[6][6] = {	//stores the elements of the array
		{ '.','.','.','.','.','.' },
		{ '.','.','.','.','.','.' },
		{ '.','.','.','.','.','.' },
		{ '.','.','.','.','.','.' },
		{ '.','.','.','.','.','.' },
		{ '.','.','.','.','.','.' } };
    char userRow = ' '; //stores users row input
    int userColumn = 0; //stores users column input
    int userQuad = 0; //stores users quadrant input
    char userRot = ' '; //stores users rotation input
    int retry = 0; //stores the return value from the function inputValidation()
    int retry2 = 0; //stores the return value from the function spotCheck
    int turnCounter = 1; //counter for turns
    int win = 0; //stores the return value from the fucntion checkWinner
    int win2 = 0;

    info(); //calls the function info()
    intro(); //calls the function intro()
    displayBoard(board); //calls the fucntion displayBoard()

    while (1) { //start of while loop for the game to continue until a win or an input of X

      //while loop for player X
      while (1) {
        printf("\n%d. Enter row, column, quadrant, direction for X: ", turnCounter++); //increments turnCounter by one after the print statement
        scanf(" %c", & userRow); //scans the row input from player X
        userRow = toupper(userRow); //uppercases userRow
        if (userRow == 'X') { //if the user inputs x then program exits
          exit(0);
        }
        scanf("%1d", & userColumn); //scans the column input from player X
        scanf("%1d", & userQuad); //scans the quadrant input from player X
        scanf(" %c", & userRot); //scans the rotation input from player X
        userRot = toupper(userRot); //uppercases th userRot

        retry = inputValidation(userRow, userColumn, userQuad, userRot, board); //calls inputValidation() and stores the return value into retry
        retry2 = spotCheck(board, userRow, userColumn); //calls spotCheck() and stores the return value into retry2
        if (retry == -1 || retry2 == -1) { //if either retry or retry2 equal -1 then turnCOunter decreases by one and the while loop restarts 
          turnCounter--;
          continue;
        }

        player1PositionInput(userRow, board, userColumn); //places X into the destination

        win = checkWinner(board, 'X'); //the return value of checkWinner() is stored into win
        win2 = checkWinner(board, 'O');
        tieGame(board, win, win2);
        if (win == -1 && win2 != -1) { //if the value of win is 1 or -1 then it displays the board and exits the program
          //tieGame(win, win2);
          printf("\nX has won the game.\n\n");
          displayBoard(board);
          break;
        }
        rotation(userQuad, userRot, board); //rotates the board
        win2 = checkWinner(board, 'O');
        win = checkWinner(board, 'X'); //the return value of checkWinner() is stored into win
        tieGame(board, win, win2);
        if (win == -1 && win2 != -1) { //if the value of win is 1 or -1 after the rotation then it displays the board and exits the program
          printf("\nX has won the game.\n\n");
          displayBoard(board);
          break;
        }
        //tieGame(win, win2);
        displayBoard(board); //displays the board
        break; //leaves the loop and goes to the next loop

      }
      if (win == -1) {
        printf("\nThanks for playing.  Exiting...");
        exit(0);
      }

      //while loop for player O
      while (1) {
        printf("\n%d. Enter row, column, quadrant, direction for O: ", turnCounter++);
        scanf(" %c", & userRow); //scans the input for player X
        userRow = toupper(userRow); //uppercases the row input
        if (userRow == 'X') {
          exit(0);
        }
        scanf("%1d", & userColumn); //scans the column input from player X
        scanf("%1d", & userQuad); //scans the quadrant input from player X
        scanf(" %c", & userRot); //scans the rotation input from player X
        userRot = toupper(userRot); //uppercases th userRot

        retry = inputValidation(userRow, userColumn, userQuad, userRot, board); //calls inputValidation() and stores the return value into retry
        retry2 = spotCheck(board, userRow, userColumn); //calls spotCheck() and stores the return value into retry2
        if (retry == -1 || retry2 == -1) { //if either retry or retry2 equal -1 then turnCOunter decreases by one and the while loop restarts 
          turnCounter--;
          continue;
        }

        player2PositionInput(userRow, board, userColumn); //places O into the destination
        win = checkWinner(board, 'X');
        win2 = checkWinner(board, 'O'); //the return value of checkWinner() is stored into win
        tieGame(board, win, win2);
        if (win2 == -1 && win != -1) { //if the value of win is 1 or -1 then it displays the board and exits the program
          //tieGame(win, win2);
          printf("\nO has won the game.\n\n");
          displayBoard(board);
          break;
        }
        //tieGame(win, win2);
        rotation(userQuad, userRot, board); //rotates the board

        win = checkWinner(board, 'X');
        win2 = checkWinner(board, 'O'); //the return value of checkWinner() is stored into win
        tieGame(board, win, win2);
        if (win2 == -1 && win != -1) { //if the value of win is 1 or -1 after the rotation then it displays the board and exits the program

          printf("\nO has won the game.\n\n");
          displayBoard(board);
          break;
        }

        displayBoard(board); //displays the board
        break; //leaves the loop and goes to the next loop
      }
      if (win2 == -1) {
        printf("\nThanks for playing.  Exiting...");
        exit(0);
      }

    }
    if (win != -1 && win2 != -1) {
      printf("The game ended with a tie..... exiting....");
      exit(0);
    }
    return 0;
  } //end main
