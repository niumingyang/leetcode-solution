#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

/*
n <= 4 枚举
n >= 5
分解的数都<4(这是因为若n > 5，则n拆成两个数乘积更大，如5 < 2*3, 6 < 3*3；而4可以写成2+2不变)
只可能是1, 2, 3
而不可能是1
2的个数小于3(这是因为2*2*2 < 3*3)
*/

class Solution {
public:
    int integerBreak(int n) {
        if (n == 1) return 1;
        else if (n == 2) return 1;
        else if (n == 3) return 2;
        else if (n == 4) return 4;
        else{
            if (n%3 == 0) return pow(3, n/3);//由若干个3和0个2组成
            else if (n%3 == 1) return 2*2*pow(3, (n-4)/3);//由若干个3和2个2组成
            else return 2*pow(3, (n-2)/3);//由若干个3和1个2组成
        }
    }
};

int main(){
    return 0;
}