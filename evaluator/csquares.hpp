#pragma once

/*
"csquares.hpp" created by grkon(Twitter: @progblog_note)
About :
    Game manager for the 3 dimensions yonmoku in a board of 4 * 4 * 4 squares.
    Usage is commented out.
*/

class CSQUARES {
    private:
    // variables

    /*
    Squares on the board.
    First index is the height of the square.
    Second and third index is the horizontal coordinate of the square.
    */
    int squares[4][4][4];
    /*
    Turn spending.
    */
    int turn;

    public:
    // constructors

    CSQUARES(); // to start game
    CSQUARES(int[4][4][4]); // to set the game on the way

    public:
    // functions

    /*
    get "squares" variable:
    store the pointer in first argument
    no return
    */
    void get_squares(int[4][4][4]);
    /*
    get "turn" variable:
    no argument
    return the value
    */
   int get_turn();
    /*
    make a move:
    put a proper player's ball in squares[now height + 1][first argument][second argument]
    return true if success
    */
    bool move(int, int);
    /*
    get the player of current turn:
    no argument
    return the player
    */
    int player_corrent_turn();
};