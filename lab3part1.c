//Numerical Bases

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int charChecker(char c) {
  if (c == '+') {
    return 1;
  } else if (c == '-') {
    return 1;
  } else if (c == '/') {
    return 1;
  } else if (c == '*') {
    return 1;
  } else if (c == '$') {
    return 1;
  } else {
    return 0;
  }
}

int numOfDigits(int num) {
  int n = 0;
  while (num != 0) {
    num = num / 10;
    n++;
  }
  return n;
}  // A function which returns the number of digits in a number

int convert2Base10(int number, int Base1) {
  int digits = numOfDigits(number), numB10 = 0, counter = 0,
      intermediateNum = 0;
  while (counter <= (digits - 1)) {
    intermediateNum = (number % 10) * pow(Base1, counter);
    number = number / 10;
    numB10 = numB10 + intermediateNum;
    counter++;
  }
  return numB10;  // function which converts numbers from any base to base 10
}

int convert2UserBase(int ans, int Base2) {
  int counter = 0, IN = 0, numBU = 0;
  while (ans != 0) {
    IN = ans % Base2;
    ans = ans / Base2;
    numBU = numBU + (IN * pow(10, counter));
    counter++;
  }
  return numBU;
}

int baseNumChecker(int Num, int Base) {
  while (Num != 0) {
    int IN = Num % 10;
    if (IN >= Base) {
      return 0;
    } else {
      Num = Num / 10;
    }
  }
  return 1;
}
