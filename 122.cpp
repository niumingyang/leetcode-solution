#include <iostream>
#include <vector>
using namespace std;

/*
�൱�������еĵ�������
��֤���������Ž���ĳ��������������prices[m...n]����m < i < j < n
��price[i] > price[j], ��prices[n] - prices[m] < prices[i] - prices[m] + prices[n] - prices[j]
���������㣬ì�ܣ��������Ž���ÿ������ص���
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