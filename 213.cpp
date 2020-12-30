#include <iostream>
#include <vector>
using namespace std;

/*
198的升级版
根据是否抢第一个房子将环状排列问题分解为两个单排排列问题
动态规划解决
*/

class Solution {
public:
    int subrob(vector<int>& nums, int begin, int end) {
        if (end-1 < begin) return 0;
        int now, last, temp;
        now = last = 0;
        for (int i = begin; i < end; ++i){
            temp = max(now, last+nums[i]);
            last = now;
            now = temp;
        }
        return now;
    }
    int rob(vector<int>& nums) {
        return max(subrob(nums, 2, nums.size()-1)+nums[0], subrob(nums, 1, nums.size()));
    }
};

int main(){
    return 0;
}