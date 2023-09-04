//
// APS105 Winter 2022 Lab 1 Part 2
//
// Program that reads in the daily rate, number of rental days,
// and prints the eligible free rental days and the total rental
// charge tax inclusive.

// Note: Every 4-day block in a rental period is counted as 3 days.
// Assumption: All input values are valid.
//

/*
1. collect _daily rate_ from the user
2. collect _rental period_ from the user
3. calculate the total numebr of day needed to be charged
4. calculate the number of free day(s) if available
5. calculate the totla charge needed
6. print the _total free days_
7. print the _total charge_
*/

#include <stdio.h>

int main(void)
{   
    double daily_rate, rental_period;  // definging # variables: daily_rate, rental_period
    int numfree_day, numcharge_day;  // defining # variables: numfree_day, numcharge_day  
    double payment;  // defining variable: the total fees for the customer

    printf("Enter the daily rate: ");  // _daily rate_ from the user
    scanf("%lf", &daily_rate);

    printf("Enter the rental period (in days): ");  //collect _rental period_ from the user
    scanf("%lf", &rental_period);


    numfree_day = rental_period / 4;  // 4 days per block: 3 days no discount + 1 day free
    numcharge_day = rental_period - numfree_day;  // calculates the day(s) that are charged

    payment = daily_rate * numcharge_day * 1.13;  // the final charging included with the 13% HST in Ontario


    printf("\nYour total free day(s) in this rental is: %d\n", numfree_day);
    printf("Your total charge including taxes is: %0.2lf", payment);


    //testing~~~
    //printf("\n\n%0.2lf  %0.2lf  %d  %lf", daily_rate, rental_period, numfree_day, payment);
    //tester = daily_rate - 0.00;
    //printf("\n%0.2lf", tester);

    return 0;
}