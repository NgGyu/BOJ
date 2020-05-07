#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> a[100001];
int parent[100001];
int order[100001];
bool check[100001];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        cin >> order[i];
    }
    queue<int> q;
    q.push(1);
    check[1] = true;
    int m = 2;
    for (int i = 1; i <= n; i++) {
        int x = q.front(); 
        q.pop();
        int cnt = 0;
        //부모자식관계 기록
        for (int y : a[x]) {
            if (check[y] == false) {
                parent[y] = x;
                cnt += 1;
            }
        }
        //order대로 q에 insert
        for (int j = 0; j < cnt; j++) {
            // x와 order에 있는 원소가 부모자식이 아닌경우
            //cout << parent[order[m + j]]<<" " << x << "\n";
            if (m + j > n || parent[order[m + j]] != x) {
                cout << 0 << '\n';
                return 0;
            }
            q.push(order[m + j]);
            check[order[m + j]] = true;
        }
        m += cnt;
    }
    cout << 1 << '\n';
    return 0;
}
/*
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> a[100000];
bool check[100000];
int main() {
    int n;
    cin >> n;
    for (int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        u -= 1; v -= 1;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    vector<int> b(n);
    vector<int> order(n);
    for (int i=0; i<n; i++) {
        cin >> b[i];
        b[i] -= 1;
        order[b[i]] = i;
    }
    for (int i=0; i<n; i++) {
        sort(a[i].begin(), a[i].end(), [&](const int &u, const int &v) {
            return order[u] < order[v];
        });
    }
    vector<int> bfs_order;
    queue<int> q;
    q.push(0);
    check[0] = true;
    while (!q.empty()) {
        int x = q.front(); q.pop();
        bfs_order.push_back(x);
        for (int y : a[x]) {
            if (check[y] == false) {
                check[y] = true;
                q.push(y);
            }
        }
    }
    if (bfs_order == b) {
        cout << 1 << '\n';
    } else {
        cout << 0 << '\n';
    }
    return 0;
}

*/