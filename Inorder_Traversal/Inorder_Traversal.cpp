#include <vector>
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
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root)
            return vector<int>();
        
        vector<int> nodes;
        inorderTraversal(root, nodes);
        return nodes;
    }

    void inorderTraversal(TreeNode* root, vector<int>& nodes) {

        if (root->left) 
            inorderTraversal(root->left, nodes);

        nodes.push_back(root->val);

        if (root->right)
            inorderTraversal(root->right, nodes);

    }
};

int main() {
    Solution solution;
    // TreeNode* root = new TreeNode(1);
    // root->right = new TreeNode(2);
    // root->right->left = new TreeNode(3);

    // TreeNode* root = new TreeNode(1);
    // root->left = new TreeNode(2);

    // TreeNode* root = new TreeNode(1);
    // root->right = new TreeNode(2);

    TreeNode* root = nullptr;

    vector<int> answer = solution.inorderTraversal(root);

    for (int elem: answer) {
        cout << elem;
    }

    return 0;
}