#include <iostream>
#include <vector>
using namespace std;

/*
����һ������ƥ�䣨ע��ֻ�����������һ�룩
������������sƴ��һ��ȥ����β�����Ӵ�s <=> s��������
<= ��֪
=> s[1]...s[i]...s[n-1],  s[0].....s[j]...s[n-2]
          s[0]...s[n-1-i],s[n-i]...s[n-1]
��ͬ����֪j=i-1;
����n-i < i���������ͬ�ĸ���С���ұ�
����s[0...n-i-i] = s[i...n-1]
    s[0...i-1]   = s[n-i...n-1]
�����s[0...n-i-i] = s[i...n-1] = s[n-i...i-1]�ֳ�������
��������KMP�㷨
�����ģ��Ż���KMP
*/

class Solution {
public:
    // bool repeatedSubstringPattern(string s) {
    //     for (int i = 0; i < s.size()/2; ++i){
    //         if (s.size()%(i+1) == 0 && s[i+1] == s[0]){
    //             bool flag = true;
    //             for (int j = i+1; j < s.size(); j += i+1){
    //                 for (int k = 0; k < i+1; ++k){
    //                     if (s[j+k] != s[k]){
    //                         flag = false;
    //                         break;
    //                     }
    //                 }
    //                 if (!flag) break;
    //             }
    //             if (flag) return true;
    //         }
    //     }
    //     return false;   
    // }

    // bool repeatedSubstringPattern(string s) {
    //     return (s+s).find(s, 1) != s.size();
    // }

    bool kmp(const string& pattern) {
        int n = pattern.size();
        vector<int> next(n, -1);
        for (int i = 1; i < n; ++i) {
            int j = next[i - 1];
            while (j != -1 && pattern[j + 1] != pattern[i]) {
                j = next[j];
            }
            if (pattern[j + 1] == pattern[i]) {
                next[i] = j + 1;
            }
        }
        return next[n - 1] != -1 && n % (n - next[n - 1] - 1) == 0;
    }

    bool repeatedSubstringPattern(string s) {
        return kmp(s);
    }
};

int main(){
    Solution s;
    return 0;
}