#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/*
暴力+技巧
计算每个i，以s[i]开头的最长字符串
计算s[i+1]时可以利用s[i]的结果
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> occ;
        int n = s.size();
        int rk = -1, ans = 0;
        for (int i = 0; i < n; ++i) {
            if (i != 0) {
                occ.erase(s[i - 1]);
            }
            while (rk + 1 < n && !occ.count(s[rk + 1])) {
                occ.insert(s[rk + 1]);
                ++rk;
            }
            ans = max(ans, rk - i + 1);
        }
        return ans;
    }
};

int main(){
    Solution s;
    cout << s.lengthOfLongestSubstring("abba");
    cout << s.lengthOfLongestSubstring("aabaab!bb");
    return 0;
}