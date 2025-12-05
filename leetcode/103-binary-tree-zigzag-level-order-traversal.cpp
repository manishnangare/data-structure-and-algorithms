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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<TreeNode*> queue;
        vector<vector<int>> result;

        if(root == nullptr)
            return result;

        queue.push_back(root);
        bool turn = true;
        while(queue.size() != 0)
        {
            vector<int> level ;
            int count = queue.size();
            for(int i =0;i<count;i++)
            {
                if(turn)
                    level.push_back(queue[0]->val);
                else
                    level.insert(level.begin(),queue[0]->val);

                if(queue[0]->left != nullptr)
                    queue.push_back(queue[0]->left);

                if(queue[0]->right != nullptr)
                    queue.push_back(queue[0]->right);

                queue.erase(queue.begin());
                
            }
            result.push_back(level);
            turn = !turn;
        }

        return result;
    }
};