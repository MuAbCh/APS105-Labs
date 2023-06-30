//Debugging: Debugged Version

#include <stdbool.h>
#include <stdio.h>

bool isShuffled(int);
int getNumDigits(int);
int getSmallestDigit(int);
bool lookForDigit(int, int);

int main(void) { 
  int num;
  printf("Enter the number to check: ");
  scanf("%d", &num);
  if (isShuffled(num)) {
    printf("Shuffled!");
  } else {
    printf("Not shuffled!");
  }
  return 0;
}

bool isShuffled(int shuffledOrder) {
  bool isShuffled = true;
  int numOfDigits = getNumDigits(shuffledOrder);
  int smallestDigit = getSmallestDigit(shuffledOrder);

  for (int place = 1; place < numOfDigits && isShuffled; place++) {
    if (!lookForDigit(shuffledOrder, smallestDigit + place)) {
      isShuffled = false;
    }
  }
  return isShuffled;
}

int getNumDigits(int num) {
  int count = 0;
  while (num > 0) {
    num = num / 10;
    count++;
  }
  return count;
}

int getSmallestDigit(int num) {
  int smalldig; 
  smalldig = num % 10;
  int digit = 0;
  while (num != 0) {
    digit = num % 10;
    if (digit < smalldig) {
      smalldig = digit;
    }
    num /= 10;
  }
  return smalldig;
}

bool lookForDigit(int num, int searchDigit) {
  int digit = 0;
  bool foundDigit = false;
  while (num != 0) {
    digit = num % 10;
    if (digit == searchDigit) {
      foundDigit = true;
    }
    num /= 10;
  }
  return foundDigit;
}
