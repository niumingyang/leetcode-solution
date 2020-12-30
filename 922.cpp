#include <iostream>
#include <vector>
using namespace std;

/*
双指针：只需保证所有偶数位满足条件即可，不满足用奇数位的交换
*/

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int i, j;
        i = 0;
        j = 1;
        while (i < A.size()){
            if (A[i]%2 == 0){
                i += 2;
                continue;
            } 
            while (A[j]%2 == 1) j += 2;
            swap(A[i], A[j]);
            i += 2;
        }
        return A;
    }
};

int main(){
    return 0;
}