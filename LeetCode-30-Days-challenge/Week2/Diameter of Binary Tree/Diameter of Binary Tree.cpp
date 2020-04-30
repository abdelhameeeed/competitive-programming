/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    private:
    int ans = 0 ;
public:
    int diameterOfBinaryTree(TreeNode* root)
    {
        solve(root) ;
        return ans  ;
    }
    int solve(TreeNode* root){

        if(root == NULL ) return 0 ;
        int leftt = 0 ;
        if(root->left != NULL ) leftt = 1 + solve( root-> left ) ;
        int rightt = 0 ;
        if(root->right!=NULL) rightt = 1 + solve(root->right) ;
        ans = max ( ans , leftt + rightt ) ;
        return  max( leftt , rightt ) ;
    }
};
