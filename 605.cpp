#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i = 0, j = 0;
        while (i < flowerbed.size()){
            while (i < flowerbed.size()){
                if (flowerbed[i] == 0) break;
                else i++;
            }
            j = i + 1;
            while (j < flowerbed.size()){
                if (flowerbed[j] == 1) break;
                else j++;
            }
            if (i == 0 && j == flowerbed.size()) n -= (j-i+1)/2;
            else if (i == 0 || j == flowerbed.size()) n -= (j-i)/2;
            else  n -= (j-i-1)/2;
            i = j;
        }
        if (n <= 0) return true;
        else return false;
    }
};

int main(){
    Solution s;
    vector<int> v = {0,0,1,0,1,1,0,0,0,0,0};
    cout << s.canPlaceFlowers(v, 4);
    return 0;
}