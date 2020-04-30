/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int>arrtemp ;
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        arrtemp = arr ;
        return  solve( root , 0 ) ;
    }
    bool solve(TreeNode* root , int ind )
    {
        if( root == NULL  || ind == arrtemp.size() )
            return false ;
        bool F = 0 , G = 0 ;
         if( root->val == arrtemp[ind] )
         {
            if( root->left == NULL && root->right == NULL && ind + 1 == arrtemp.size() ) return true ;
            F = solve(root->left  , ind + 1 )  ;
            G = solve(root->right , ind + 1 ) ;
         }
        if( F || G ){ return true ; }
        return false ;
    }
};
