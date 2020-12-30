#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
���ζ�̬�滮
Ϊ��ʵ�ּ��仯������ʹ��unordered_map��¼�Ѿ������ֵ
�Ż�����������map��f��g���ֱ��ʾ��ǰ�ڵ�ѡ�벻ѡ�����Ž����ʹ�ú������dfs����ÿ���ڵ��f��g
���������Ż���ÿ�μ���֮��f��g������
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