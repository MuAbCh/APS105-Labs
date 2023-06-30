//Calculating the Score of Each Player

#include <stdbool.h>
#include <stdio.h>
void calculateScore(int[], const int, int[], int[], const int, int*,
                    int*);  // calculate the score of each user

int main(void) {
  const int BoxesNum = 20;
  const int ChoicesNum = 5;
  int boxes[BoxesNum], userOne[ChoicesNum], userTwo[ChoicesNum];
  printf("Enter boxes content: ");
  for (int i = 0; i < BoxesNum; i++) {
    scanf("%d", &boxes[i]);
  }
  printf("Enter player 1 choices: ");
  for (int i = 0; i < ChoicesNum; i++) {
    scanf("%d", &userOne[i]);
  }
  printf("Enter player 2 choices: ");
  for (int i = 0; i < ChoicesNum; i++) {
    scanf("%d", &userTwo[i]);
  }
  int userOneScore = 0, userTwoScore = 0;
  calculateScore(boxes, BoxesNum, userOne, userTwo, ChoicesNum, &userOneScore,
                 &userTwoScore);
  printf("Player 1: %d.\nPlayer 2: %d.\n", userOneScore, userTwoScore);
  return 0;
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
