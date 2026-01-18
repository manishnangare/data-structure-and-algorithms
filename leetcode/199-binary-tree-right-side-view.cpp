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
    vector<int> rightSideView(TreeNode* root) {
        
        if(root == nullptr)
            return {};
        else
        {
            queue<TreeNode*> q;
            int layerCount = 1;
            vector<int> res = {root->val};

            q.push(root);

            while(layerCount != 0)
            {
                int count =0;

                for(int i =0;i<layerCount;i++)
                {
                    if(q.front()->left != nullptr)
                    {
                        count++;
                        q.push(q.front()->left);
                    }

                    if(q.front()->right != nullptr)
                    {
                        count++;
                        q.push(q.front()->right);
                    }

                    q.pop();
                }

                layerCount = count;

                if(count != 0)
                    res.push_back( q.back()->val);

            }

            return res; 

        }

    }
};