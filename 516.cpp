#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

/*
区间dp:
dp[i][j]表示[i, j]最长子序列的长度
若s[i]==s[j],方法数为dp[i+1][j-1]+2
若s[i]!=s[j],方法数为max(dp[i+1][j], dp[i][j-1])
实质上是s与其逆序的LCS
*/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int dp[s.size()][s.size()];
        for (int i = 0; i < s.size(); ++i)
            dp[i][i] = 1;
        for (int i = s.size()-1; i >=0; --i)
            for (int j = 0; j < s.size(); ++j) if (i < j){
                if (s[i]==s[j]){
                    if (i+1 == j) dp[i][j] = 2;
                    else dp[i][j] = dp[i+1][j-1]+2;
                }
                else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        return dp[0][s.size()-1];
    }
};

int main(){
    Solution s;
    cout << s.longestPalindromeSubseq("bbbab");
    return 0;
}