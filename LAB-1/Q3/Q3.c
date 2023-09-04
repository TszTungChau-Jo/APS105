//
// APS105 Winter 2022 Lab 1 Part 3
//
// A C program that converts metres to yards, feet and inches.
//

/*
0. define vairables
1. collect _meters_ from the user
2. conversion
3. print out the result
*/

#include <stdio.h>

int main(void)
{   
    //part 1: define variables
    double user_input, metres;
    int inches, feet, yards;   


    //part 2: collect info. from the user
    printf("Please provide a distance in metres: ");  // get a number of distance in metres
        scanf("%lf", &user_input);  


    //part 3: unit conversions
    /* 
        we know that 
        1 inch = 2.54 cm
        1 foot = 12 inches
        1 yard = 3 feet = 3 * 12 inches = 3 * 12 * 2.54 cm = 3 * 12 * 0.0254 m
    */

    metres = user_input;

    //yards conversions
    double metres_factor_yards = 3 * 12 * 0.0254;
    yards = metres / metres_factor_yards;
        double yards_c = (double)yards;  //for calculation
        double yards_d = metres / metres_factor_yards;  //store a double for calculation
    double re_yards = yards_d - yards_c;  //yards remainder
    
    //feet conversions
    double yards_factor_feet = 3;
    feet = re_yards * yards_factor_feet;
        double feet_c = feet;  //for calculation
        double feet_d = re_yards * yards_factor_feet;  //store a double for calculation
    double re_feet = feet_d - feet_c;  //feet remainder

    //inches conversion
    double feet_factor_inches = 12;
    inches = re_feet * feet_factor_inches;
        double inches_c = inches;  //for calculation
        double inches_d = re_feet * feet_factor_inches;  //store a double for calculation
    double re_inches = inches_d - inches_c;  //feet remainder


    //part 4: printing out the result
    printf("%d yards, %d feet, %d incehs, %0.2lf inches remainder",  yards, feet, inches, re_inches);


    //testing~~~
    /*
    printf("\n\n%d", yards);
    printf("\n%lf  %lf  %lf", yards_d, feet_c, re_yards);

    printf("\n\n%d", feet);
    printf("\n%lf  %lf  %lf", feet_d, feet_c, re_feet);

    printf("\n\n%d", inches);
    printf("\n%lf  %lf  %lf", inches_d, inches_c, re_inches);
    */

    return 0;
}







/*
    double user_input;  // collector: for the inputed "metres"

    printf("Please provide a distance in metres: ");  // collection: of the inputed "meters"
        scanf("%lf", &user_input);


    double meter_to_centi = user_input * 100;  //conversion: meters to cms
    double centi_to_inch = meter_to_centi / 2.54;  //conversion: cms to inches
    double inch_to_foot = centi_to_inch / 12;  //conversion: inches to feet
    double foot_to_yard = inch_to_foot / 3;  //conversion: feet to yards

    
    int yards = foot_to_yard;  //taking the "int" part of yards
        double yards_d = yards;
            double yards_remainder = foot_to_yard - yards_d;

    double yards_to_feet = yards_remainder * 3;  //reverse conversion
        
    int feet = yards_to_feet; 
        double feet_d = feet;
            double feet_remainder = yards_to_feet - feet_d;

    printf("\n\n%lf cm  %lf inches  %lf feet  %lf yards", meter_to_centi, centi_to_inch, inch_to_foot, foot_to_yard);
    printf("\n%d  %lf", yards, yards_d);
    printf("\n%lf  %lf", yards_remainder, yards_to_feet);
    printf("\n%d", feet);
    printf("\n%lf  %lf", feet_d, feet_remainder);
*/






/*
    double meters; // define input: meters
    double inches;  // define output: yards, feet, inches
    double remainder;  // define opearator: remainder

  
    printf("Please provide a distance in metres: ");
        scanf("%lf", &meters);

    remainder = meters % 0.02540.
    ; 
    inches = (meters / 0.0254) - meters;  // conversion: 1 inch = 2.54 cm = 0.0254 m
    
    //yards = 
    //feet  = 

    printf("\n yards,  feet,  inches, and  inch remainder");

    //testing~~~
    printf("\n\n%0.2lf %lf", meters, inches);

*/