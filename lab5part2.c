//Getting the Statistics of the Game

#include <stdio.h>

void appendStatistics(int userChoice[], const int ChoicesNum, int histogram[]);
int frequentBox(int histogram[], const int BoxesNum);

int main(void) {
  const int BoxesNum = 20;
  const int ChoicesNum = 5;
  int userOne[ChoicesNum], userOneHisto[BoxesNum];
  for (int i = 0; i < BoxesNum; i++) {
    userOneHisto[i] = 0;
  }
  int numOfTimes = 0;
  while (numOfTimes <= 5) {
    printf("Enter choices: ");
    for (int i = 0; i < 5; i++) {
      scanf("%d", &userOne[i]);
    }
    appendStatistics(userOne, ChoicesNum, userOneHisto);
    numOfTimes++;
  }
  printf("The smallest and most frequently used box is: %d\n",
         frequentBox(userOneHisto, BoxesNum));
  return 0;
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
      GP = counter -1;
    } else if (greatestNum <= x) {
      greatestNum = x;
      GP = counter;
    }
  }
  return GP;
}

