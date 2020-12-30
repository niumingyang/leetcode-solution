#include <iostream>
#include <vector>
using namespace std;

/*
����һ��������㣨���һ��ȫ1����ͬλ��������
��������-N-1Ϊn���룬ֻ��ȥ��ǰ��1����
*/

// class Solution {
// public:
//     int bitwiseComplement(int N) {
//         int n = N;
//         int cnt = N == 0 ? 1 : 0;//��nλ��
//         while (n > 0){
//             cnt++;
//             n >>= 1;
//         }
//         return N ^ ((1 << cnt) - 1);//�������
//     }
// };

class Solution {
public:
    int bitwiseComplement(int N) {
        if (N == 0) return 1;
        int temp = N;
        temp = (temp >> 1) | temp;//O(1)ʱ�佫temp����λ���Ϊ1
        temp = (temp >> 2) | temp;
        temp = (temp >> 4) | temp;
        temp = (temp >> 8) | temp;
        temp = (temp >> 16) | temp;
        return temp & (-N-1);
    }
};

int main(){
    return 0;
}