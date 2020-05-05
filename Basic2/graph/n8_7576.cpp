#include <cstdio>
#include <queue>
using namespace std;
int tomato[1000][1000];
int dist[1000][1000];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int main() {
    int n, m;
    scanf("%d %d", &m, &n);
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &tomato[i][j]);
            dist[i][j] = -1;
            if (tomato[i][j] == 1) {
                q.push(make_pair(i, j));
                dist[i][j] = 0;
            }
        }
    }
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                //a[][]==0 : unaccessed
                if (tomato[nx][ny] == 0 && dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    //최다 일수 구하기
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (ans < dist[i][j]) {
                ans = dist[i][j];
            }
        }
    }
    //아직 도달하지 못한점이 있다면 -1
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (tomato[i][j] == 0 && dist[i][j] == -1) {
                ans = -1;
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}