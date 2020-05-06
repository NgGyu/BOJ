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