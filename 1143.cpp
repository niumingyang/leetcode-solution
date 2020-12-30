#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

/*
LCS问题
dp[i][j]表示text1[0...i-1]与text2[0...j-1]的LCS长度
若text1[i] == text2[i], dp[i+1][j+1] = dp[i][j]+1;
否则dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1])
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int dp[text1.size()+1][text2.size()+1];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < text1.size(); ++i)
            for (int j = 0; j < text2.size(); ++j){
                if (text1[i] == text2[j]) dp[i+1][j+1] = dp[i][j]+1;
                else dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
            }
        return dp[text1.size()][text2.size()];
    }
};

int main(){
    return 0;
}