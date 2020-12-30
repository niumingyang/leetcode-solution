#include <iostream>
#include <vector>
using namespace std;

/*
record��¼��������Сֵ��������С�ĸ��£���������ĸ���������ret
�е㵥��ջ����˼
֤�����������Ž�ʱ��record�ر����£�����֮ǰ��һ����С���������Ž���Ը���
PS.���Լ����֣�ת��Ϊ������������
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