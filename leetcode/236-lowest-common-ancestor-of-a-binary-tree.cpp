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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr)
        {
            return nullptr;
        }
        else if(root != p && root != q)
        {
            root->left = lowestCommonAncestor(root->left,p,q);
            root->right = lowestCommonAncestor(root->right,p,q);

            if(root->left == p && root->right == q || root->left == q && root->right == p )
                return root;
            if(root->left == p || root->left == q)
                return root->left;
            else if(root->right ==p || root->right == q)
                return root->right;
            else if(root->right == nullptr && root->left != nullptr)
                return root->left;
            else if(root->right != nullptr && root->left == nullptr)
                return root->right;
            else
                return nullptr;
        }
        else
        {
            return root;
        }   

    }
};