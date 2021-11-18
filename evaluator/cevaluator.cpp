#include "cevaluator.hpp"

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

template <typename T> T datadefault_byID(int id) {
    switch(id) {
        case LINE_DAT_ID:
        return LINE_DAT_DEFAULT;
    }
    return 0;
}

template <typename T> bool data_init(int id,  bool _delete) {
    string file = datafile_byID(id);
    ifstream ifs(file);
    bool exist = ifs.is_open();

    ofstream ofs;
    ios_base::openmode mode = ios_base::binary;
    if (_delete) {
        mode = mode | ios_base::trunc;
    }
    ofs.open(file, mode);

    int def = datadefault_byID<T>(id);
    if (_delete || !exist) {
        for (int i = 0; i < datasize_byID(id); i++) {
            ofs.write((char *) &def, sizeof(T));
        }
    }
    if (_delete || exist) {
        return true;
    }
    return false;
}

template <typename T> bool data_get(int id, T *data) {
    ifstream ifs(datafile_byID(id), ios::binary);
    if (!ifs) {
        return false;
    }

    int dsize = datasize_byID(id);
    data = new T[dsize];
    for (int i = 0; i < dsize; i++) {
        ifs.read((char *) &data[i], sizeof(T));
    }
    return true;
}

template <typename T> bool data_put(int id, T data[]) {
    ofstream ofs(datafile_byID(id));
    if (!ofs) {
        return false;
    }
    
    int dsize = datasize_byID(id);
    for (int i = 0; i < dsize; i++) {
        ofs.write((char *) &data[i], sizeof(T));
    }
    return true;
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
    
    int evaluation = 0;
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
            if (z == 0 && s[s1][(int)(s23 / 4)][s23 % 4] != 0) {
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
            if (z == 0 && s[(int)(s31 / 4)][s2][s31 % 4] != 0) {
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
            if (z == 0 && s[(int)(s12 / 4)][s12 % 4][s3] != 0) {
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
            if (z == 0 && s[s1][s1][s3] != 0) {
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
            if (z == 0 && s[s1][3 - s1][s3] != 0) {
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
            if (z == 0 && s[s1][s2][s2] != 0) {
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
            if (z == 0 && s[s1][s2][3 - s2] != 0) {
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
            if (z == 0 && s[s3][s2][s3] != 0) {
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
            if (z == 0 && s[s3][s2][3 - s3] != 0) {
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
        if (z == 0 && s[s1][s1][s1] != 0) {
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
        if (z == 0 && s[s1][s1][3 - s1] != 0) {
            z = s[s1][s1][s1];
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
        if (z == 0 && s[s1][3 - s1][s1] != 0) {
            z = s[s1][s1][s1];
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
        if (z == 0 && s[s1][3 - s1][3 - s1] != 0) {
            z = s[s1][s1][s1];
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