// SOURCE CODE
//
// Author: Chau, Tsz Tung
//
// Completion Date: 2022/04/01 (expected)
// 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//-------------------------------------------------------ALGORITHM------------------------------------------------------------//


// FX. (at specific location) Checks if the User input is a valid move; return (bool); Status -> improving
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


// FX. Checks if the current position is in bounds and appropriate
bool positionInBounds( int boardSize, int currentRow, int currentCol ){

    if ( (0 <= currentRow && currentRow < boardSize) && (0 <= currentCol && currentCol < boardSize) ){

        return true;  // within boardSize -> TRUE

    }

    else{

        return false;  // out of boardSize -> FALSE

    }
}


// FX. Check if the chess is legal at the specific location and in the specified direction
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


int numberFlip( char computerChessColor, char chessBoard[][26], int boardSize, int currentRowIdx, int currentColIdx ){

    int totalNumFlip = 0;

    if ( checkLegalInDirection(chessBoard, boardSize, currentRowIdx, currentColIdx, computerChessColor, 1 , 0 ) ){  // Dir.1 search in SOUTH
        totalNumFlip++;
    }

    if ( checkLegalInDirection(chessBoard, boardSize, currentRowIdx, currentColIdx, computerChessColor, 1 , -1 ) ){  // Dir.2 search in SOUTH-WEST
        totalNumFlip++;
    }

    if ( checkLegalInDirection(chessBoard, boardSize, currentRowIdx, currentColIdx, computerChessColor, 0 , -1 ) ){  // Dir.3 search in WEST 
        totalNumFlip++;
    }

    if ( checkLegalInDirection(chessBoard, boardSize, currentRowIdx, currentColIdx, computerChessColor, -1 , -1 ) ){  // Dir.4 search in NORTH-WEST
        totalNumFlip++;
    }

    if ( checkLegalInDirection(chessBoard, boardSize, currentRowIdx, currentColIdx, computerChessColor, -1 , 0 ) ){  // Dir.5 search in NORTH
        totalNumFlip++;
    }

    if ( checkLegalInDirection(chessBoard, boardSize, currentRowIdx, currentColIdx, computerChessColor, -1 , 1 ) ){  // Dir.6 search in NORTH-EAST
        totalNumFlip++;
    }

    if ( checkLegalInDirection(chessBoard, boardSize, currentRowIdx, currentColIdx, computerChessColor, 0 , 1 ) ){  // Dir.7 search in EAST
        totalNumFlip++;
    }

    if ( checkLegalInDirection(chessBoard, boardSize, currentRowIdx, currentColIdx, computerChessColor, 1 , 1 ) ){  // Dir.8 search in SOUTH-EAST
        totalNumFlip++;
    }

    return totalNumFlip;
}


// FX. Check for available corners
bool IsCornerAvailable( char computerChessColor, char chessBoard[][26], int boardSize, int *RowIdx, int *ColIdx ){

    bool moveExist = false;
    int corner = boardSize - 1;

    int largestNumFlip = 0;
    int tempNumFlip = 0;

    char largestRowIdx = 0;
    char largestColIdx = 0;
    
    if ( checkValidMove( chessBoard, boardSize, 0, 0, computerChessColor ) ){
        moveExist = true;

        tempNumFlip = numberFlip( computerChessColor, chessBoard, boardSize, 0, 0 );

        if( tempNumFlip > largestNumFlip ){
            largestNumFlip = tempNumFlip;
            largestRowIdx = 0;
            largestColIdx = 0;
        }
    }

    if ( checkValidMove( chessBoard, boardSize, 0, corner, computerChessColor ) ){
        moveExist = true;

        tempNumFlip = numberFlip( computerChessColor, chessBoard, boardSize, 0, corner );

        if(  tempNumFlip > largestNumFlip  ){
            largestNumFlip = tempNumFlip;
            largestRowIdx = 0;
            largestColIdx = corner;
        }
    }

    if ( checkValidMove( chessBoard, boardSize, corner, 0, computerChessColor ) ){
        moveExist = true;

        tempNumFlip = numberFlip( computerChessColor, chessBoard, boardSize, corner, 0 );
        
        if( tempNumFlip > largestNumFlip  ){
            largestNumFlip = tempNumFlip;
            largestRowIdx = corner;
            largestColIdx = 0;
        }
    }

    if ( checkValidMove( chessBoard, boardSize, corner, corner, computerChessColor ) ){
        moveExist = true;
        
        tempNumFlip = numberFlip( computerChessColor, chessBoard, boardSize, corner, corner );
        
        if(  tempNumFlip > largestNumFlip ){
            largestNumFlip = tempNumFlip;
            largestRowIdx = corner;
            largestColIdx = corner;
        }
    }


    if( moveExist ){
        *RowIdx = largestRowIdx;
        *ColIdx = largestColIdx;
        return true;
    }
    
    else{
        return false;
    }
}


// FX. Check for available edges
bool IsEdgeAvailable( char computerChessColor, char chessBoard[][26], int boardSize, int *RowIdx, int *ColIdx ){

    bool moveExist = false;

    int largestNumFlip = 0;
    int tempNumFlip = 0;

    char largestRowIdx = 0;
    char largestColIdx = 0;
    
    for( int row = 0; row < boardSize; row++ ){
        
        if( row == 0 || row == boardSize - 1 ){  // for the first and last row

            for( int col = 2 ; col < boardSize - 2 ; col++ ){
                
                if ( checkValidMove( chessBoard, boardSize, row, col, computerChessColor ) ){
                    moveExist = true;
                    
                    tempNumFlip = numberFlip( computerChessColor, chessBoard, boardSize, row, col );
        
                    if( tempNumFlip > largestNumFlip ){
                        largestNumFlip = tempNumFlip;
                        largestRowIdx = row;
                        largestColIdx = col;
                    }
                }
            }        
        }

        else if( (row > 1) && (row < boardSize - 2) ){  // for the in between rows

            if ( checkValidMove( chessBoard, boardSize, row, 0, computerChessColor ) ){  // cells in the first column
                moveExist = true;
                
                tempNumFlip = numberFlip( computerChessColor, chessBoard, boardSize, row, 0 );
        
                if(  tempNumFlip > largestNumFlip ){
                    largestNumFlip = tempNumFlip;
                    largestRowIdx = row;
                    largestColIdx = 0;
                }
            }

            if( checkValidMove( chessBoard, boardSize, row, boardSize - 1, computerChessColor ) ){  // cells in the last column
                moveExist = true;

                tempNumFlip = numberFlip( computerChessColor, chessBoard, boardSize, row, boardSize - 1 );
        
                if(  tempNumFlip > largestNumFlip ){
                    largestNumFlip = tempNumFlip;
                    largestRowIdx = row;
                    largestColIdx = boardSize - 1;
                }
            }
        }
    }
    
    if( moveExist ){
        *RowIdx = largestRowIdx;
        *ColIdx = largestColIdx;
        return true;
    }
    
    else{
        return false;
    }
}


// FX. (general for a color) Checks if the input chess color has an available move; Status -> editing
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

// FX. Test if the chess is around the 4 corners in the chessboard
bool IsAroundcorners( char computerChessColor, char chessBoard[][26], int boardSize, int currentRowIdx, int currentColIdx ){

    int lowCorner = 0;
    int highCorner = boardSize - 1;

    if( currentRowIdx == 0 && currentColIdx == 1 ){
        return true;
    }

    else if( currentRowIdx == 0 && currentColIdx == boardSize - 2 ){
        return true;
    }

    else if( currentRowIdx == 1 && currentColIdx == 0 ){
        return true;
    }

    else if( currentRowIdx == 1 && currentColIdx == 1 ){
        return true;
    }

    else if( currentRowIdx == 1 && currentColIdx == boardSize - 2 ){
        return true;
    }

    else if( currentRowIdx == 1 && currentColIdx == boardSize - 1 ){
        return true;
    }

    else if( currentRowIdx == boardSize - 2 && currentColIdx == 0 ){
        return true;
    }

    else if( currentRowIdx == boardSize - 2 && currentColIdx == 1 ){
        return true;
    }

    else if( currentRowIdx == boardSize - 2 && currentColIdx == boardSize - 2 ){
        return true;
    }

    else if( currentRowIdx == boardSize - 2 && currentColIdx == boardSize - 1 ){
        return true;
    }

    else if( currentRowIdx == boardSize - 1 && currentColIdx == 1 ){
        return true;
    }

    else if( currentRowIdx == boardSize - 1 && currentColIdx == boardSize - 2 ){
        return true;
    }
    
    return false;
}


// FX. Counts the 
int Count(char chessBoard[][26], int boardSize){

    int empty = 0;

    for (int row = 0; row < boardSize; row++){

        for (int col = 0; col < boardSize; col++){

            if( chessBoard[row][col] == 'U'){
                empty++;
            }
        }
    }

    return empty;
}

//
//
//

// FXediting. Finds the position with the largest number of flip(s)
int makeMove( const char board[][26], int n, char turn, int *row, int *col ){

    char colour = turn;

    int larRowIdx = 0;
    int larColIdx = 0;

    double currentRowIdx = 0;
    double currentColIdx = 0;
    double larDistance = 100;

    bool found = false;

    if ( IsCornerAvailable(turn, board, n, &larRowIdx, &larColIdx) ){
    }
    
    else if ( IsEdgeAvailable(turn, board, n, &larRowIdx, &larColIdx ) ){
    }

    else{

        if ( colour == 'B' ) {
            
            // (loop through) OR (check for) all row and col cells
            for ( int row = 0 ; row < n ; row++ ){

                for ( int col = 0 ; col < n ; col++ ){

                    found = false;

                    if ( checkLegalInDirection(board, n, row, col, colour, 1 , 0 ) ){  // Dir.1 search in SOUTH
                        currentRowIdx = row;
                        currentColIdx = col;
                        found = true;
                    }

                    else if ( checkLegalInDirection(board, n, row, col, colour, 1 , -1 ) ){  // Dir.2 search in SOUTH-WEST
                        currentRowIdx = row;
                        currentColIdx = col;
                        found = true;
                    }

                    else if ( checkLegalInDirection(board, n, row, col, colour, 0 , -1 ) ){  // Dir.3 search in WEST 
                        currentRowIdx = row;
                        currentColIdx = col;
                        found = true;
                    }

                    else if ( checkLegalInDirection(board, n, row, col, colour, -1 , -1 ) ){  // Dir.4 search in NORTH-WEST
                        currentRowIdx = row;
                        currentColIdx = col;
                        found = true;
                    }

                    else if ( checkLegalInDirection(board, n, row, col, colour, -1 , 0 ) ){  // Dir.5 search in NORTH
                        currentRowIdx = row;
                        currentColIdx = col;
                        found = true;
                    }

                    else if ( checkLegalInDirection(board, n, row, col, colour, -1 , 1 ) ){  // Dir.6 search in NORTH-EAST
                        currentRowIdx = row;
                        currentColIdx = col;
                        found = true;
                    }

                    else if ( checkLegalInDirection(board, n, row, col, colour, 0 , 1 ) ){  // Dir.7 search in EAST
                        currentRowIdx = row;
                        currentColIdx = col;
                        found = true;
                    }

                    else if ( checkLegalInDirection(board, n, row, col, colour, 1 , 1 ) ){  // Dir.8 search in SOUTH-EAST
                        currentRowIdx = row;
                        currentColIdx = col;
                        found = true;
                    }

                    // calculates the dis distance between the cuurent vaide move and the corner (0,0)
                    double distance =  sqrt(currentRowIdx*currentRowIdx + currentColIdx*currentColIdx);

                    if( found && (distance < larDistance) ){
                        
                        larRowIdx = currentRowIdx;
                        larColIdx = currentColIdx;

                    }
                }
            }
        }

        else if ( colour == 'W' ) {

            char colour = turn;

            int largestFlip = 0;

            int leastFlip = 100;

            
            
            // (loop through) OR (check for) all row and col cells
            for ( int row = 0 ; row < n ; row++ ){

                for ( int col = 0 ; col < n ; col++ ){
                    
                    int currentFlip = 0;
                    found = false;

                    if ( checkLegalInDirection(board, n, row, col, colour, 1 , 0 ) ){  // Dir.1 search in SOUTH
                        found = true;
                        currentFlip++;
                    }

                    if ( checkLegalInDirection(board, n, row, col, colour, 1 , -1 ) ){  // Dir.2 search in SOUTH-WEST
                        found = true;
                        currentFlip++;
                    }

                    if ( checkLegalInDirection(board, n, row, col, colour, 0 , -1 ) ){  // Dir.3 search in WEST 
                        found = true;
                        currentFlip++;
                    }

                    if ( checkLegalInDirection(board, n, row, col, colour, -1 , -1 ) ){  // Dir.4 search in NORTH-WEST
                        found = true;
                        currentFlip++;
                    }

                    if ( checkLegalInDirection(board, n, row, col, colour, -1 , 0 ) ){  // Dir.5 search in NORTH
                        found = true;
                        currentFlip++;
                    }

                    if ( checkLegalInDirection(board, n, row, col, colour, -1 , 1 ) ){  // Dir.6 search in NORTH-EAST
                        found = true;
                        currentFlip++;
                    }

                    if ( checkLegalInDirection(board, n, row, col, colour, 0 , 1 ) ){  // Dir.7 search in EAST
                        found = true;
                        currentFlip++;
                    }

                    if ( checkLegalInDirection(board, n, row, col, colour, 1 , 1 ) ){  // Dir.8 search in SOUTH-EAST
                        found = true;
                        currentFlip++;
                    }

                    int count = Count(board, n);

                    // at the end of searching at each cell
                    if( count >= 20 && found && (currentFlip > largestFlip) ){  // updates the larger flip position
                        largestFlip = currentFlip;
                        larRowIdx = row;
                        larColIdx = col;
                    }

                    else if ( count < 20 && found && (currentFlip < leastFlip) ){
                        leastFlip = currentFlip;
                        larRowIdx = row;
                        larColIdx = col;    

                    }
                }
            }
        }
    }

            
    // return the postion of the cell that contains the largest flip position
    *row = larRowIdx;
    *col = larColIdx;


    return 0;
}


//--------------------------------------------------------------
// SOURCE CODE
//
// Author: Chau, Tsz Tung
//
// Completion Date: 2022/03/30 (expected)
// 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//-------------------------------------------------------ALGORITHM------------------------------------------------------------//


// FX. (at specific location) Checks if the User input is a valid move; return (bool); Status -> improving
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


// FX. Checks if the current position is in bounds and appropriate
bool positionInBounds( int boardSize, int currentRow, int currentCol ){

    if ( (0 <= currentRow && currentRow < boardSize) && (0 <= currentCol && currentCol < boardSize) ){

        return true;  // within boardSize -> TRUE

    }

    else{

        return false;  // out of boardSize -> FALSE

    }
}


// FX. Check if the chess is legal at the specific location and in the specified direction
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


int numberFlip( char computerChessColor, char chessBoard[][26], int boardSize, int currentRowIdx, int currentColIdx ){

    int totalNumFlip = 0;

    if ( checkLegalInDirection(chessBoard, boardSize, currentRowIdx, currentColIdx, computerChessColor, 1 , 0 ) ){  // Dir.1 search in SOUTH
        totalNumFlip++;
    }

    if ( checkLegalInDirection(chessBoard, boardSize, currentRowIdx, currentColIdx, computerChessColor, 1 , -1 ) ){  // Dir.2 search in SOUTH-WEST
        totalNumFlip++;
    }

    if ( checkLegalInDirection(chessBoard, boardSize, currentRowIdx, currentColIdx, computerChessColor, 0 , -1 ) ){  // Dir.3 search in WEST 
        totalNumFlip++;
    }

    if ( checkLegalInDirection(chessBoard, boardSize, currentRowIdx, currentColIdx, computerChessColor, -1 , -1 ) ){  // Dir.4 search in NORTH-WEST
        totalNumFlip++;
    }

    if ( checkLegalInDirection(chessBoard, boardSize, currentRowIdx, currentColIdx, computerChessColor, -1 , 0 ) ){  // Dir.5 search in NORTH
        totalNumFlip++;
    }

    if ( checkLegalInDirection(chessBoard, boardSize, currentRowIdx, currentColIdx, computerChessColor, -1 , 1 ) ){  // Dir.6 search in NORTH-EAST
        totalNumFlip++;
    }

    if ( checkLegalInDirection(chessBoard, boardSize, currentRowIdx, currentColIdx, computerChessColor, 0 , 1 ) ){  // Dir.7 search in EAST
        totalNumFlip++;
    }

    if ( checkLegalInDirection(chessBoard, boardSize, currentRowIdx, currentColIdx, computerChessColor, 1 , 1 ) ){  // Dir.8 search in SOUTH-EAST
        totalNumFlip++;
    }

    return totalNumFlip;
}


// FX. Check for available corners
bool IsCornerAvailable( char computerChessColor, char chessBoard[][26], int boardSize, int *RowIdx, int *ColIdx ){

    bool moveExist = false;
    int corner = boardSize - 1;

    int largestNumFlip = 0;
    int tempNumFlip = 0;

    char largestRowIdx = 0;
    char largestColIdx = 0;
    
    if ( checkValidMove( chessBoard, boardSize, 0, 0, computerChessColor ) ){
        moveExist = true;

        tempNumFlip = numberFlip( computerChessColor, chessBoard, boardSize, 0, 0 );

        if( tempNumFlip > largestNumFlip ){
            largestNumFlip = tempNumFlip;
            largestRowIdx = 0;
            largestColIdx = 0;
        }
    }

    else if ( checkValidMove( chessBoard, boardSize, 0, corner, computerChessColor ) ){
        moveExist = true;

        tempNumFlip = numberFlip( computerChessColor, chessBoard, boardSize, 0, corner );

        if(  tempNumFlip > largestNumFlip  ){
            largestNumFlip = tempNumFlip;
            largestRowIdx = 0;
            largestColIdx = corner;
        }
    }

    else if ( checkValidMove( chessBoard, boardSize, corner, 0, computerChessColor ) ){
        moveExist = true;

        tempNumFlip = numberFlip( computerChessColor, chessBoard, boardSize, corner, 0 );
        
        if( tempNumFlip > largestNumFlip  ){
            largestNumFlip = tempNumFlip;
            largestRowIdx = corner;
            largestColIdx = 0;
        }
    }

    else if ( checkValidMove( chessBoard, boardSize, corner, corner, computerChessColor ) ){
        moveExist = true;
        
        tempNumFlip = numberFlip( computerChessColor, chessBoard, boardSize, corner, corner );
        
        if(  tempNumFlip > largestNumFlip ){
            largestNumFlip = tempNumFlip;
            largestRowIdx = corner;
            largestColIdx = corner;
        }
    }


    if( moveExist ){
        *RowIdx = largestRowIdx;
        *ColIdx = largestColIdx;
        return true;
    }
    
    else{
        return false;
    }
}

// FX. Check for available edges
bool IsEdgeAvailable( char computerChessColor, char chessBoard[][26], int boardSize, int *RowIdx, int *ColIdx ){

    bool moveExist = false;

    int largestNumFlip = 0;
    int tempNumFlip = 0;

    char largestRowIdx = 0;
    char largestColIdx = 0;
    
    for( int row = 0; row < boardSize; row++ ){
        
        if( row == 0 || row == boardSize - 1 ){  // for the first and last row

            for( int col = 1 ; col < boardSize - 2 ; col++ ){
                
                if ( checkValidMove( chessBoard, boardSize, row, col, computerChessColor ) ){
                    moveExist = true;
                    
                    tempNumFlip = numberFlip( computerChessColor, chessBoard, boardSize, row, col );
        
                    if( tempNumFlip > largestNumFlip ){
                        largestNumFlip = tempNumFlip;
                        largestRowIdx = row;
                        largestColIdx = col;
                    }
                }
            }        
        }

        else if( (row > 0) && (row < boardSize - 1) ){  // for the in between rows

            if ( checkValidMove( chessBoard, boardSize, row, 0, computerChessColor ) ){  // cells in the first column
                moveExist = true;
                
                tempNumFlip = numberFlip( computerChessColor, chessBoard, boardSize, row, 0 );
        
                if(  tempNumFlip > largestNumFlip ){
                    largestNumFlip = tempNumFlip;
                    largestRowIdx = row;
                    largestColIdx = 0;
                }
            }

            if( checkValidMove( chessBoard, boardSize, row, boardSize - 1, computerChessColor ) ){  // cells in the last column
                moveExist = true;

                tempNumFlip = numberFlip( computerChessColor, chessBoard, boardSize, row, boardSize - 1 );
        
                if(  tempNumFlip > largestNumFlip ){
                    largestNumFlip = tempNumFlip;
                    largestRowIdx = row;
                    largestColIdx = boardSize - 1;
                }
            }
        }
    }
    
    if( moveExist ){
        *RowIdx = largestRowIdx;
        *ColIdx = largestColIdx;
        return true;
    }
    
    else{
        return false;
    }
}




// FXediting. Finds the position with the largest number of flip(s)
int makeMove( const char board[][26], int n, char turn, int *row, int *col ){

    char colour = turn;

    int larRowIdx = 0;
    int larColIdx = 0;

    double currentRowIdx = 0;
    double currentColIdx = 0;
    double larDistance = 100;

    bool found = false;

    if ( IsCornerAvailable(turn, board, n, &larRowIdx, &larColIdx) ){
    }
    
    else if ( IsEdgeAvailable(turn, board, n, &larRowIdx, &larColIdx ) ){
    }

    else{

        if ( colour == 'B' ) {
            
            // (loop through) OR (check for) all row and col cells
            for ( int row = 0 ; row < n ; row++ ){

                for ( int col = 0 ; col < n ; col++ ){

                    found = false;

                    if ( checkLegalInDirection(board, n, row, col, colour, 1 , 0 ) ){  // Dir.1 search in SOUTH
                        currentRowIdx = row;
                        currentColIdx = col;
                        found = true;
                    }

                    else if ( checkLegalInDirection(board, n, row, col, colour, 1 , -1 ) ){  // Dir.2 search in SOUTH-WEST
                        currentRowIdx = row;
                        currentColIdx = col;
                        found = true;
                    }

                    else if ( checkLegalInDirection(board, n, row, col, colour, 0 , -1 ) ){  // Dir.3 search in WEST 
                        currentRowIdx = row;
                        currentColIdx = col;
                        found = true;
                    }

                    else if ( checkLegalInDirection(board, n, row, col, colour, -1 , -1 ) ){  // Dir.4 search in NORTH-WEST
                        currentRowIdx = row;
                        currentColIdx = col;
                        found = true;
                    }

                    else if ( checkLegalInDirection(board, n, row, col, colour, -1 , 0 ) ){  // Dir.5 search in NORTH
                        currentRowIdx = row;
                        currentColIdx = col;
                        found = true;
                    }

                    else if ( checkLegalInDirection(board, n, row, col, colour, -1 , 1 ) ){  // Dir.6 search in NORTH-EAST
                        currentRowIdx = row;
                        currentColIdx = col;
                        found = true;
                    }

                    else if ( checkLegalInDirection(board, n, row, col, colour, 0 , 1 ) ){  // Dir.7 search in EAST
                        currentRowIdx = row;
                        currentColIdx = col;
                        found = true;
                    }

                    else if ( checkLegalInDirection(board, n, row, col, colour, 1 , 1 ) ){  // Dir.8 search in SOUTH-EAST
                        currentRowIdx = row;
                        currentColIdx = col;
                        found = true;
                    }

                    // calculates the dis distance between the cuurent vaide move and the corner (0,0)
                    double distance =  sqrt(currentRowIdx*currentRowIdx + currentColIdx*currentColIdx);

                    if( found && (distance < larDistance) ){
                        
                        larRowIdx = currentRowIdx;
                        larColIdx = currentColIdx;

                    }
                }
            }
        }

        else if ( colour == 'W' ) {

            char colour = turn;

            int largestFlip = 0;
            
            // (loop through) OR (check for) all row and col cells
            for ( int row = 0 ; row < n ; row++ ){

                for ( int col = 0 ; col < n ; col++ ){
                    
                    int currentFlip = 0;
                    found = false;

                    if ( checkLegalInDirection(board, n, row, col, colour, 1 , 0 ) ){  // Dir.1 search in SOUTH
                        found = true;
                        currentFlip++;
                    }

                    if ( checkLegalInDirection(board, n, row, col, colour, 1 , -1 ) ){  // Dir.2 search in SOUTH-WEST
                        found = true;
                        currentFlip++;
                    }

                    if ( checkLegalInDirection(board, n, row, col, colour, 0 , -1 ) ){  // Dir.3 search in WEST 
                        found = true;
                        currentFlip++;
                    }

                    if ( checkLegalInDirection(board, n, row, col, colour, -1 , -1 ) ){  // Dir.4 search in NORTH-WEST
                        found = true;
                        currentFlip++;
                    }

                    if ( checkLegalInDirection(board, n, row, col, colour, -1 , 0 ) ){  // Dir.5 search in NORTH
                        found = true;
                        currentFlip++;
                    }

                    if ( checkLegalInDirection(board, n, row, col, colour, -1 , 1 ) ){  // Dir.6 search in NORTH-EAST
                        found = true;
                        currentFlip++;
                    }

                    if ( checkLegalInDirection(board, n, row, col, colour, 0 , 1 ) ){  // Dir.7 search in EAST
                        found = true;
                        currentFlip++;
                    }

                    if ( checkLegalInDirection(board, n, row, col, colour, 1 , 1 ) ){  // Dir.8 search in SOUTH-EAST
                        found = true;
                        currentFlip++;
                    }


                    // at the end of searching at each cell
                    if( found && (currentFlip > largestFlip) ){  // updates the larger flip position
                        largestFlip = currentFlip;
                        larRowIdx = row;
                        larColIdx = col;
                    }
                }
            }
        }
    }

            
    // return the postion of the cell that contains the largest flip position
    *row = larRowIdx;
    *col = larColIdx;


    return 0;
}

