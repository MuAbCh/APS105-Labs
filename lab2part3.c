//BMI

#include <stdio.h>
#include <math.h> 

int main(void) {

    double weight = 0.0, H = 0.0, BMI = 0.0;
    char c1, c2, c3, c4;

    printf("Enter the body weight: ");
    scanf(" %lf%c%c", &weight, &c1, &c2);
    printf("Enter the height: \n");
    scanf(" %lf%c%c", &H, &c3, &c4);

    if (c1 == 108 && c2 == 98) { //ascii for l and b
        weight = weight * 0.4536; //convert from lb to kg
    }

    if (c3 == 105 && c4 == 110) { //ascii for i and n
        H = H / 39.37; //convert inches to meters
    } else if (c3 == 102 && c4 == 116) { //ascii for f and t
        H = H / 3.281;
    }

    BMI = rint((weight / pow(H, 2)) * 10) / 10; //calculating BMI with weight in kg and H in metres

    printf("The Body Mass Index (BMI) is: %.1lf\n", BMI);

    if (BMI >= 30.0) {
        printf("Category: Obesity\n");
    } else if (BMI >= 25.0 && BMI <= 29.9) {
        printf("Category: Overweight\n");
    } else if (BMI >= 18.5 && BMI <= 24.9) {
        printf("Category: Healthy Weight\n");
    } else if (BMI < 18.5) {
        printf("Category: Underweight\n");
    }

    return 0;

}
