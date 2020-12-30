#include <iostream>
#include <vector>
using namespace std;

/*
方法一：递推
方法二：奇数后胜，偶数先胜（归纳法可得）
*/

class Solution {
public:
    bool divisorGame(int N) {
        /*vector<bool> win(N+1, 0);//win[i]表示i是否先胜
        for (int i = 1; i <= N; ++i){
            for (int j = 1; j < i; ++j) if (i%j == 0){
                if (!win[i-j]){
                    win[i] = true;
                    break;
                }
            }
        }
        return win[N];*/
        return 1-N%2;
    }
};

int main(){
    Solution s;
    int n = 30;
    for (int i = 1; i < n; ++i){
        cout << i << ": " << s.divisorGame(i) << endl;
    }
    return 0;
}