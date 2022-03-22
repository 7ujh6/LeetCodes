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
    TreeNode** curr;
    void flatten(TreeNode* root) {
        //You have a reference; then you create a new reference to the right; in preorder, you push all the left
        //reference to the right; when you have fully traversed the left subtree, close it off (i.e. left == null)
        //then your traverse the right subtree.

        if (!root || (!root->left && !root->right)) 
            return;

        curr = &root;
        TreeNode* left_st = root->left;
        TreeNode* right_st = root->right;
        if (left_st)
            preorder_append(left_st);

        root->left = nullptr;

        if (right_st)
            preorder_append(right_st);
    }

    void preorder_append(TreeNode* subtree) {
        (*curr)->right = new TreeNode(subtree->val);
        curr = &((*curr)->right);

        if (subtree->left)
            preorder_append(subtree->left); 
        
        if (subtree->right)
            preorder_append(subtree->right);
    }
};

int main() {
    Solution solution;

    // TreeNode* root = new TreeNode(1);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(5);
    // root->left->left = new TreeNode(3);
    // root->left->right = new TreeNode(4);
    // root->right->right = new TreeNode(6);

    // TreeNode* root = new TreeNode(1);
    // root->right = new TreeNode(2);
    // root->right->right = new TreeNode(3);
    // root->right->right->right = new TreeNode(4);
    // root->right->right->right->right = new TreeNode(5);
    // root->right->right->right->right->right = new TreeNode(6);
    

    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(5);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(6);
    root->right->left->left = new TreeNode(3);
    root->right->left->right = new TreeNode(4);

    // TreeNode* root = nullptr;

    // TreeNode* root = new TreeNode(0);

    solution.flatten(root);

    cout << (root ? root->val : -1);


    return 0;
}

//Preorder: 
//root
//left
//right