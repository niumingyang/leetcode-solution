#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

/*
n <= 4 ö��
n >= 5
�ֽ������<4(������Ϊ��n > 5����n����������˻�������5 < 2*3, 6 < 3*3����4����д��2+2����)
ֻ������1, 2, 3
����������1
2�ĸ���С��3(������Ϊ2*2*2 < 3*3)
*/

class Solution {
public:
    int integerBreak(int n) {
        if (n == 1) return 1;
        else if (n == 2) return 1;
        else if (n == 3) return 2;
        else if (n == 4) return 4;
        else{
            if (n%3 == 0) return pow(3, n/3);//�����ɸ�3��0��2���
            else if (n%3 == 1) return 2*2*pow(3, (n-4)/3);//�����ɸ�3��2��2���
            else return 2*pow(3, (n-2)/3);//�����ɸ�3��1��2���
        }
    }
};

int main(){
    return 0;
}