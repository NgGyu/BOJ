#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int chess_board[300][300];
int dx[] = { -2,-1,1,2,2,1,-1,-2 };
int dy[] = { 1,2,2,1,-1,-2,-2,-1 };
int main() {
    int nProblem; // 문제 수
    cin >> nProblem;
    while (nProblem--) {
        int n;
        cin >> n;
        int startX, startY;
        cin >> startX >> startY;
        int destX, destY;
        cin >> destX >> destY;
        // init
        memset(chess_board, -1, sizeof(chess_board));
        queue<pair<int, int>> q;

        //accessed
        q.push(make_pair(startX, startY));
        chess_board[startX][startY] = 0;
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int k = 0; k < 8; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                //경계검사
                if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                    if (chess_board[nx][ny] == -1) {
                        //accessed
                        chess_board[nx][ny] = chess_board[x][y] + 1;
                        q.push(make_pair(nx, ny));
                    }
                }
            }
        }
        cout << chess_board[destX][destY] << '\n';
    }
    return 0;
}
