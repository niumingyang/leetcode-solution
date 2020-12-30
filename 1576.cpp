#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string modifyString(string s) {
        for (int i = 0; i < s.size();){
            if (s[i] != '?') {
                i++;
                continue;
            }
            int index = i+1;
            while (index < s.size() && s[index] == '?') index++;
            if (i == 0){
                if (index == s.size()) 
                    for (int j = i; j < index; ++j){
                        if (j%2 == 0) s[j] = 'a';
                        else s[j] = 'c';
                    }
                else {
                    char t = (s[index]=='c'?'a':'c');
                    char r = (t=='a'?'c':'a');
                    for (int j = i; j < index; ++j){
                        if ((index-j)%2 == 0) s[j] = r;
                        else s[j] = t;
                    }
                }
            }
            else {
                if (index == s.size()){
                    char t = (s[i-1]=='c'?'a':'c');
                    char r = (t=='a'?'c':'a');
                    for (int j = i; j < index; ++j){
                        if ((i-j)%2 == 0) s[j] = t;
                        else s[j] = r;
                    }
                }
                else {
                    char t, r;
                    if (s[i-1] != 'x' && s[index] != 'x') t = 'x';
                    else if (s[i-1] != 'y' && s[index] != 'y') t = 'y';
                    else if (s[i-1] != 'z' && s[index] != 'z') t = 'z';
                    if (s[i-1] != 'm' && s[index] != 'm') r = 'm';
                    else if (s[i-1] != 'n' && s[index] != 'n') r = 'n';
                    else if (s[i-1] != 'p' && s[index] != 'p') r = 'p';
                    if (index == i+1) s[i] = t;
                    else{
                        for (int j = i+1; j < index-1; ++j){
                            if (j%2 == 0) s[j] = 'a';
                            else s[j] = 'c';
                        }
                        s[i] = t; s[index-1] = r;
                    }
                }
            }
            i = index;
        }
        return s;
    }
};

int main(){
    return 0;
}