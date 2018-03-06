/*prog4Secret_akidwa2_hqurai3.c
NetID: akidwa2, hqurai3

Sample Output:
	Welcome to the decoding program, where hidden messages are found inside of a text file.
	 
	Author: Dale Reed 
	Program: #4, Secret 
	TA: Gail Chapman, Tues 10 
	Mar 5, 2017 
	 
	Read in 3 keyWords, which are: 
	quick
	get
	going
	
	Read in 390 cipherText characters.
	
	Choose from the following options:     
	   1. Display a particular sized table 
	   2. Find all matching key word phrases 
	   X. Exit the program 
	Enter your choice -> 1
	
	Enter the row size: 15
	oo fggo pbuzbbb
	y gmjekjnbi son
	cc ppptyewx rbt
	l mbbx  gadhcg 
	hcwhz alcjq  ma
	vj vnpd aamy zn
	qy dt znq sjv g
	h pjq fxtozhvq 
	dft eqw qkj  pt
	 rka puk nih ps
	a nkb yiu oxm r
	t rwnyvgcykel n
	i w vc ydgpbg f
	hz ccfy cdrz yr
	oxednco ulkd ou
	gg  sfc dvsgpc 
	zpl shbc iwkc j
	fyd te  z sv nv
	xwz ugskm uutix
	 knkzdf  kyab p
	cm wioqv pltv h
	jp hdjj emcwczu
	ibfc clyxs  igd
	 opqqrx vo xf y
	dedqa bnclqgf f
	troaom chhnaz
	And running your program again to automatically decode should look like:
	
	Welcome to the decoding program, where hidden messages are found inside of a text file.
	 
	Author: Dale Reed 
	Program: #4, Secret 
	TA: Gail Chapman, Tues 10 
	Mar 5, 2017 
	 
	Read in 3 keyWords, which are: 
	quick
	get
	going
	
	Read in 390 cipherText characters.
	
	Choose from the following options:     
	   1. Display a particular sized table 
	   2. Find all matching key word phrases 
	   3. Place key word phrase into a datafile (not required for students) 
	   X. Exit the program 
	Enter your choice -> 2
	
	Found "get" diagonally with table size 15 at 4. Secret message:  get cash prize ses 
*/
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
#include <string.h> 
#include <ctype.h>

//--------------------------------------------------------------------------------------
//this function prints out the basic info
void info() {
    printf("Welcome to the decoding program, where hidden messages are found inside of a text file.\n\n");
    printf("Author: Abdullah Kidwai and Hamzah Quraishi \n");
    printf("Program : #4, Secret \n");
    printf("TA : Momita Samanta, Tues 2:00 and 5:00\n");
    printf("Mar 15, 2017\n\n");
}//end info()

//--------------------------------------------------------------------------------------
//this function opens the cipher file and puts it into an array
void openCipher(char cipherText[], int size) {
  int i;
  FILE * fpointer;
  fpointer = fopen("cipher.txt", "rb");	//opens the text file
  for (i = 0; i < size; i++) {
    fscanf(fpointer, "%c", & cipherText[i]);	//places the file into the array one character at a time
  }
}//end openCipher()

//--------------------------------------------------------------------------------------
//this funtion opens the keys text file and places it into an array
void openKeys(char keysText[], int size) {
  int i;
  FILE * fpointer;
  fpointer = fopen("keys.txt", "rb");	//opens the text file
  for (i = 0; i < size; i++) {
    fscanf(fpointer, "%c", & keysText[i]);	//places the file into the array one character at a time
  }
}//end openKeys()

//--------------------------------------------------------------------------------------
//this function prints the cipher file in the specified number of characters per line 
void printCipher(char cipherText[], int width) {
  int j = 0;
  int i;
  for (i = 0; i <= 16128; i++) {	//the number 16128 may need to be changed 
    if (j == width) {
      printf("\n");	//prints a new line after the specified line width
      j = 0;
    }
    printf("%c", cipherText[i]);
    j++;
  }
}//end printCipher()

//--------------------------------------------------------------------------------------
//this function prints out each of the keys per line
void printKeys(char keysText[], int keySize) {
  int i;
  printf("Read in the key words, which are : \n");
  for (i = 0; i <= keySize; i++) {
    printf("%c", keysText[i]);
    if (keysText[i] == ' ') {	//if there is a space between the words then print a new line character
      printf("\n");
    }
  }
  printf("\n\nRead in 390 cipherText characters.\n\n");
  printf("**Choose from the following options:\n");
  printf("  1. Display a particular sized table\n");
  printf("  2. Find all matching key word phrases\n");
  printf("  X. Exit the program \n");
  printf("Enter your choice ->  ");
}//end printKeys()

//--------------------------------------------------------------------------------------
//this function takes in te users input and returns a value based off of the input
int userOption(int userInput, char userInputC) {
  int width;
  if (userInput == 1) {
    printf("\nEnter a row size between 13 and 132:  ");
    return -1;	//if the input is 1 then return -1
  } else if (userInput == 2) {
    return -2;	//if the input is 2 then return -2
  } else if (userInputC == 'X' || userInputC == 'x') {
    return 1;	//if the input is x or X then return 1
  }
}//end userOption

//--------------------------------------------------------------------------------------
//this function compares each character of the keys word with the characters of the cipher file horizontally
void compareHorizontal(char cipherText[], char keysText[]){
	int i =0, j = 0, k =0;
	char newArray[500];	//holds the secret message
	for(i=0; i<388; i++){
		for(j=0; j<10; j++){
			if(cipherText[i] == keysText[j]){	//if the cipher character and the keys character match
				newArray[k] = cipherText[i];	//then put that charcter into the new array
			}
			else{
				break;	//if it doesnt then break and check the next cipher character
			}
		}
	}
	for(i=0; i<j; i++){
		printf("%c", newArray[i]);	//this prints out the secret message
	}
}//end compareHorizontal()

//--------------------------------------------------------------------------------------
//start main()
int main() {
  int size = 17424;	//size of the array cipherText
  char cipherText[size];	//array that hold the cipher
  int width;	//holds the users width input
  int keySize = 20;	//size of the array keysText
  char keysText[keySize];	//array that holds the keys
  int userInput;	//holds the users input
  char userInputC;	//holds the users input
  int userOptionReturn = 0;	//holds the return value of theh function userOption
  

  info();	//calls the function info()
  openKeys(keysText, keySize);	//calls the function openKeys()
  printKeys(keysText, keySize);	//calls the function printKeys()

  scanf("%d", & userInput);	//gets users input for the menu options
  scanf("%c", & userInputC);	//gets users input for the menu options

  userOptionReturn = userOption(userInput, userInputC);	//sets the retun value into userOptionReturn

  if (userOptionReturn == -1) {	//if userOptionReturn equals -1
    while (1) {
      scanf("%d", & width);	//get the width size from user
      if (width < 13 || width > 132) {	//checks to see if the width is within the correct parameters
        printf("Try again. Input must be between 13 and 132\n");
        continue;	//if it isnt then restart the while loop
      }
      break;	//if the width input is between the correct parameters then breka out of the loop
    }
    openCipher(cipherText, size);	//the fucntion openCipher() is called
    printCipher(cipherText, width);	//the function printCipher() is called
  } 
  else if (userOptionReturn == -2) {	//if userOptionReturn equals -2 the it finds the secret message
    printf("WORKING ON THIS PART");
    openCipher(cipherText, size);	//calls the fucntion openCipher()
    compareHorizontal(cipherText, keysText);	//calls the function compareHorizontal()
  } 
  else if (userOptionReturn == 1) {	//if userOptionReturn equals 1 then the program exits
    printf("Program is exiting...");
    exit(0);
  }
  
  return 0;
}//end main()
