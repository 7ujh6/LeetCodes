#include <iostream>

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
    int smallest = -1;
    int count = 0;
public:
    int kthSmallest(TreeNode* root, int k) {
        //Edge Cases
        count = k;
        traverse(root);
        return smallest;
    }

    void  traverse(TreeNode* current) {  
        if (current->left)
            traverse(current->left);
        count--;
        
        if (!count) {
            smallest = current->val;
            count--;
        }   

        if (current->right)
            traverse(current->right);

        return;   
    }
};

int main () {
    Solution solution;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    root->right = new TreeNode(4);

    // TreeNode* root = new TreeNode(5);
    // root->left = new TreeNode(3);
    // root->right = new TreeNode(6);
    // root->left->left = new TreeNode(2);
    // root->left->right = new TreeNode(4);
    // root->left->left->left = new TreeNode(1);
    
    int k = 
    1;
    // 3;

    cout << solution.kthSmallest(root, k);
    return 0;
}