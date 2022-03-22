#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> out;

        out_order(root, out, 0);

        return out;   
    }

    void out_order(TreeNode* curr, vector<int>& out, int index) {
        if (!curr)
            return;
        if (index == out.size()) 
            out.push_back(curr->val);
        out_order(curr->right, out, index+1);
        out_order(curr->left, out, index+1);
    }
};

int main () {
    Solution solution;
    // TreeNode* root = new TreeNode(1);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(3);
    // root->left->right = new TreeNode(5);
    // root->right->right = new TreeNode(4);

    // TreeNode* root = new TreeNode(1);
    // root->right = new TreeNode(3);

    // TreeNode* root = new TreeNode(10);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(3);
    // root->left->left = new TreeNode(7);
    // root->left->right = new TreeNode(8);
    // root->right->left = new TreeNode(12);
    // root->right->right = new TreeNode(15);
    // root->right->right->left = new TreeNode(14);

    // TreeNode* root = new TreeNode(1);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(3);
    // root->left->left = new TreeNode(4);
    // root->left->right = new TreeNode(5);
    // root->right->left = new TreeNode(6);
    // root->right->right = new TreeNode(7);
    // root->right->right->right = new TreeNode(8);

    TreeNode* root =  nullptr;

    vector<int> answer = solution.rightSideView(root);

    for (int elem : answer) 
        cout << elem << " ";
    
    return 0;

}