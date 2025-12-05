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
    int lnr(TreeNode* root, int* temp)
    {
        if(root == nullptr)
        {
            return -10000000;
        }
        else if(root->left == nullptr && root->right == nullptr)
        {
            return root->val;
        }
        else
        {
            int l = lnr(root->left, temp);
            int r = lnr(root->right,temp);
            int a,b;

            
            a = max(l,r);
            b = max(a,l+r+root->val);
            *temp = max(*temp,b);


            return max(root->val, a+root->val);
            
        }
    }
    int maxPathSum(TreeNode* root) {
        int temp = -100000000;
        int temp2 = lnr(root, &temp);

        return max(temp,temp2);
    }
};