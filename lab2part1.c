//Tirgnometric Calculations

#include <stdio.h>
#include <math.h>

int main(void) {

    double Xvar = 0, Yvar = 0, Hvar = 0, theta = 0;

    printf("Enter X: ");
    scanf("%lf", &Xvar);

    printf("Enter Y: ");
    scanf("%lf", &Yvar);

    Hvar = sqrt(pow(Xvar, 2) + pow(Yvar, 2));

    theta = asin(Yvar / Hvar) * (180 / M_PI);

    printf("\nThe Hypotenuse Lenght is: %.1lf\nThe Angle Theta is %.1lf degrees\n", Hvar, theta);

    return 0;
}
