/*
Completion Date: xx/03/2022
Lab 6: Part 2 - Sudoko
Goal: Write a C functino to help us solve a simple 4 × 4 Sudoko puzzle
*/

#include <stdio.h>
#include <stdbool.h>

bool isZero(int element);

int whichIsMissing( int testingRow, int testingCol , const int Size, int sudoko[Size][Size]);

void fillSudoko(const int Size, int sudoko[Size][Size]){

    // Goal: Go through every elements in the sudoko and fills in the empty squeares
    for ( int row = 0 ; row < Size ; row++ ){
        for ( int col = 0 ; col < Size ; col++ ){

            if ( isZero( sudoko[row][col] ) ){

                int testingRow = row;
                int testingCol = col;

                // fills the square with missing number
                sudoko[row][col] = whichIsMissing(testingRow, testingCol, Size, sudoko);

            }

        }

    }

}


// fun'c 1: checks if the current array element is zero
bool isZero(int element){

    if ( element == 0 ){
        return true;
    }

    return false;
}

// fun'c 2: find which number is missing at the index row and col
int whichIsMissing( int testingRow, int testingCol, const int Size, int sudoko[Size][Size]){

    int theMissingNumber = 0;

    int checkTable[4] = { 0 , 0 , 0 , 0 };

    // Go through the row of the specific index (row, col)
        for ( int n_thElement = 0 ; n_thElement < Size ; n_thElement++ ){
            if ( sudoko[testingRow][n_thElement] == 1 ){
                checkTable[0] = 1;
            }
            
            else if ( sudoko[testingRow][n_thElement] == 2 ){
                checkTable[1] = 2;
            }

            else if ( sudoko[testingRow][n_thElement] == 3 ){
                checkTable[2] = 3;
            }

            else if ( sudoko[testingRow][n_thElement] == 4 ){
                checkTable[3] = 4;
            }
        }


    // Go through the col of the specific index (row, col)
    for ( int n_thElement = 0 ; n_thElement < Size ; n_thElement++ ){
        if ( sudoko[n_thElement][testingCol] == 1 ){
            checkTable[0] = 1;
        }

        else if ( sudoko[n_thElement][testingCol] == 2 ){
            checkTable[1] = 2;
        }

        else if ( sudoko[n_thElement][testingCol] == 3 ){
            checkTable[2] = 3;
        }

        else if ( sudoko[n_thElement][testingCol] == 4 ){
            checkTable[3] = 4;
        }
    }

    // Finally go through the check table
    for ( int checkElement = 0; checkElement < Size ; checkElement++ ){
        
        // the 0 value n_th element in the check element represents the missing number
        if ( checkTable[checkElement] == 0 ){
            theMissingNumber = checkElement + 1;
        }

    }

    return theMissingNumber;
}


int main(void){

    const int Size = 4;

    int puzzle[4][4] = {{ 0 , 4 , 1 , 0},
                        { 1 , 0 , 0 , 4},
                        { 2 , 3 , 0 , 0},
                        { 0 , 0 , 2 , 3}};

    printf("The sudoko puzzle is\n");

    for ( int row = 0 ; row < Size ; row++ ){
        for ( int col = 0 ; col < Size ; col++ ){
            printf("%d ", puzzle[row][col]);
        }
        printf("\n");
    }

    //////////////////////////////////////////////

    printf("\n");

    fillSudoko( Size, puzzle );

    for ( int row = 0 ; row < Size ; row++ ){
        for ( int col = 0 ; col < Size ; col++ ){
            printf("%d ", puzzle[row][col]);
        }
        printf("\n");
    }


    printf("\n");
    return 0;
}