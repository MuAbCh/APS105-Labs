//Populating the Boxes and Validating the Player's Choices

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool validateChoices(int choices[], const int ChoicesNum, const int BoxesNum);
void takeUserChoices(int userOne[], int userTwo[], const int ChoicesNum,
                     const int BoxesNum);
void populateBoxes(int boxes[], const int BoxesNum);

int main(void) {
  const int BoxesNum = 20;
  const int ChoicesNum = 5;
  int boxes[BoxesNum], userOne[ChoicesNum], userTwo[ChoicesNum];
  populateBoxes(boxes, BoxesNum);
  takeUserChoices(userOne, userTwo, ChoicesNum, BoxesNum);
  return 0;
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

void populateBoxes(int boxes[], const int BoxesNum) {
  // Fill each element randomly by either
  // 0 empty
  // -10 bomb
  // 10 candy
  // Print the contents of the boxes
  for (int counter = 0; counter < BoxesNum; counter++) {
    int x = 0;
    boxes[counter] = ((rand() % 3) - 1) * 10
    }

  for (int index = 0; index < BoxesNum; index++) {
    int num = boxes[index];
    printf("%d: %d, ", index, num);
  }
  printf("\n");
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
