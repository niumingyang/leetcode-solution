#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string s[n];
        s[0] = "1";
        for (int i = 1; i < n; ++i){
            s[i] = "";
            int num = 1;
            char now = s[i-1][0];
            for (int j = 1; j < s[i-1].size(); ++j){
                if (s[i-1][j] == now) num++;
                else {
                    s[i] = s[i]+to_string(num)+now;
                    now = s[i-1][j];
                    num = 1;
                }
            }
            s[i] = s[i]+to_string(num)+now;
        }
        return s[n-1];
    }
};

int main(){
    return 0;
}