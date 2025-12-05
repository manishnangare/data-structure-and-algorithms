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
    vector<double> averageOfLevels(TreeNode* root) {

        
        vector<double> result;
        if(root == nullptr)
            return result;
        vector<TreeNode*> queue;

        queue.push_back(root);

        while( queue.size() != 0)
        {
            int count = queue.size();
            long sum = 0;
            for(int i =0; i<count;i++)
            {
                
                sum += queue[0]->val;

                if(queue[0]->left != nullptr)
                    queue.push_back(queue[0]->left);

                if(queue[0]->right != nullptr)
                    queue.push_back(queue[0]->right);

                queue.erase(queue.begin());
            }
            double avg = (double)sum/count;
            result.push_back(avg);
        }
        return result;

    }
};