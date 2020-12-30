#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    // int to_number(string s, int begin, int end){
    //     int _begin = begin, _end = end-1;
    //     while (s[_begin] == ' ') _begin++;
    //     while (s[_end] == ' ') _end--;
    //     int res = 0;
    //     while (_begin <= _end){
    //         res *= 10;
    //         res += (s[_begin] - '0');
    //         _begin++;
    //     }
    //     return res;
    // }
    // int cal_mul_and_div(string s, int begin, int end){
    //     int res = 1;
    //     int flag = 1;//1  means *, 0 means /
    //     for (int i = begin; i < end;){
    //         int j = i;
    //         while (j < end && s[j] != '*' && s[j] != '/') j++;
    //         if (flag) res *= to_number(s, i, j);
    //         else res /= to_number(s, i, j);
    //         if (j == end) return res;
    //         if (s[j] == '*') flag = 1;
    //         if (s[j] == '/') flag = 0;
    //         i = j+1;
    //     }
    //     return res;
    // }
    // int calculate(string s) {
    //     int res = 0;
    //     int flag = 1;//1  means +, 0 means -
    //     for (int i = 0; i < s.size();){
    //         int j = i;
    //         while (j < s.size() && s[j] != '+' && s[j] != '-') j++;
    //         if (flag) res += cal_mul_and_div(s, i, j);
    //         else res -= cal_mul_and_div(s, i, j);
    //         if (j == s.size()) return res;
    //         if (s[j] == '+') flag = 1;
    //         if (s[j] == '-') flag = 0;
    //         i = j+1;
    //     }
    //     return res;
    // }
    int calculate(string s) {
        stack<int> sta;
        char c = '+';
        int num = 0;
        for(int i = 0; i <= s.length(); i++){
            if(isdigit(s[i])){
                num = num*10 + (s[i] - '0');
            }else if(isspace(s[i])){
                continue;
            }else{
                switch(c){
                    case '+': sta.push(num); break;
                    case '-': sta.push(-num); break;
                    case '*': num *= sta.top(); sta.pop(); sta.push(num); break;
                    case '/': num = sta.top()/num; sta.pop(); sta.push(num); break;
                }
                num = 0;
                c = s[i];
            }
        }
        int res = 0;
        while(!sta.empty()){
            res += sta.top();
            sta.pop();
        }
        return res;
    }
};

int main(){
    Solution s;
    cout << s.calculate(" 8/4*32/5+  32234 -98 ");
    return 0;
}