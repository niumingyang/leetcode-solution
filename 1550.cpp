#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        for (int i = 0; i < arr.size();){
            if (i+2 < arr.size() && arr[i]%2 && arr[i+1]%2 && arr[i+2]%2){
                return true;
            }
            else {
                int old_i = i;
                for (int j = i+1; j < arr.size(); ++j)
                    if (arr[j]%2){
                        i = j;
                        break;
                    }
                if (i == old_i) return false;
            }
        }
        return false;
    }
};

int main(){
    vector<int> v1 = {0,1,3,4,5,6};
    vector<int> v2 = {-6,-9,3,5,0};
    vector<int> v3 = {-4,-3,-2,-1};
    Solution s;
    cout << s.threeConsecutiveOdds(v1) << endl;
    cout << s.threeConsecutiveOdds(v2) << endl;
    cout << s.threeConsecutiveOdds(v3) << endl;
    return 0;
}