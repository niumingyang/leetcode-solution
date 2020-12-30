#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        for (int i = 0; i < m; ++i){
            for (int j = 0; j <= (n-1)/2; ++j){
                if (A[i][j] == A[i][n-j-1]){
                    int temp = 1 - A[i][j];
                    A[i][n-j-1] = A[i][j] = temp;
                }
            }
        }
        return A;
    }
};

int main(){
    return 0;
}