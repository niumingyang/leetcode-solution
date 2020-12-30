#include <iostream>
#include <vector>
using namespace std;

/*
����һ������O(nlgn)
�����������ȶ���ά��ɨһ��O(nlgk)
����������������,�������O(n)���O(n2)
*/

class Solution {
public:
    int distance(vector<int>& x){
        return x[0]*x[0] + x[1]*x[1];
    }
    void quick_select(vector<vector<int>>& p, int begin, int end, int k){//p[begin...end)ǰk��Ԫ��
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