#include <iostream>
#include <vector>
using namespace std;

/*
方法一：正确条件：
左括号数=右括号数
没闭合一个括号时，中间不存在未闭合的括号
方法二：使用栈
*/

class Solution {
public:
    bool isValid(string s) {
        int sum1, sum2, sum3;//统计括号数
        int rec1[s.size()], rec2[s.size()], rec3[s.size()];//记录所有左括号的位置
        int cnt1, cnt2, cnt3;//记录未闭合的左括号数
        sum1 = sum2 = sum3 = cnt1 = cnt2 = cnt3 = 0;
        for (int i = 0; i < s.size(); ++i){
            switch (s[i]){
                case '(': sum1++;
                    rec1[cnt1++] = i;
                    break;
                case '[': sum2++;
                    rec2[cnt2++] = i;
                    break;
                case '{': sum3++;
                    rec3[cnt3++] = i;
                    break;
                case ')': sum1--;
                    if (sum1 < 0) return false;
                    if (cnt2 > 0 && rec2[cnt2-1] > rec1[cnt1-1]) return false;
                    if (cnt3 > 0 && rec3[cnt3-1] > rec1[cnt1-1]) return false;
                    cnt1--;
                    break;
                case ']': sum2--;
                    if (sum2 < 0) return false;
                    if (cnt1 > 0 && rec1[cnt1-1] > rec2[cnt2-1]) return false;
                    if (cnt3 > 0 && rec3[cnt3-1] > rec2[cnt2-1]) return false;
                    cnt2--;
                    break;
                case '}': sum3--;
                    if (sum3 < 0) return false;
                    if (cnt2 > 0 && rec2[cnt2-1] > rec3[cnt3-1]) return false;
                    if (cnt1 > 0 && rec1[cnt1-1] > rec3[cnt3-1]) return false;
                    cnt3--;
                    break;
            }
        }
        if (sum1 == 0 && sum2 == 0 && sum3 == 0) return true;
        else return false;
    }
};

int main(){
    return 0;
}