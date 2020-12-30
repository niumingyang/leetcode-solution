#include <iostream>
#include <vector>
using namespace std;

/*
record记录遇到的最小值，遇到更小的更新，遇到更大的更新两数差ret
有点单调栈的意思
证明：碰到最优解时，record必被更新，否则之前有一个更小的数，最优解可以更大
PS.可以计算差分，转化为最大子序和问题
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        int record = prices[0], ret = 0;
        for (int i = 1; i < prices.size(); ++i){
            if (prices[i] < record)
                record = prices[i];
            else ret = max(ret, prices[i]-record);
        }
        return ret;
    }
};

int main(){
    return 0;
}