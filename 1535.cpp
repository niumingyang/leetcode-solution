#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int i = 0, j = 0;
        if (k == 0) return arr[0];
        int Max = 0;
        for (int m = 0; m < arr.size(); ++m){
            if (arr[m] > Max) Max = arr[m];
        }
        while (i < arr.size()){
            for (j = i+1; j < i+k; ++j){
                if (j == arr.size()) return Max;
                if (arr[j] > arr[i]) break;
                if (j == arr.size()-1 && j != i+k-1) return Max;
            }
            if (i == 0){
                if (i+k >= arr.size()) return Max;
                if (j == i+k && arr[i+k] < arr[i]) return arr[i];
                else i = j;
            }
            if (j == i+k) return arr[i];
            else i = j;
        }
        return -1;
    }
};

int main(){
    vector<int> v = {1,11,22,33};
    Solution s;
    cout << s.getWinner(v, 1);
    return 0;
}