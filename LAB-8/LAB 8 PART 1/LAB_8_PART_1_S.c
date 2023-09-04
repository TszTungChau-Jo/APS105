// FINAL EDITION
// 
// Author: Chau, Tsz Tung
//
// Completion Date: 2022/03/30 (expected)
// 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//---------------------------------------------------------FUNC'S-------------------------------------------------------------//

// F1. Gets boardSiZe and initialzes the chessBoard; return (int); Status -> tested
int getBoardInitialized( char chessBoard[][26] ){

    int boardSize = 0;
    char stateCharacters[3] = { 'U', 'B', 'W' };

    printf("Enter the board dimension: ");  // Assume: all (input) dimensions are even number
    scanf("%d", &boardSize);

    // -) initialze all the cells inside the board to U w/ the base "WB\nBW"
    for ( int row = 0 ; row < boardSize ; row++ ){

        for ( int col = 0 ; col < boardSize ; col++ ){
            
            chessBoard[row][col] = stateCharacters[0];  // board[row][col] = 'U'

            if ( (row == boardSize/2 - 1 && col == boardSize/2 - 1) || (row == boardSize/2 && col == boardSize/2) ){
                chessBoard[row][col] = stateCharacters[2];  // board[row][col] = 'W'
            }
            
            else if ( (row == boardSize/2 - 1 && col == boardSize/2) || (row == boardSize/2 && col == boardSize/2 - 1)  ){
                chessBoard[row][col] = stateCharacters[1]; // board[row][col] = 'B'
            }

        }

    }

    return boardSize;
}


// F2. Prints the current state of the chessBoard; return (void); Status -> tested
void printBoard( char chessBoard[][26], int boardSize ){

    char alphabet[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 
                          'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

    
    // the first line of board
    printf("  ");
    
    for ( int idx = 0 ; idx < boardSize ; idx++ ){
        printf( "%c", *(alphabet+idx) );
    }
    
    printf("\n");

    //  the rest of the board
    for ( int row = 0 ; row < boardSize ; row++ ){
        printf( "%c ", *(alphabet+row) );  // N: a space in "%c_"

        for ( int col = 0 ; col < boardSize ; col++ ){
            printf( "%c", chessBoard[row][col] );

        }

        printf("\n");
    }

}


// F3. Checks if the current position is in bounds and appropriate; return (bool); Status -> improving
bool positionInBounds( int boardSize, int currentRow, int currentCol ){

    if ( (0 <= currentRow && currentRow < boardSize) && (0 <= currentCol && currentCol < boardSize) ){

        return true;  // within boardSize -> TRUE

    }

    else{

        return false;  // out of boardSize -> FALSE

    }
}


// F4. Gets for which color the computer plays ('B' or 'W'); return char; Status -> improving
char getComputerChessColor( void ){

    char computerChessColor = 0;

    printf("Computer plays (B/W): ");
    scanf(" %c", &computerChessColor);  // N: a space in "_%c"
    
    return computerChessColor;
}


// F5. Gets the User plays color; return (char); Status -> editing
char getUserChessColor( char computerChessColor ){

    char userChessColor = 0;

    if ( computerChessColor == 'B' ){
        userChessColor = 'W';
    }
    
    else if ( computerChessColor == 'W' ){
        userChessColor = 'B';
    }

    return userChessColor;
}


// F6. Check if the chess is legal at the specific location and in the specified direction; return (bool); Status -> improving
bool checkLegalInDirection( char chessBoard[][26], int n, int row, int col,
                           char colour, int deltaRow, int deltaCol ) {

    char characterBegin = colour;
    char nextCharacter1 = colour;  //  the latest collected one
    char nextCharacter2 = 0;  //  the previous collected one
    
    
    if ( (chessBoard[row][col] == 'B') || (chessBoard[row][col]  == 'W') ){  // do not need to check for pre-occupied 'W' || 'B' cells
        return false;

    }
    
    // ensure the checking is within the boundary
    while ( positionInBounds(n, row + deltaRow, col + deltaCol) ){  // we only check for unoccupied space: 'U' cells
        
        if ( chessBoard[row + deltaRow][col + deltaCol] == 'U' ){
            return false;  //  do not need to check for next term being 'U'

        }
  
        nextCharacter1 = chessBoard[row + deltaRow][col + deltaCol];

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


// F7. (at specific location) Checks if the User input is a valid move; return (bool); Status -> improving
bool checkValidMove( char chessBoard[][26], int boardSize, int Row, int Col, char colour ) {

    if ( positionInBounds(boardSize, Row, Col) ){

        // for the current chess with the specific position, check all the eight drections
        if ( checkLegalInDirection(chessBoard, boardSize, Row, Col, colour, 1 , 0 ) ){  // Dir.1 search in SOUTH
            return true;
        }

        else if ( checkLegalInDirection(chessBoard, boardSize, Row, Col, colour, 1 , -1 ) ){  // Dir.2 search in SOUTH-WEST
            return true;
        }

        else if ( checkLegalInDirection(chessBoard, boardSize, Row, Col, colour, 0 , -1 ) ){  // Dir.3 search in WEST 
            return true;
        }

        else if ( checkLegalInDirection(chessBoard, boardSize, Row, Col, colour, -1 , -1 ) ){  // Dir.4 search in NORTH-WEST
            return true;
        }

        else if ( checkLegalInDirection(chessBoard, boardSize, Row, Col, colour, -1 , 0 ) ){  // Dir.5 search in NORTH
            return true;
        }

        else if ( checkLegalInDirection(chessBoard, boardSize, Row, Col, colour, -1 , 1 ) ){  // Dir.6 search in NORTH-EAST
            return true;
        }

        else if ( checkLegalInDirection(chessBoard, boardSize, Row, Col, colour, 0 , 1 ) ){  // Dir.7 search in EAST
            return true;
        }

        else if ( checkLegalInDirection(chessBoard, boardSize, Row, Col, colour, 1 , 1 ) ){  // Dir.8 search in SOUTH-EAST
            return true;
        }
    }

    return false;
}


// F8. (general for a color) Checks if the input chess color has an available move; Status -> editing
bool IfMovesExist( char chessBoard[][26], int boardSize, char colour ) {

    // (loop through) OR (check for) all row and col cells
    for ( int row = 0 ; row < boardSize ; row++ ){

        for ( int col = 0 ; col < boardSize ; col++ ){

            if ( checkLegalInDirection(chessBoard, boardSize, row, col, colour, 1 , 0 ) ){  // Dir.1 search in SOUTH
                return true;
            }

            else if ( checkLegalInDirection(chessBoard, boardSize, row, col, colour, 1 , -1 ) ){  // Dir.2 search in SOUTH-WEST
                return true;
            }

            else if ( checkLegalInDirection(chessBoard, boardSize, row, col, colour, 0 , -1 ) ){  // Dir.3 search in WEST 
                return true;
            }

            else if ( checkLegalInDirection(chessBoard, boardSize, row, col, colour, -1 , -1 ) ){  // Dir.4 search in NORTH-WEST
                return true;
            }

            else if ( checkLegalInDirection(chessBoard, boardSize, row, col, colour, -1 , 0 ) ){  // Dir.5 search in NORTH
                return true;
            }

            else if ( checkLegalInDirection(chessBoard, boardSize, row, col, colour, -1 , 1 ) ){  // Dir.6 search in NORTH-EAST
                return true;
            }

            else if ( checkLegalInDirection(chessBoard, boardSize, row, col, colour, 0 , 1 ) ){  // Dir.7 search in EAST
                return true;

            }

            else if ( checkLegalInDirection(chessBoard, boardSize, row, col, colour, 1 , 1 ) ){  // Dir.8 search in SOUTH-EAST
                return true;

            }

        }

    }

    return false;
}


// F9. Determines the turn for who can place a chess; return (int); Status -> editing
int whoseTurn( char currentColor, char chessBoard[][26], int boardSize ){

    char oppositeColor = 0;

    if( currentColor == 'W' ){
        oppositeColor = 'B';
    }

    else if( currentColor == 'B' ){
        oppositeColor = 'W';
    }

    if( IfMovesExist( chessBoard, boardSize, oppositeColor ) ){
        
        if( currentColor == 'B' ){
            return 1;
        }

        else if( currentColor == 'W' ){
            return 0;
        }
    }

    else {
        
        if( currentColor == 'B' ){
            return 0;
        }

        else if( currentColor == 'W' ){
            return 1;
        }
    }

    return 0; 
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


// F11. Finds the position with the largest number of flip(s)
void findLargestFlip( char computerChessColor, char chessBoard[][26], int boardSize, int *largestRowIdx, int *largestColIdx ){

    char colour = computerChessColor;

    int largestFlip = 0;

    int larRowIdx = 0;
    int larColIdx = 0;
    
    // (loop through) OR (check for) all row and col cells
    for ( int row = 0 ; row < boardSize ; row++ ){

        for ( int col = 0 ; col < boardSize ; col++ ){
            
            int currentFlip = 0;

            if ( checkLegalInDirection(chessBoard, boardSize, row, col, colour, 1 , 0 ) ){  // Dir.1 search in SOUTH
                currentFlip++;
            }

            if ( checkLegalInDirection(chessBoard, boardSize, row, col, colour, 1 , -1 ) ){  // Dir.2 search in SOUTH-WEST
                currentFlip++;
            }

            if ( checkLegalInDirection(chessBoard, boardSize, row, col, colour, 0 , -1 ) ){  // Dir.3 search in WEST 
                currentFlip++;
            }

            if ( checkLegalInDirection(chessBoard, boardSize, row, col, colour, -1 , -1 ) ){  // Dir.4 search in NORTH-WEST
                currentFlip++;
            }

            if ( checkLegalInDirection(chessBoard, boardSize, row, col, colour, -1 , 0 ) ){  // Dir.5 search in NORTH
                currentFlip++;
            }

            if ( checkLegalInDirection(chessBoard, boardSize, row, col, colour, -1 , 1 ) ){  // Dir.6 search in NORTH-EAST
                currentFlip++;
            }

            if ( checkLegalInDirection(chessBoard, boardSize, row, col, colour, 0 , 1 ) ){  // Dir.7 search in EAST
                currentFlip++;
            }

            if ( checkLegalInDirection(chessBoard, boardSize, row, col, colour, 1 , 1 ) ){  // Dir.8 search in SOUTH-EAST
                currentFlip++;

            }


            // at the end of searching at each cell
            if( currentFlip > largestFlip ){  // updates the larger flip position
                largestFlip = currentFlip;
                larRowIdx = row;
                larColIdx = col;
            }
        
        }

    }

    // return the postion of the cell that contains the largest flip position
    *largestRowIdx = larRowIdx;
    *largestColIdx = larColIdx;
}


// F12. Determines the result of the game
void postTheResult( char board[][26], int boardSize, bool validUserInput, char computerChessColor ){

    if( validUserInput ){

        int countBlack = 0;
        int countWhite = 0;

        for( int row = 0; row < boardSize; row++ ){
            for( int col = 0; col < boardSize; col++ ){
                
                if( board[row][col] == 'B' ){
                    countBlack++;
                }
                
                else if( board[row][col] == 'W' ){
                    countWhite++;
                }
            }
        }


        if( countBlack == countWhite ){
            printf("Draw!");
        }

        else if( countBlack < countWhite ){
            printf("W player wins.");
        }

        else if( countBlack > countWhite ){
            printf("B player wins.");
        }
    }

    else{
        printf("Invalid move.\n");
        printf("%c player wins.", computerChessColor);
    }

}


//----------------------------------------------------------CODE--------------------------------------------------------------//


int main(void){

    // 1. Foundation
    char chessBoard[26][26] = {{0},{0}};
    const int boardSize = getBoardInitialized( chessBoard );
    char computerChessColor = getComputerChessColor();
    char userChessColor = getUserChessColor( computerChessColor );

    printBoard( chessBoard, boardSize );

    // 2. Game Loop
    bool validUserInput = true;

    /*
        if ( playerTurn == 0 )
            -> black 'B' moves a chess
        
        else ( playerTurn == 1 )
            -> white 'W' moves a chess
    */

    int playerTurn = 0;  // Initialized as 0, b/c 0_'B' ALWAYS gets move first

    while( ( IfMovesExist( chessBoard, boardSize, computerChessColor ) || IfMovesExist( chessBoard, boardSize, userChessColor )) && validUserInput ){

        char userChessRow = 0;
        char userChessCol = 0;

        // black 'B' plays
        if( playerTurn == 0 ){

            int currentTurn = playerTurn;

            if( userChessColor == 'B' ){
                printf("Enter move for colour B (RowCol): ");
                scanf(" %c %c", &userChessRow, &userChessCol);

                int userChessRowIdx = userChessRow - 'a';
                int userChessColIdx = userChessCol - 'a';

                if( checkValidMove( chessBoard, boardSize, userChessRowIdx, userChessColIdx, 'B' ) ){
                    
                    // Makes move
                    makeValidMove( chessBoard, boardSize, userChessRowIdx, userChessColIdx, 'B' );

                    printBoard( chessBoard, boardSize );
                }

                else{
                    validUserInput = false;
                }
            }

            else if( computerChessColor == 'B' ){
                
                // call the computer to move a chess

                int larRowIdx = 0;
                int larColIdx = 0;

                findLargestFlip( computerChessColor, chessBoard, boardSize, &larRowIdx, &larColIdx );

                makeValidMove( chessBoard, boardSize, larRowIdx, larColIdx, computerChessColor );

                printf("Computer places B at %c%c.\n", ('a'+larRowIdx), ('a'+larColIdx) );

                printBoard( chessBoard, boardSize );
            }

            playerTurn = whoseTurn( 'B', chessBoard, boardSize );

            if( ( currentTurn == playerTurn ) && ( IfMovesExist( chessBoard, boardSize, computerChessColor ) || IfMovesExist( chessBoard, boardSize, userChessColor )) ){
                printf("W player has no valid move.\n");
            }
        }


        // white 'W' plays
        else if( playerTurn == 1 ){

            int currentTurn = playerTurn;

            if( userChessColor == 'W' ){
                printf("Enter move for colour W (RowCol): ");
                scanf(" %c %c", &userChessRow, &userChessCol);

                int userChessRowIdx = userChessRow - 'a';
                int userChessColIdx = userChessCol - 'a';

                if( checkValidMove( chessBoard, boardSize, userChessRowIdx, userChessColIdx, 'W' ) ){
                    
                    // Makes move
                    makeValidMove( chessBoard, boardSize, userChessRowIdx, userChessColIdx, 'W' );

                    printBoard( chessBoard, boardSize );
                }

                else{
                    validUserInput = false;
                }
            }

            else if( computerChessColor == 'W' ){
                
                // call the computer to move a chess

                int larRowIdx = 0;
                int larColIdx = 0;

                findLargestFlip( computerChessColor, chessBoard, boardSize, &larRowIdx, &larColIdx );

                makeValidMove( chessBoard, boardSize, larRowIdx, larColIdx, computerChessColor );

                printf("Computer places W at %c%c.\n", ('a'+larRowIdx), ('a'+larColIdx) );

                printBoard( chessBoard, boardSize );
            }

            playerTurn = whoseTurn( 'W', chessBoard, boardSize );

            if( ( currentTurn == playerTurn ) && ( IfMovesExist( chessBoard, boardSize, computerChessColor ) || IfMovesExist( chessBoard, boardSize, userChessColor )) ){
                printf("B player has no valid move.\n");
            }
        }
            
    }


    // 3. Leaving
    postTheResult( chessBoard, boardSize, validUserInput, computerChessColor );

    return 0;
}




//----------------------------------------------------------PLAN--------------------------------------------------------------//


/*

Computer Makes Chess Move Algorithm:

void ComputerMadeMove(void){

    1. Determine where to place the next chess [use the provided algorithm]

        [ In every valid move position, record the position that flips the highest number of opposite chess. ]

    -( place the chess onto the board [ at the specific postion record as above ]

    -( update the board

    -( print the chess board

    -> Let the opposite color player to make the move

}

*/


/*
{MAIN EXECUTOR}

int main(void) {

     Structure:

        1. Collect boardSize and initialise the corresponding chess board

        2. Ask for what color of chess is computer (B/W)
            - Assume: the Black 'B' player always gets the first move

        3. ENTER the main game loop

            -( The first player 'B' place a move on the chess board

            - CONTINUE Game condition:
                
                -[ If a valid move is made

                    -( place the chess onto the board 

                    -( update the board

                    -( print the chess board

                    -> Let the opposite color player to make the move

            - End Game Condition:

                -[ If the human player makes an illegal move ( !valid move )

                    -> EXIT MAIN

                -[ If there is no available move for both 'B' and 'W' ( If the current number of 'U' on the chess board is zero ) 

                    -> EXIT MAIN

        
        4. End Game messages

            -( Counts the #s of 'B' and 'W' currently on the chess board

            -[ If ended b/c of an INVALID user input, then the computer (w/ opposite color) automatically wins

                -> printf("Invalide move.");

                -> printf("B player wins.");

            -[ (ended under normal condition) If the # of 'W' chess currently on the chess board is more than 'B' chess
                        
                -> "W player wins."

            -[ Else if the # of 'B' chess currently on the chess board is more than 'W' chess

                -> "B player wins."

            -[ Else if the # of 'B' chess currently on the chess board equals the # of 'W' chess
            
                -> "Draw."

    return 0;
}
*/