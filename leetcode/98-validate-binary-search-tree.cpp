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
    void getBST(TreeNode* root, vector<int> &a)
    {
        if(root != nullptr)
        {
            getBST(root->left,a);
            a.push_back(root->val);
            getBST(root->right,a); 
        }
    }
    bool isValidBST(TreeNode* root) {
        vector<int> a;
        getBST(root,a);

        if(a.size() == 1)
            return true;
        else
        {
            for(int i =0; i< a.size()-1;i++)
            {
                if(a[i+1] <= a[i])
                    return false;
            }
            return true;
        }
    }
};