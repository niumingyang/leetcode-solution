#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

/*
双指针，从中间往两边计算
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> B;
        int mid = 0;
        int absmin = (1 << 30);
        for (int i = 0; i < A.size(); i++)
            if (abs(A[i]) < abs(absmin)){
                absmin = A[i];
                mid = i;
            }
        int p = mid-1, q = mid+1;
        B.push_back(absmin*absmin);
        while (p >= 0 || q < A.size()){
            if (p < 0){
                for (int i = q; i < A.size(); ++i)
                    B.push_back(A[i]*A[i]);
                break;
            }
            else if (q >= A.size()){
                for (int i = p; i >= 0; --i)
                    B.push_back(A[i]*A[i]);
                break;
            }
            else if (abs(A[p]) < abs(A[q])){
                B.push_back(A[p]*A[p]);
                p--;
            }
            else {
                B.push_back(A[q]*A[q]);
                q++;
            }
        }
        return B;
    }
};

int main(){
    vector<int> v = {-4, -1, 0, 3, 10};
    Solution s;
    vector<int> vv = s.sortedSquares(v);
    for (int i = 0; i < vv.size(); ++i)
        cout << vv[i] << ' ';
    return 0;
}