#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
void dfs(int x, int nV, bool* check, vector<int>* graph);
int main() {
    int nV, nE;
    cin >> nV >> nE;
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
    int cnt = 0;
    for (int i = 1; i <= nV; i++) {
        if (check[i] == false) {
            dfs(i, nV, check, graph);
            cnt++;
        }
    }
    cout << cnt;

    
    return 0;
}

void dfs(int x, int nV, bool* check, vector<int>* graph) {
    check[x] = true;
    for (int i = 0; i < graph[x].size(); i++) {
        int dest = graph[x][i];
        if (check[dest] == false) {
            dfs(dest, nV, check, graph);
        }
    }
}