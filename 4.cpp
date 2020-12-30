#include <vector>
#include <iostream>
using namespace std;

/*
算法导论9.3-8
求两个有序数组nums1[begin1...end1),nums2[begin2...end2)合并后的第k个数大小
算法复杂度O(log(min(m,n)))
*/

class Solution {
private:
    //数组nums1[begin1...end1),nums2[begin2...end2)中第k个数的大小
    int find(vector<int>& nums1, vector<int>& nums2, int begin1, int end1, int begin2, int end2, int k){
        int lower, upper, mid, t;
        //若有数组为空
        if (begin1 == end1)
            return nums2[begin2+k-1];
        else if (begin2 == end2)
            return nums1[begin1+k-1];
        //若nums1中所有数大于nums2[(end2+begin2)/2]
        if (nums1[begin1] > nums2[(end2+begin2)/2]) {
            t = (end2+begin2)/2-begin2+1;
            if (t > k) return find(nums1, nums2, begin1, begin1, begin2, (end2+begin2)/2, k);
            else if (t == k) return nums2[(end2+begin2)/2];
            else return find(nums1, nums2, begin1, end1, (end2+begin2)/2+1, end2, k-t);
        }
        //二分查找nums1中的某个i，使得nums1[i]<=nums2[(end2+begin2)/2], nums1[i+1]>nums2[(end2+begin2)/2]
        lower = begin1, upper = end1-1;
        while (lower < upper){
            mid = (lower+upper+1)/2;
            if (nums1[mid] <= nums2[(end2+begin2)/2]) lower = mid;
            else upper = mid-1;
        }
        //根据(lower-begin1+1) + ((end2+begin2)/2-begin2+1)的大小进行递归
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