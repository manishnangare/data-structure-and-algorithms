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
class BSTIterator {
public:
    vector<int> lnr;
    int p;

    void getTree(TreeNode* root, vector<int> &lnr)
    {
        if(root != nullptr)
        {
            getTree(root->left,lnr);
            lnr.push_back(root->val);
            getTree(root->right,lnr);
        }
    }

    BSTIterator(TreeNode* root) {
        
        getTree(root,lnr);
        p = 0;

    }
    
    int next() {
        if( p < lnr.size())
        {
            return lnr[p++];
        }
        else
        {
            return lnr[0];
        }
    }
    
    bool hasNext() {
        if( p < lnr.size())
            return true;
        else
            return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */