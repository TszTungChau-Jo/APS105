/*
Date: 2022-01-29
Lab 3: Part 2——The Triangle
Description: uses the * (star) character to draw a triangle of a 
             given number of rows 
*/

/*
Assumptions:
- all inputs are valid integers within the range allowed by the int type
    - ranging from 1 to 20
*/

#include <stdio.h>

int main(void)
{
    /* Initialize the values  */
    int rows = 0;
    char spaces = ' ';
    int i = 1;  // section 1 controller 
    int k = 1, end = 0;  // section 2 controllers
    int j = 1, boundary = 1;  // section 3 controllers

    /* Collect the number of rows */
    printf("Enter the number of rows in the triangle: ");
    scanf("%d", &rows);


    /* The main idea is to divide the printing in 3 sections  */
    // and the ideas are mainly based on obvervation
        // 1st section: the first row, with only one star
        // 2nd section: the body row(s), with two stars
        // 3rd section: the base (bottom) line, with all stars

    // Section 1 
    for (; i <= rows ; i++ ){  // notice the first * is at the n_th column
        if ( i != rows ){      // and the n_th column = n_rows collected
            printf("%c", spaces); 
        } 
        else if (rows == 1){
            printf("*");
        } 
        else {
            printf("*\n");
        }           
    }

    // Section 2
    // section 2 modify begining from row 2 to row n - 1
    end = rows - 1;
    
    for (; k < end ; k++ ){  // begins with the opeartion in each row
                              // where k is the nth row starting after the 1st row

        /* the main idea is to divide the output into 2 parts */
        // we build up each row part by part
        // 1st part: 1st part of spaces and *
        for( int c = 1, major_column = rows - k ; c < major_column ; c++ ){
            printf(" ");
        }
        
        printf("*");

        // 2nd part: 2nd part of spaces and *
        for( int d = 1 ; d <= 2*k - 1 ; d++ ){  // d controls the number of times 
            printf(" ");                        // the number of space is modeled by 1 + 2(k-1)
        }                                       // where starts from: 1, 3, 5, ...
        
        printf("*\n");
    }

        
    // Section 3
    // notice the bottom starts with 1 star
    // and add 2 per rows accumulated
    boundary =  1 + 2 * (rows - 1);  // the pattern of # of stars
                                     // is: 1, 3, 5, ..., 39 (+2 each term)
    if (rows != 1){
        for (; j <= boundary ; j++ ){
        printf("*");
        }
    }
      
    return 0;
}