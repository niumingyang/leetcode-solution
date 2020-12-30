#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    int height(TreeNode* k){
        if (k == nullptr) return 0;
        int leftheight = height(k->left);
        if (leftheight == -1) return -1;
        int rightheight = height(k->right);
        if (rightheight == -1) return -1;
        if (abs(leftheight-rightheight) > 1)
            return -1;
        return max(leftheight+1, rightheight+1);
    }
    bool isBalanced(TreeNode* root) {
        return height(root) >= 0;
    }
};

int main(){
    return 0;
}