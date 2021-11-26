#include "evaluator/cevaluator.hpp"
#include "evaluator/csquares.hpp"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// プロトタイプ宣言

int main_noarg();
int main_usearg(int, char *[]);

int play_game(int);

// グローバル変数
CEVALUATOR cev;

/*
コマンドライン引数でファイル名を指定した場合、そのファイルの操作をする
*/
int main(int argc, char *argv[]) {
    // line.dat データが存在しなかったら作成する
    data_init<LINE_DAT_TYPE>(LINE_DAT_ID, false);

    LINE_DAT_TYPE *ldat;
    data_get(LINE_DAT_ID, ldat);
    cev.data_set(LINE_DAT_ID, ldat);

    if (argc == 1) {
        return main_noarg();
    } else {
        return main_usearg(argc - 1, argv);
    }

    return 0;
}

int main_noarg() {
    string smenu;
    int menu;
    bool ex = false;
    while (1) {
        cout << "【MENU】" << endl;
        cout << "1. CPUと対戦" << endl;
        cout << "2. CPU同士で対戦" << endl;
        cout << "3. プレイヤー同士で対戦" << endl;
        cout << "0. 終了" << endl;
        cout << "user > ";
        getline(cin, smenu);
        menu = stoi(smenu);
        switch(menu) {
            case 1:
            case 2:
            case 3:
            playgame(menu);
            break;
            case 0:
            ex = true;
            break;
            default:
            cout << "無効な入力" << endl;
        }
        if (ex) {
            break;
        }
    }
    return 0;
}

int main_usearg(int vol, char *arg[]) {
    return 0;
}

int playgame(int menu) {
    string sinput;
    int input;
    bool p_ai[2] = {false, false};

    /*
    1. CPUと対戦
    2. CPU同士で対戦
    3. プレイヤー同士で対戦
    */
    switch (menu) {
        case 1:
        while(1) {
            cout << "プレイヤーが先手なら1, 後手なら2, ランダムなら3を入力" << endl;
            cout << "user > ";
            getline(cin, sinput);
            input = stoi(sinput);
            switch(input) {
                case 1:
                case 2:
                p_ai[input % 2] = true;
            }
        }
        break;
        case 2:
        p_ai[0] = true;
        p_ai[1] = true;
        break;
        case 3:
        break;
        default:
        return 0;
    }

    int nextmove;

    return 0;
}