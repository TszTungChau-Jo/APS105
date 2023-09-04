/*
Date: [ 2022-02-19 ]
Lab 5: [ Part 3 —— Longest Common Sequence ]
Task: [ implement a C function that finds the longest common sequence of 
        numbers in the 2 arrays parameters ]
*/

/*
Assumption:
    - there is at least one common elements in these arrays
*/

#include <stdio.h>
#include <stdbool.h>

void longestMutualSequence(int firstArr[], int secondArr[], int sizeA, int sizeB);

int main(void){

//    int a[] = { 1, 2, 3, 4, 1000, 90, 100, 110, 200, 202 };
//    int b[] = { 1, 1, 2, 3, 90, 100, 110, 200, 202, 600 };

    int a[] = { 1, 80, 83, 75, 56 };
    int b[] = { 75, 56, 56, 75, 56 };

//    int a[] = { 4, 7, 5, 10, 22, 34, 17, 6, 8, 56, 77, 39, 28, 4, 9, 6, 9, 7, 3 };
//    int b[] = { 1, 7, 10, 34, 17, 6, 8, 56, 77, 9, 8, 6, 5, 10, 22, 34, 17, 6 };

//    int a[] = { 1, 1, 1, 1, 1, 1 };
//    int b[] = { 1, 1, 1, 1, 1, 1 };

    const int sizeA = 19;
    const int sizeB = 18;

//  Longest common sequence is 90, 100, 110, 200, 202.

    longestMutualSequence(a, b, sizeA, sizeB);

    return 0;
}

void longestMutualSequence(int firstArr[], int secondArr[], int sizeA, int sizeB){

    int index_A = 0;
//    int index_B = 0;

    int longest_length = 1;

    int starting_point_B = 0;  // starting point of the longest common sequence (in index)
    int ending_point_B = 0;    // ending point of the longest common sequence (in index)
    int testing_poiunt_B = 0;

    bool found = false; 
    bool stop = false;

    int inx_A = 0;
    int inx_B = 0;

    /* using a[] as the base for comparison */
    for (; index_A < sizeA ; index_A++ ){

        stop = false;

        inx_B = 0;

        while ( !stop ){

            int testing_length = 0;

            inx_A = index_A;

            found = false; 

            // find the first starting pt of the same element in array B
            while ( inx_B < sizeB && !found ){

                if ( firstArr[inx_A] == secondArr[inx_B] ){

                    testing_poiunt_B = inx_B;

                    found = true;

                } 

                else if ( firstArr[inx_A] != secondArr[inx_B] ){

                    inx_B++;

                }
 
            }

            // evaluate the common sequence
            while ( firstArr[inx_A] == secondArr[testing_poiunt_B] && inx_A < sizeA && inx_B < sizeB ){

                testing_length++;

                inx_A++;

                testing_poiunt_B++;

            }

            // check if the testing length is longer than the current longest length
            if ( testing_length > longest_length ){

                longest_length = testing_length;

                starting_point_B = inx_B;

            }

            // exit the testing loop once the indeces in B have all been gone through
            if ( inx_B == sizeB ){
                stop = true;
            }

            // provide the next start testing point int array B
            inx_B = testing_poiunt_B;

        }

    }

    ending_point_B = starting_point_B + longest_length - 1;

    // prints the result
    printf("Longest common sequence is ");

    for (; starting_point_B <= ending_point_B ; starting_point_B++ ){

        printf("%d", secondArr[starting_point_B]);
        
        // using if-else to determine the punctuation
        if ( starting_point_B < ending_point_B ){
            printf(", ");
        }

        else if ( starting_point_B == ending_point_B ){
            printf(".");
        } 

    }


//    printf("\n\n%d  %d", longest_length, starting_point_B);

}