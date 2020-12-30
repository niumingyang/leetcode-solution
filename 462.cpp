#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

/*
即找中位数，其他数都往中位数靠拢
PS.快排必写随机，否则会卡
*/

class Solution {
public:
    int findk(vector<int>& v, int begin, int end, int k){//找v[begin...end)第k小数
        if (begin+1 >= end) return v[begin];
        int r = begin+rand()%(end-begin);
        int x = v[r];
        v[r] = v[end-1];
        v[end-1] = x;
        int j = begin-1;
        int temp;
        for (int i = begin; i < end-1; ++i){
            if (v[i] < x){
                j++;
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
        j++;
        v[end-1] = v[j];
        v[j] = x;
        int cnt = j-begin+1;
        if (cnt < k) return findk(v, j+1, end, k-cnt);
        else if (cnt == k) return x;
        else return findk(v, begin, j, k);
    }
    int minMoves2(vector<int>& nums) {
        int num = findk(nums, 0, nums.size(), nums.size()/2+1);
        int ret = 0;
        for (int i = 0; i < nums.size(); ++i){
            ret += abs(nums[i]-num);
        }
        return ret;
    }
};

int main(){
    vector<int> v = {83,86,77,15,93,35,86,92,49,21};
    Solution s;
    cout << s.findk(v, 0, 10, 6) << endl;
    cout << s.minMoves2(v) <<endl;
    return 0;
}