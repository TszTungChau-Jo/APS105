/*
Completion Date: 03/03/2022
Lab 6: Part 1 - Word Search Puzzle
Goal: Write a C function to search for a word within a puzzle of random words
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// fun'c: after finding the first letter, determine if there exist the word "B E N" in that specific direction
bool search1D(char word[], int wordSize, const int Size, char grid[Size][Size], int foundRowIdx, int foundColIdx, int rowDir, int colDir) {

    int countSame = 0;  // counts the number of same letters (contiguous)

    // 1. we are now searching in the SOUTH direction
    if ( rowDir == -1 && colDir == 0 ){

        // col direction does not move, only move 1 row down per try

        for ( int wordLength = 0 ; wordLength < wordSize && foundRowIdx < Size ; wordLength++, foundRowIdx++ ){

            if ( grid[foundRowIdx][foundColIdx] == word[wordLength] ){  
                countSame = countSame + 1;  
            }
        }
    }

    // 2. we are now searching in the SOUTH-WEST direction
    if ( rowDir == -1 && colDir == -1 ){

        // row moves downward 1 -> row + 1 , col moves left 1 -> col - 1
        
        for ( int wordLength = 0 ; wordLength < wordSize && foundRowIdx < Size  && foundColIdx > -1 ; wordLength++, foundRowIdx++, foundColIdx-- ){

//            printf("%c %c  ", grid[foundRowIdx][foundColIdx], word[wordLength]);

            if ( grid[foundRowIdx][foundColIdx] == word[wordLength] ){  
                countSame = countSame + 1;  
            }
        }
    }

    // 3. now searching in the WEST direction
    if ( rowDir == 0 && colDir == -1 ){

        // only col shifts to the left each time, no motion in the shifting the row
        
        for ( int wordLength = 0 ; wordLength < wordSize && foundColIdx > -1 ; wordLength++, foundColIdx-- ){
        
            if ( grid[foundRowIdx][foundColIdx] == word[wordLength] ){  
                countSame = countSame + 1;  
            }
        }
    }


    // 4. now searching in the NORTH-WEST direction
    if ( rowDir == 1 && colDir == -1 ){

        // row goes up and col goes left each left

        for ( int wordLength = 0 ; wordLength < wordSize && foundRowIdx > -1 && foundColIdx > -1 ; wordLength++, foundRowIdx--, foundColIdx-- ){

            if ( grid[foundRowIdx][foundColIdx] == word[wordLength] ){  
                countSame = countSame + 1;  
            }
        }
    }


    // 5. now searching in the NORTH direction
    if ( rowDir == 1 && colDir == 0 ){

        // only row goes up, does not move horizontally

        for ( int wordLength = 0 ; wordLength < wordSize && foundRowIdx > -1 ; wordLength++, foundRowIdx-- ){

            if ( grid[foundRowIdx][foundColIdx] == word[wordLength] ){  
                countSame = countSame + 1;  
            }
        }
    }


    // 6. now searching in the NORTH-EAST direction
    if ( rowDir == 1 && colDir == 1 ){

        // row goes up and col goes right per time

        for ( int wordLength = 0 ; wordLength < wordSize && foundRowIdx > -1 && foundColIdx < Size ; wordLength++, foundRowIdx--, foundColIdx++ ){

            if ( grid[foundRowIdx][foundColIdx] == word[wordLength] ){  
                countSame = countSame + 1;  
            }
        }
    }


    // 7. now searching in the EAST direction
    if ( rowDir == 0 && colDir == 1 ){

        // only col goes in the right direction

        for ( int wordLength = 0 ; wordLength < wordSize && foundColIdx < Size ; wordLength++, foundColIdx++ ){

            if ( grid[foundRowIdx][foundColIdx] == word[wordLength] ){  
                countSame = countSame + 1;  
            }
        }
    }


    // 8. now searching in the SOUTH-EAST direction
    if ( rowDir == -1 && colDir == 1 ){

        // row goes down and col goes right each time

        for ( int wordLength = 0 ; wordLength < wordSize && foundRowIdx < Size && foundColIdx < Size ; wordLength++, foundRowIdx++, foundColIdx++ ){

            if ( grid[foundRowIdx][foundColIdx] == word[wordLength] ){  
                countSame = countSame + 1;  
            }
        }
    }


    /////////////////////////////////////////////////////////////
    if ( countSame == wordSize ){
        return true;
    } 
    else {
        return false;
    }  

}



// fun'c: print the final result

void printFoundLocation( int wordRowIdx, int wordColIdx, int wordRowDir, int wordColDir ) {

    if ( wordRowDir == -1 && wordColDir == 0 ){  // 1. SOUTH direction

        printf("Word found at row %d and column %d in the south direction.", wordRowIdx, wordColIdx);

    }

    else if ( wordRowDir == -1 && wordColDir == -1 ){  // 2. SOUTH-WEST direction

        printf("Word found at row %d and column %d in the south-west direction.", wordRowIdx, wordColIdx);

    }

    else if ( wordRowDir == 0 && wordColDir == -1 ){  // 3. WEST direction

        printf("Word found at row %d and column %d in the west direction.", wordRowIdx, wordColIdx);

    }

    else if ( wordRowDir == 1 && wordColDir == -1 ){  // 4. NORTH-WEST direction

        printf("Word found at row %d and column %d in the north-west direction.", wordRowIdx, wordColIdx); 

    }
    
    else if ( wordRowDir == 1 && wordColDir == 0 ){  // 5. NORTH direction

        printf("Word found at row %d and column %d in the north direction.", wordRowIdx, wordColIdx);

    }

    else if ( wordRowDir == 1 && wordColDir == 1 ){  // 6. NORTH-EAST direction

        printf("Word found at row %d and column %d in the north-east direction.", wordRowIdx, wordColIdx);

    }

    else if (  wordRowDir == 0 && wordColDir == 1 ){  // 7. EAST direction

        printf("Word found at row %d and column %d in the east direction.", wordRowIdx, wordColIdx);

    }

    else if (  wordRowDir == -1 && wordColDir == 1 ){  // 8. SOUTH-EAST direction

        printf("Word found at row %d and column %d in the south-east direction.", wordRowIdx, wordColIdx);

    }

}



// fun'c: let's go!

void search2D(char word[], int wordSize, const int Size, char grid[Size][Size]) {

    int foundRowIdx = 0;  // stores the row idx of the first letter of the word "B E N" if found 
    int foundColIdx = 0;  // (........) col idx of the first letter (..........................) 
    
    int wordRowIdx = 0;  // stores the final row idx of the word "B E N"
    int wordColIdx = 0;  // stores the final col idx of the word "B E N"

    int wordRowDir = 0;  // stores the final row direction of the word, if found
    int wordColDir = 0;  // stores the final col direction of the word, if found

    bool foundFirstLetter = false;  // indicates if found the first letter of "B E N"
    bool foundWord = false;  // indicates if found the word "B E N" or not

//    int directions[8] = { 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 };  // total 8 directions that we need to search on
    // 1 - SOUTH, 2 - SOUTH-WEST, 3 - WEST, 4 - NORTH-WEST, 5 - NORTH, 6 - NORTH-EAST, 7 - EAST, 8 - SOUTH-EAST

    // 1.) find the index of the first letter of the word "B E N"
    for ( int row = 0; row < Size && !foundWord; row++ ){  // goes through each row

        for ( int col = 0 ; col < Size && !foundWord ; col++ ){  // goes through each col, thus goes through each element

            // once we found the word "B E N", we will begin the testing and searching process
            if ( grid[row][col] == word[0] && !foundFirstLetter ){  // the first letter of the word has the idx of 0


                foundRowIdx = row;
                foundColIdx = col;

                // for testing and searchin, we need to go through in 8 directions, starting from south and clockwise
                for ( int currentDirection = 1 ; currentDirection < 9 && !foundWord ; currentDirection++ ){
                    
                    int rowDir = 0;  // will be used as { -1 , 0 , 1 }, -1 -> left, 0 -> no motion, 1 -> right
                    int colDir = 0;  // -1 -> down, 0 -> no motion, 1 -> up 
                    bool result = false;

                    // a list of all the rowDir and colDir
                    // 1. searching in SOUTH direction
                    if ( currentDirection == 1 ){  
                        
                        // searching motions
                        rowDir = -1;  // down 1 row per search
                        colDir = 0;  // col doesn't change

                        result = search1D(word, wordSize, Size, grid, foundRowIdx, foundColIdx, rowDir, colDir);

                        // if we found the word "B E N"
                        if ( result == true ){
                            wordRowIdx = foundRowIdx;
                            wordColIdx = foundColIdx;

                            wordRowDir = rowDir;
                            wordColDir = colDir;
                            
                            foundWord = true;  // once we found the existance of the word "B E N", we will exit the loop
                        }
                    }


                    // 2. searching in the SOUTH-WEST direction
                    if ( currentDirection == 2 ){  

                        // searching motions
                        rowDir = -1;  // down 1 row per search
                        colDir = -1;  // left 1 col per search

                        result = search1D(word, wordSize, Size, grid, foundRowIdx, foundColIdx, rowDir, colDir);

                        // if we found the word "B E N"
                        if ( result == true ){
                            wordRowIdx = foundRowIdx;
                            wordColIdx = foundColIdx;

                            wordRowDir = rowDir;
                            wordColDir = colDir;
                            
                            foundWord = true;  // once we found the existance of the word "B E N", we will exit the loop
                        }
                    }


                    // 3. searching in the WEST direction
                    if ( currentDirection == 3 ){

                        // searching motions
                        rowDir = 0;  // stays in the same row, so not motion
                        colDir = -1;  // moves left per times

                        result = search1D(word, wordSize, Size, grid, foundRowIdx, foundColIdx, rowDir, colDir);

                        // if we found the word "B E N"
                        if ( result == true ){
                            wordRowIdx = foundRowIdx;
                            wordColIdx = foundColIdx;

                            wordRowDir = rowDir;
                            wordColDir = colDir;
                            
                            foundWord = true;  // once we found the existance of the word "B E N", we will exit the loop
                        }
                    }


                    // 4. searching in the NORTH-WEST direction
                    if ( currentDirection == 4 ){
                        
                        // searching motions
                        rowDir = 1;  //  row goes up
                        colDir = -1;  // col goes left

                        result = search1D(word, wordSize, Size, grid, foundRowIdx, foundColIdx, rowDir, colDir);

                        // if we found the word "B E N"
                        if ( result == true ){
                            wordRowIdx = foundRowIdx;
                            wordColIdx = foundColIdx;

                            wordRowDir = rowDir;
                            wordColDir = colDir;
                            
                            foundWord = true;  // once we found the existance of the word "B E N", we will exit the loop
                        }
                    }
                    

                    // 5. searching in the NORTH direction
                    if ( currentDirection == 5 ){

                        // searching motions
                        rowDir = 1;  // only row goes up
                        colDir = 0;  // stays in the same col

                        result = search1D(word, wordSize, Size, grid, foundRowIdx, foundColIdx, rowDir, colDir);

                        // if we found the word "B E N"
                        if ( result == true ){
                            wordRowIdx = foundRowIdx;
                            wordColIdx = foundColIdx;

                            wordRowDir = rowDir;
                            wordColDir = colDir;
                            
                            foundWord = true;  // once we found the existance of the word "B E N", we will exit the loop
                        }
                    }


                    // 6. searching in the NORTH-EAST direction
                    if ( currentDirection == 6 ){

                        // searching motions
                        rowDir = 1;  // row goes up 
                        colDir = 1;  // col goes right

                        result = search1D(word, wordSize, Size, grid, foundRowIdx, foundColIdx, rowDir, colDir);

                        // if we found the word "B E N"
                        if ( result == true ){
                            wordRowIdx = foundRowIdx;
                            wordColIdx = foundColIdx;

                            wordRowDir = rowDir;
                            wordColDir = colDir;
                            
                            foundWord = true;  // once we found the existance of the word "B E N", we will exit the loop
                        }
                    }


                    // 7. searching in the EAST direction
                    if ( currentDirection == 7 ){

                        // searching motions
                        rowDir = 0;  // stays in the same row
                        colDir = 1;  // moves right per time

                        result = search1D(word, wordSize, Size, grid, foundRowIdx, foundColIdx, rowDir, colDir);
                        
                        // if we found the word "B E N"
                        if ( result == true ){
                            wordRowIdx = foundRowIdx;
                            wordColIdx = foundColIdx;

                            wordRowDir = rowDir;
                            wordColDir = colDir;
                            
                            foundWord = true;  // once we found the existance of the word "B E N", we will exit the loop
                        }
                    }


                    // 8. searching in SOUTH-EAST direction
                    if ( currentDirection == 8 ){

                        // searching motions
                        rowDir = -1;
                        colDir = 1;

                        result = search1D(word, wordSize, Size, grid, foundRowIdx, foundColIdx, rowDir, colDir);

                        // if we found the word "B E N"
                        if ( result == true ){
                            wordRowIdx = foundRowIdx;
                            wordColIdx = foundColIdx;

                            wordRowDir = rowDir;
                            wordColDir = colDir;
                            
                            foundWord = true;  // once we found the existance of the word "B E N", we will exit the loop
                        } 
                    }


                }

            }

        }

    }


    // THE FINAL handling machine
    if ( foundWord == true ) {

        printFoundLocation( wordRowIdx , wordColIdx , wordRowDir, wordColDir );

    } else {
        
        printf("Word not found.");

    }

}


int main(void){

    const int Size = 5;
    const int wordSize = 3;

    char grid[5][5] = {{ 'T', 'N', 'E', 'P', 'S'},  // ROW 1
                       { 'E', 'C', 'L', 'H', 'N' },  // ROW 2
                       { 'N', 'B', 'D', 'N', 'T' },  // ROW 3
                       { 'A', 'L', 'E', 'F', 'K' },  // ROW 4
                       { 'C', 'Z', 'G', 'N', 'H' }};  // ROW 5

    char word[3] = { 'B', 'E', 'N' };

    for( int row = 0 ; row < Size ; row++ ){
        for( int col = 0 ; col < Size ; col++ ){
            printf("%c ", grid[row][col]);
        }
        printf("\n");
    }

    printf("\n");

    for ( int idx = 0 ; idx < wordSize ; idx++ ){
        printf("%c ", word[idx]);
    }

    printf("\n");

    /////////////////////////////////////////////////////////////

    search2D(word, wordSize, Size, grid);


    printf("\n");

    return 0;
}
