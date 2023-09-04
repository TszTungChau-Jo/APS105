//
// Author: Chau, Tsz Tung
//
// Completion Date: 2022/03/14 (before estimationa date)
// 


//#include "reversi.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// fun'c 1: gets the size of the board from the USER
int getBoardSize(void) {
    
    int boardSize = 0;

    // Assume: the input will always be even numbers less than or equal to 26 and larger than 0
    printf("Enter the board dimension: ");
    scanf("%d", &boardSize);

    return boardSize;    
}


// fun'c 2: initializes the board to the basic background
void initializeBoard(char board[][26], int boardSize) {

    char stateCharacters[3] = { 'U', 'B', 'W' };  // U - for unoccupied; B - occupied by the black; W - occupied by white

    // 1.) initialze all the cells inside the board to U w/ the base "WB\nBW"
    for ( int row = 0 ; row < boardSize ; row++ ){

        for ( int col = 0 ; col < boardSize ; col++ ){
            
            board[row][col] = stateCharacters[0];  // board[row][col] = 'U'

            if ( (row == boardSize/2 - 1 && col == boardSize/2 - 1) || (row == boardSize/2 && col == boardSize/2) ){
                board[row][col] = stateCharacters[2];  // board[row][col] = 'W'
            }
            
            else if ( (row == boardSize/2 - 1 && col == boardSize/2) || (row == boardSize/2 && col == boardSize/2 - 1)  ){
                board[row][col] = stateCharacters[1]; // board[row][col] = 'B'
            }

        }

    }
    
}


// fun'c 3: prints the current state of the board
void printBoard(char board[][26], int n) {
    
    char alphabet[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
                    'h', 'i', 'j', 'k', 'l', 'm', 'n',
                    'o', 'p', 'q', 'r', 's', 't', 'u',
                    'v', 'w', 'x', 'y', 'z' };

    // 1.) print the board to the given format
    
    // 1.1) the first line of board
    printf("  ");
    
    for ( int idx = 0 ; idx < n ; idx++ ){
        printf( "%c", *(alphabet+idx) );
    }
    
    printf("\n");

    // 1.2) the rest of the board
    for ( int row = 0 ; row < n ; row++ ){

        printf( "%c ", *(alphabet+row) );

        for ( int col = 0 ; col < n ; col++ ){

            printf("%c", board[row][col]);

        }

        printf("\n");
    }

}


// fun'c 4: gets and edits the board to the first configuration
void getBoardConfig(char board[][26]) {

    char chess = 0;
    char row = 0;
    char col = 0;

    bool endEntry = false;

    printf("Enter board configuration:\n");

    while ( !endEntry ){


        // ASSUMING all the inputs are valid and correct
        scanf(" %c %c %c", &chess, &row, &col);

        if ( chess == '!' && row == '!' && col == '!' ){  // exit when hitting !!!
            
            endEntry = true;
        
        } else{
            
            board[ row - 'a' ][ col - 'a' ] = chess;  // put the input value into the chessboard; by character arithmetic
        
        }

    }

}


// fun'c 5: checks whether the specified (row, col) lies awithin the board dimensions
bool positionInBounds(int boardSize, int row, int col) {

    if ( (0 <= row && row < boardSize) && (0 <= col && col < boardSize) ){

        return true;  // within boardSize -> TRUE

    }

    else{

        return false;  // out of boardSize -> FALSE

    }

}


// fun'c 6: check wheter the current input position (row, col) is an available move for either a white or black chess, as we input
bool checkLegalInDirection(char board[][26], int n, int row, int col,
                           char colour, int deltaRow, int deltaCol) {
    
//    char stateCharacters[3] = { 'U', 'B', 'W' };  // U - for unoccupied; B - occupied by the black; W - occupied by white

    char characterBegin = colour;

    char nextCharacter1 = colour;  //  the latest collected one
    
    char nextCharacter2 = 0;  //  the previous collected one
    

    
    if ( (board[row][col] == 'B') || (board[row][col]  == 'W') ){  // do not need to check for pre-occupied 'W' || 'B' cells

        return false;

    }
    

    // ensure the checking is within the boundary
    while ( positionInBounds(n, row + deltaRow, col + deltaCol) ){  // we only check for unoccupied space: 'U' cells
        
        if ( board[row + deltaRow][col + deltaCol] == 'U' ){

            return false;  //  do not need to check for next term being 'U'

        }
  
        nextCharacter1 = board[row + deltaRow][col + deltaCol];

        if ( nextCharacter1 != characterBegin ){
            
            nextCharacter2 = nextCharacter1;

        }

        else if ( nextCharacter1 == characterBegin && nextCharacter2 != 0 ){

            return true;

        }
        
        else if (  nextCharacter1 == characterBegin && nextCharacter2 == 0  ){

            return false;

        }

        row = row + deltaRow;
        col = col + deltaCol;

    }

    return false;
}


// fun'c 7: prints out the available moves for an input chess
void printAvailableMoves(char board[][26], int boardSize, char colour) {

    char alphabet[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
                    'h', 'i', 'j', 'k', 'l', 'm', 'n',
                    'o', 'p', 'q', 'r', 's', 't', 'u',
                    'v', 'w', 'x', 'y', 'z' };

    // check for each row and col cells
    for ( int row = 0 ; row < boardSize ; row++ ){

        for ( int col = 0 ; col < boardSize ; col++ ){

            if ( checkLegalInDirection(board, boardSize, row, col, colour, 1 , 0 ) ){  // Dir.1 search in SOUTH

                printf("%c%c\n", alphabet[row], alphabet[col]);

            }

            else if ( checkLegalInDirection(board, boardSize, row, col, colour, 1 , -1 ) ){  // Dir.2 search in SOUTH-WEST

                printf("%c%c\n", alphabet[row], alphabet[col]);

            }

            else if ( checkLegalInDirection(board, boardSize, row, col, colour, 0 , -1 ) ){  // Dir.3 search in WEST 

                printf("%c%c\n", alphabet[row], alphabet[col]);

            }


            else if ( checkLegalInDirection(board, boardSize, row, col, colour, -1 , -1 ) ){  // Dir.4 search in NORTH-WEST

                printf("%c%c\n", alphabet[row], alphabet[col]);

            }

            else if ( checkLegalInDirection(board, boardSize, row, col, colour, -1 , 0 ) ){  // Dir.5 search in NORTH

                printf("%c%c\n", alphabet[row], alphabet[col]);

            }

            else if ( checkLegalInDirection(board, boardSize, row, col, colour, -1 , 1 ) ){  // Dir.6 search in NORTH-EAST

                printf("%c%c\n", alphabet[row], alphabet[col]);

            }

            else if ( checkLegalInDirection(board, boardSize, row, col, colour, 0 , 1 ) ){  // Dir.7 search in EAST

                printf("%c%c\n", alphabet[row], alphabet[col]);

            }

            else if ( checkLegalInDirection(board, boardSize, row, col, colour, 1 , 1 ) ){  // Dir.8 search in SOUTH-EAST

                printf("%c%c\n", alphabet[row], alphabet[col]);

            }

        }

    }

}


// fun'c 8: check if the current position is an available move for the input chess
bool checkValidMove(char board[][26], int boardSize, int row, int col, char colour) {

    if (positionInBounds(boardSize, row, col)){
        // for the current chess with the specific position, check all the eight drections
        if ( checkLegalInDirection(board, boardSize, row, col, colour, 1 , 0 ) ){  // Dir.1 search in SOUTH

            return true;

        }

        else if ( checkLegalInDirection(board, boardSize, row, col, colour, 1 , -1 ) ){  // Dir.2 search in SOUTH-WEST

            return true;

        }

        else if ( checkLegalInDirection(board, boardSize, row, col, colour, 0 , -1 ) ){  // Dir.3 search in WEST 

            return true;

        }

        else if ( checkLegalInDirection(board, boardSize, row, col, colour, -1 , -1 ) ){  // Dir.4 search in NORTH-WEST

            return true;

        }

        else if ( checkLegalInDirection(board, boardSize, row, col, colour, -1 , 0 ) ){  // Dir.5 search in NORTH

            return true;

        }

        else if ( checkLegalInDirection(board, boardSize, row, col, colour, -1 , 1 ) ){  // Dir.6 search in NORTH-EAST

            return true;

        }

        else if ( checkLegalInDirection(board, boardSize, row, col, colour, 0 , 1 ) ){  // Dir.7 search in EAST

            return true;

        }

        else if ( checkLegalInDirection(board, boardSize, row, col, colour, 1 , 1 ) ){  // Dir.8 search in SOUTH-EAST

            return true;

        }
    }

    return false;
}


// F10. Makes moves for the User
void makeValidMove( char board[][26], int boardSize, int row, int col, char colour ){
    

    int initial_row = row;
    int initial_col = col;

    // for the current chess with the specific position, check all the eight drections
    if ( checkLegalInDirection(board, boardSize, row, col, colour, 1 , 0 ) ){  // Dir.1 search in SOUTH

        while ( board[ row + 1 ][ col + 0 ] !=  colour ){

            board[ row + 1 ][ col + 0 ] = colour;

            row = row + 1;
            col = col + 0;
        }
    }

    row = initial_row;
    col = initial_col;

    if ( checkLegalInDirection(board, boardSize, row, col, colour, 1 , -1 ) ){  // Dir.2 search in SOUTH-WEST

        while ( board[ row + 1 ][ col - 1 ] != colour){

            board[ row + 1 ][ col - 1 ] = colour;

            row = row + 1;
            col = col - 1;
        }
    }

    row = initial_row;
    col = initial_col;

    if ( checkLegalInDirection(board, boardSize, row, col, colour, 0 , -1 ) ){  // Dir.3 search in WEST 

        while ( board[ row + 0 ][ col - 1 ] != colour ){

            board[ row + 0 ][ col - 1 ] = colour;

            row = row + 0;
            col = col - 1;
        }
    }

    row = initial_row;
    col = initial_col;

    if ( checkLegalInDirection(board, boardSize, row, col, colour, -1 , -1 ) ){  // Dir.4 search in NORTH-WEST

        while ( board[ row - 1 ][ col - 1 ] != colour ){

            board[ row - 1 ][ col - 1 ] = colour;

            row = row - 1;
            col = col - 1;
        }        
    }

    row = initial_row;
    col = initial_col;

    if ( checkLegalInDirection(board, boardSize, row, col, colour, -1 , 0 ) ){  // Dir.5 search in NORTH

        while ( board[ row - 1 ][ col + 0 ] != colour ){

            board[ row - 1 ][ col + 0 ] = colour;

            row = row - 1;
            col = col + 0;
        }
    }

    row = initial_row;
    col = initial_col;

    if ( checkLegalInDirection(board, boardSize, row, col, colour, -1 , 1 ) ){  // Dir.6 search in NORTH-EAST

        while ( board[ row - 1 ][ col + 1 ] != colour ){

            board[ row - 1 ][ col + 1 ] = colour;

            row = row - 1;
            col = col + 1;
        }
    }

    row = initial_row;
    col = initial_col;

    if ( checkLegalInDirection(board, boardSize, row, col, colour, 0 , 1 ) ){  // Dir.7 search in EAST

        while ( board[ row + 0 ][ col + 1 ] != colour ){

            board[ row + 0 ][ col + 1 ] = colour;

            row = row + 0;
            col = col + 1;
        }
    }

    row = initial_row;
    col = initial_col;

    if ( checkLegalInDirection(board, boardSize, row, col, colour, 1 , 1 ) ){  // Dir.8 search in SOUTH-EAST

        while ( board[ row + 1 ][ col + 1 ] != colour ){

            board[ row + 1 ][ col + 1 ] = colour;

            row = row + 1;
            col = col + 1;
        }
    }

    row = initial_row;
    col = initial_col;

    board[row][col] = colour;
}

// MAIN EXECUTOR
int main(void) {

    //** 1.) Gets the size of the board and create a "n" by "n" 2-D arrays for the game to take place

    // 1.1) gets the USER input for the board size
    int BoardSize = getBoardSize();
    const int Size = BoardSize;  // the definite size of the board (the boundary)

    // 1.2) creates a board (2-D array) with maximum size 26 x 26
    char board[26][26] = {{0},{0}};

    // 1.3) gets the board w/ the initialized background
    initializeBoard(board, Size);

    // 1.4) prints the board w/ the most basic background (basci state)
    printBoard(board, Size);


    //** 2.) Gets the board configuration and print the curren board state
    getBoardConfig(board);

    printBoard(board, Size);

    
    //** 3.) Determines and prints out the lists of available moves for the white and black chess players
    printf("Available moves for W:\n");
    printAvailableMoves(board, Size, 'W');

    printf("Available moves for B:\n");
    printAvailableMoves(board, Size, 'B');
    

    //** 4.) Collects a move from the USER, prompt whether it is a valid/Invalid move
    char nextChess = 0;
    char nextRow = 0;
    char nextCol = 0;


    printf("Enter a move:\n");
    scanf(" %c %c %c", &nextChess, &nextRow, &nextCol);

    bool valid = checkValidMove(board, Size, (nextRow - 'a'), (nextCol - 'a'), nextChess);

    if ( valid ){
        
        printf("Valid move.\n");

        //* 5.) Makes changes to the correct movement on the chessboard, e.g. changes the whole line to ...
        makeValidMove(board, Size, (nextRow - 'a'), (nextCol - 'a'), nextChess);

        board[nextRow - 'a'][nextCol - 'a'] = nextChess;
    }

    else if ( !valid ){

        printf("Invalid move.\n");

    }

    printBoard(board, Size);

    return 0;
}