#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int bisearch(vector<int>& nums, int begin, int end, int target){
        if (begin == end-1) return (nums[begin]>=target ? begin : end);
        int mid = (begin+end)/2;
        int k = nums[mid];
        if (target == k) return mid;
        else if (target < k) return bisearch(nums, begin, mid, target);
        else return bisearch(nums, mid, end, target);  
    }
    int searchInsert(vector<int>& nums, int target) {
        return bisearch(nums, 0, nums.size(), target);
    }
};

int main(){
    return 0;
}