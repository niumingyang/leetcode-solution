#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string ret = "";
        for (int i = 0; i < num/1000; ++i) ret += 'M';
        num %= 1000;
        //已经转化为1000以内
        if (num >= 900){
            num -= 900;
            ret += "CM";
        }
        else if (num >= 500){
            num -= 500;
            ret += 'D';
            for (int i = 0; i < num/100; ++i) ret += 'C';
            num %= 100;
        }
        else if (num >= 400){
            num -= 400;
            ret += "CD";
        }
        else {
            for (int i = 0; i < num/100; ++i) ret += 'C';
            num %= 100;
        }
        //已经转化为100以内
        if (num >= 90){
            num -= 90;
            ret += "XC";
        }
        else if (num >= 50){
            num -= 50;
            ret += 'L';
            for (int i = 0; i < num/10; ++i) ret += 'X';
            num %= 10;
        }
        else if (num >= 40){
            num -= 40;
            ret += "XL";
        }
        else {
            for (int i = 0; i < num/10; ++i) ret += 'X';
            num %= 10;
        }
        //已经转化为10以内
        switch (num){
            case 0: break;
            case 1: ret += "I"; break;
            case 2: ret += "II"; break;
            case 3: ret += "III"; break;
            case 4: ret += "IV"; break;
            case 5: ret += "V"; break;
            case 6: ret += "VI"; break;
            case 7: ret += "VII"; break;
            case 8: ret += "VIII"; break;
            case 9: ret += "IX"; break;
        }
        return ret;
    }
};

int main(){
    Solution s;
    cout << s.intToRoman(4) << endl;
    cout << s.intToRoman(9) << endl;
    cout << s.intToRoman(58) << endl;
    cout << s.intToRoman(1994) << endl;
    return 0;
}