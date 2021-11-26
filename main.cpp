#include "evaluator/cevaluator.hpp"
#include "evaluator/csquares.hpp"

#include <iostream>
#include <fstream>
#include <string>

// プロトタイプ宣言

int main_noarg();
int main_usearg(int, char *[]);

/*
コマンドライン引数でファイル名を指定した場合、そのファイルの操作をする
*/
int main(int argc, char *argv[]) {
    // line.dat データの初期化
    data_init<LINE_DAT_TYPE>(LINE_DAT_ID, true);
    
    if (argc == 1) {
        return main_noarg();
    } else {
        return main_usearg(argc - 1, argv);
    }

    return 0;
}

int main_noarg() {
    return 0;
}

int main_usearg(int vol, char *arg[]) {
    return 0;
}