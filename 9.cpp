#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        string s = to_string(x);
        string s1;
        s1.assign(s.rbegin(), s.rend());
        return s1 == s;
    }
};

int main(){
    return 0;
}