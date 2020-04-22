#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
//모음 자음 갯수 확인
bool check(string& password) {
    int ja = 0;
    int mo = 0;
    for (char x : password) {
        if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
            mo += 1;
        }
        else {
            ja += 1;
        }
    }
    return ja >= 2 && mo >= 1;
}
void go(int n, vector<char>& alpha, string password, int i) {
    if (password.length() == n) {
        if (check(password)) {
            cout << password << '\n';
        }
        return;
    }
    if (i == alpha.size()) return;
    //현재 문자 사용
    go(n, alpha, password + alpha[i], i + 1);
    //현재 문자 사용X
    go(n, alpha, password, i + 1);
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<char> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    go(n, a, "", 0);

    return 0;
}