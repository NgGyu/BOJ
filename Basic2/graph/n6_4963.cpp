#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int islands[100][100] = {0};
int check[100][100];
int dx[] = { 0,0,1,-1,1,1,-1,-1 };
int dy[] = { 1,-1,0,0,1,-1,1,-1 };
int nRow, nCol;
void dfs(int x, int y, int cnt);
void bfs(int x, int y, int cnt);
int main() {
    
    while (true) {
        
        scanf("%d %d", &nCol, &nRow);
        if (nRow == 0 && nCol == 0) {
            break;
        }
        for (int i = 0; i < nRow; i++) {
            for (int j = 0; j < nCol; j++) {
                scanf("%d", &islands[i][j]);
                check[i][j] = 0;
            }
        }
        int cnt = 0;
        for (int i = 0; i < nRow; i++) {
            for (int j = 0; j < nCol; j++) {
                if (islands[i][j] == 1 && check[i][j] == 0) {
                    bfs(i, j, ++cnt);
                }
            }
        }
        printf("%d\n", cnt);
    }
    
    return 0;
}
void dfs(int x, int y, int cnt) {
    check[x][y] = cnt;
    //std::cout << "x: " << x << ", y: " << y << std::endl;
    for (int k = 0; k < 8; k++) {
        // 이동
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (0 <= nx && nx < nRow && 0 <= ny && ny < nCol) {
            if (islands[nx][ny] == 1 && check[nx][ny] == 0) {
                dfs(nx, ny, cnt);
            }
        }
    }
}
void bfs(int x, int y, int cnt) {
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    check[x][y] = cnt;
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int k = 0; k < 8; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (0 <= nx && nx < nRow && 0 <= ny && ny < nCol) {
                if (islands[nx][ny] == 1 && check[nx][ny] == 0) {
                    q.push(make_pair(nx, ny));
                    check[nx][ny] = cnt;
                }
            }
        }
    }
}