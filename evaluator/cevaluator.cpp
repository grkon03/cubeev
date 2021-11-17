#include "cevaluator.hpp"

using namespace std;

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