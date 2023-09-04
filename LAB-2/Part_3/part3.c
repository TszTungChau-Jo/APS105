/*
Completion Date: 2022/01/20
Lab 3: Part 3——Arrival Time Calculator
Task: takes in the current time in hrs and mins, and the trip time in hrs,
        then tells the user if them will arrive on the same day, or the next day,
        as well as the time in 24hrs format.
*/

/* Assumptions:
    1. the trip time is less than 24 hrs 
    2. only available input values, ex: integers for hours and min in line_1, double for tripTime 
    2.1 input current hours can only be within the range from 00:00 to 23:59;
    2.2 input minutes can only be within the range from 00 to 59;
*/

/* Thoughts procedure: (general)
    1. Collect data
    2. Units and maths conversions
    3. Outputs results
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    /* 0. Deaclaring variables.  */
    double currentHours, currentMinutes, currentSum, sumTime;  // sumTime(minutes)
    double tripTime, tripHours, tripMinutes, tripSum;  // tripTime(hours), tripSum(minutes)
    const double MinutesPerHour = 60, HoursPerDay = 24;
    const double MinutesPerDay = 24 * 60;  // there are total 24 hr per day * 60 mins per hr = 1440 mins per day


    /* 1. Collecting the times.  */
    printf("Enter current time: ");
        scanf("%lf%lf", &currentHours, &currentMinutes);  //to pass the 2 values to the desired addresses; with a space b/w when entering

    printf("Enter trip time: ");
        scanf("%lf", &tripTime);


    /* 2.1 Reporting the user of the current time.  */
    printf("\nCurrent time is %02d:%02d", (int)currentHours, (int)currentMinutes);

    /* 2.2.1 Calculation of the time of arrival.  */
    tripHours = floor(tripTime);
    tripMinutes = tripTime - floor(tripTime);
    
    tripSum = tripHours * MinutesPerHour + tripMinutes * MinutesPerHour;  // total trip time (in minutes)
    currentSum = currentHours * MinutesPerHour + currentMinutes;  // total current time has passed on that day (in minutes)

    /* 2.2.1.1 Determining if the user will arrive on the same day or the next day */
    sumTime = tripSum + currentSum;
        
        /* Case 1: If will arrive on the same day. */
        if (sumTime < MinutesPerDay)
        { 
            double arrivalHour, arrivalMinute;

            /* Perform calculations.  */
            arrivalHour = rint(floor(sumTime / MinutesPerHour));
            arrivalMinute = rint(((sumTime / MinutesPerHour) - arrivalHour) * MinutesPerHour);
            
            /* Reporting the user of the time of arrival.  */
            printf("\nArrival Time is the same day %02d:%02d", (int)arrivalHour, (int)arrivalMinute);

//            printf("\n%lf  %lf", arrivalHour, arrivalMinute);
        }
        
        /* Case 2: If will arive on the next day */
        else
        {
            double NextDayHour, NextDayMinute;

            /* Perform calculations.  */
            NextDayHour = rint(floor(sumTime / MinutesPerHour) - HoursPerDay);  // the exceeding hrs - 24 hrs per day = #hrs on the next day 
            NextDayMinute =  rint(((sumTime / MinutesPerHour) - HoursPerDay - NextDayHour) * MinutesPerHour);

            /* Reporting the user of the time of arrival.  */
            printf("\nArrival Time is next day %02d:%02d", (int)NextDayHour, (int)NextDayMinute);

//            printf("\n%lf  %lf", NextDayHour, NextDayMinute);            
        }


    /* Testing~ */
//    printf("\n\n%lf  %lf  %lf", currentHours, currentMinutes, tripTime);
//    printf("\n\n%lf  %lf  %lf  %lf", tripHours, tripMinutes, tripSum, currentSum);

//    printf("\n\n%lf", sumTime);

    return 0;    
}