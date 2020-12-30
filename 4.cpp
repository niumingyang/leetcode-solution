#include <vector>
#include <iostream>
using namespace std;

/*
�㷨����9.3-8
��������������nums1[begin1...end1),nums2[begin2...end2)�ϲ���ĵ�k������С
�㷨���Ӷ�O(log(min(m,n)))
*/

class Solution {
private:
    //����nums1[begin1...end1),nums2[begin2...end2)�е�k�����Ĵ�С
    int find(vector<int>& nums1, vector<int>& nums2, int begin1, int end1, int begin2, int end2, int k){
        int lower, upper, mid, t;
        //��������Ϊ��
        if (begin1 == end1)
            return nums2[begin2+k-1];
        else if (begin2 == end2)
            return nums1[begin1+k-1];
        //��nums1������������nums2[(end2+begin2)/2]
        if (nums1[begin1] > nums2[(end2+begin2)/2]) {
            t = (end2+begin2)/2-begin2+1;
            if (t > k) return find(nums1, nums2, begin1, begin1, begin2, (end2+begin2)/2, k);
            else if (t == k) return nums2[(end2+begin2)/2];
            else return find(nums1, nums2, begin1, end1, (end2+begin2)/2+1, end2, k-t);
        }
        //���ֲ���nums1�е�ĳ��i��ʹ��nums1[i]<=nums2[(end2+begin2)/2], nums1[i+1]>nums2[(end2+begin2)/2]
        lower = begin1, upper = end1-1;
        while (lower < upper){
            mid = (lower+upper+1)/2;
            if (nums1[mid] <= nums2[(end2+begin2)/2]) lower = mid;
            else upper = mid-1;
        }
        //����(lower-begin1+1) + ((end2+begin2)/2-begin2+1)�Ĵ�С���еݹ�
        t = (lower-begin1+1) + ((end2+begin2)/2-begin2+1);
        if (t > k) 
            return find(nums1, nums2, begin1, lower+1, begin2, (end2+begin2)/2, k);
        else if (t == k)
            return nums2[(end2+begin2)/2];
        else 
            return find(nums1, nums2, lower+1, end1, (end2+begin2)/2+1, end2, k-t);
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if ((m+n)%2==1) return (double)find(nums1, nums2, 0, m, 0, n, (m+n)/2+1);
        else return (double)(find(nums1, nums2, 0, m, 0, n, (m+n)/2) + find(nums1, nums2, 0, m, 0, n, (m+n)/2+1))/2;
    }
};

int main(){
    vector<int> v1 = {1, 2};
    vector<int> v2 = {3, 4};
    Solution s;
    cout << s.findMedianSortedArrays(v1, v2);
    return 0;
}