#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int nummin = nums[0];
        for (int i = 0; i < nums.size(); ++i)
            nummin = min(nummin, nums[i]);
        int ret = 0;
        for (int i = 0; i < nums.size(); ++i)
            ret += nums[i] - nummin;
        return ret;
    }
};

int main(){
    Solution s;
    return 0;
}