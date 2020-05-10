#include <iostream>
#include <queue>
using namespace std;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
const int MAX = 100; 
int check[MAX][MAX];
int cost[MAX][MAX];
struct cmp {
    bool operator()(pair<int, int> t, pair<int, int> u) {
        int tRow = t.first;
        int tCol = t.second;
        int uRow = u.first;
        int uCol = u.second;
        return cost[tRow][tCol] > cost[uRow][uCol];
    }
};
int main() {
    int nCol, nRow;
    cin >> nCol >> nRow;
    for (int i = 0; i < nRow; i++) {
        for (int j = 0; j < nCol; j++) {
            scanf("%1d", &check[i][j]);
        }
    }
    /*
    check;
    1: wall, 0: not checked, -1: checked
    */
    int x, y;
    priority_queue< pair<int, int>,
        vector<pair<int, int>>,
        cmp > pq;
    pq.push(make_pair(0, 0));
    check[0][0] = -1;
    /*
    for (int i = 0; i < nRow; i++) {
        for (int j = 0; j < nCol; j++) {
            cout << cost[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    */
    while (!pq.empty()) {
        x = pq.top().first;
        y = pq.top().second;
        //cout << "x: " << x << ", y: " << y << "\n";
        pq.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            //경계검사
            if (0 <= nx && nx < nRow && 0 <= ny && ny < nCol) {
                //not checked 
                if (check[nx][ny] == 0) {
                    cost[nx][ny] = cost[x][y];
                    pq.push(make_pair(nx, ny));
                    check[nx][ny] = -1;
                }else if (check[nx][ny] == 1) {
                    cost[nx][ny] = cost[x][y] + 1;
                    pq.push(make_pair(nx, ny));
                    check[nx][ny] = -1;
                }
            }
        }
        /*
        for (int i = 0; i < nRow; i++) {
            for (int j = 0; j < nCol; j++) {
                cout << cost[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
        */
    }
    cout << cost[nRow-1][nCol-1];
    return 0;
}
/*
#include <iostream>
#include <cstdio>
#include <deque>
using namespace std;
int d[555][555];
int a[555][555];
int n,m;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int main() {
    scanf("%d %d",&m,&n);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%1d",&a[i][j]);
            d[i][j] = -1;
        }
    }
    deque<pair<int,int>> q;
    q.push_back(make_pair(0,0));
    d[0][0] = 0;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop_front();
        for (int k=0; k<4; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (d[nx][ny] == -1) {
                    if (a[nx][ny] == 0) {
                        d[nx][ny] = d[x][y];
                        q.push_front(make_pair(nx,ny));
                    } else {
                        d[nx][ny] = d[x][y]+1;
                        q.push_back(make_pair(nx,ny));
                    }
                }
            }
        }
    }
    printf("%d\n",d[n-1][m-1]);
    return 0;
}
*/