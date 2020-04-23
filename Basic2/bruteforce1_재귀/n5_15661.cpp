#include <iostream>
#include <vector>
#include <cmath>


int score[21][21] ;
int n;
int ans = 0;
int f(int index, std::vector<int> &inStart, std::vector<int> &inLink) {
    
    if (index == n) {
        
        int t1 = 0;
        int t2 = 0;
        for (int i = 0; i < inStart.size(); i++) {
            for (int j = 0; j < inStart.size(); j++) {
                if (i == j) continue;
                t1 += score[inStart[i]][inStart[j]];
            }
        }

        for (int i = 0; i < inLink.size(); i++) {
            for (int j = 0; j < inLink.size(); j++) {
                if (i == j) continue;
                t2 += score[inLink[i]][inLink[j]];
            }
        }
        
        return abs(t1-t2);
    }
    

    int ans = -1;

    inStart.push_back(index);
    int t1 = f(index + 1, inStart, inLink);
    inStart.pop_back();
    if (ans == -1 || (t1 != -1 && ans > t1)) {
        ans = t1;
    }

    inLink.push_back(index);
    int t2 = f(index + 1, inStart, inLink);
    inLink.pop_back();
    if (ans == -1 || (t2 != -1 && ans > t2)) {
        ans = t2;
    }
    return ans;
}
int main() {
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> score[i][j];
        }
    }

    std::vector<int> inStart, inLink;
    std::cout << f(0, inStart, inLink) << '\n';
    return 0;
}