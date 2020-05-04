#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
void dfs(int x, int nV, bool* check, vector<int>* graph);
void bfs(int x, int nV, bool* check, vector<int>* graph);
int main() {
    int nV, nE, start;
    cin >> nV >> nE >> start;
    vector<int> graph[101];
    bool check[101];
    int s, d;
    for (int i = 0; i < nE; i++) {
        cin >> s >> d;
        graph[s].push_back(d);
        graph[d].push_back(s);
    }
    //정렬
    for (int i = 1; i <= nV; i++) {
        sort(graph[i].begin(), graph[i].end());
    }
    
    memset(check, false, sizeof(check));
    dfs(start, nV, check, graph);
    cout << "\n";
    memset(check, false, sizeof(check));
    bfs(start, nV, check, graph);
    
    return 0;
}

void dfs(int x, int nV, bool* check, vector<int>* graph) {
    check[x] = true;
    cout << x << " ";
    for (int i = 0; i < graph[x].size(); i++) {
        int dest = graph[x][i];
        if (check[dest] == false) {
            dfs(dest, nV, check, graph);
        }
    }
}
void bfs(int start, int nV, bool* check, vector<int>* graph) {
    queue<int> q;
    check[start] = true;
    q.push(start);
    while (!q.empty()) {
        int x = q.front();
        cout << x << " ";
        q.pop();
        for (int i = 0; i < graph[x].size(); i++) {
            int dest = graph[x][i];
            if (check[dest] == false) {
                check[dest] = true;
                q.push(dest);
            }
        }
    }
}