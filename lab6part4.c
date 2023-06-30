//Complete Game

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool gameStatus(int Size, char userArray[][Size], int difficultyLevel);

void printBoard(int Size, char grid[][Size]);
bool validRowCol(int row, int col, int Size);
void updateRowCol(int* row, int* col, int dir, bool forward);
int calculateScoreInDir(int row, int col, int direction, int Size,
                        char userArray[][Size]);

void getInput(int* row, int* col, int Size);
void getLevelAndDimensions(int* size, int* difficultyLevel, const int maxDim);
int getRand(int maxChoices);

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

  char grid[Size][Size];
  for (int row = 0; row < Size; row++) {
    for (int col = 0; col < Size; col++) {
      grid[row][col] = copy[row][col] + '0';
    }
  }
  // TODO: check if there is a valid game, if not, create one
  if (gameStatus(Size, grid, difficultyLevel) == false) {
    while (gameStatus(Size, grid, difficultyLevel) != true) {
        grid[getRand(Size)][getRand(Size)] = '1';
    }
  }

  int userInputRow = 0, userInputCol = 0;

  // test gameStatus
  char userArray[Size][Size];
  for (int row = 0; row < Size; row++) {
    for (int col = 0; col < Size; col++) {
      userArray[row][col] = '-';
    }
  }
  bool gameOver = true;
  int steps = 0;
  do {
    getInput(&userInputRow, &userInputCol, Size);
    userArray[userInputRow][userInputCol] = grid[userInputRow][userInputCol];
    printBoard(Size, userArray);

    gameOver = gameStatus(Size, userArray, difficultyLevel);
    steps++;
  } while (!gameOver && steps < Size * Size);
  if (steps == Size * Size) {
    printf("Not a valid game!");
  } else {
    printf("Game over!\n");
    printf("Your score is %d", Size * Size - steps);
  }

  return 0;
}

bool gameStatus(int Size, char userArray[][Size], int difficultyLevel) {
  // you will need to call calculateScoreInDir
  for (int row = 0; row < Size; row++) {
    for (int col = 0; col < Size; col++) {
      if (calculateScoreInDir(row, col, 0, Size, userArray) >=
          difficultyLevel) {
        return true;
      } else if (calculateScoreInDir(row, col, 1, Size, userArray) >=
                 difficultyLevel) {
        return true;
      } else if (calculateScoreInDir(row, col, 2, Size, userArray) >=
                 difficultyLevel) {
        return true;
      } else if (calculateScoreInDir(row, col, 3, Size, userArray) >=
                 difficultyLevel) {
        return true;
      }
    }
  }
  return false;
}

int calculateScoreInDir(int row, int col, int direction, int Size,
                        char userArray[][Size]) {
  int score = 0, restoreOriginalRowVal = row, restoreOriginalColVal = col;
  if (userArray[row][col] == 48) {
    return 0;
  } else {
    while (userArray[row][col] == 49) {
      if (row >= 0 && col >= 0 && row < Size && col < Size) {
        score++;
        updateRowCol(&row, &col, direction, true);
      } else {
        break;
      }
    }
    row = restoreOriginalRowVal, col = restoreOriginalColVal;
    while (userArray[row][col] == 49) {
      if (row >= 0 && col >= 0 && row < Size && col < Size) {
        score++;
        updateRowCol(&row, &col, direction, false);
      } else {
        break;
      }
    }
    return score - 1;
  }
}

bool validRowCol(int row, int col, int Size) {
  if (row >= 0 && row < Size && col >= 0 && col < Size) {
    return true;
  } else {
    return false;
  }
}

void updateRowCol(int* row, int* col, int dir, bool forward) {
  if (forward == true) {
    if (dir == 0) {
      (*row)--;
    } else if (dir == 1) {
      (*row)--;
      (*col)++;
    } else if (dir == 2) {
      (*col)++;
    } else if (dir == 3) {
      (*row)--;
      (*col)--;
    }
  } else {
    if (dir == 0) {
      (*row)++;
    } else if (dir == 1) {
      (*row)++;
      (*col)--;
    } else if (dir == 2) {
      (*col)--;
    } else if (dir == 3) {
      (*row)++;
      (*col)++;
    }
  }
}

void printBoard(int Size, char grid[][Size]) {
  for (int row = 0; row < Size; row++) {
    for (int column = 0; column < Size; column++) {
      printf("%d", grid[row][column]);
    }
    printf("\n");  // need each row on a seperate line
  }
}

void getInput(int* row, int* col, int Size) {
  printf("Enter user input: ");
  scanf(" %d %d", row, col);
  while (validRowCol(*row, *col, Size) == false) {
    printf("Please enter your row and col to be between 0 and Size - 1: ");
    scanf(" %d %d", row, col);
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

int getRand(int maxChoices) { return (rand() % (maxChoices)); }
