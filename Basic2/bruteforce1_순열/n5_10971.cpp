#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;
int main() {
    int n, sum, dist;
    int isRoute;
    int ans = 999999999;
    cin >> n;
    vector<int> perm(n);
    int map[11][11];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
        perm[i] = i;
    }

    //sort(perm.begin(), perm.end());
    do {
        sum = 0;
        isRoute = 1;
        for (int i = 0; i < n; i++) {
            dist = map[perm[i % n]][perm[(i+1) % n]];
            if (dist == 0) {
                isRoute = 0;
                break;
            }
            sum += dist;
        }
        if (isRoute==1) {
            /*
            for (int i = 0; i < n; i++) {
                cout << perm[i] << " ";
            }
            cout << sum;
            cout << "\n";
            */
            ans = min(ans, sum);
        }
    } while (next_permutation(perm.begin()+1, perm.end())); 
    // 원형이므로 시작 점은 고정 되어도 된다.

    cout << ans;
    return 0;
}