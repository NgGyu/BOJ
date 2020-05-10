#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int check(int len, std::vector<int>& ans, int* sign) {
    
    int sum = 0;
    int tmp;
    for (int i = len; i >= 0; i--) {
        tmp = *(sign + i * 10 + len);
        //std::cout << tmp << " ";
        sum += ans[i];
        if (tmp == 0) {
            if (sum != 0) return false;
        }
        else if (tmp < 0) {
            if (sum >= 0) return false;
        }
        else if (tmp > 0) {
            if (sum <= 0) return false;
        }
    }
    //std::cout << "\n";
    return 1;
}

int f(int n, int len, int*sign, std::vector<int>& ans) {
    
    if (len == n) {
        return 1;
    }
    int tmp = *(sign + len * 10 + len);
    if (tmp != 0) {
        for (int i = 1; i <= 10; i++) {
            // int to char
            ans.push_back(i * tmp);
            if (check(len, ans, sign) && f(n, len + 1, sign, ans)) {
                return 1;
            }
            ans.pop_back();
        }
    }
    else{
        ans.push_back(0);
        
        if (check(len, ans, sign) && f(n, len + 1, sign, ans)) {
            return 1;
        }
        ans.pop_back();
    }
    return 0;
}


int main() {
    int n;
    std::cin >> n;
    int sign[10][10] = {0};
    char inequal[100] = {0};
    char tmp = 0;
    for (int i = 0; i < n*(n+1)/2; i++) {
        std::cin >> inequal[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (inequal[tmp] == '0') {
                sign[i][j] = 0;
            }
            else if (inequal[tmp] == '+') {
                sign[i][j] = 1;
            }
            else {
                sign[i][j] = -1;
            }
            tmp++;
        }
    }
    std::vector<int> ans;
 
    
    f(n, 0, (int*)sign, ans);
    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i] << ' ';
    }
    std::cout << '\n';
    return 0;
}