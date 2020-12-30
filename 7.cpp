#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long ret = 0;
        long long _x;
        bool flag = false;
        if (x < 0){
            flag = true;
            _x = -x;
        }
        else _x = x;
        int temp;
        while (_x){
            temp = _x%10;
            _x /= 10;
            ret = ret*10 + temp;
        }
        if (flag) ret = -ret;
        if (ret < INT_MIN || ret > INT_MAX) ret = 0;
        return (int)ret;
    }
};

int main(){
    return 0;
}