#include <iostream>
#include <vector>
using namespace std;

/*
dp[i][j]��ʾ����key[i]ʱringͣ��λ��j����С����
dp[i][j] = Min_t(dp[i-1][t] + ��t�ƶ���j�Ĳ���)
ʱ��O(nm^2)
*/

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int max_num = 1000000000;
        int m = ring.size(), n = key.size();
        int dp[n][m];
        for (int j = 0; j < m; ++j){
            if (ring[j] == key[0])
                dp[0][j] = min(j+1, m-j+1);
            else dp[0][j] = max_num;
        }
        for (int i = 1; i < n; ++i){
            for (int j = 0; j < m; ++j){
                if (ring[j] != key[i]) dp[i][j] = max_num;
                else {
                    dp[i][j] = max_num;
                    for (int t = 0; t < m; ++t){
                        dp[i][j] = min(dp[i][j], dp[i-1][t]+min(abs(t-j), m-abs(t-j))+1);
                    }
                }
            }
        }
        int ret = max_num;
        for (int j = 0; j < m; ++j)
            ret = min(ret, dp[n-1][j]);
        // for (int i = 0; i < n; ++i){
        //     for (int j = 0; j < m; ++j)
        //         cout << dp[i][j] << ' ';
        //     cout << endl;
        // }
        return ret;
    }
};

int main(){
    string Ring = "godding", Key = "goddig";
    Solution s;
    cout << s.findRotateSteps(Ring, Key);
    return 0;
}