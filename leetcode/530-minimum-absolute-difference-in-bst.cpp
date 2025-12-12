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
    void getBFS(TreeNode* root, vector<int> &a)
    {
        if(root != nullptr)
        {
            a.push_back(root->val);

            getBFS(root->left,a);
            getBFS(root->right,a);
        }
    }
    int getMinimumDifference(TreeNode* root) {
        
        vector<int> a;
        getBFS(root,a);

        int diff = 1000000;

        for(int i =0; i<a.size()-1;i++)
        {
            for(int j = i+1; j<a.size();j++)
            {
                diff = min( diff, abs(a[i] - a[j]));
            }
        }
        return diff;
    }
};