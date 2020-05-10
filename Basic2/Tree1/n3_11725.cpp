#include <iostream>
#include <queue>
#define MAX 100000
using namespace std;
int parent[MAX+1];
int depth[MAX+1];
bool check[MAX+1];
vector<int> g[MAX + 1];
int main() {
    int n, x, y;
    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    //dfs bfs둘다 가능
    queue<int> q;
    depth[1] = 0;
    check[1] = true;
    parent[1] = 0; 
    q.push(1);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int y : g[x]) {
            if (!check[y]) {
                depth[y] = depth[x] + 1;
                check[y] = true;
                parent[y] = x;
                q.push(y);
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        cout << parent[i] << '\n';
    }
    return 0;
}