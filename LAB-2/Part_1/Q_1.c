/*
Due: Sat. Jan. 29th. 2022
Lab 2: More Comlpex Calculations
Part 1: Using arithmetic operators, maths functions from the math library and the given formulation
        calculate the monthly playment for a customer to buy a car
*/

#include <stdio.h>
#include <math.h>

int main(void)
{
    /* 1. Declareing variables: purchasePrice - P , downPayment - D , financeTerm - n , interestRate - r  */
                            // monthlyPayment - M //
    int purchasePrice, downPayment, financeTerm;
    double interestRate, monthlyPayment, numerator, denominator; 


    /* 2. Collect the required information from the user.  */
    printf("Enter the purchase price P: ");
        scanf("%d", &purchasePrice);

    printf("Enter the amount of down payment D: ");
        scanf("%d", &downPayment);

    printf("Enter the finance term (in months): ");
        scanf("%d", &financeTerm);

    printf("Enter the monthly interest r0ate (in percent): ");
        scanf("%lf", &interestRate);


    /* 3. Perform calculation for the monthly payment. */
    double rate = interestRate * 0.01;

    /* 3.1 Calculate the numerator of the M - fraction.  */
    numerator = (purchasePrice - downPayment) * rate * pow((1 + rate), financeTerm);

    /* 3.2 Calculate the denominator of the M - fraction.  */
    denominator = pow((1 + rate), financeTerm) - 1.0;

    /* 3.3 divide the numerator by the denominator to yields M.  */
    monthlyPayment = numerator / denominator;


    /* 4. Display the result of the calculation.  */
    printf("\nThe monthly payment is: %.2lf", monthlyPayment);


    /* testing~  */
    //printf("\n%d  %d  %d  %lf  ", purchasePrice, downPayment, financeTerm, rate);
    //printf("\n%lf  %lf  %lf  ", numerator, denominator, monthlyPayment);

    return 0;
}
