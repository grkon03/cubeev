#pragma once

/*
"csquares.hpp" created by grkon
About :
    Game manager for the 3 dimensions yonmoku in a board of 4 * 4 * 4 squares.
    Usage is commented out.
*/

class CSQUARES {
    public:
    // variable

    /*
    Squares on the board.
    First index is the height of the square.
    Second and third index is the horizontal coordinate of the square.
    */
    int squares[4][4][4];

    public:
    // constructor

    CSQUARES(); // to start game
    CSQUARES(int[4][4][4]); //to set the game on the way
};