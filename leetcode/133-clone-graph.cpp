/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        
        if(node == nullptr)
            return nullptr;

        map<Node*,Node*> m;
        map<Node*,int> v;

        vector<Node*> q;
        int n = 0;

        q.push_back(node);
        v[ q.back()] = 1;

        Node* temp = new Node(q.back()->val);
        m[q.back()] = temp;

        while(n != q.size())
        {
            for(int i =0; i< q[n]->neighbors.size();i++)
            {
                if(v[q[n]->neighbors[i]] == 0)
                {
                    q.push_back(q[n]->neighbors[i]);
                    v[ q.back()] = 1;
                    temp = new Node( q.back()->val);
                    m[ q.back()] = temp;
                }
            }
            n++;
        }

        for(int i =0;i<q.size();i++)
        {
            for( int j =0; j< q[i]->neighbors.size();j++)
            {
                m[ q[i]]->neighbors.push_back( m[ q[i]->neighbors[j] ]);
            }
        }


        return m[q[0]];
    }
};