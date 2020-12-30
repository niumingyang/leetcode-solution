#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*
二分查找
先二分猜答案，然后贪心验证
*/

class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int lower = 0, upper = position[position.size()-1];
        while (lower < upper){
            int mid = (lower+upper+1)/2;
            int cnt = 1;
            int last = 0;
            for (int i = 1; i < position.size(); ++i){
                if (position[i]-position[last] >= mid){
                    last = i;
                    cnt++;
                }
            }
            if (cnt>=m) lower = mid;
            else upper = mid-1;
        }
        return lower;
    }
};

int main(){
    vector<int> v = {1,2,3,5,8,10};
    Solution s;
    cout << s.maxDistance(v, 4);
    return 0;
}