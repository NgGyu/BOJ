#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, n, x, y;
        cin >> m >> n >> x >> y;
        x -= 1;
        y -= 1;
        bool flag = false;
        for (int k=x; k<(n*m); k+=m) {
            if (k%n == y) {
                cout << k+1 << '\n';
                flag = true;
                break;
            }
        }
        if (!flag) {
            cout << -1 << '\n';
        }
    }
    return 0;
}