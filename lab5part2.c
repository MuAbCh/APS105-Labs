//Getting the Statistics of the Game

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
