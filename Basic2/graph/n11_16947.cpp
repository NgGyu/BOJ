#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> stations[3000]; // 인접리스트
int check[3000]; // 0: not visited, 1: visited, 2: cycle
int dist_from_cycle[3000];
int find_cycle(int curr_node, int prev_node) {
    // -2: found cycle and not included
    // -1: not found cycle
    // 0~n-1: found cycle and start index
    if (check[curr_node] == 1) {
        return curr_node; 
    }
    check[curr_node] = 1;
    for (int next_node : stations[curr_node]) {
        if (next_node == prev_node) continue;
        int res = find_cycle(next_node, curr_node);
        if (res == -2) return -2;
        if (res >= 0) {
            check[curr_node] = 2;
            if (curr_node == res) return -2; // cycle 시작점
            else return res; //cycle포함, not 시작점
        }
    }
    return -1; // no cycle
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u -= 1; v -= 1;
        stations[u].push_back(v);
        stations[v].push_back(u);
    }
    find_cycle(0, -1); //dfs : 어디가 cycle인지 체크

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (check[i] == 2) {
            dist_from_cycle[i] = 0;
            q.push(i);
        }
        else {
            dist_from_cycle[i] = -1;
        }
    }
    while (!q.empty()) {
        int x = q.front(); 
        q.pop();
        for (int y : stations[x]) {
            if (dist_from_cycle[y] == -1) { //not cycle
                q.push(y);
                dist_from_cycle[y] = dist_from_cycle[x] + 1; 
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << dist_from_cycle[i] << ' ';
    }
    cout << '\n';
    return 0;
}

