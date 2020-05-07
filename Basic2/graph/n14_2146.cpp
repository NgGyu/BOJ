// 다리만들기
#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>
#define MAX 100
using namespace std;
int a[MAX][MAX];
int d[MAX][MAX];
int check[MAX][MAX];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n;
int ans[25 * 25];
void dfs(int x, int y, int cnt);
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%1d", &a[i][j]);
        }
    }
    //dfs
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 1 && check[i][j] == 0) {
                dfs(i, j, ++cnt);
            }
        }
    }
    //섬 push
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            d[i][j] = -1;
            if (a[i][j] == 1) {
                q.push(make_pair(i, j));
                d[i][j] = 0;
            }
        }
    }
    //경계를 넓혀나간다.
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                if (d[nx][ny] == -1) {
                    d[nx][ny] = d[x][y] + 1;
                    check[nx][ny] = check[x][y];
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    //가장 짧은 다리를 구한다.
    int ans = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];
                //현재 점을 기준으로 사방을 체크
                if (0 <= x && x < n && 0 <= y && y < n) {
                    if (check[i][j] != check[x][y]) {
                        if (ans == -1 || ans > d[i][j] + d[x][y]) {
                            ans = d[i][j] + d[x][y];
                        }
                    }
                }
            }
        }
    }
    printf("%d\n", ans);
    /*
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << check[i][j] << " ";
        }
        cout << "\n";
    }
    */
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
            if (a[nx][ny] == 1 && check[nx][ny] == 0) {
                dfs(nx, ny, cnt);
            }
        }
    }
}
