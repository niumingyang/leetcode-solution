#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        string row[numRows];
        for (int i = 0; i < numRows; ++i)
            row[i] = "";
        int j = 0;
        int flag = 0;
        for (int i = 0; i < s.size(); ++i){
            row[j] += s[i];
            if (flag == 0){
                if (j == numRows-1){
                    j--;
                    flag = 1;
                }
                else j++;
            }
            else{
                if (j == 0){
                    j++;
                    flag = 0;
                }
                else j--;
            }
        }
        string ret = "";
        for (int i = 0; i < numRows; ++i)
            ret += row[i];
        return ret;
    }
};

int main(){
    return 0;
}