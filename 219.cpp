#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i){
            if (m.find(nums[i]) != m.end()){
                if (i-m[nums[i]] <= k) return true;
                else m[nums[i]] = i;
            }
            else m.insert(pair<int, int>(nums[i], i));
        }
        return false;
    }
};

int main(){
    return 0;
}