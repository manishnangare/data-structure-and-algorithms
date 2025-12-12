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
    void getBFS(TreeNode* root, vector<int> &a,int k)
    {
        if(a.size() >=  k)
            return;
        else if(root != nullptr)
        {
            getBFS(root->left,a,k);
            a.push_back(root->val);
            cout<<a.back()<<" ";
            
            getBFS(root->right,a,k);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> a;
        getBFS(root,a,k);

        return a[k-1];
    }
};