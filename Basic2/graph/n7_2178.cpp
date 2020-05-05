#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
int maze[101][101];
int check[101][101];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int nRow, nCol;
int ans[25 * 25];
void bfs(int x, int y, int cnt);
int main() {
    scanf("%d %d", &nRow, &nCol);
    for (int i = 0; i < nRow; i++) {
        for (int j = 0; j < nCol; j++) {
            scanf("%1d", &maze[i][j]);
        }
    }
    bfs(0, 0, 1);
    printf("%d", check[nRow - 1][nCol - 1]);
    return 0;
}

void bfs(int x, int y, int cnt) {
    //init
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    check[x][y] = cnt;

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        cnt = check[x][y];
        cnt++;
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            //경계검사
            if (0 <= nx && nx < nRow && 0 <= ny && ny < nCol) {
                //아직 체크하지않은 아파트 
                if (maze[nx][ny] == 1 && check[nx][ny] == 0) {
                    q.push(make_pair(nx, ny));
                    check[nx][ny] = cnt;
                }
            }
        }
    }
}