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
    TreeNode* merged_tree;
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
         mergeTrees(t1, t2, &merged_tree);  
         return merged_tree;  
    }

    void mergeTrees(TreeNode* t1, TreeNode* t2,
        TreeNode** merged_pointer) {

            if (t1 && t2)
                *merged_pointer = new TreeNode(t1->val + t2->val);
            else {
                if (t1) 
                    *merged_pointer = new TreeNode(t1->val);
                else if (t2)
                    *merged_pointer = new TreeNode(t2->val);
                else 
                    return;
            }

            mergeTrees(t1 ? t1->left : nullptr, 
                t2 ? t2->left : nullptr, 
                &(*merged_pointer)->left);
            mergeTrees(t1 ? t1->right : nullptr,
                 t2 ? t2->right : nullptr,
                 &(*merged_pointer)->right);
                        
    }
};

int main() {
    Solution solution;
    TreeNode* merged_tree;

    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(3);
    root1->left->left = new TreeNode(5);
    root1->right = new TreeNode(2);

    TreeNode* root2 = new TreeNode(2);
    root2->left = new TreeNode(1);
    root2->left->right = new TreeNode(4);
    root2->right = new TreeNode(3);
    root2->right->right = new TreeNode(7);

    merged_tree = solution.mergeTrees(root1, root2);

    cout << "done" << endl;

    return 0;
}