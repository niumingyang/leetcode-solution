#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
计算x二进制表示中1的个数
方法一：暴力
while(x){
    cnt += x%2;
    x >>= 1;
}
方法二：x&(x-1) => 去除二进制表示中最后一个1
while(x){
    x &= x-1;
    cnt++;
}
方法三：系统自带函数__builtin_popcount(x)
*/

class Solution {
private:
    static bool cmp(const int& x, const int& y){
        int m = __builtin_popcount(x);
        int n = __builtin_popcount(y);
        if (m == n) return x < y;
        else return m < n;
    }
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};

int main(){
    return 0;
}