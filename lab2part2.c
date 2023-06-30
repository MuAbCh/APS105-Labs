//Cartesian Coordinates

#include <stdio.h>
#include <math.h>

int main(void) {

    double Xcoor = 0.0, Ycoor = 0.0;

    printf("Enter the x-coordinate in floating point: ");
    scanf("%lf", &Xcoor);
    printf("Enter the y-coordinate in floating point: \n");
    scanf("%lf", &Ycoor);

    Xcoor = rint(Xcoor * 100) / 100;
    Ycoor = rint(Ycoor * 100) / 100;

    if (Xcoor == 0 && Ycoor == 0) {
        printf("(%.2lf, %.2lf) is at the origin.\n", Xcoor, Ycoor);
    } //if statement for origin

    if (Xcoor == 0 && Ycoor != 0) {
        printf("(%.2lf, %.2lf) is on the y axis.\n", Xcoor, Ycoor);
    } //if statement for y axis

    if (Xcoor != 0 && Ycoor == 0) {
        printf("(%.2lf, %.2lf) is on the x axis.\n", Xcoor, Ycoor);
    } //if statement for x axis

    if (Ycoor > 0 && Xcoor > 0){
        printf("(%.2lf, %.2lf) is in quadrant I.\n", Xcoor, Ycoor);
    } //Q1 if statement. Checking to see if both X and Y are psoitive

    if (Ycoor > 0 && Xcoor < 0) {
        printf("(%.2lf, %.2lf) is in quadrant II.\n", Xcoor, Ycoor);
    }

    if (Ycoor < 0 && Xcoor < 0) {
        printf("(%.2lf, %.2lf) is in quadrant III.\n", Xcoor, Ycoor);
    }

    if (Ycoor < 0 && Xcoor > 0) {
        printf("(%.2lf, %.2lf) is in quadrant IV.\n", Xcoor, Ycoor);
    }

    return 0;
}
