#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
bool isBipartite(int x, int color, int* check, vector<int>* graph);  
int main() {
    int nProblem;
    int nV, nE;
    vector<int> graph[20001];
    int check[20001];
    cin >> nProblem;
    while(nProblem--) {
        int nV, nE;
        cin >> nV >> nE;
        for (int i = 1; i <= nV; i++) {
            graph[i].clear();
            check[i] = 0;
        }
        int s, d;
        for (int i = 0; i < nE; i++) {
            cin >> s >> d;
            graph[s].push_back(d);
            graph[d].push_back(s);
        }
        
        
        memset(check, 0, sizeof(check));
        bool ok = true;
        for (int i = 1; i <= nV; i++) {
            if (check[i] == 0) {
                if (isBipartite(i, 1, check, graph) == false) {
                    ok = false;
                }
            }
        }
        printf("%s\n", ok ? "YES" : "NO");
    }
    return 0;
}
//dfs
bool isBipartite(int x, int color, int* check, vector<int>* graph) {
    check[x] = color;
    for (int i = 0; i < graph[x].size(); i++) {
        int dest = graph[x][i];
        if (check[dest] == 0) {
            //false : direct end
            if (isBipartite(dest, -color, check, graph)==false) {
                return false;
            }
        }else if (check[dest] == check[x]) {
            return false;
        }
        
    }
    // 자식 노드들에서 bipartite조건에 맞아야 root에서 return true
    return true;
}