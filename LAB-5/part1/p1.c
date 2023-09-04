/*
Date: [ 2022-02-17 ]
Lab 5: [ Part 1 —— Median of two sorted arrays ]
Task: [ implement a C function that receives 2 arrays as parameters passed
       and returns the median of the values stored in these 2 arrays ]
*/

/*
Assume that:
    - the 2 inputed arrays are sotred
*/

#include <stdio.h>

double median(int a[], int b[], int sizeA, int sizeB);

int main(void){

    double tester = 0.0;
    
    int a[] = {-100, -50, -50, -1, 0};
    int b[] = {0, 1, 4, 6, 6};


    tester = median(a, b, 5, 5);

    printf("\n%.2lf", tester);

    return 0;
}

// median{}: returns a double median of the values sorted in the 2 given arrays
double median(int a[], int b[], int sizeA, int sizeB){

    double median = 0.0;
    int merged_index = 0;
    int a_index = 0;
    int b_index = 0;

    const int merged_size = sizeA + sizeB;
    int merged[merged_size];

    // 0. initialse all the values inside the merged array to 0
    for ( int index = 0; index < merged_size; index++){
        merged[index] = 0;
    }

//    printf("\n%d", *(a + 3));


    // 1. Determine whether the merged array is odd or even

    // for odd merged_array 
    if (merged_size - 2 * ( merged_size / 2 ) == 1){  
        
        for (; merged_index <= merged_size / 2; merged_index++){
            
            //  1.1 Start comparing with the smallest numbers in arrays a and b

            if ( *( a + a_index ) <= * ( b + b_index ) ){  // pointer arithmetics
                merged[merged_index] = *( a + a_index );

                a_index = a_index + 1;

                printf("\n%d", merged[merged_index]);
            
            } else {  // * ( b + b_index ) < *( a + a_index )
                merged[merged_index] = *( b + b_index );

                b_index = b_index + 1;

                printf("\n%d", merged[merged_index]);

            }
        }    

        // 1.2 When we reach the middle index for the merged_array, it is then the median
        median = (double) merged[ merged_size / 2 ];

    }

    // for even merged_array
    else if (merged_size - 2 * ( merged_size / 2 ) == 0){  
        
        for (; merged_index <= merged_size / 2 ; merged_index++){

        //  1.3 Comparing with the smallest numbers in arrays a and b with the same idea

            if ( *( a + a_index ) <= * ( b + b_index ) ){
                merged[merged_index] = *( a + a_index );

                a_index = a_index + 1;

                printf("\n%d", merged[merged_index]);
            
            } else {  // * ( b + b_index ) < *( a + a_index )
                merged[merged_index] = *( b + b_index );

                b_index = b_index + 1;

                printf("\n%d", merged[merged_index]);

            }
            
        // 1.2 When we reach the middle index for the merged_array, we can then evalute the median
        median = ( (double)( merged[ merged_size / 2 ] + merged[ merged_size / 2 - 1 ] ) ) / 2 ;
        

        }
    }

    return median;
}