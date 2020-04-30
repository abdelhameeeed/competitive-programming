/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int ans = 0 ;
class Solution
{
public:
    int maxPathSum(TreeNode* root)
    {
        int rest = INT_MIN;
         solve( root , rest ) ;
        return rest;
    }
    int solve(TreeNode* root,int &res)
    {
        if (root == NULL)
        return 0;
    int l = solve(root->left,res);
    int r = solve(root->right,res);
    int max_single = max(max(l, r) + root->val, root->val);
    int max_top = max(max_single, l + r + root->val);

    res = max( res , max_top);

    return max_single;
    }
};
