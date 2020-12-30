#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

/*
0-1背包问题，暴力dp
dp[i][j][k] = max(dp[i-1][j-0_of_strs[i]][k-1_of_strs[i]], dp[i-1][j][k])
优化：去掉i维度（滚动数组）
*/

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int dp[strs.size()+1][m+1][n+1];
        memset(dp, 0, sizeof(dp));
        int cnt0, cnt1;
        for (int i = 1; i <= strs.size(); ++i){
            cnt0 = cnt1 = 0;
            for (int p = 0; p < strs[i-1].size(); ++p){
                if (strs[i-1][p] == '0') cnt0++;
                else if (strs[i-1][p] == '1') cnt1++;
            }
            for (int j = 0; j <= m; ++j){
                for (int k = 0; k <= n; ++k){
                    if (j-cnt0 < 0 || k-cnt1 < 0) dp[i][j][k] = dp[i-1][j][k];
                    else dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j-cnt0][k-cnt1]+1);
                }
            }
        }
        return dp[strs.size()][m][n];
    }
};

int main(){
    Solution s;
    vector<string> v = {"10","0","1"};
    cout << s.findMaxForm(v, 1, 1);
    return 0;
}