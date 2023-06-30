//In this part, I create another algorithm which can beat all the algoetihsms provided by 
//the teaching team at the Reversi game


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

bool isMoveValid(char board[26][26], int n, char move[3], char color) {
  for (int row = 0; row < n; row++) {
    for (int col = 0; col < n; col++) {
      if (checkLegalInAllDir(board, n, row, col, color) == true &&
          move[0] == row + 'a' && move[1] == col + 'a') {
        return true;
      }
    }
  }
  return false;
}

void executeMove(char userBoard[26][26], char row, char col, int n,
                 char colour) {
  char board[26][26];
  for (int Row = 0; Row < n; Row++) {
    for (int Col = 0; Col < n; Col++) {
      board[Row][Col] = userBoard[Row][Col];
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

bool isBoardFull(char board[26][26], int n) {
  for (int row = 0; row < n; row++) {
    for (int col = 0; col < n; col++) {
      if (board[row][col] == 'U') {
        return false;
      }
    }
  }
  return true;
}

bool anyValidMove(char board[26][26], int n) {
  for (int row = 0; row < n; row++) {
    for (int col = 0; col < n; col++) {
      if (checkLegalInAllDir(board, n, row, col, 'W') == true) {
        return true;
      } else if (checkLegalInAllDir(board, n, row, col, 'B') == true) {
        return true;
      }
    }
  }
  return false;
}

bool validMovesAvailable(char board[26][26], int n, char color) {
  for (int row = 0; row < n; row++) {
    for (int col = 0; col < n; col++) {
      if (checkLegalInAllDir(board, n, row, col, color) == true) {
        return true;
      }
    }
  }
  return false;
}

void getComputerMove(char board[26][26], int n, char move[3], char colour) {
  // fist calculate the score, then store row and col value for greatest score
  int count = 0, score = 0, greatestScore = 0;
  for (int intRow = 0; intRow < n; intRow++) {
    for (int intCol = 0; intCol < n; intCol++) {
      if (checkLegalInDirection(board, n, intRow, intCol, colour, -1, 1) ==
          true) {
        while (board[intRow + (count * (-1))][intCol + (count * 1)] != colour) {
          count++;
          score++;
        }
      }
      count = 0;
      if (checkLegalInDirection(board, n, intRow, intCol, colour, 0, 1) ==
          true) {
        while (board[intRow + (count * 0)][intCol + (count * 1)] != colour) {
          count++;
          score++;
        }
      }
      count = 0;
      if (checkLegalInDirection(board, n, intRow, intCol, colour, 1, 1) ==
          true) {
        while (board[intRow + (count * 1)][intCol + (count * 1)] != colour) {
          count++;
          score++;
        }
      }
      count = 0;
      if (checkLegalInDirection(board, n, intRow, intCol, colour, 1, 0) ==
          true) {
        while (board[intRow + (count * 1)][intCol + (count * 0)] != colour) {
          count++;
          score++;
        }
      }
      count = 0;
      if (checkLegalInDirection(board, n, intRow, intCol, colour, 1, -1) ==
          true) {
        while (board[intRow + (count * (1))][intCol + (count * (-1))] !=
               colour) {
          count++;
          score++;
        }
      }
      count = 0;
      if (checkLegalInDirection(board, n, intRow, intCol, colour, 0, -1) ==
          true) {
        while (board[intRow + (count * (0))][intCol + (count * (-1))] !=
               colour) {
          count++;
          score++;
        }
      }
      count = 0;
      if (checkLegalInDirection(board, n, intRow, intCol, colour, -1, -1) ==
          true) {
        while (board[intRow + (count * (-1))][intCol + (count * (-1))] !=
               colour) {
          count++;
          score++;
        }
      }
      count = 0;
      if (checkLegalInDirection(board, n, intRow, intCol, colour, -1, 0) ==
          true) {
        while (board[intRow + (count * (-1))][intCol + (count * 0)] != colour) {
          count++;
          score++;
        }
      }
      if (score > greatestScore) {
        greatestScore = score;
        move[0] = intRow + 'a';
        move[1] = intCol + 'a';
      }
      score = 0;  // reinnitialize score
    }
  }
}

int calculateScore(char board[26][26], int n, char color) {
  int score = 0;
  for (int row = 0; row < n; row++) {
    for (int col = 0; col < n; col++) {
      if (board[row][col] == color) {
        score++;
      }
    }
  }
  return score;
}

int makeMove(char board[26][26], int n, char turn, int *row, int *col) {
  /*
  // old algorithm from part one
  char colour = turn;
  // fist calculate the score, then store row and col value for greatest score
  int count = 0, score = 0, greatestScore = 0;
  for (int intRow = 0; intRow < n; intRow++) {
    for (int intCol = 0; intCol < n; intCol++) {
      if (checkLegalInDirection(board, n, intRow, intCol, colour, -1, 1) ==
          true) {
        while (board[intRow + (count * (-1))][intCol + (count * 1)] != colour) {
          count++;
          score++;
        }
      }
      count = 0;
      if (checkLegalInDirection(board, n, intRow, intCol, colour, 0, 1) ==
          true) {
        while (board[intRow + (count * 0)][intCol + (count * 1)] != colour) {
          count++;
          score++;
        }
      }
      count = 0;
      if (checkLegalInDirection(board, n, intRow, intCol, colour, 1, 1) ==
          true) {
        while (board[intRow + (count * 1)][intCol + (count * 1)] != colour) {
          count++;
          score++;
        }
      }
      count = 0;
      if (checkLegalInDirection(board, n, intRow, intCol, colour, 1, 0) ==
          true) {
        while (board[intRow + (count * 1)][intCol + (count * 0)] != colour) {
          count++;
          score++;
        }
      }
      count = 0;
      if (checkLegalInDirection(board, n, intRow, intCol, colour, 1, -1) ==
          true) {
        while (board[intRow + (count * (1))][intCol + (count * (-1))] !=
               colour) {
          count++;
          score++;
        }
      }
      count = 0;
      if (checkLegalInDirection(board, n, intRow, intCol, colour, 0, -1) ==
          true) {
        while (board[intRow + (count * (0))][intCol + (count * (-1))] !=
               colour) {
          count++;
          score++;
        }
      }
      count = 0;
      if (checkLegalInDirection(board, n, intRow, intCol, colour, -1, -1) ==
          true) {
        while (board[intRow + (count * (-1))][intCol + (count * (-1))] !=
               colour) {
          count++;
          score++;
        }
      }
      count = 0;
      if (checkLegalInDirection(board, n, intRow, intCol, colour, -1, 0) ==
          true) {
        while (board[intRow + (count * (-1))][intCol + (count * 0)] != colour) {
          count++;
          score++;
        }
      }
      if (score > greatestScore) {
        greatestScore = score;
        *row = intRow;
        *col = intCol;
      }
      score = 0;  // reinnitialize score
    }
  }
  return 0;
  */
  // new one (somehting close to minimax)
  char testBoard[26][26];
  for (int Row = 0; Row < n; Row++) {
    for (int Col = 0; Col < n; Col++) {
      testBoard[Row][Col] = board[Row][Col];
    }
  }
  char opposite = 'B', move[3], cMove[3];
  if (turn == 'B') {
    opposite = 'W';
  }

  greatestScore = 0;

  for (int r = 0; r < n; r++) {
    for (int c = 0; c < n; c++) {
      if (checkLegalInAllDir(testBoard, n, r, c, turn) == true) {
        executeMove(testBoard, r, c, n, turn);
        getComputerMove(testBoard, n, move, opposite);
        executeMove(testBoard, move[0], move[1], n, opposite);
        for (int r2 = 0; r2 < n; r2++) {
          for (int c2 = 0; c2 < n; c2++) {
            if (checkLegalInAllDir(testBoard, n, r2, c2, turn) == true) {
              executeMove(testBoard, r2, c2, n, turn);
              getComputerMove(testBoard, n, move, opposite);
              executeMove(testBoard, move[0], move[1], n, opposite);
              for (int r3 = 0; r3 < n; r3++) {
                for (int c3 = 0; c3 < n; c3++) {
                  if (checkLegalInAllDir(testBoard, n, r3, c3, turn) == true) {
                    executeMove(testBoard, r3, c3, n, turn);
                    getComputerMove(testBoard, n, move, opposite);
                    executeMove(testBoard, move[0], move[1], n, opposite);
                    if (calculateScore(testBoard, n, turn) > greatestScore) {
                      greatestScore = calculateScore(testBoard, n, turn);
                      *row = r;
                      *col = c;
                    }
                  }
                }
                for (int Row = 0; Row < n; Row++) {
                  for (int Col = 0; Col < n; Col++) {
                    testBoard[Row][Col] = board[Row][Col];
                  }
                }
              }
            }
            for (int Row = 0; Row < n; Row++) {
              for (int Col = 0; Col < n; Col++) {
                testBoard[Row][Col] = board[Row][Col];
              }
            }
          }
        }
      }
      for (int Row = 0; Row < n; Row++) {
        for (int Col = 0; Col < n; Col++) {
          testBoard[Row][Col] = board[Row][Col];
        }
      }
    }
  }
  return 0;
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

  // ask for color of computer tiles
  char computerColor, userColor;
  printf("Computer plays (B/W): ");
  scanf(" %c", &computerColor);

  if (computerColor == 'B') {
    userColor = 'W';
  } else {
    userColor = 'B';
  }

  // print the initialized board
  printBoard(board, n);

  // decide whether user goes first or computer
  bool computerTurn = false;
  if (computerColor == 'B') {
    computerTurn = true;
  }

  // now execute turns (game ends if board full or neither player has available
  // move)
  char userMove[3], computerMove[3];
  int rows = 0, cols = 0;
  while (isBoardFull(board, n) != true && anyValidMove(board, n) == true) {
    if (computerTurn == true) {
      if (validMovesAvailable(board, n, computerColor) == false) {
        printf("%c player has no valid move.\n", computerColor);
        computerTurn = false;
      } else {
        makeMove(board, n, computerColor, &rows, &cols);
        printf("Computer places %c at %c%c.\n", computerColor, rows + 'a',
               cols + 'a');
        executeMove(board, rows + 'a', cols + 'a', n, computerColor);
        printBoard(board, n);
        computerTurn = false;
      }
    } else {
      if (validMovesAvailable(board, n, userColor) == false) {
        printf("%c player has no valid move.\n", userColor);
        computerTurn = true;
      } else {
        printf("Enter move for colour %c (RowCol): ", userColor);
        scanf("%s", userMove);
        if (isMoveValid(board, n, userMove, userColor) == false) {
          printf("Invalid move.\n%c player wins.", computerColor);
          return 0;
        }
        executeMove(board, userMove[0], userMove[1], n, userColor);
        printBoard(board, n);
        computerTurn = true;
      }
    }
  }

  // now determine winner based on number of tiles of each player
  if (calculateScore(board, n, 'B') > calculateScore(board, n, 'W')) {
    printf("B player wins.\n");
  } else if (calculateScore(board, n, 'B') < calculateScore(board, n, 'W')) {
    printf("W player wins.\n");
  } else {
    printf("Draw!\n");
  }

  return 0;
}
