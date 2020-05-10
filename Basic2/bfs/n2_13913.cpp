#include <iostream>
#include <queue>
using namespace std;
const int MAX = 200000; //200000까지 갈 수 있음
bool check[MAX + 1];
int time_taken[MAX + 1];
int parent[MAX + 1] = {0};
// timeline 출력
void print(int n, int m) {
    if (n != m) {
        print(n, parent[m]);
    }
    cout << m << ' ';
}
int main() {
    int n, m;
    cin >> n >> m;
    check[n] = true;
    time_taken[n] = 0;
    queue<int> q;
    q.push(n);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        if (curr - 1 >= 0) {
            if (check[curr - 1] == false) {
                q.push(curr - 1);
                check[curr - 1] = true;
                parent[curr - 1] = curr;
                time_taken[curr - 1] = time_taken[curr] + 1;
            }
        }
        if (curr + 1 < MAX) {
            if (check[curr + 1] == false) {
                q.push(curr + 1);
                check[curr + 1] = true;
                parent[curr + 1] = curr;
                time_taken[curr + 1] = time_taken[curr] + 1;
            }
        }
        if (curr * 2 < MAX) {
            if (check[curr * 2] == false) {
                q.push(curr * 2);
                check[curr * 2] = true;
                parent[curr * 2] = curr;
                time_taken[curr * 2] = time_taken[curr] + 1;
            }
        }
    }
    cout << time_taken[m] << '\n';
    print(n, m);
    return 0;
}