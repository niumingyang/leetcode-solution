#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
1 3 3 8 5 4 3 2 1  -->
      ^         ^
1 3 4 1 2 3 3 5 8
找原数组最后的单减区间[i...j]
将nums[i-1]换为稍大的一个数，并排列成单增
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int k = nums.size()-1;
        while (k > 0){
            if (nums[k-1] < nums[k]){
                break;
            }
            else k--;
        }
        if (k == 0) reverse(nums.begin(), nums.end());
        else {
            int i = nums.size()-1;
            for (; i >= k; --i){
                if (nums[i] > nums[k-1]){
                    swap(nums[i], nums[k-1]);
                    break;
                }
            }
            reverse(nums.begin()+k, nums.end());
        }
    }
};

int main(){
    return 0;
}