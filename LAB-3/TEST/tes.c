/*
Date: 2022-02-02
Lab 3: Part 3 —— Change
Description: a program that makes change for amounts less than one dollar (100 cents)
the change should contain the minimum number of coins required for the given amount 
*/

/*
Background info:
1 dollar = 100 cents
1 quarter = 25 cents
1 dime = 10 cents
1 nickel = 5 cents
*/

/*
Assumptions:
- the input is a positive integer value more than or equal to 0 and less than 100
    - represents an amount of cash in cents
- the program repeatedly prompts the user for the next amount
    - and, terminates right after an invalid value is entered
*/

/*
Steps:
    0. request an input value from the user
    1. check if the input is an valid integer within the bounds
        - if not, terminate the program
        - if yes, shows
            - the # of cents input
            - if possible, shows the quivalent components of 
                - the # of quarter(s)
                - the # of dime(s)
                - the # of nickel(s)
    2. repeat the loop and back to step 0.
*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>


int main(void){

    /*  */
    int cents = 0;
    int remainder_cents = 0;
    int quarters = 0;  // stores the highest possible number of quarter(s)
    int dimes = 0;  // stores the highest possible number of dime(s)
    int nickels = 0;  // stores the highest possible number of nickel(s)
    int remainder_amount = 0;  
    bool exit = false;  // controls if we will exit the loop
    int count_zeros = 0;
    //int sum = 0;

    /*  */
    do{
        
        /* 0. The good beginnnig~  */
        printf("Please give an amount in cents less than 100: ");
        scanf("%d", &cents);

        /* 1. Check if the input is outside of range.  */
        // if yes, exit the loop
        if( cents <= 0 || cents >= 100 ){
            
            printf("%d cents: invalid amount.", cents);    
            exit = true;
        
        // if not (within the range), then continue~ 
        } else{
            
            // 1st: extract all the indivisible cents
            remainder_cents = cents % 5;  // so the remainder now has factors 25, 10, 5
            remainder_amount = cents - remainder_cents; 

            
            
            // 2nd: get the max. amount of quarter(s) possible

            quarters = remainder_amount / 25;
            remainder_amount = remainder_amount - quarters * 25;



            // 3rd: get the max. amount of nickel(s) possible

            dimes = remainder_amount / 10;
            remainder_amount = remainder_amount - dimes * 10;



            // 3th: collect the number of nickels

            nickels = remainder_amount / 5;
            remainder_amount = remainder_amount - nickels * 5;



            // count the number of presenting ZEROS
            count_zeros = 0;

            if ( remainder_cents == 0 ){
                count_zeros += 1;
            }

            if ( quarters == 0 ){
                count_zeros += 1;
            }

            if ( dimes == 0){
                count_zeros += 1; 
            }

            if ( nickels == 0){
                count_zeros += 1; 
            }


            /* 2. Present our result!  */
            printf("%d cents: ", cents);

            /* Single output  */
            // quarters
            if ( quarters == 1){
                printf("1 quarter");
            } else if ( quarters > 1 ) {
                printf("%d quarters", quarters);
            }
            // check 1
            if ( dimes + nickels + remainder_cents != 0 ){
                if ( cents > 25){
                    if ( count_zeros != 2){
                        printf(", ");
                    } else if (count_zeros == 2){
                        printf(" ");
                    }
                }
                if ( quarters != 0 && dimes + nickels + remainder_cents == dimes ){
                    printf("and ");
                }
                if ( quarters != 0 && dimes + nickels + remainder_cents == nickels ){
                    printf("and ");
                } 
                if ( quarters != 0 && dimes + nickels + remainder_cents == remainder_cents ){
                    printf("and ");
                } 
            
            } else if(  dimes + nickels + remainder_cents == 0  ){
                printf(".");
            }

            // dimes
            if ( dimes == 1){
                printf("1 dime");
            } else if ( dimes > 1 ) {
                printf("%d dimes", dimes);
            }
            // check 2
            if ( nickels + remainder_cents != 0 ){
                if ( cents > 10 && dimes != 0){
                    if ( count_zeros != 2){
                        printf(", ");
                    } else if (count_zeros == 2){
                        printf(" ");
                    }
                }
                if ( dimes != 0 && nickels + remainder_cents == nickels ){
                    printf("and ");
                }
                if ( dimes != 0 && nickels + remainder_cents == remainder_cents ){
                    printf("and ");
                } 
           
            } else if( nickels + remainder_cents == 0  && dimes != 0 ){
                printf(".");
            }


            // nickels
            if ( nickels == 1){
                printf("1 nickel");
            }
            // check 3
            if ( remainder_cents != 0 ){
                if ( cents > 5 &&  nickels != 0){
                    if ( count_zeros != 2){
                        printf(", ");
                    } else if (count_zeros == 2){
                        printf(" ");
                    }
                }
                
                if ( nickels != 0 && remainder_cents != 0 ){
                    printf("and ");
                }
           
            } else if( remainder_cents == 0 && nickels != 0 ){
                printf(".");
            }

            // cents
            if ( remainder_cents == 1){
                printf("1 cent.");
            } else if ( remainder_cents > 1 ){
                printf("%d cents.", remainder_cents);
            }
            

            printf("\n");  // the finale, or not?~
        }


    } while( !exit );  // while not exit (when exit is false), continue

    return 0;
}