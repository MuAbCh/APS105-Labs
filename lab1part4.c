//Debusging: Denigged Version

#include <stdio.h>

int main(void) {
	const double CmPerInch = 2.54;
	const double CmPerMetre = 100.00;
	const int InchesPerFoot = 12;
	const int InchesPerYard = 36;
	
	double distance;
	printf("Please provide a distance in metres: ");
	scanf("%lf", &distance);
	
	double distanceInInches = (distance * CmPerMetre) / CmPerInch;
	
	int inches = distanceInInches;

	int yards = inches / InchesPerYard;
	
	// how many inches are left after extracting yards
	inches = inches % InchesPerYard;
	
	int feet = inches / InchesPerFoot;
	
	// how many inches are left after extracting feet
	inches = inches % InchesPerFoot;
 /* code is good up till here, everything seems to be printing 
 properly and giving the right outup after the fixes made above. The only issue 
 is the remainder left in inches. That is printing wrong as the variable printed is
 the intial value we started off with, not the remainder, so we need to calculate
 the remainder */
	double remainder = distanceInInches - yards * InchesPerYard - feet * InchesPerFoot - inches;
	printf("%d yards, %d feet, %d inches, %.2f inches remainder\n", yards, feet, inches, remainder);
	
	return 0;
}
