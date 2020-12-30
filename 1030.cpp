#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool valid(int r, int c, int x, int y){
        return x >= 0 && x < r && y >= 0 && y < c;
    }
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> res;
        int maxd = R+C+1;
        res.push_back({r0, c0});
        for (int d = 1; d < maxd; ++d){
            int i = r0-d, j = c0;
            while(i != r0){
                if (valid(R, C, i, j)) res.push_back({i, j});
                i++; j--;
            }
            while(j != c0){
                if (valid(R, C, i, j)) res.push_back({i, j});
                i++; j++;
            }
            while(i != r0){
                if (valid(R, C, i, j)) res.push_back({i, j});
                i--; j++;
            }
            while(j != c0){
                if (valid(R, C, i, j)) res.push_back({i, j});
                i--; j--;
            }
        }
        return res;
    }
};

int main(){
    return 0;
}