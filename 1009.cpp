#include <iostream>
#include <vector>
using namespace std;

/*
方法一：异或运算（异或一个全1的相同位数的数）
方法二：-N-1为n反码，只需去除前导1即可
*/

// class Solution {
// public:
//     int bitwiseComplement(int N) {
//         int n = N;
//         int cnt = N == 0 ? 1 : 0;//求n位数
//         while (n > 0){
//             cnt++;
//             n >>= 1;
//         }
//         return N ^ ((1 << cnt) - 1);//异或运算
//     }
// };

class Solution {
public:
    int bitwiseComplement(int N) {
        if (N == 0) return 1;
        int temp = N;
        temp = (temp >> 1) | temp;//O(1)时间将temp所有位填充为1
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