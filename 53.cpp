#include <iostream>
#include <vector>
using namespace std;

/*
最大子序和问题
方法一：暴力O(n2)
方法一：dp O(n2)
dp[n+1] = max(dp[n], Max_i{Sigma(i->n+1)sums[i]});
方法三：分治 O(nlgn)
f(n) = 2f(n/2) + Max_i{Sigma(i->n/2)sums[i]} + Max_i{Sigma(n/2->i)sums[i]}
方法四：线性扫描法O(n)
sum记录子序列和
从头开始往sum中累加，sum<0时变为0，抛弃已经计算的子序列，ret存储sum的最大值
这是因为计算到最大子序和的子序列时，sum必定为0，否则子序列可以加长
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int ret = nums[0];
        for (int i = 0; i < nums.size(); ++i){
            sum += nums[i];
            ret = max(sum, ret);
            if (sum < 0) sum = 0;
        }
        return ret;
    }
};

int main(){
    return 0;
}