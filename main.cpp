#include "evaluator/cevaluator.hpp"
#include "evaluator/csquares.hpp"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// プロトタイプ宣言

int main_noarg();
int main_usearg(int, char *[]);

int playgame(int);

// グローバル変数
CEVALUATOR cev;

/*
コマンドライン引数でファイル名を指定した場合、そのファイルの操作をする
*/
int main(int argc, char *argv[]) {
    // line.dat データが存在しなかったら作成する
    data_init<LINE_DAT_TYPE>(LINE_DAT_ID, false);

    // データをセット

    LINE_DAT_TYPE *ldat;
    ldat = new LINE_DAT_TYPE[LINE_DAT_SIZE];

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
    int ex = false;
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
                ex = true;
                break;
            }
            if (ex) {
                break;
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

    CSQUARES csq;
    int t;
    int nextmove;
    string temp;
    int winner;
    int moves[64];

    for (int i = 0; i < 64; i++) {
        moves[i] = -1;
    }
    
    // ゲームループ
    while(1) {
        csq.cout_board();
        cev.evaluate(csq);
        cout << "評価値 : " << cev.get_now_evaluation() << endl;
        t = csq.player_corrent_turn();
        temp = (t == 1) ? "先手" : "後手";
        cout << (csq.get_turn() + 1) << "ターン目:" << temp << "のターンです" << endl;
        cout << "次の手を入力してください" << endl;
        if (p_ai[t - 1]) {
            cout << "AI > ";
            nextmove = cev.get_next_bestmove();
            cout << (int(nextmove / 4 + 1) * 10 + (nextmove % 4 + 1)) << endl;
        } else {
            cout << "user > ";
            cin >> sinput;
            input = stoi(sinput);
            if (
                (1 <= (input % 10) && (input % 10) <= 4) &&
                (1 <= int(input /10) && int(input / 10) <= 4)
            ) {
                nextmove = int(input / 10 - 1) * 4 + input % 10 - 1;
            } else {
                cout << "存在しない手です" << endl;
                continue;
            }
        }
        if (!csq.move(int(nextmove / 4), nextmove % 4)) {
            cout << "その手は指せません" << endl;
            continue;
        }
        moves[csq.get_turn() - 1] = nextmove;
        winner = csq.judge_winner();
        if (winner != 0) {
            break;
        }
    }
    
    csq.cout_board();
    temp = (winner == 1) ? "先手" : "後手";
    cout << temp << "の勝利です" << endl;

    cout << endl;
    cout << "今ゲームの棋譜" << endl;
    for (int i = 0; i < 64; i++) {
        if (moves[i] == -1) {
            break;
        }
        if (i % 2 == 0) {
            cout << "先手";
        } else {
            cout << "後手";
        }
        cout << (int)(moves[i] / 4 + 1) << (int)(moves[i] % 4 + 1);
        if (i % 2 == 0) {
            cout << " ";
        } else {
            cout << endl;
        }
    }

    return 0;
}