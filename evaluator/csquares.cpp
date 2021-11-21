#include "csquares.hpp"

CSQUARES::CSQUARES() {
    for (int i = 0; i < 64; i++) {
        squares[(int)(i / 16)][(int)(i / 4) % 4][i % 4] = 0;
    }
    turn = 0;
}

CSQUARES::CSQUARES(int _s[4][4][4]) {
    turn = 0;
    for (int i = 0; i < 64; i++) {
        if ((squares[(int)(i / 16)][(int)(i / 4) % 4][i % 4] = _s[(int)(i / 16)][(int)(i / 4) % 4][i % 4]) != 0) {
            turn++;
        }
    }
}

CSQUARES::CSQUARES(const CSQUARES &cs) : turn(cs.turn) {
    for (int i = 0; i < 64; i++) {
        squares[(int)(i / 16)][(int)(i / 4) % 4][i % 4] = cs.squares[(int)(i / 16)][(int)(i / 4) % 4][i % 4];
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
    return true;
}

int CSQUARES::player_corrent_turn() {
    return (turn % 2 + 1);
}

int CSQUARES::get_turn() {
    return turn;
}

int CSQUARES::judge_winner() {
    int z;

    for (int s23 = 0; s23 < 16; s23++) {
        z = squares[3][(int)(s23 / 4)][s23 % 4];
        if (z == 0) {
            continue;
        } else if (
            squares[0][(int)(s23 / 4)][s23 % 4] == z &&
            squares[1][(int)(s23 / 4)][s23 % 4] == z &&
            squares[2][(int)(s23 / 4)][s23 % 4] == z
        ) {
            return z;
        }
    }
    for (int s31 = 0; s31 < 16; s31++) {
        z = squares[(int)(s31 / 4)][3][s31 % 4];
        if (z == 0) {
            continue;
        } else if (
            squares[(int)(s31 / 4)][0][s31 % 4] == z &&
            squares[(int)(s31 / 4)][1][s31 % 4] == z &&
            squares[(int)(s31 / 4)][2][s31 % 4] == z
        ) {
            return z;
        }
    }
    for (int s12 = 0; s12 < 16; s12++) {
        z = squares[(int)(s12 / 4)][s12 % 4][3];
        if (z == 0) {
            continue;
        } else if (
            squares[(int)(s12 / 4)][s12 % 4][0] == z &&
            squares[(int)(s12 / 4)][s12 % 4][1] == z &&
            squares[(int)(s12 / 4)][s12 % 4][2] == z
        ) {
            return z;
        }
    }
    for (int s3 = 0; s3 < 4; s3++) {
        z = squares[3][3][s3];
        if (z == 0) {
            continue;
        } else if (
            squares[0][0][s3] == z &&
            squares[1][2][s3] == z &&
            squares[1][2][s3] == z
        ) {
            return z;
        }
        z = squares[3][0][s3];
        if (z == 0) {
            continue;
        } else if (
            squares[0][3][s3] == z &&
            squares[1][2][s3] == z &&
            squares[2][1][s3] == z
        ) {
            return z;
        }
    }
    for (int s1 = 0; s1 < 4; s1++) {
        z = squares[s1][3][3];
        if (z == 0) {
            continue;
        } else if (
            squares[s1][0][0] == z &&
            squares[s1][1][1] == z &&
            squares[s1][2][2] == z
        ) {
            return z;
        }
        z = squares[s1][3][0];
        if (z == 0) {
            continue;
        } else if (
            squares[s1][0][3] == z &&
            squares[s1][1][2] == z &&
            squares[s1][2][1] == z
        ) {
            return z;
        }
    }
    for (int s2 = 0; s2 < 4; s2++) {
        z = squares[3][s2][3];
        if (z == 0) {
            continue;
        } else if (
            squares[0][s2][0] == z &&
            squares[1][s2][1] == z &&
            squares[2][s2][2] == z
        ) {
            return z;
        }
        z = squares[3][s2][0];
        if (z == 0) {
            continue;
        } else if (
            squares[0][s2][3] == z &&
            squares[1][s2][2] == z &&
            squares[2][s2][1] == z
        ) {
            return z;
        }
    }
    z = squares[3][0][0];
    if (z != 0) {
        if (
            squares[0][3][3] == z &&
            squares[1][2][2] == z &&
            squares[2][1][1] == z
        ) {
            return z;
        }
    }
    z = squares[3][0][3];
    if (z != 0) {
        if (
            squares[0][3][0] == z &&
            squares[1][2][1] == z &&
            squares[2][1][2] == z
        ) {
            return z;
        }
    }
    z = squares[3][3][0];
    if (z != 0) {
        if (
            squares[0][0][3] == z &&
            squares[1][1][2] == z &&
            squares[2][2][1] == z
        ) {
            return z;
        }
    }
    z = squares[3][3][3];
    if (z != 0) {
        if (
            squares[0][0][0] == z &&
            squares[1][1][1] == z &&
            squares[2][2][2] == z
        ) {
            return z;
        }
    }

    return 0;
}