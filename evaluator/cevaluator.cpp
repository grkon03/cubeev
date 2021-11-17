#include "cevaluator.hpp"

using namespace std;

bool data_init(std::string file, bool _delete) {
    ifstream ifs(file);
    bool exist = ifs.is_open();

    ofstream ofs;
    ios_base::openmode mode = ios_base::binary;
    if (_delete) {
        mode = mode | ios_base::trunc;
    }
    ofs.open(file, mode);
    if (_delete || !exist) {
        for (int i = 0; i < LINE_DAT_SIZE; i++) {
            ofs << to_string(LINE_DAT_DEFAULT);
        }
    }
    if (_delete || exist) {
        return true;
    }
    return false;
}