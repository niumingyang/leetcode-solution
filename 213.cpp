#include <iostream>
#include <vector>
using namespace std;

/*
198��������
�����Ƿ�����һ�����ӽ���״��������ֽ�Ϊ����������������
��̬�滮���
*/

class Solution {
public:
    int subrob(vector<int>& nums, int begin, int end) {
        if (end-1 < begin) return 0;
        int now, last, temp;
        now = last = 0;
        for (int i = begin; i < end; ++i){
            temp = max(now, last+nums[i]);
            last = now;
            now = temp;
        }
        return now;
    }
    int rob(vector<int>& nums) {
        return max(subrob(nums, 2, nums.size()-1)+nums[0], subrob(nums, 1, nums.size()));
    }
};

int main(){
    return 0;
}