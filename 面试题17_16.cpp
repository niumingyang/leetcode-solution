#include <iostream>
#include <vector>
using namespace std;

/*
dp[n+1] = max(dp[n], dp[n-1]+nums[n+1])
滚动数组优化
时间O(n) 空间O(1)
*/

class Solution {
public:
    int massage(vector<int>& nums) {
        int now, last, temp;
        now = last = 0;
        for (int i = 0; i < nums.size(); ++i){
            temp = max(now, last+nums[i]);
            last = now;
            now = temp;
        }
        return now;
    }
};

int main(){
    return 0;
}