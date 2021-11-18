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