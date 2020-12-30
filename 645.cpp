#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> m;
        vector<int> ret;
        for (int i = 0; i < nums.size(); ++i){
            if (m.find(nums[i]) != m.end()){
                ret.push_back(nums[i]);
            }
            else m.insert(pair<int, int>(nums[i], 1));
        }
        for (int i = 0; i < nums.size(); ++i)
            if (m.find(i+1) == m.end()){
                ret.push_back(i+1);
                break;
            }
        return ret;
    }
};

int main(){
    return 0;
}