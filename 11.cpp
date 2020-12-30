#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ret = 0;
        stack<int> s;
        for (int i = 0; i < height.size(); ++i){
            if (s.empty() || height[i] < s.top()){
                s.push(i);
                cout << "push " << i << endl;
            }
            else{
                while (!s.empty() && height[i] >= s.top()){
                    ret = max(ret, (i-s.top())*height[s.top()]);
                    cout << "pop " << s.top() << endl;
                    cout << s.top() << ' ' << (i-s.top())*height[s.top()] << endl;
                    s.pop();
                }
                s.push(i);
            }
        }
        return ret;
    }
};

int main(){
    Solution s;
    vector<int> v = {1,8,6,2,5,4,8,3,7};
    cout << s.maxArea(v);
    return 0;
}