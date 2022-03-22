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
    int count = 0;
public:
    int numTrees(int n) {

        TreeNode* head = new TreeNode(1);
        
        numTrees(1, n, nullptr, nullptr, head);
        return count;
    }

    void numTrees(int curr, int n, TreeNode* left, TreeNode* right, TreeNode*&previous) {
        if (curr == n) {
            count++;
            return;
        }

        if (left) {
            previous->left = left;
            previous = previous->left;
        } 

        if (right) {
            previous->right = right;
            previous = previous->right;
        }


        //simulates left insertion
        numTrees(curr+1, n, new TreeNode(curr+1), nullptr, previous);

        //simulates right insertion
        numTrees(curr+1, n,  nullptr, new TreeNode(curr+1), previous);
    
    }
};

int main()  {
    Solution solution;
    int n = 3;

    cout << solution.numTrees(n);
    return 0;
}