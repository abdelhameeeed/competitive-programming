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
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode *root = NULL ;
        for( int i = 0 ; i < preorder.size() ; i ++ )
        {
             root = insert( root , preorder[i] ) ;
        }
        return root ;
    }
    TreeNode* insert( TreeNode *root , int data )
    {
        if( root == NULL )
        {
            root = makenewnode( data ) ;
            return root ;
        }
        else if( root->val > data ) {  root -> left = insert( root -> left , data ) ;  }
        else {    root->right = insert( root -> right , data )  ; }
        return root ;
    }

    TreeNode* makenewnode( int data )
    {
        TreeNode *node = new TreeNode() ;
        node->val = data ;
        node->left=node->right=NULL;
        return node ;
    }
};
