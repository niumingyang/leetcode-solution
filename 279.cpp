#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    bool isSquare(int x){
        int k = (int)sqrt(x);
        return k*k == x;
    }
    int numSquares(int n) {
        int temp = n;
        while (temp%4 == 0){
            temp /= 4;
        }
        if (temp%8 == 7) return 4;

        if (isSquare(n)) return 1;
        int k = (int)sqrt(n)+1;
        for (int i = 1; i < k; ++i){
            if (isSquare(n-i*i)) return 2;
        }
        return 3;
    }
};

int main(){
    return 0;
}