//This Lab Revolves Arround Creating the Reversi Game
//this is the full code for the game

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void printBoard(char board[26][26], int n) {
  // print the top row which reps column headings
  printf("  ");
  for (char columnHeading = 'a'; columnHeading < n + 'a'; columnHeading++) {
    printf("%c", columnHeading);
  }
  printf("\n");
  char rowHeading = 'a';

  // now print the rest of the rows, including row headings
  for (int arrayRowIndex = 0; arrayRowIndex < n; arrayRowIndex++) {
    printf("%c ", rowHeading);
    for (int arrayColumnIndex = 0; arrayColumnIndex < n; arrayColumnIndex++) {
      printf("%c", board[arrayRowIndex][arrayColumnIndex]);
    }
    rowHeading++;
    printf("\n");
  }
}

bool positionInBounds(int n, int row, int col) {
  if (row < 0 || row >= n || col < 0 || col >= n) {
    return false;
  } else {
    return true;
  }
}

bool checkLegalInDirection(char board[26][26], int n, int row, int col,
                           char colour, int deltaRow, int deltaCol) {
  int count = 1;
  char opposite;
  if (colour == 'W') {
    opposite = 'B';
  } else {
    opposite = 'W';
  }
  if (positionInBounds(n, row, col) == false || board[row][col] == colour ||
      board[row][col] == opposite) {
    return false;
  } else {
    while (
        (positionInBounds(n, row + (count * deltaRow),
                          col + (count * deltaCol))) &&
        (board[row + (count * deltaRow)][col + (count * deltaCol)] != colour) &&
        (board[row + (count * deltaRow)][col + (count * deltaCol)] != 'U')) {
      count++;
      if (board[row + (count * deltaRow)][col + (count * deltaCol)] == colour &&
          positionInBounds(n, row + (count * deltaRow),
                           col + (count * deltaCol))) {
        return true;
      }
    }
    return false;
  }
}

bool checkLegalInAllDir(char board[26][26], int n, int row, int col,
                        char colour) {
  if (checkLegalInDirection(board, n, row, col, colour, -1, 1) == true) {
    return true;
  } else if (checkLegalInDirection(board, n, row, col, colour, 0, 1) == true) {
    return true;
  } else if (checkLegalInDirection(board, n, row, col, colour, 1, 1) == true) {
    return true;
  } else if (checkLegalInDirection(board, n, row, col, colour, 1, 0) == true) {
    return true;
  } else if (checkLegalInDirection(board, n, row, col, colour, 1, -1) == true) {
    return true;
  } else if (checkLegalInDirection(board, n, row, col, colour, 0, -1) == true) {
    return true;
  } else if (checkLegalInDirection(board, n, row, col, colour, -1, -1) ==
             true) {
    return true;
  } else if (checkLegalInDirection(board, n, row, col, colour, -1, 0) == true) {
    return true;
  } else {
    return false;
  }
}

void printAvailableMoves(char board[26][26], int n) {
  printf("Available moves for W:\n");
  for (int row = 0; row < n; row++) {
    for (int col = 0; col < n; col++) {
      if (checkLegalInAllDir(board, n, row, col, 'W') == true) {
        printf("%c%c\n", 'a' + row, 'a' + col);
      }
    }
  }

  printf("Available moves for B:\n");
  for (int row = 0; row < n; row++) {
    for (int col = 0; col < n; col++) {
      if (checkLegalInAllDir(board, n, row, col, 'B') == true) {
        printf("%c%c\n", 'a' + row, 'a' + col);
      }
    }
  }
}

bool isMoveValid(char board[26][26], int n, char move[4]) {
  for (int row = 0; row < n; row++) {
    for (int col = 0; col < n; col++) {
      if (checkLegalInAllDir(board, n, row, col, move[0]) == true &&
          move[1] == row + 'a' && move[2] == col + 'a') {
        return true;
      }
    }
  }
  return false;
}

void executeMove(char userBoard[26][26], char row, char col, int n, char colour) {
  char board[26][26];
  for (int row = 0; row < n; row++) {
    for (int col = 0; col < n; col++) {
      board[row][col] = userBoard[row][col];
    }
  }
  int intRow = row - 'a', intCol = col - 'a', count = 0;
  if (checkLegalInDirection(board, n, intRow, intCol, colour, -1, 1) == true) {
    while (board[intRow + (count * (-1))][intCol + (count * 1)] != colour) {
      userBoard[intRow + (count * (-1))][intCol + (count * 1)] = colour;
      count++;
    }
  }
  count = 0;
  if (checkLegalInDirection(board, n, intRow, intCol, colour, 0, 1) == true) {
    while (board[intRow + (count * 0)][intCol + (count * 1)] != colour) {
      userBoard[intRow + (count * 0)][intCol + (count * 1)] = colour;
      count++;
    }
  }
  count = 0;
  if (checkLegalInDirection(board, n, intRow, intCol, colour, 1, 1) == true) {
    while (board[intRow + (count * 1)][intCol + (count * 1)] != colour) {
      userBoard[intRow + (count * 1)][intCol + (count * 1)] = colour;
      count++;
    }
  }
  count = 0;
  if (checkLegalInDirection(board, n, intRow, intCol, colour, 1, 0) == true) {
    while (board[intRow + (count * 1)][intCol + (count * 0)] != colour) {
      userBoard[intRow + (count * 1)][intCol + (count * 0)] = colour;
      count++;
    }
  }
  count = 0;
  if (checkLegalInDirection(board, n, intRow, intCol, colour, 1, -1) == true) {
    while (board[intRow + (count * (1))][intCol + (count * (-1))] != colour) {
      userBoard[intRow + (count * (1))][intCol + (count * (-1))] = colour;
      count++;
    }
  }
  count = 0;
  if (checkLegalInDirection(board, n, intRow, intCol, colour, 0, -1) == true) {
    while (board[intRow + (count * (0))][intCol + (count * (-1))] != colour) {
      userBoard[intRow + (count * (0))][intCol + (count * (-1))] = colour;
      count++;
    }
  }
  count = 0;
  if (checkLegalInDirection(board, n, intRow, intCol, colour, -1, -1) == true) {
    while (board[intRow + (count * (-1))][intCol + (count * (-1))] != colour) {
      userBoard[intRow + (count * (-1))][intCol + (count * (-1))] = colour;
      count++;
    }
  }
  count = 0;
  if (checkLegalInDirection(board, n, intRow, intCol, colour, -1, 0) == true) {
    while (board[intRow + (count * (-1))][intCol + (count * 0)] != colour) {
      userBoard[intRow + (count * (-1))][intCol + (count * 0)] = colour;
      count++;
    }
  }
}

int main(void) {
  int n = 0;

  // get dimensions
  printf("Enter the board dimension: ");
  scanf("%d", &n);

  // innitialize the board
  char board[26][26];
  for (int row = 0; row < n; row++) {
    for (int col = 0; col < n; col++) {
      board[row][col] = 'U';
      if ((row == n / 2 - 1 && col == n / 2 - 1) ||
          (row == n / 2 && col == n / 2)) {
        board[row][col] = 'W';
      } else if ((row == n / 2 - 1 && col == n / 2) ||
                 (row == n / 2 && col == n / 2 - 1)) {
        board[row][col] = 'B';
      }
    }
  }

  // print the initialized board
  printBoard(board, n);

  // now get baord configuraiton from the user and print the configured board
  char userConfigArray[4];
  printf("Enter board configuration:\n");
  while (userConfigArray[1] != '!') {
    scanf("%s", userConfigArray);
    if (userConfigArray[0] == 'W') {
      board[userConfigArray[1] - 'a'][userConfigArray[2] - 'a'] = 'W';
    } else if (userConfigArray[0] == 'B') {
      board[userConfigArray[1] - 'a'][userConfigArray[2] - 'a'] = 'B';
    }
  }
  printBoard(board, n);

  // now, need to check for available moves on the baord for each player
  printAvailableMoves(board, n);

  // ask user to enter a move
  char enteredMove[4];
  printf("Enter a move:\n");
  scanf("%s", enteredMove);
  if (isMoveValid(board, n, enteredMove) == false) {
    printf("Invalid move.\n");
  } else {
    printf("Valid move.\n");
    executeMove(board, enteredMove[1], enteredMove[2], n, enteredMove[0]);
  }

  printBoard(board, n);

  return 0;
}
