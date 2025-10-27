#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int N = 20; 
char board[N][N];

// 检查某个玩家是否在棋盘上胜利
bool checkWin(int n, char player) {
    // 水平检查
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= n - 5; ++j) {
            bool ok = true;
            for (int k = 0; k < 5; ++k) {
                if (board[i][j + k] != player) {
                    ok = false;
                    break;
                }
            }
            if (ok) return true;
        }
    }

    // 垂直检查
    for (int i = 0; i <= n - 5; ++i) {
        for (int j = 0; j < n; ++j) {
            bool ok = true;
            for (int k = 0; k < 5; ++k) {
                if (board[i + k][j] != player) {
                    ok = false;
                    break;
                }
            }
            if (ok) return true;
        }
    }

    // 左上到右下检查
    for (int i = 0; i <= n - 5; ++i) {
        for (int j = 0; j <= n - 5; ++j) {
            bool ok = true;
            for (int k = 0; k < 5; ++k) {
                if (board[i + k][j + k] != player) {
                    ok = false;
                    break;
                }
            }
            if (ok) return true;
        }
    }

    // 右上到左下检查
    for (int i = 0; i <= n - 5; ++i) {
        for (int j = 4; j < n; ++j) {
            bool ok = true;
            for (int k = 0; k < 5; ++k) {
                if (board[i + k][j - k] != player) {
                    ok = false;
                    break;
                }
            }
            if (ok) return true;
        }
    }

    return false;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> board[i][j];
            }
        }

        bool ok1 = checkWin(n, 'B');
        bool ok2 = checkWin(n, 'W');

        if (ok1) {
            cout << "Black" << endl;
        } else if (ok2) {
            cout << "White" << endl;
        } else {
            cout << "Not so fast" << endl;
        }
    }

    return 0;
}
