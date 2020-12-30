#include <vector>
#include <iostream>
using namespace std;

/*
摩尔算法
将第一个数假定为majority element，计数器设为1
若后一个数与前一个数相同计数器加一，反之减一
计数器减为0时将下一个数假定为majority element

证明：majority element简称m
这样做将问题规模缩小了
若假定正确，每次计数器减为0设置新假定时，m与其他元素扔掉相同个数，余下的数里面它依然是m
若假定错误，扔掉的那部分里面m小于等于一半，余下的数里面它依然是m
所以，若存在m，则算法必能输出m
若不存在m，算法输出错误解，重新遍历一遍数组统计即可
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