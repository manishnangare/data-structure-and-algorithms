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
    
    void flatten(TreeNode* root) {
        
        
        if( root != nullptr)
        {
            if(root->left == nullptr && root->right == nullptr)
            {
                return;
            }
            else if(root->left != nullptr)
            {
                
                flatten(root->left);
                flatten(root->right);
                TreeNode *temp;
                temp = root->left;
                while(temp->right != nullptr)
                {
                    temp = temp->right;
                }
                temp->right = root->right;
                root->right = root->left;
                root->left = nullptr;
            }
            else
            {
                flatten(root->right);
            }
            return;  
        }
        return;
    }
};