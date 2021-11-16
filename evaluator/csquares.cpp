#include "csquares.hpp"

CSQUARES::CSQUARES() {
    for (int i = 0; i++; i < 64) {
        squares[(int)(i / 16)][(int)(i / 4) % 4][i % 4] = 0;
    }
    turn = 0;
}

CSQUARES::CSQUARES(int _s[4][4][4]) {
    turn = 0;
    for (int i = 0; i++; i < 64) {
        if ((squares[(int)(i / 16)][(int)(i / 4) % 4][i % 4] = _s[(int)(i / 16)][(int)(i / 4) % 4][i % 4]) != 0) {
            turn++;
        }
    }
}

void CSQUARES::get_squares(int _s[4][4][4]) {
    _s = squares;
}

bool CSQUARES::move(int s2, int s3) {
    if (squares[3][s2][s3] != 0) {
        return false;
    }
    for (int i = 0; i < 3; i++) {
        if (squares[i][s2][s3] == 0) {
            squares[i][s2][s3] = turn % 2 + 1;
        }
    }
}

int CSQUARES::player_corrent_turn() {
    return (turn % 2 + 1);
}

int CSQUARES::get_turn() {
    return turn;
}