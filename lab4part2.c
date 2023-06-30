//Graphing

#include <math.h>
#include <stdio.h>

void printFunction(int x0, int x1, int x2, int x3) {
  for (int y = -10; y <= 10; y++) {
    for (int x = -10; x <= 10; x++) {
      if (y == -(x0 + x1 * x + x2 * pow(x, 2) +
                x3 * pow(x, 3))) {  //x0, x1 .. are all coefficients
        printf(" * ");
      } else if (x == 0) {
        printf(" | ");
      } else if (y == 0) {
        printf(" - ");
      } else {
        printf("   ");
      }
    }
    printf("\n");
  }
}

int main(void) {
  int order = 0, coEff0 = 0, coEff1 = 0, coEff2 = 0, coEff3 = 0;

  printf("Enter the order of the function: ");
  scanf("%d", &order);

  while (order != -1) {
    while (order != -1) {
      if (order == 0) {
        printf("Enter coefficient of x^0: ");
        scanf("%d", &coEff0);
        break;
      } else if (order == 1) {
        printf("Enter coefficient of x^0: ");
        scanf("%d", &coEff0);
        printf("Enter coefficient of x^1: ");
        scanf("%d", &coEff1);
        break;
      } else if (order == 2) {
        printf("Enter coefficient of x^0: ");
        scanf("%d", &coEff0);
        printf("Enter coefficient of x^1: ");
        scanf("%d", &coEff1);
        printf("Enter coefficient of x^2: ");
        scanf("%d", &coEff2);
        break;
      } else if (order == 3) {
        printf("Enter coefficient of x^0: ");
        scanf("%d", &coEff0);
        printf("Enter coefficient of x^1: ");
        scanf("%d", &coEff1);
        printf("Enter coefficient of x^2: ");
        scanf("%d", &coEff2);
        printf("Enter coefficient of x^3: ");
        scanf("%d", &coEff3);
        break;
      } else {
        printf("The order must be between [0, 3].\n");
        printf("Enter the order of the function: ");
        scanf("%d", &order);
      }
    }
    if (order == -1) {
        break;
    }
      printFunction(coEff0, coEff1, coEff2, coEff3);
      coEff0 = 0, coEff1 = 0, coEff2 = 0, coEff3 = 0;
      printf("Enter the order of the function: ");
      scanf("%d", &order);
  }

  return 0;
}
