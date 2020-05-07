#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> a[100000];
bool check[100000];
void dfs(int x);
vector<int> dfs_order(n);
int main() {
    
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u -= 1; v -= 1;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    vector<int> b(n);
    vector<int> order(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        b[i] -= 1;
        order[b[i]] = i; //order는 정렬할 수 있게 만들어주는 key
    }
    for (int i = 0; i < n; i++) {
        sort(a[i].begin(), a[i].end(), [&](const int& u, const int& v) {
            return order[u] < order[v];
        });
    }
    check[0] = 1;
    dfs_order.push_back(0);
    dfs(0);
    //cout <<'\n';
    /*
    for (int i = 0; i < dfs_order.size(); i++) {
        cout << dfs_order[i] << " ";
    }
    cout << '\n';
    for (int i = 0; i < b.size(); i++) {
        cout << b[i] << " ";
    }
    cout << '\n';
    */
    if (dfs_order == b) {
        cout << 1 << '\n';
    }
    else {
        cout << 0 << '\n';
    }
    return 0;
}
void dfs(int x) {
    //cout << x << " ";
    for (int y : a[x]) {
        
        if (check[y] == 0) {
            dfs_order.push_back(y);
            check[y] = 1;
            dfs(y);
        }
        
    }
}