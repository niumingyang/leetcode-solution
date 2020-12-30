#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
树形动态规划
为了实现记忆化搜索，使用unordered_map记录已经计算的值
优化：计算两个map，f和g，分别表示当前节点选与不选的最优结果，使用后序遍历dfs计算每个节点的f和g
滚动数组优化：每次计算之后将f和g都返回
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    unordered_map<TreeNode*, int> sum;
public:
    int rob(TreeNode* root) {
        if (root == NULL) return 0;
        else if (sum.count(root)){
            return sum[root];
        }
        else {
            int robed, unrobed;
            unrobed = rob(root->left) + rob(root->right);
            robed = root->val;
            if (root->left!=NULL) robed += rob(root->left->left) + rob(root->left->right);
            if (root->right!=NULL) robed += rob(root->right->left) + rob(root->right->right);
            sum[root] = max(robed, unrobed);
            return sum[root];
        }
    }
};

int main(){
    return 0;
}