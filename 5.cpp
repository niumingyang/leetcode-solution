#include <iostream>
#include <vector>
using namespace std;

/*
����һ����̬�滮��dp[i][j],ÿ��s[i...j]�Ƿ��ǻ��Ĵ�
��������������չ����ÿ��Ԫ��Ϊ����������չ
��������Manacher�㷨
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int len = -1;//�۳�
        int index = 0;
        for (int i = 0; i < s.size(); ++i){
            int j = 0;
            for (; i-j>=0 && i+j<s.size(); ++j){
                if (s[i-j] != s[i+j]) break;
            }
            if (j-1 > len){
                len = j-1;
                index = i;
            }
        }
        int len1 = -1;//�۳�
        int index1 = -1;
        for (int i = 0; i < s.size()-1; ++i){
            if (s[i] != s[i+1]) continue;
            int j = 0;
            for (; i-j>=0 && i+1+j<s.size(); ++j){
                if (s[i-j] != s[i+1+j]) break;
            }
            if (j-1 > len1){
                len1 = j-1;
                index1 = i;
            }
        }
        if (index1 == -1) return s.substr(index-len, 2*len+1);
        if (len > len1) return s.substr(index-len, 2*len+1);
        else return s.substr(index1-len1, 2*len1+2);
    }
};

int main(){
    Solution s;
    cout << s.longestPalindrome("aaaabaaab");
    return 0;
}