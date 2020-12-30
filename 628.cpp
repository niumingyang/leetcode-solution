#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int p1, p2, p3;
        int n1, n2;
        p1 = p2 = p3 = -1005;
        n1 = n2 = 1005;
        for (int i = 0; i < nums.size(); ++i){
            if (nums[i] > p1){
                p3 = p2;
                p2 = p1;
                p1 = nums[i];
            }
            else if (nums[i] > p2){
                p3 = p2;
                p2 = nums[i];
            }
            else if (nums[i] > p3) 
                p3 = nums[i];
            if (nums[i] < n1){
                n2 = n1;
                n1 = nums[i];
            }
            else if (nums[i] < n2)
                n2 = nums[i];
        }
        int res = 0;
        if (p1*n1*n2 < p1*p2*p3)
            res = p1*p2*p3;
        else res = p1*n1*n2;
        return res;
    }
};

int main(){
    vector<int> v1 = {0,1,3,4,5,6};
    vector<int> v2 = {-6,-9,3,5,0};
    vector<int> v3 = {-4,-3,-2,-1};
    Solution s;
    cout << s.maximumProduct(v1) << endl;
    cout << s.maximumProduct(v2) << endl;
    cout << s.maximumProduct(v3) << endl;
    return 0;
}