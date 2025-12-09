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
    int sumNumbers(TreeNode* root) {
        
        if( root == nullptr)
        {
            return 0;
        }
        else if(root->left != nullptr && root->right != nullptr)
        {
            root->left->val += root->val*10;
            root->right->val += root->val*10;

            return sumNumbers(root->left) + sumNumbers(root->right);
        }
        else if(root->left != nullptr && root->right == nullptr)
        {
            root->left->val += root->val*10;

            return sumNumbers(root->left);
        }
        else if(root->left == nullptr && root->right != nullptr)
        {
            root->right->val += root->val*10;
            return sumNumbers(root->right);
        }
        else
        {
            return root->val;
        }
    }
};