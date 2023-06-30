//Kaprekar's Constant

#include <math.h>
#include <stdio.h>

int DOD(int n) {
  int AN = getAscendingOrderedDigits(n), DN = 0, IN = 0;
  for (int counter = 3; counter >= 0; counter--) {
    IN = AN % 10;
    DN += (IN * pow(10, counter));
    AN /= 10;
  }
  return DN;
}

void KCD(int num) {
  if (num < 1000) {
    printf("Error: The number is too small.\n");
  } else if (num > 9999) {
    printf("Error: The number is too large.\n");
  } else {
    int counter = 0, num1 = 0, num2 = 0;
    while (num != 6174) {
      counter++;
      printf("Number %d: %d\n", counter, num);
      num1 = getAscendingOrderedDigits(num);
      num2 = DOD(num);
      if (num1 > num2) {
        num = num1 - num2;
      } else {
        num = num2 - num1;
      }
    }
    printf(
        "Number %d: 6174\nKaprekar's Constant was reached in %d iteration(s)\n",
        (counter + 1), counter);
  }
}

int main(void) {
  int num = 0;

  printf("Enter a number (-1 to stop): ");
  scanf("%d", &num);

  while (num != -1) {
    KCD(num);

    printf("Enter a number (-1 to stop): ");
    scanf("%d", &num);
  }

  return 0;
}
