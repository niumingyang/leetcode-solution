#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int ret = 0;
        int flag = 0;
        if (strs.size() == 0) return "";
        for ( ; ret < strs[0].size(); ++ret){
            for (int i = 1; i < strs.size(); ++i)
                if (strs[i][ret] != strs[0][ret]){
                    flag = 1;
                    break;
                }
            if (flag == 1) break;
        }
        return strs[0].substr(0, ret);
    }
};

int main(){
    return 0;
}