
#include <stdio.h>
#include <stdbool.h>
#include <math.h>


// forward declaring fucntions
int get_Start_k(void);
int get_End_k(int *beginning_k);
int get_Start_a(void);
int get_End_a(int *beginning_a);
int gcd(int a, int b);



int main(void){

    int Erdos_Woods = 0;
    int corresponding_a = 0;

    /* 0. get the necessary info. from the user */
    int lower_k = get_Start_k();  // inclusive
    int higher_k = get_End_k(&lower_k);  // inclusive

    int lower_a = get_Start_a();  // inclusive
    int higher_a = get_End_a(&lower_a);  // inclusive


    bool flag = true;  // determine whether a Erdos-Woods number is found in the for loop
    bool stop = false;  // determine when to exit for testing  


    /* 1. finding the existance of an Erdos-Woods Numbers */
    for ( int k_candidate = lower_k ; k_candidate <= higher_k && !stop ; k_candidate++ ){
        
        printf("Trying k = %d...\n", k_candidate);  // testing for the n_th candidate of Erods-Woods number
        
        for ( int testing_a = lower_a ; testing_a <= higher_a && !stop ; testing_a++ ){
            
            flag = true;  // re-define the flag after every failing so to re-enter the loop for the next testing value

            for ( int i = 1 ; i <= (k_candidate - 1) && flag == true ; i++ ){
                

                if ( gcd(testing_a, testing_a + i) > 1 || gcd(testing_a + k_candidate, testing_a + i) > 1 ){  // given condition

                    flag = true;

                }
                
                else{

                    flag = false;  // if the flag fails, then we will exit the loop and test for the next a value

                }
            
            
            }
            
            // if the flag is still true after all the testing within the range, 
            // then we just found an Erdos-Woods Numbers with the corresponding a value
            if ( flag == true ){ 

                Erdos_Woods = k_candidate;

                corresponding_a = testing_a;

                stop = true;

            }

        }

    }

    printf("\n%d  %d", Erdos_Woods, corresponding_a);

    return 0;
}



// get_Start_k: returns the starting bound for k
int get_Start_k(void){

    int starting_k = 0;

    do{

        printf("Enter the number to start searching for k (> 2, inclusive): ");
        scanf("%d", &starting_k);

    } while( starting_k <= 2 );  // k must be greater than 2 in order to proceed
   
    return starting_k;

}



// get_End_k{}: returns the ending bound for k
int get_End_k(int *beginning_k){

    int ending_k = 0;
    int begin_k = *beginning_k;  // dereferencing the address of beginning of k
  
    do{
        printf("Enter the number to stop searching for k (inclusive): ");
        scanf("%d", &ending_k);

    } while( ending_k <= begin_k );  // end bound must be greater than the starting

    return ending_k;

}



// get_End_a{}: returns the starting bound for a
int get_Start_a(void){
  
    int starting_a = 0;

    do{

        printf("Enter the number to start searching for a (> 0, inclusive): ");
        scanf("%d", &starting_a);

    } while( starting_a <= 0 );  // a must be greater than 0 in order to proceed
   
    return starting_a;

}



// get_End_a{}: returns the ending bound for a
int get_End_a(int *beginning_a){

    int ending_a = 0;
    int begin_a = *beginning_a;  // dereferencing address of beginning of a
  
    do{
        printf("Enter the number to stop searching for a (inclusive): ");
        scanf("%d", &ending_a);

    } while( ending_a <= begin_a );  // end bound must be greater than the starting

    return ending_a;

}



// gcd{}: returns the greatest common factor between the two input values
// The gcd{} function is written mainly based on the Euclidean Algorithm
int gcd(int a, int b){

    int larger_num = 0;
    int smaller_num = 0;
    int dividend = 0;
    int divisor = 0;
    int remainder = 0;
    int greatest_common_divisor = 0;

// 1st: find the larger value between the two number
    if ( a > b ){
        larger_num = a;
        dividend = larger_num;

        smaller_num = b;
        divisor = b;

    } else{
        larger_num = b;
        dividend = larger_num;

        smaller_num = a;
        divisor = smaller_num;
    }

// 2nd: continually re-shuffling and calculating for the gcd
// computed based on the mechanism of Euclidean Algorithm
    do{
        remainder = dividend % divisor;

        if ( remainder == 0 ){
            greatest_common_divisor = divisor;

        } else{
            dividend = divisor;
            divisor = remainder;
        }

    } while ( remainder != 0 );

    return greatest_common_divisor;
}