#pragma once

#include "../csquares.hpp"
#include "../cevaluator.hpp"
#include <math.h>

bool improve_paramater(CSQUARES cs, LINE_DAT_TYPE line_data[]) {
    int winner = cs.judge_winner();
    int loser = winner % 2 + 1;
    int T = cs.get_turn();

    if (winner == 0 && T < 64) {
        return false;
    }

    int index = 0;
    int s[4][4][4];
    int temp;
    int w, l, d;
    double p;
    double weight;
    cs.get_squares(s);

    for (int s23 = 0; s23 < 16; s23++) {
        w = 0;
        l = 0;
        for (int s1 = 0; s1 < 4; s1++) {
            temp = s[s1][(int)(s23 / 4)][s23 % 4];
            if (temp == winner) {
                w++;
            } else if (temp == loser) {
                l++;
            }
        }

        d = w - l;

        p = line_data[index];
        weight = 1;

        if (d > 0) {
            weight = exp(3 - p);
        } else {
            weight = exp(p - 3);
        }

        line_data[index] += d * weight / T;

        index++;
    }
    for (int s31 = 0; s31 < 16; s31++) {
        w = 0;
        l = 0;
        for (int s2 = 0; s2 < 4; s2++) {
            temp = s[s2][(int)(s31 / 4)][s31 % 4];
            if (temp == winner) {
                w++;
            } else if (temp == loser) {
                l++;
            }
        }

        d = w - l;

        p = line_data[index];
        weight = 1;

        if (d > 0) {
            weight = exp(3 - p);
        } else {
            weight = exp(p - 3);
        }

        line_data[index] += d * weight / T;

        index++;
    }
    for (int s12 = 0; s12 < 16; s12++) {
        w = 0;
        l = 0;
        for (int s3 = 0; s3 < 4; s3++) {
            temp = s[s3][(int)(s12 / 4)][s12 % 4];
            if (temp == winner) {
                w++;
            } else if (temp == loser) {
                l++;
            }
        }

        d = w - l;

        p = line_data[index];
        weight = 1;

        if (d > 0) {
            weight = exp(3 - p);
        } else {
            weight = exp(p - 3);
        }

        line_data[index] += d * weight / T;

        index++;
    }
    for (int s3 = 0; s3 < 4; s3++) {
        w = 0;
        l = 0;
        for (int s1 = 0; s1 < 4; s1++) {
            temp = s[s1][s1][s3];
            if (temp == winner) {
                w++;
            } else if (temp == loser) {
                l++;
            }
        }

        d = w - l;

        p = line_data[index];
        weight = 1;

        if (d > 0) {
            weight = exp(3 - p);
        } else {
            weight = exp(p - 3);
        }

        line_data[index] += d * weight / T;

        index++;
        
        w = 0;
        l = 0;
        for (int s1 = 0; s1 < 4; s1++) {
            temp = s[s1][3 - s1][s3];
            if (temp == winner) {
                w++;
            } else if (temp == loser) {
                l++;
            }
        }

        d = w - l;

        p = line_data[index];
        weight = 1;

        if (d > 0) {
            weight = exp(3 - p);
        } else {
            weight = exp(p - 3);
        }

        line_data[index] += d * weight / T;

        index++;
    }
    for (int s1 = 0; s1 < 4; s1++) {
        w = 0;
        l = 0;
        for (int s2 = 0; s2 < 4; s2++) {
            temp = s[s1][s2][s2];
            if (temp == winner) {
                w++;
            } else if (temp == loser) {
                l++;
            }
        }

        d = w - l;

        p = line_data[index];
        weight = 1;

        if (d > 0) {
            weight = exp(3 - p);
        } else {
            weight = exp(p - 3);
        }

        line_data[index] += d * weight / T;

        index++;
        
        w = 0;
        l = 0;
        for (int s2 = 0; s2 < 4; s2++) {
            temp = s[s1][s2][3 - s2];
            if (temp == winner) {
                w++;
            } else if (temp == loser) {
                l++;
            }
        }

        d = w - l;

        p = line_data[index];
        weight = 1;

        if (d > 0) {
            weight = exp(3 - p);
        } else {
            weight = exp(p - 3);
        }

        line_data[index] += d * weight / T;
        
        index++;
    }
    for (int s2 = 0; s2 < 4; s2++) {
        w = 0;
        l = 0;
        for (int s3 = 0; s3 < 4; s3++) {
            temp = s[s3][s2][s3];
            if (temp == winner) {
                w++;
            } else if (temp == loser) {
                l++;
            }
        }

        d = w - l;

        p = line_data[index];
        weight = 1;

        if (d > 0) {
            weight = exp(3 - p);
        } else {
            weight = exp(p - 3);
        }

        line_data[index] += d * weight / T;

        index++;
        
        w = 0;
        l = 0;
        for (int s3 = 0; s3 < 4; s3++) {
            temp = s[s3][s2][3 - s3];
            if (temp == winner) {
                w++;
            } else if (temp == loser) {
                l++;
            }
        }

        d = w - l;

        p = line_data[index];
        weight = 1;

        if (d > 0) {
            weight = exp(3 - p);
        } else {
            weight = exp(p - 3);
        }

        line_data[index] += d * weight / T;
        
        index++;
    }

    w = 0;
    l = 0;
    for (int s1 = 0; s1 < 4; s1++) {
        temp = s[s1][s1][s1];
        if (temp == winner) {
            w++;
        } else if (temp == loser) {
            l++;
        }
    }
    d = w - l;

    p = line_data[index];
    weight = 1;

    if (d > 0) {
        weight = exp(3 - p);
    } else {
        weight = exp(p - 3);
    }

    line_data[index] += d * weight / T;

    index++;

    w = 0;
    l = 0;
    for (int s1 = 0; s1 < 4; s1++) {
        temp = s[s1][s1][3 - s1];
        if (temp == winner) {
            w++;
        } else if (temp == loser) {
            l++;
        }
    }
    d = w - l;

    p = line_data[index];
    weight = 1;

    if (d > 0) {
        weight = exp(3 - p);
    } else {
        weight = exp(p - 3);
    }

    line_data[index] += d * weight / T;

    index++;

    w = 0;
    l = 0;
    for (int s1 = 0; s1 < 4; s1++) {
        temp = s[s1][3 - s1][s1];
        if (temp == winner) {
            w++;
        } else if (temp == loser) {
            l++;
        }
    }
    d = w - l;

    p = line_data[index];
    weight = 1;

    if (d > 0) {
        weight = exp(3 - p);
    } else {
        weight = exp(p - 3);
    }

    line_data[index] += d * weight / T;

    index++;

    w = 0;
    l = 0;
    for (int s1 = 0; s1 < 4; s1++) {
        temp = s[s1][3 - s1][3 - s1];
        if (temp == winner) {
            w++;
        } else if (temp == loser) {
            l++;
        }
    }
    d = w - l;

    p = line_data[index];
    weight = 1;

    if (d > 0) {
        weight = exp(3 - p);
    } else {
        weight = exp(p - 3);
    }

    line_data[index] += d * weight / T;

    index++;

    return true;
}