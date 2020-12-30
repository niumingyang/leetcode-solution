#include <vector>
#include <iostream>
using namespace std;

/*
Ħ���㷨
����һ�����ٶ�Ϊmajority element����������Ϊ1
����һ������ǰһ������ͬ��������һ����֮��һ
��������Ϊ0ʱ����һ�����ٶ�Ϊmajority element

֤����majority element���m
�������������ģ��С��
���ٶ���ȷ��ÿ�μ�������Ϊ0�����¼ٶ�ʱ��m������Ԫ���ӵ���ͬ���������µ�����������Ȼ��m
���ٶ������ӵ����ǲ�������mС�ڵ���һ�룬���µ�����������Ȼ��m
���ԣ�������m�����㷨�������m
��������m���㷨�������⣬���±���һ������ͳ�Ƽ���
*/

class Solution {
public:
    int majorityElement(vector<int>& nums){
	    int major = 0, cnt = 0;
	    for (int i = 0; i < nums.size(); i++){
		    if (cnt == 0){
			    major = nums[i];
			    cnt++;
		    }
		    else major == nums[i] ? cnt++ : cnt--;
	    }
        cnt = 0;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] == major) cnt++;
        if (cnt*2 > nums.size()) return major;
        else return -1;
    }
};

int main(){
    Solution s;
    vector<int> v1 = {1, 2, 3, 4, 5, 1, 1, 1, 1};
    vector<int> v2 = {1, 2, 3, 4, 5, 1, 4, 3, 2};
    vector<int> v3 = {1, 1, 1, 1, 2, 2, 3, 3};
    vector<int> v4 = {1, 2, 5, 9, 5, 9, 5, 5, 5};
    vector<int> v5 = {3, 2};
    vector<int> v6 = {2, 2, 1, 1, 1, 2, 2};
    cout << s.majorityElement(v1) << endl;
    cout << s.majorityElement(v2) << endl;
    cout << s.majorityElement(v3) << endl;
    cout << s.majorityElement(v4) << endl;
    cout << s.majorityElement(v5) << endl;
    cout << s.majorityElement(v6) << endl;
    return 0;
}