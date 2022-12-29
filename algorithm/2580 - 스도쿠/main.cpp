#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> p;

int N;
int board[10][10];
vector<p> position;
bool flag = false;

bool is_valid(int y, int x) {
    for (int i=0; i<9; i++) {
        if (board[y][x] == board[y][i] && i != x) return false;
        if (board[y][x] == board[i][x] && i != y) return false;
    }

    int coord_y = y / 3;
    int coord_x = x / 3;
    for (int row = 3*coord_y; row < 3*coord_y+3; row++) {
        for (int col = 3*coord_x; col < 3*coord_x+3; col++) {
            if (row == y && col == x) continue;
            if (board[y][x] == board[row][col]) return false;
        }
    }

    return true;
}

void draw_sdoku() {
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++)
            cout << board[i][j] << ' ';
        cout << "\n";
    }
    return;
}

void sdoku(int cnt) {
    for (int num=1; num<=9; num++) {
        board[position[cnt].first][position[cnt].second] = num;
        if (is_valid(position[cnt].first, position[cnt].second)) {
            if (N-1 == cnt) {
                flag = true;
                draw_sdoku();
                return;
            } else {
                sdoku(cnt + 1);
            }
        }
        if (flag) return;
    }
    board[position[cnt].first][position[cnt].second] = 0;
    return;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            cin >> board[i][j];
            if (board[i][j] == 0) {
                N++;
                position.push_back({i, j});
            }
        }
    }
    sdoku(0);
    return 0;
} 