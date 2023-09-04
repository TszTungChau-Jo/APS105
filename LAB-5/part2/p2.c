/*
Date: [ 2022-02-18 ]
Lab 5: [ Part 2 —— Longest sequence of increasing numbers ]
Task: [ write a C function that finds the longest sequence
        of increasing numbers in an array ]
*/

/*
What the functions do:
    - receives an array passed as a parameter
    - prints the longest sequence of increasing numbers
*/


#include <stdio.h>

void longestSequence(int a[], int sizeA);

// -15, -14, -7, -3, -888, -11, 3, 6, -15, -14, -7, -3, -1

int main(void){

    int a[] = { -15, -14, -7, -8, -888, -11, -12, 6, -15, -14, -7, -3, -3 };

    longestSequence(a, 13);

    return 0;
}


void longestSequence(int a[], int sizeA){

    int index = 0;  // the n_th index in the array
    int longest_length = 1;  // stores the longest array length
    int testing_length = 1;  // stores the local array length used for comparison
    int ending_pt = 0;  // record the ending point of the longest array (in index)
    int starting_pt = 0;  // used to evaluate the starting point of the longest array (in index)


    // start comparing with the first number in the array

    for (; index < sizeA - 1; index++ ){

        if ( a[index] < a[index + 1] ){

            testing_length++;

        } else if ( a[index] >= a[index + 1] ){  // a new testing sequence begins

            if ( testing_length > longest_length ){
                
                longest_length = testing_length;

                ending_pt = index;

            }
            
            testing_length = 1;

        }

        // determine for the last term of the array
        
        if ( index == sizeA - 2){  // comparing between the last and the second last number in the array
            
            if ( a[sizeA - 2] < a[sizeA - 1] ){  // if the second last number is smaller than the last number

            longest_length = testing_length;

            ending_pt = index + 1;  // endgin_pt counting in index
            
            }

            starting_pt = ending_pt - longest_length + 1;

        }

    }

    // printing out the longest sequence in the array

    printf("Longest sequence is ");

    for(; starting_pt <= ending_pt ; starting_pt++ ){

        printf("%d", a[starting_pt]);

        // using if-else to determine the punctuation
        if ( starting_pt < ending_pt ){
            printf(", ");
        }

        else if ( starting_pt == ending_pt ){
            printf(".");
        } 

    }
    
    
//    printf("\nend-pt: %d", ending_pt);

//    printf("\n\nlongest length: %d", longest_length);

}