#include "cevaluator.hpp"
#include <math.h>

using namespace std;

/// data handler

int datasize_byID(int id) {
    switch(id) {
        case LINE_DAT_ID:
        return LINE_DAT_SIZE;
    }
    return 0;
}

string datafile_byID(int id) {
    switch(id) {
        case LINE_DAT_ID:
        return LINE_DAT_FILE;
    }
    return "";
}

// evaluator

CEVALUATOR::CEVALUATOR() : now_evaluation(0) {
    for (int i = 0; i < LINE_DAT_SIZE; i++) {
        line_data[i] = LINE_DAT_DEFAULT;
    }

    for (int i = 0; i < 64; i++) {
        bestmove[i] = -1;
    }
}

CEVALUATOR::CEVALUATOR(LINE_DAT_TYPE _line[LINE_DAT_SIZE]) : now_evaluation(0) {
    for (int i = 0; i < LINE_DAT_SIZE; i++) {
        line_data[i] = _line[i];
    }

    for (int i = 0; i < 64; i++) {
        bestmove[i] = -1;
    }
}

double CEVALUATOR::temporary_evaluator(CSQUARES cs) {
    switch(cs.judge_winner()) {
        case 1:
        return 10000;
        case 2:
        return -10000;
    }
    
    double evaluation = 0;
    int z, numofball;
    int index = 0;
    int s[4][4][4];
    bool skip;
    cs.get_squares(s);

    for (int s23 = 0; s23 < 16; s23++) {
        z = 0;
        numofball = 0;
        skip = false;
        for (int s1 = 0; s1 < 4; s1++) {
            if (s[s1][(int)(s23 / 4)][s23 % 4] == 0) {
                continue;
            } else if (z == 0) {
                z = s[s1][(int)(s23 / 4)][s23 % 4];
                numofball++;
            } else if (z != s[s1][(int)(s23 / 4)][s23 % 4]) {
                skip = true;
                break;
            } else {
                numofball++;
            }
        }
        if (!skip) {
            if (z == 1) {
                evaluation += line_data[index] * numofball;
            } else {
                evaluation -= line_data[index] * numofball;
            }
        }
        index++;
    }
    for (int s31 = 0; s31 < 16; s31++) {
        z = 0;
        numofball = 0;
        skip = false;
        for (int s2 = 0; s2 < 4; s2++) {
            if (s[(int)(s31 / 4)][s2][s31 % 4] == 0) {
                continue;
            } else if (z == 0) {
                z = s[(int)(s31 / 4)][s2][s31 % 4];
                numofball++;
            } else if (z != s[(int)(s31 / 4)][s2][s31 % 4]) {
                skip = true;
                break;
            } else {
                numofball++;
            }
        }
        if (!skip) {
            if (z == 1) {
                evaluation += line_data[index] * numofball;
            } else {
                evaluation -= line_data[index] * numofball;
            }
        }
        index++;
    }
    for (int s12 = 0; s12 < 16; s12++) {
        z = 0;
        numofball = 0;
        skip = false;
        for (int s3 = 0; s3 < 4; s3++) {
            if (s[(int)(s12 / 4)][s12 % 4][s3] == 0) {
                continue;
            } else if (z == 0) {
                z = s[(int)(s12 / 4)][s12 % 4][s3];
                numofball++;
            } else if (z != s[(int)(s12 / 4)][s12 % 4][s3]) {
                skip = true;
                break;
            } else {
                numofball++;
            }
        }
        if (!skip) {
            if (z == 1) {
                evaluation += line_data[index] * numofball;
            } else {
                evaluation -= line_data[index] * numofball;
            }
        }
        index++;
    }
    for (int s3 = 0; s3 < 4; s3++) {
        z = 0;
        numofball = 0;
        skip = false;
        for (int s1 = 0; s1 < 4; s1++) {
            if (s[s1][s1][s3] == 0) {
                continue;
            } else if (z == 0) {
                z = s[s1][s1][s3];
                numofball++;
            } else if (z != s[s1][s1][s3]) {
                skip = true;
                break;
            } else {
                numofball++;
            }
        }
        if (!skip) {
            if (z == 1) {
                evaluation += line_data[index] * numofball;
            } else {
                evaluation -= line_data[index] * numofball;
            }
        }
        index++;
        z = 0;
        numofball = 0;
        skip = false;
        for (int s1 = 0; s1 < 4; s1++) {
            if (s[s1][3 - s1][s3] == 0) {
                continue;
            } else if (z == 0) {
                z = s[s1][3 - s1][s3];
                numofball++;
            } else if (z != s[s1][3 - s1][s3]) {
                skip = true;
                break;
            } else {
                numofball++;
            }
        }
        if (!skip) {
            if (z == 1) {
                evaluation += line_data[index] * numofball;
            } else {
                evaluation -= line_data[index] * numofball;
            }
        }
        index++;
    }
    for (int s1 = 0; s1 < 4; s1++) {
        z = 0;
        numofball = 0;
        skip = false;
        for (int s2 = 0; s2 < 4; s2++) {
            if (s[s1][s2][s2] == 0) {
                continue;
            } else if (z == 0) {
                z = s[s1][s2][s2];
                numofball++;
            } else if (z != s[s1][s2][s2]) {
                skip = true;
                break;
            } else {
                numofball++;
            }
        }
        if (!skip) {
            if (z == 1) {
                evaluation += line_data[index] * numofball;
            } else {
                evaluation -= line_data[index] * numofball;
            }
        }
        index++;
        z = 0;
        numofball = 0;
        skip = false;
        for (int s2 = 0; s2 < 4; s2++) {
            if (s[s1][s2][3 - s2] == 0) {
                continue;
            } else if (z == 0) {
                z = s[s1][s2][3 - s2];
                numofball++;
            } else if (z != s[s1][s2][3 - s2]) {
                skip = true;
                break;
            } else {
                numofball++;
            }
        }
        if (!skip) {
            if (z == 1) {
                evaluation += line_data[index] * numofball;
            } else {
                evaluation -= line_data[index] * numofball;
            }
        }
        index++;
    }
    for (int s2 = 0; s2 < 4; s2++) {
        z = 0;
        numofball = 0;
        skip = false;
        for (int s3 = 0; s3 < 4; s3++) {
            if (s[s3][s2][s3] == 0) {
                continue;
            } else if (z == 0) {
                z = s[s3][s2][s3];
                numofball++;
            } else if (z != s[s3][s2][s3]) {
                skip = true;
                break;
            } else {
                numofball++;
            }
        }
        if (!skip) {
            if (z == 1) {
                evaluation += line_data[index] * numofball;
            } else {
                evaluation -= line_data[index] * numofball;
            }
        }
        index++;
        z = 0;
        numofball = 0;
        skip = false;
        for (int s3 = 0; s3 < 4; s3++) {
            if (s[s3][s2][3 - s3] == 0) {
                continue;
            } else if (z == 0) {
                z = s[s3][s2][3 - s3];
                numofball++;
            } else if (z != s[s3][s2][3 - s3]) {
                skip = true;
                break;
            } else {
                numofball++;
            }
        }
        if (!skip) {
            if (z == 1) {
                evaluation += line_data[index] * numofball;
            } else {
                evaluation -= line_data[index] * numofball;
            }
        }
        index++;
    }
    z = 0;
    numofball = 0;
    skip = false;
    for (int s1 = 0; s1 < 4; s1++) {
        if (s[s1][s1][s1] == 0) {
            continue;
        } else if (z == 0) {
            z = s[s1][s1][s1];
            numofball++;
        } else if (z != s[s1][s1][s1]) {
            skip = true;
            break;
        } else {
            numofball++;
        }
    }
    if (!skip) {
        if (z == 1) {
            evaluation += line_data[index] * numofball;
        } else {
            evaluation -= line_data[index] * numofball;
        }
    }
    index++;
    z = 0;
    numofball = 0;
    skip = false;
    for (int s1 = 0; s1 < 4; s1++) {
        if (s[s1][s1][3 - s1] == 0) {
            continue;
        } else if (z == 0) {
            z = s[s1][s1][3 - s1];
            numofball++;
        } else if (z != s[s1][s1][3 - s1]) {
            skip = true;
            break;
        } else {
            numofball++;
        }
    }
    if (!skip) {
        if (z == 1) {
            evaluation += line_data[index] * numofball;
        } else {
            evaluation -= line_data[index] * numofball;
        }
    }
    index++;
    z = 0;
    numofball = 0;
    skip = false;
    for (int s1 = 0; s1 < 4; s1++) {
        if (s[s1][3 - s1][s1] == 0) {
            continue;
        } else if (z == 0) {
            z = s[s1][3 - s1][s1];
            numofball++;
        } else if (z != s[s1][3 - s1][s1]) {
            skip = true;
            break;
        } else {
            numofball++;
        }
    }
    if (!skip) {
        if (z == 1) {
            evaluation += line_data[index] * numofball;
        } else {
            evaluation -= line_data[index] * numofball;
        }
    }
    index++;
    z = 0;
    numofball = 0;
    skip = false;
    for (int s1 = 0; s1 < 4; s1++) {
        if (s[s1][3 - s1][3 - s1] == 0) {
            continue;
        } else if (z == 0) {
            z = s[s1][3 - s1][3 - s1];
            numofball++;
        } else if (z != s[s1][3 - s1][3 - s1]) {
            skip = true;
            break;
        } else {
            numofball++;
        }
    }
    if (!skip) {
        if (z == 1) {
            evaluation += line_data[index] * numofball;
        } else {
            evaluation -= line_data[index] * numofball;
        }
    }

    return evaluation;
}

double CEVALUATOR::evaluator_main(CSQUARES cs, double alpha, double beta, int depth, int depthmax) {
    switch (cs.judge_winner()) {
        case 1:
        return 10000;
        case 2:
        return -10000;
    }

    if (cs.get_turn() == 64) {
        return 0;
    }

    CSQUARES cs_copy;
    int turn = cs.player_corrent_turn();
    double ret;
    bool move_suc;

    if (depth == depthmax) {
        return temporary_evaluator(cs);
    } else {
        for (int s23 = 0; s23 < 16; s23++) {
            cs_copy = cs;
            move_suc = cs_copy.move((int)(s23 / 4), s23 % 4);
            if (!move_suc) {
                continue;
            }
            ret = evaluator_main(cs_copy, alpha, beta, depth + 1, depthmax);
            if (turn == 1) {
                if (beta <= ret) {
                    return ret;
                } else if (alpha < ret) {
                    alpha = ret;
                    bestmove[depth] = s23;
                }
            } else if (turn == 2) {
                if (alpha >= ret) {
                    return ret;
                } else if (beta > ret) {
                    beta = ret;
                    bestmove[depth] = s23;
                }
            }
        }
    }

    if (turn == 1) {
        return alpha;
    } else if (turn == 2) {
        return beta;
    }

    return 0;
}

double CEVALUATOR::evaluate(CSQUARES cs) {
    int depthmax = 0;
    int turn = cs.get_turn();
    int t = cs.player_corrent_turn();
    now_analyzed_squares = cs;
    for (int i = 0; i < 64; i++) {
        bestmove[i] = -1;
    }
    
    if (turn < 16) {
        if (t == 1) {
            depthmax = 6;
        } else {
            depthmax = 5;
        }
    } else if (turn < 44) {
        if (t == 1) {
            depthmax = 8;
        } else {
            depthmax = 7;
        }
    } else if (turn < 54) {
        if (t == 1) {
            depthmax = 10;
        } else {
            depthmax = 9;
        }
    } else {
        if (t == 1) {
            depthmax = 64 - turn;
        } else {
            depthmax = 64 - turn;
        }
    }
    now_evaluation = evaluator_main(cs, -INT_MAX, INT_MAX, 0, depthmax);
    return now_evaluation;
}

CSQUARES CEVALUATOR::get_now_analyzed_squares() {
    return now_analyzed_squares;
}

void CEVALUATOR::get_bestmove(int bm[64]) {
    for (int i = 0; i < 64; i++) {
        bm[i] = bestmove[i];
    }
}

int CEVALUATOR::get_next_bestmove() {
    return bestmove[0];
}

double CEVALUATOR::get_now_evaluation() {
    return now_evaluation;
}

bool CEVALUATOR::improve_paramater(CSQUARES cs) {
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
            weight = exp(4 - p);
        } else {
            weight = exp(p - 2);
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
            weight = exp(4 - p);
        } else {
            weight = exp(p - 2);
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
            weight = exp(4 - p);
        } else {
            weight = exp(p - 2);
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
            weight = exp(4 - p);
        } else {
            weight = exp(p - 2);
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
            weight = exp(4 - p);
        } else {
            weight = exp(p - 2);
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
            weight = exp(4 - p);
        } else {
            weight = exp(p - 2);
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
            weight = exp(4 - p);
        } else {
            weight = exp(p - 2);
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
            weight = exp(4 - p);
        } else {
            weight = exp(p - 2);
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
            weight = exp(4 - p);
        } else {
            weight = exp(p - 2);
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
        weight = exp(4 - p);
    } else {
        weight = exp(p - 2);
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
        weight = exp(4 - p);
    } else {
        weight = exp(p - 2);
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
        weight = exp(4 - p);
    } else {
        weight = exp(p - 2);
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
        weight = exp(4 - p);
    } else {
        weight = exp(p - 2);
    }

    line_data[index] += d * weight / T;

    index++;

    return true;
}