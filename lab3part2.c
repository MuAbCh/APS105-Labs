//Printing Circle

#include <math.h>
#include <stdio.h>

void printCircle(int radius) { 
  for (int y = -radius; y <= radius; y++) {
    for (int x = -radius; x <= radius; x++) {
      if (pow(x, 2) + pow(y, 2) <= pow(radius, 2)) {
        printf("o");
      } else {
        printf(".");
      }
    }
    printf("\n");
  }
}

int main(void) {
  int r = 0;

  printf("Enter the radius of the circle: ");
  scanf("%d", &r);

  printCircle(r);

  return 0;
}
