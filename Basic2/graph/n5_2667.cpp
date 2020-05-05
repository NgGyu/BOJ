//인접행렬, 인접그래프 불필요
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
int apartment[30][30];
int check[30][30];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n;
int ans[25 * 25];
void dfs(int x, int y, int cnt);
void bfs(int x, int y, int cnt);
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%1d", &apartment[i][j]);
        }
    }
    //dfs
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (apartment[i][j] == 1 && check[i][j] == 0) {
                bfs(i, j, ++cnt);
            }
        }
    }
    printf("%d\n", cnt);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //printf("%d ", check[i][j]);
            ans[check[i][j]] += 1;
        }
        //printf("\n");
    }
    sort(ans + 1, ans + cnt + 1);
    for (int i = 1; i <= cnt; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
void dfs(int x, int y, int cnt) {
    check[x][y] = cnt;
    for (int k = 0; k < 4; k++) {
        // 이동
        int nx = x + dx[k];
        int ny = y + dy[k];
        //경계검사
        if (0 <= nx && nx < n && 0 <= ny && ny < n) {
            //아직 체크하지않은 아파트 
            if (apartment[nx][ny] == 1 && check[nx][ny] == 0) {
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
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            //경계검사
            if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                //아직 체크하지않은 아파트 
                if (apartment[nx][ny] == 1 && check[nx][ny] == 0) {
                    q.push(make_pair(nx, ny));
                    check[nx][ny] = cnt;
                }
            }
        }
    }
}