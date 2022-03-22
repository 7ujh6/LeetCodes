#include <iostream>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
              return traverse(root, p, q);
    }

    TreeNode* traverse (TreeNode* node, TreeNode* p, TreeNode* q) {
        if (!node || node == p || node == q)
            return node;
        TreeNode *left = traverse(node->left, p, q),
         *right = traverse(node->right, p, q);
        
        if (left && right)
            return node;
        
        return left ? left : right;
    }
};


int main() {
    Solution solution;
    // TreeNode* root = new TreeNode(3);
    // root->left = new TreeNode(5);
    // root->right = new TreeNode(1);
    // root->left->left = new TreeNode(6);
    // root->left->right = new TreeNode(2);
    // root->right->left = new TreeNode(0);
    // root->right->right = new TreeNode(8);
    // root->left->right->left = new TreeNode(7);
    // root->left->right->right = new TreeNode(4); 

    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);

    TreeNode *p = 
    // root->left;
    // root->left;
    root;
    TreeNode *q = 
    // root->right;
    // root->left->right->right;
    root->left;

    cout << solution.lowestCommonAncestor(root, p, q)->val;
    return 0;
}