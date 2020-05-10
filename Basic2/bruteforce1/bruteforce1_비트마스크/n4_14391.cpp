#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[16];
int main() {
    int nRow, nCol;
    scanf("%d %d", &nRow, &nCol);
    for (int i = 0; i < nRow * nCol; i++) {
        scanf("%1d", &a[i]);
    }
    int ans = 0;
    int sum, cur;
    for (int s = 0; s < (1 << (nRow * nCol)); s++) {
        sum = 0;
        for (int i = 0; i < nRow; i++) {
            cur = 0;
            for (int j = 0; j < nCol; j++) {
                int idx = i * nCol + j;
                //가로
                if ((s & (1 << idx)) == 0) {
                    cur = cur * 10 + a[idx];
                }
                else {
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }

        for (int i = 0; i < nCol; i++) {
            cur = 0;
            for (int j = 0; j < nRow; j++) {
                int idx = nCol * j + i;
                //세로
                if ((s & (1 << idx)) != 0) {
                    cur = cur * 10 + a[idx];
                }
                else {
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }
        ans = max(ans, sum);
    }
    cout << ans << '\n';

    return 0;
}