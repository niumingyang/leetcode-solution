#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> ret;
        for (int i = 0; i < nums.size(); ++i){
            if (m.find(target-nums[i]) != m.end()){
                ret.push_back(m[target-nums[i]]);
                ret.push_back(i);
                return ret;
            }
            else m.insert(pair<int, int>(nums[i], i));
        }
        return ret;
    }
};

int main(){
    return 0;
}