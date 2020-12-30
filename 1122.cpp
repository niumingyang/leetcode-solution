#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

int location[1005];
bool mycmp(const int& x, const int& y){
    if (location[x] == -1 && location[y] == -1) return x < y;
    else if (location[x] == -1) return 0;
    else if (location[y] == -1) return 1;
    else return location[x] < location[y];
}

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        memset(location, -1, sizeof(location));
        for (int i = 0; i < arr2.size(); ++i)
            location[arr2[i]] = i;
        sort(arr1.begin(), arr1.end(), mycmp);
        return arr1;
    }
};

int main(){
    vector<int> v1 = {5,4,3,2,1};
    vector<int> v2 = {4,5};
    Solution s;
    vector<int> res = s.relativeSortArray(v1, v2);
    for (int i = 0; i < res.size(); ++i)
        cout << res[i] << ' ';
    return 0;
}