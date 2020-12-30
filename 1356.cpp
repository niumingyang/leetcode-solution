#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
����x�����Ʊ�ʾ��1�ĸ���
����һ������
while(x){
    cnt += x%2;
    x >>= 1;
}
��������x&(x-1) => ȥ�������Ʊ�ʾ�����һ��1
while(x){
    x &= x-1;
    cnt++;
}
��������ϵͳ�Դ�����__builtin_popcount(x)
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