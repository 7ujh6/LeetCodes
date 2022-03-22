class Solution {
public:
    int rob(TreeNode* root) {
        bool permit;
        int MAX=0;
        MAX = max(max(MAX, aggregate(root, !permit, new int(0))), 
            max(MAX, aggregate(root, permit, new int(0))));
        return MAX;      
    }

    int aggregate(TreeNode* node, bool permit, int* sum) {
        if (permit) 
            *sum+=node->val;
        if (node->left)
            aggregate(node->left, !permit, sum);
        if(node->right)
            aggregate(node->right, !permit, sum);

        return *sum;
    }
};