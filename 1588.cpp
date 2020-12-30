#include <vector>
#include <iostream>
using namespace std;

/*
考虑Ai在多少个奇数长度子序列中出现过
若在左边选偶数个数，右边也要选偶数个
若在左边选奇数个数，右边也要选奇数个
左边共i个数，右边共n-i-1个数（数组索引从0到n-1）
lodd = (i+1)/2
rodd = (n-i)/2
leven = i/2+1
reven = (n-i-1)/2+1
*/

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int res = 0;
        int n = arr.size();
        for (int i = 0; i < n; ++i)
            res += arr[i]*(((i+1)/2) * ((n-i)/2) + (i/2+1) * ((n-i-1)/2+1));
        return res;
    }
};

int main(){
    vector<int> v = {1, 4, 2, 5, 3};
    Solution s;
    cout << s.sumOddLengthSubarrays(v);
    return 0;
}