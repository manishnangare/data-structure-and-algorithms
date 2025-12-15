/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
    
    Node* connect(Node* root) {
        
        vector<Node*> bfs;
        int i = 0;

        if(root != nullptr)
            bfs.push_back(root);

        while(i < bfs.size())
        {
            int k = bfs.size();
            for(int j = i;j<k;j++)
            {
                if(bfs[j]->left != nullptr)
                {
                    bfs.push_back(bfs[j]->left);
                }
                
                if(bfs[j]->right != nullptr)
                {
                    bfs.push_back(bfs[j]->right);
                }
                
            }

            for(int j = i;j<k-1;j++)
            {
                bfs[j]->next = bfs[j+1];
            }
            bfs[k-1]->next = nullptr;
            i = k;
        }

        return root;

    }
};