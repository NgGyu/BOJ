#include <iostream>
#include <queue>
using namespace std;
const int MAX = 2000;
bool check[MAX + 1][MAX + 1];
int imo[MAX + 1][MAX + 1];

int main() {
    int n, first, second;
    int mini;
    cin >> n;
    
    queue<pair<int, int>> q;
    q.push(make_pair(1, 0));
    check[1][0] = true;
    imo[1][0] = 0;
    while (!q.empty()) {
        first = q.front().first;
        second = q.front().second;
        q.pop();
        //복사
        if (check[first][first] == false) {
            q.push(make_pair(first, first));
            check[first][first] = true;
            imo[first][first] = imo[first][second] + 1;
        }
        //붙여넣기
        if (first+second < MAX && second!=0) {
            if (check[first+second][second] == false) {
                q.push(make_pair(first + second, second));
                check[first + second][second] = true;
                imo[first + second][second] = imo[first][second] + 1;
                
                if (first + second == n ) {
                    mini = imo[first + second][second];
                    break;
                }
            }
        }
        //삭제
        if (first-1 >= 0) {
            if (check[first-1][second] == false) {
                q.push(make_pair(first-1, second));
                check[first-1][second] = true;
                imo[first-1][second] = imo[first][second] + 1;
                if (first - 1 == n ) {
                    mini = imo[first - 1][second];
                    break;
                }
            }
        }
    }
    cout << mini << '\n';
    return 0;
}