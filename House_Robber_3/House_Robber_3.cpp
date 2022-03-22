#include <iostream>
#include <algorithm>

using namespace std;
using Pair = pair<int, int>;


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
    int rob(TreeNode* root) {  
        Pair result = robSub(root);
        return max(result.first, result.second);
    } 
    
    Pair robSub(TreeNode* node) {
        if(!node) return {0,0};
        
        Pair left = robSub(node->left);
        Pair right = robSub(node->right);
        Pair result;

        result.first = max(left.first, left.second) +
            max(right.first, right.second);
        result.second = node->val + left.first + right.first;

        return result;
    }
};


int main() {
    Solution solution;
    // TreeNode* root = new TreeNode(3);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(3);
    // root->left->right = new TreeNode(3);
    // root->right->right = new TreeNode(1);

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);
    //WRONG output...

    cout << solution.rob(root);
    return 0;
}