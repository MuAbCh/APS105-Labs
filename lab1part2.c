//Currency Conversion 
#include <stdio.h>

int main(void) {

    double inputCR = 0, inputAmount = 0, outputAmount = 0;

    printf("Enter the conversion rate: ");
    scanf("%lf", &inputCR);
    printf("Enter the amount to be converted (in foreign currency): ");
    scanf("%lf", &inputAmount);

    outputAmount = inputCR * inputAmount;
    printf("The amount in Canadian Dollars is: %.2lf\n", outputAmount);

}
