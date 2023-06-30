//Addding the Loop - Game Complete

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void populateBoxes(int[], int);
void takeUserChoices(int[], int[], const int, const int);
bool validateChoices(int[], const int, const int);
void calculateScore(int[], const int, int[], int[], const int, int*,
                    int*);  // calculate the score of each user
void appendStatistics(int[], const int, int[]);
int frequentBox(int[], const int);

int main(void) {
  // don't set srand!
  const int BoxesNum = 20;
  const int ChoicesNum = 5;
  int boxes[BoxesNum], userOne[ChoicesNum], userTwo[ChoicesNum],
      histogramUserOne[BoxesNum], histogramUserTwo[BoxesNum];
  int userOneScore = 0, userTwoScore = 0;
  for (int i = 0; i < BoxesNum; i++) {
    histogramUserOne[i] = 0;
    histogramUserTwo[i] = 0;
  }

  // start from here
  int dif = 0;
  while (dif <= 50) {
    populateBoxes(boxes, BoxesNum);
    takeUserChoices(userOne, userTwo, ChoicesNum, BoxesNum);
    calculateScore(boxes, BoxesNum, userOne, userTwo, ChoicesNum, &userOneScore,
                   &userTwoScore);
    // Append Statistics for User One
    appendStatistics(userOne, ChoicesNum, histogramUserOne);
    // Append Statistics for User Two
    appendStatistics(userTwo, ChoicesNum, histogramUserTwo);
    if (userOneScore > userTwoScore) {
        dif = userOneScore - userTwoScore;
    } else {
        dif = userTwoScore - userOneScore;
    }
  }

  printf("Player 1: %d.\nPlayer 2: %d.\n", userOneScore, userTwoScore);
  if (userOneScore > userTwoScore) {
    printf("User 1 wins,");
    printf(" and the first box they chose most frequently is: %d\n",
           frequentBox(histogramUserOne, BoxesNum));
  } else {
    printf("User 2 wins,");
    printf(" and the first box they chose most frequently is: %d\n",
           frequentBox(histogramUserTwo, BoxesNum));
  }
  return 0;
}

void populateBoxes(int boxes[], const int BoxesNum) {
  // Fill each element randomly by either
  // 0 empty
  // -10 bomb
  // 10 candy
  // Print the contents of the boxes
  for (int counter = 0; counter < BoxesNum; counter++) {
    boxes[counter] = ((rand() % 3) - 1) * 10;
  }

  for (int index = 0; index < BoxesNum; index++) {
    int num = boxes[index];
    printf("%d: %d, ", index, num);
  }
  printf("\n");
}

void takeUserChoices(int userOne[], int userTwo[], const int ChoicesNum,
                     const int BoxesNum) {
  // Can check if the inputs are distinct and if they are between 1 and BoxesNum
  // - 1
  do {
    printf("Player 1, please enter distinct box choices between 0 and 19: ");
    for (int choiceInd = 0; choiceInd < ChoicesNum; choiceInd++) {
      scanf("%d", &userOne[choiceInd]);
    }
  } while (!validateChoices(userOne, ChoicesNum, BoxesNum));
  do {
    printf("Player 2, please enter distinct box choices between 0 and 19: ");
    for (int choiceInd = 0; choiceInd < ChoicesNum; choiceInd++) {
      scanf("%d", &userTwo[choiceInd]);
    }
  } while (!validateChoices(userTwo, ChoicesNum, BoxesNum));
}

bool validateChoices(int choices[], const int ChoicesNum, const int BoxesNum) {
  bool valid = true;
  // Check if elements in choices is between 0 and BoxesNum - 1
  int tempNum = -1;
  for (int index = 0; index < ChoicesNum; index++) {
    int x = choices[index];
    if (x < 0 || x > BoxesNum - 1) {
      valid = false;
    } else if (tempNum == x) {
      valid = false;
    }
    tempNum = x;
  }
  // Check if elements in choices is distinct (done with tempNum at top)
  return valid;
}

void calculateScore(int boxes[], const int BoxesNum, int userOne[],
                    int userTwo[], const int ChoicesNum, int* score1,
                    int* score2) {
  // Get the score of each user
  int x = 0;
  for (int i = 0; i < BoxesNum; i++) {
    x = boxes[i];
    int pick1 = 0, pick2 = 0;

    for (int z = 0; z < ChoicesNum; z++) {
      if (userOne[z] == i) {
        pick1 = 1;
      }
      if (userTwo[z] == i) {
        pick2 = 1;
      }
    }

    if (x == 10 || x == -10) {
      printf("Found %d in boxes[%d]\n", x, i);
      if (x == 10) {
        if (pick1 == 1 && pick2 == 1) {
          printf(
              "Found index %d in player 1.\nFound index %d in player 2.\n+5 "
              "to "
              "players 1 and 2 scores\n",
              i, i);
          *score1 = *score1 + 5;
          *score2 = *score2 + 5;
        } else if (pick1 == 1) {
          printf("Found index %d in player 1.\n+10 to player 1 score.\n", i);
          *score1 = *score1 + 10;
        } else if (pick2 == 1) {
          printf("Found index %d in player 2.\n+10 to player 2 score.\n", i);
          *score2 = *score2 + 10;
        }
      } else if (x == -10) {
        if (pick1 == 1 && pick2 == 1) {
          printf(
              "Found index %d in player 1.\nFound index %d in player 2.\n-10 "
              "from player 1 score.\n-10 from player 2 score.\n",
              i, i);
          *score1 = *score1 - 10;
          *score2 = *score2 - 10;
        } else if (pick1 == 1) {
          printf("Found index %d in player 1.\n-10 from player 1 score.\n", i);
          *score1 = *score1 - 10;
        } else if (pick2 == 1) {
          printf("Found index %d in player 2.\n-10 from player 2 score.\n", i);
          *score2 = *score2 - 10;
        }
      }
    }
  }
}

void appendStatistics(int userChoice[], const int ChoicesNum, int histogram[]) {
  // Fill in the histogram with the number of times each index was picked
  for (int x = 0; x < ChoicesNum; x++) {
    int value = userChoice[x];
    for (int y = 0; y < 20; y++) {
      if (value == y) {
        histogram[y]++;
      }
    }
  }
  // Print the histogram
  for (int counter = 0; counter < 20; counter++) {
    printf("%d: %d, ", counter, histogram[counter]);
  }
  printf("\n");
}

int frequentBox(int histogram[], const int BoxesNum) {
  // Return the index having the maximum number in histogram
  int greatestNum = 0, x = 0, y = 0, GP = 0;
  for (int counter = BoxesNum - 1; counter > 0; counter--) {
    x = histogram[counter];
    y = histogram[counter - 1];
    if (greatestNum <= y) {
      greatestNum = y;
      GP = counter - 1;
    } else if (greatestNum <= x) {
      greatestNum = x;
      GP = counter;
    }
  }
  return GP;
}
