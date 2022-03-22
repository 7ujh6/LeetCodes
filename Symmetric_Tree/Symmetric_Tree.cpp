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
public:
    bool isSymmetric(TreeNode* root) {
        
        TreeNode* sub_t1_root = root, * sub_t2_root = root;
        return isSymmetric(sub_t1_root, sub_t2_root);   
    }

    bool isSymmetric (TreeNode* sub_t1_root, TreeNode* sub_t2_root) {
        
        if (!sub_t1_root && !sub_t2_root)
            return true;

        else {
            if (sub_t1_root && sub_t2_root) {
                if (sub_t1_root->val == sub_t2_root->val) {
                    return isSymmetric(sub_t1_root->left, sub_t2_root->right) && 
                        isSymmetric(sub_t1_root->right, sub_t2_root->left);
                }
            }
            return false;
        }    
    }
};

int main() {
    Solution solution;
    
    TreeNode *root = new TreeNode(1); 
    root -> left = new TreeNode(3); 
    root -> right = new TreeNode(3); 
    root -> left -> left = new TreeNode(4); 
    root -> left -> right = new TreeNode(6);
    root -> right -> left = new TreeNode(6);
    root -> right -> right = new TreeNode(4);
    
    
    // TreeNode* root = NULL;
    
    
    // TreeNode* root = new TreeNode(1);
    
    cout << solution.isSymmetric(root);

    return 0;
}