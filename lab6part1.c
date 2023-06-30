/*
This lab, like the last one, develops a game over parts
The game: 

You are asked to develop a program for a one-player game. The game starts with a 
2D board that is filled with 0s and 1s. Depending on the board dimensions, the board 
will be generated. The board contents are hidden from the player. It is required that 
the user finds a line of 1s that is equal or greater than the difficulty level. The 
line can be horizontal, vertical or diagonal. The user will be asked to enter the 
coordinates until the line of 1s is found or until the user attempts all boxes, and 
not find the line of 1s.

Points - The user should find the line of boxes in the fewest possible trials. The 
points gained is calculated as the number of unattempted boxes in the board. The game 
ends when the user finds the line of 1s that is equal or greater than the difficulty 
level or until the user attempts all boxes, and not find the line of 1s. In the latter 
case, the game is invalid. The points will be displayed at the end of the game, if the 
game is valid.
*/

//Getting Input and Printing Board

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void printBoard(int Size, int grid[][Size]);
void getInput(int* row, int* col, int Size);
void getLevelAndDimensions(int* size, int* difficultyLevel, const int maxDim);
bool validRowCol(int row, int col, int Size);

int main(void) {
  const int maxDim = 23;
  int Size = 0, difficultyLevel = 0;

  getLevelAndDimensions(&Size, &difficultyLevel, maxDim);

  int copy[maxDim][maxDim] = {
      {1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1},
      {1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1},
      {0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0},
      {1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1},
      {1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1},
      {0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0},
      {1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1},
      {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1},
      {1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1},
      {1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
      {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0},
      {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1},
      {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
      {0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1},
      {1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1},
      {0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1},
      {0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0},
      {0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1},
      {1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0},
      {1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1},
      {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1},
      {1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1}};

  int grid[Size][Size];
  for (int row = 0; row < Size; row++) {
    for (int col = 0; col < Size; col++) {
      grid[row][col] = copy[row][col];
    }
  }
  printBoard(Size, grid);

  int userInputRow = 0, userInputCol = 0;
  getInput(&userInputRow, &userInputCol, Size);
  printf("row, col = %d, %d\n", userInputRow, userInputCol);
  grid[userInputRow][userInputCol] = 9;  // any arbitrary number
  printBoard(Size, grid);

  return 0;
}

void getInput(int* row, int* col, int Size) {
  printf("Enter user input: ");
  scanf(" %d %d", row, col);
  while (validRowCol(*row, *col, Size) == false) {
    printf("Please enter your row and col to be between 0 and Size - 1: ");
    scanf(" %d %d", row, col);
  }
}

bool validRowCol(int row, int col, int Size) {
  if (row >= 0 && row < Size && col >= 0 && col < Size) {
    return true;
  } else {
    return false;
  }
}

void getLevelAndDimensions(int* Size, int* levelOfDiff, const int maxDim) {
  printf("Enter difficulty level: ");
  scanf("%d", levelOfDiff);
  while (*levelOfDiff < 1 || *levelOfDiff > maxDim) {
    printf("Please enter a difficulty level between 1 and 23: ");
    scanf("%d", levelOfDiff);
  }
  printf("Enter the dimensions of the grid: ");
  scanf("%d", Size);
  while (*Size < *levelOfDiff || *Size > maxDim) {
    printf("Please enter dimensions >= %d: ", *levelOfDiff);
    scanf("%d", Size);
  }
}

void printBoard(int Size, int grid[][Size]) {
  //print row by row, looping through each column
  for (int row = 0; row < Size; row++) {
    for (int column = 0; column < Size; column++) {
      printf("%d", grid[row][column]);
    }
    printf("\n"); //need each row on a seperate line
  }
}
