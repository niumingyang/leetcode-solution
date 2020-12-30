#include <vector>
#include <iostream>
using namespace std;

/*
����Ai�ڶ��ٸ����������������г��ֹ�
�������ѡż���������ұ�ҲҪѡż����
�������ѡ�����������ұ�ҲҪѡ������
��߹�i�������ұ߹�n-i-1����������������0��n-1��
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