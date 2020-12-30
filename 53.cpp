#include <iostream>
#include <vector>
using namespace std;

/*
������������
����һ������O(n2)
����һ��dp O(n2)
dp[n+1] = max(dp[n], Max_i{Sigma(i->n+1)sums[i]});
������������ O(nlgn)
f(n) = 2f(n/2) + Max_i{Sigma(i->n/2)sums[i]} + Max_i{Sigma(n/2->i)sums[i]}
�����ģ�����ɨ�跨O(n)
sum��¼�����к�
��ͷ��ʼ��sum���ۼӣ�sum<0ʱ��Ϊ0�������Ѿ�����������У�ret�洢sum�����ֵ
������Ϊ���㵽�������͵�������ʱ��sum�ض�Ϊ0�����������п��Լӳ�
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int ret = nums[0];
        for (int i = 0; i < nums.size(); ++i){
            sum += nums[i];
            ret = max(sum, ret);
            if (sum < 0) sum = 0;
        }
        return ret;
    }
};

int main(){
    return 0;
}