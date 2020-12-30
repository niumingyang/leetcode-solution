#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        char c = '=';
        while (i < s.size() && s[i] == ' ') i++;
        if (i == s.size()) return 0;
        switch(s[i]){
            case '+': c = '+'; i++; break;
            case '-': c = '-'; i++; break;
            case '0':case '1':case '2':case '3':case '4':
            case '5':case '6':case '7':case '8':case '9':
                break;
            default: return 0;
        }
        int j = i;
        while (j < s.size() && isdigit(s[j])) j++;
        long long ret = 0;
        while (i < j){
            ret = (ret*10) + (s[i]-'0');
            i++;
            if ((c == '-' && -ret < INT_MIN) || ret > INT_MAX){
                if (c == '-') return INT_MIN;
                else return INT_MAX;
            }
        }
        if (c == '-') ret = -ret;
        return ret;
    }
};

int main(){
    Solution s;
    cout << s.myAtoi("+-9207482347283948982374832");
    return 0;
}