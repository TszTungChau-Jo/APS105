// APS105S-W22 Lab 4 Part 1

// This program includes a function named "triangle" that outputs Pascal's
// triangle. In general the Pascal's triangle can be represented as:

//             0C0
//           1C1 1C0
//         2C2 2C1 2C0
//       3C3 3C2 3C1 3C0
//      4C4 4C3 4C2 4C1 4C0

// where nCr represents how many ways there are to choose r from n, not
// counting duplicates.

// The formula used to calculate nCr can be written as:
//  nCr=n!/(r!(n-r)!)
// where n! is the factorial of n.

// triangle:
// is called by value where exactly one parameter
// returns void
// prints out the Pascal's triangle to the standard output
// employes 2 other functions, namely:
    // 1.) int choose(int t, int r);
    //      That chooses r from n
    // 2.) int factorial(int n);
    //      That calculates factorial of n

/*
Note:
    - # of rows is limited to integers between 0 to 13
    - if 0 is entered, nothing will be printed
    - if a negative integer is entered by the user, the program terminates
    - the number displayed in the last column must always be displayed at the start of the line
    - print the output number carefully with correct format
*/


// forward declaration
void triangle(int row);
int choose(int n, int r);
int factorial(int n);

#include <stdio.h>

int main(void) {
  
  int rows = 0 ;  // the total number of rows

  do {
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    if (rows >= 0) {
      triangle(rows);
    }
  
  } while (rows >= 0);

  return 0;
}


// triangle (function): main function that prints out the Pascal's triangle
void triangle(int row){
  
  int nth_row = 1 ;  // uses as n in nCr
  int nCr = 0 ;  // uses as nCr

  for (; nth_row <= row ; nth_row++ ){  // controls the total rows present, representing each row

    for ( int block  = 1 ; block <= (row - nth_row) * 3 ; block++ ){  // controls the number of empty spaces corresponding to each row
      printf(" ");

    }
    

    for( int rth_column = nth_row - 1; rth_column >= 0 ; rth_column-- ){  // controls the number of Pascal's num in each row

      nCr = choose(nth_row - 1, rth_column);

      printf("%d", nCr);


      if ( nCr - 10 < 0 ){  // if nCr is signle number
        printf("     ");
      }
      else if( nCr < 100 ){  // if nCr is 2-digit number
        printf("    ");
      }
      else if( nCr < 1000 ){  // if nCr is 2-digit number
        printf("   ");
      }
    }


    printf("\n");
  }

}


// choose (function)
int choose(int n, int r){  // calculate the nCr (Pascal's num) of the corresponding position

  int nCr = 0 ;
  int n_factorial = 0 ;
  int r_factorial = 0 ;
  int nr_factorial = 0 ;

  // 1. calculate n!
  n_factorial = factorial( n ) ;

  // 2. calculate r!
  r_factorial = factorial( r ) ;

  // 3. calculate (n-r)!
  nr_factorial = factorial(( n - r )) ;

  // 4. evaluate the nCr by the given formula nCr = n! / ( r! ( n - r )! )
  nCr = n_factorial / ( r_factorial * nr_factorial ) ;

  return nCr;
}


// factorial calculation (function)
int factorial(int value){  // calculate the n_th factorial 
  
  int product = 1 ;

  for( int i = 1; i <= value ; i++ ){
    product = product * i ;
  }


  return product;
}

/*
// blocks between each number (function)
void num_block_between(int n){



}
*/