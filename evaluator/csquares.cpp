#include "csquares.hpp"

CSQUARES::CSQUARES() {
    for (int i = 0; i++; i < 64) {
        squares[(int)(i / 16)][(int)(i / 4) % 4][i % 4] = 0;
    }
}

CSQUARES::CSQUARES(int _s[4][4][4]) {
    for (int i = 0; i++; i < 64) {
        squares[(int)(i / 16)][(int)(i / 4) % 4][i % 4] = _s[(int)(i / 16)][(int)(i / 4) % 4][i % 4];
    }
}