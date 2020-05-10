// bfs 2번하는 풀이
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
struct Edge {
    int to;
    int cost;
    Edge(int to, int cost) : to(to), cost(cost) {
    }
};
vector<Edge> a[100001];
bool check[100001];
int dist[100001];
void bfs(int start) {
    memset(dist,0,sizeof(dist));
    memset(check,false,sizeof(check));
    queue<int> q;
    check[start] = true;
    q.push(start);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i=0; i<a[x].size(); i++) {
            Edge &e = a[x][i];
            if (check[e.to] == false) {
                dist[e.to] = dist[x] + e.cost;
                q.push(e.to);
                check[e.to] = true;
            }
        }
    }
}
int main() {
    int n;
    scanf("%d",&n);
    for (int i=0; i<n-1; i++) {
        int u, v, w;
        scanf("%d %d %d",&u,&v,&w);
        a[u].push_back(Edge(v,w));
        a[v].push_back(Edge(u,w));
    }
    //1번 정점에서 가장 먼 점 start 구함
    bfs(1);
    int start = 1;
    for (int i=2; i<=n; i++) {
        if (dist[i] > dist[start]) {
            start = i;
        }
    }
    //start에서 가장 먼점 구함
    bfs(start);
    int ans = dist[1];
    for (int i=2; i<=n; i++) {
        if (ans < dist[i]) {
            ans = dist[i];
        }
    }
    printf("%d\n",ans);
    return 0;
}
//postorder이용
/*
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
struct Edge {
    int to;
    int cost;
    Edge(int to, int cost) : to(to), cost(cost) {
    }
};
vector<Edge> a[10001];
bool check[10001];
pair<int, int> dfs(int x) { // first: diameter, second: height
    check[x] = true;
    vector<int> heights;
    int ans = 0;
    //Post order
    for (auto &e : a[x]) {
        int y = e.to;
        int cost = e.cost;
        if (check[y] == false) {
            auto p = dfs(y);
            if (ans < p.first) ans = p.first;
            heights.push_back(p.second+cost);
        }
    }
    //자손만 포함했을 때 가장 긴 높이 구함
    int height = 0;
    sort(heights.begin(), heights.end());
    reverse(heights.begin(), heights.end());
    //자식 하나일때의 지름
    if (heights.size() >= 1) {
        height = heights[0];
        if (ans < height) {
            ans = height;
        }
    }
    //자식이 둘이상일때의 지름
    if (heights.size() >= 2) {
        if (ans < heights[0] + heights[1]) {
            ans = heights[0] + heights[1];
        }
    }
    return make_pair(ans, height);
}
int main() {
    int n;
    scanf("%d",&n);
    for (int i=0; i<n-1; i++) {
        int u, v, w;
        scanf("%d %d %d",&u,&v,&w);
        a[u].push_back(Edge(v,w));
        a[v].push_back(Edge(u,w));
    }
    auto ans = dfs(1);
    cout << ans.first << '\n';
    return 0;
}
*/