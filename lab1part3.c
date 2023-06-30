//Conversion to Base 2

#include <stdio.h>

int main(void) {

    int inputNum = 0, D1, D2, D3, D4, IN1, IN2, IN3; /*Declaring variables. 
    D stands for Digit and we need intermediate variables wich will hold intermediate value which
    will be used for further division. IN stands for intermediate number*/

    printf("Enter number to convert to base 2: ");
    scanf("%d", &inputNum);

    D4 = inputNum % 2;
    IN1 = (inputNum - D4) / 2;
    D3 = IN1 % 2;
    IN2 = (IN1 - D3) / 2;
    D2 = IN2 % 2;
    IN3 = (IN2 - D2) / 2;
    D1 = IN3 % 2;

    printf("The four digits of that number are as follows:\nMost significant digit: %d\nNext digit: %d\nNext digit: %d\nLeast significant digit: %d\n", D1, D2, D3, D4);

    return 0;
}
