#include <iostream>
#include <vector>
using namespace std;

/*
方法一：排序O(nlgn)
方法二：优先队列维护扫一遍O(nlgk)
方法三：快速排序,随机期望O(n)，最坏O(n2)
*/

class Solution {
public:
    int distance(vector<int>& x){
        return x[0]*x[0] + x[1]*x[1];
    }
    void quick_select(vector<vector<int>>& p, int begin, int end, int k){//p[begin...end)前k大元素
        if (end  <= begin+1) return;
        int now = begin-1;
        vector<int> temp;
        for (int i = begin; i < end; ++i){
            if (distance(p[i]) <= distance(p[end-1])){
                now++;
                temp = p[i];
                p[i] = p[now];
                p[now] = temp;
            }
        }
        if (now-begin+1 > k) quick_select(p, begin, now, k);
        else if (now-begin+1 == k) return;
        else quick_select(p, now+1, end, k-(now-begin+1));
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        quick_select(points, 0, points.size(), K);
        vector<vector<int>> ret;
        for (int i = 0; i < K; ++i)
            ret.push_back(points[i]);
        return ret;
    }
};

int main(){
    return 0;
}