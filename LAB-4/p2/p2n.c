/*
Lab 4: Part 2 —— Erdos-Woods Numbers
Description: Given a potential Erdos-Woods number "k" within a specic range 
             and a positive integer "a" within a specific range, the program
             will determine if there exist an "k" that satifies the condition.
*/

/*
Background Info:
    - A positive integer k is said to be an Erd̋os–Woods number if there exists 
      a positive integer a such that each of the consecutive integers a + i 
      for 0 < i < k shares at least one prime factor with either a or a + k.

    - If for a "k" there is an "a" such that each evaluation of 
      gcd(a, a + i) > 1 or gcd(a + k, a + i) > 1 returns TRUE,
      then "k" is an Erdos-Woods number.
*/

/*
Info needed to be collected from the user:
    1. The number to start searching for k (inclusive).  [lower bound]
        - It needs to be greater than 2. The program will start searching for 
          Erdos-Woods number from this starting point.
    
    2. The number to stop searching for k (inclsive).  [upper bound]
        - It needs to be greater than the starting point above searching for k.
        
    3. The number to start searching for a (inclusive).  [lower bound]
        - It needs to be posive ( > 0 )

    4. The number to stop searching for a (inclusive).  [upper bound]
        - It needs to be greater than the starting point abovve searching for a.
*/

/*
Note:
    - If the stated requirements are not satisfied, the user will be repeatedly
      prompted to enter new values for the same integer until the requirements
      are satisfied
    
    - The C program needs to define and use at least one funciton that computes
      the greatest common divisor between, a and b
        - int gcd(int a, int b){/stuff/} // which takes 2 integer input and 
          returns the greatest (integer) common divisor b/w a and b   
*/


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

    if ( Erdos_Woods == 0){
        printf("Erdos-Woods number not found.");
    } else{
        printf("Erdos-Woods number: %d\na = %d", Erdos_Woods, corresponding_a);
    }

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