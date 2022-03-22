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
    int max = 0;
public:
    int maxDepth(TreeNode* root) {
        if (!root) 
            return 0;
            
        maxDepth (root, 1);
        return max;
    }

    void maxDepth (TreeNode* root, int path_length) {
        max = max < path_length ? path_length : max;

        if (root->left)
            maxDepth(root->left, path_length + 1);
        if (root->right)
            return maxDepth(root->right, path_length + 1);
    }
};

int main () {
    Solution solution;
    // TreeNode* root = new TreeNode(3);
    // root->left = new TreeNode(9);
    // root->right = new TreeNode(20);
    // root->right->left = new TreeNode(15);
    // root->right->right = new TreeNode(7);

    // TreeNode* root = new TreeNode(1);
    // root->right = new TreeNode(2);

    // TreeNode* root = NULL;

    TreeNode* root = new TreeNode(0);


    cout << solution.maxDepth(root);
}
