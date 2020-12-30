#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

/*
C++数字字符串使用sstream流或者to_string函数
*/

// class Solution {
// public:
//     vector<string> summaryRanges(vector<int>& nums) {
//         vector<string> res;
//         int j;
//         ostringstream temp;
//         for (int i = 0; i < nums.size();){
//             j = i+1;
//             while (j < nums.size() && nums[j] == nums[j-1]+1)
//                 j++;
//             temp.str("");
//             if (j == i+1) temp << nums[i];
//             else temp << nums[i] << "->" << nums[j-1];
//             i = j;
//             res.push_back(temp.str());
//         }
//         return res;
//     }
// };

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int j;
        string temp;
        for (int i = 0; i < nums.size();){
            j = i+1;
            while (j < nums.size() && nums[j] == nums[j-1]+1)
                j++;
            if (j == i+1) temp = to_string(nums[i]);
            else temp = to_string(nums[i]) + "->" + to_string(nums[j-1]);
            i = j;
            res.push_back(temp);
        }
        return res;
    }
};

int main(){
    vector<int> v1 = {0,1,3,4,5,6};
    vector<int> v2 = {-6,-3,3,5,10};
    vector<int> v3 = {-4,-3,-2,-1};
    Solution s;
    vector<string> vv1 = s.summaryRanges(v1);
    vector<string> vv2 = s.summaryRanges(v2);
    vector<string> vv3 = s.summaryRanges(v3);
    for (int i = 0; i < vv1.size(); ++i)
        cout << vv1[i] << ' ';
    cout << endl;
    for (int i = 0; i < vv2.size(); ++i)
        cout << vv2[i] << ' ';
    cout << endl;
    for (int i = 0; i < vv3.size(); ++i)
        cout << vv3[i] << ' ';
    cout << endl;
    return 0;
}