class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        map<string,int> nodeMap;
        map<string,int> validNodes;
        vector<string> nodes;

        for( vector<string> a: equations)
        {
            if( nodeMap[a[0]] == 0)
            {
                nodes.push_back(a[0]);
                nodeMap[a[0]]++;
            }
            
            if( nodeMap[a[1]] == 0)
            {
                nodes.push_back(a[1]);
                nodeMap[a[1]]++;
            }
        }

        for(int i=0;i<nodes.size();i++)
        {
            nodeMap[nodes[i]] = i;
            validNodes[nodes[i]] = 1;
        }

        vector<vector<double>> adj(nodes.size(), vector<double>(nodes.size(),-1));

        for(int i=0;i<equations.size();i++)
        {
            adj[ nodeMap[equations[i][0]]][nodeMap[equations[i][1]]] = values[i];
            adj[ nodeMap[equations[i][1]]][nodeMap[equations[i][0]]] = 1/values[i];
        }

        for(int i=0;i<adj.size();i++)
            adj[i][i] = 1;
        
        for(int i=0;i<adj.size();i++)
        {
            for(int j=0;j<adj.size();j++)
            {
                for(int k=0;k<adj.size();k++)
                {
                    if( j != i && k != i)
                    {
                        if(adj[j][k] == -1 && adj[i][k] != -1 && adj[j][i] != -1)
                        {
                            adj[j][k] = adj[i][k] * adj[j][i];
                        }
                    }
                }
            }
        }

        vector<double> op;

        for(vector<string> a: queries)
        {
            if( validNodes[a[0]] == 0 || validNodes[a[1]] == 0)
                op.push_back(-1);
            else
            {
                float x = adj[ nodeMap[a[0]]][nodeMap[a[1]]];
                op.push_back(x);
            }
        }

        return op;

    }
};