#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int to_number(char c){
        switch(c){
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default:  return 0;
        }
    }
    int romanToInt(string s) {
        int last = 0, now = 0;
        int sum = 0;
        for (int i = 0; i < s.size(); ++i){
            now = to_number(s[i]);
            if (now > last) sum -= last;
            else sum += last;
            last = now;
        }
        sum += now;
        return sum;
    }
};

int main(){
    Solution s;
    cout << s.romanToInt("III") << endl;
    cout << s.romanToInt("IV") << endl;
    cout << s.romanToInt("IX") << endl;
    cout << s.romanToInt("LVIII") << endl;
    cout << s.romanToInt("MCMXCIV") << endl;
    return 0;
}