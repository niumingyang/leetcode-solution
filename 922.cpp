#include <iostream>
#include <vector>
using namespace std;

/*
˫ָ�룺ֻ�豣֤����ż��λ�����������ɣ�������������λ�Ľ���
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