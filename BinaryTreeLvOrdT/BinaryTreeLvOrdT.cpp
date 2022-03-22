#include <iostream>
#include <vector>

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;

        if (root)
            levelOrder(root, result, 0);

        return result;
    }

    void levelOrder(TreeNode* curr, vector<vector<int>>& result, int level) {
        if (level == result.size())
            result.push_back(vector<int>());
        
        result[level].push_back(curr->val);

        if (curr->left)
            levelOrder(curr->left, result, level+1);
        if (curr->right)
            levelOrder(curr->right, result, level+1);
        
    }
};

int main () {
    Solution solution;
    TreeNode* head = nullptr;
    // TreeNode* head = new TreeNode(3);
    // head->left = new TreeNode(9);
    // head->right = new TreeNode(20);
    // head->right->left = new TreeNode(15);
    // head->right->right = new TreeNode(7);

    vector<vector<int>> answer = solution.levelOrder(head);

    for (vector<int> v: answer) {
        cout << "[";
        for (int elem: v)
            cout << elem << ",";
        cout << "]," << endl;
    }

    return 0;
}