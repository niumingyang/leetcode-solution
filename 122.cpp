#include <iostream>
#include <vector>
using namespace std;

/*
相当于找所有的单增区间
反证法，若最优解中某个买入卖出区间prices[m...n]存在m < i < j < n
有price[i] > price[j], 则prices[n] - prices[m] < prices[i] - prices[m] + prices[n] - prices[j]
这样更划算，矛盾，多以最优解中每个区间必单增
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        int sum = 0;
        int now = prices[0];
        for (int i = 1; i < prices.size(); ++i){
            if (prices[i] < prices[i-1]){
                sum += prices[i-1] - now;
                now = prices[i];
            }
        }
        sum += prices[prices.size()-1] - now;
        return sum;
    }
};

int main(){
    return 0;
}