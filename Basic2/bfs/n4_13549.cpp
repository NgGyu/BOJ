#include <iostream>
#include <queue>
#include <deque>
using namespace std;
const int MAX = 200000; //200000까지 갈 수 있음
bool check[MAX + 1];
int time_taken[MAX + 1];
int main() {
    int n, m;
    cin >> n >> m;
    check[n] = true;
    time_taken[n] = 0;
    deque<int> q;
    q.push_back(n);
    while (!q.empty()) {
        int curr = q.front();
        q.pop_front();
        if (curr * 2 < MAX) {
            if (check[curr * 2] == false) {
                q.push_front(curr * 2);
                check[curr * 2] = true;
                time_taken[curr * 2] = time_taken[curr];
            }
        }
        
        if (curr - 1 >= 0) {
            if (check[curr - 1] == false) {
                q.push_back(curr - 1);
                check[curr - 1] = true;
                time_taken[curr - 1] = time_taken[curr] + 1;
            }
        }
        if (curr + 1 < MAX) {
            if (check[curr + 1] == false) {
                q.push_back(curr + 1);
                check[curr + 1] = true;
                time_taken[curr + 1] = time_taken[curr] + 1;
            }
        }
        
    }
    cout << time_taken[m] << '\n';
    return 0;
}