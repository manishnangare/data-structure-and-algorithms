class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        
        vector<int> nodes;
        nodes.push_back(0);
        int n = board.size();
         
        n *= n;

        int flip = 0;
        for(int i=board.size()-1;i>=0;i--)
        {
            if(flip == 0)
            {
                for(int j=0;j<board[i].size();j++)
                {
                    nodes.push_back(board[i][j]);
                }
                flip = 1;
            }
            else
            {
               for(int j=board[i].size()-1;j>=0;j--)
                {
                    nodes.push_back(board[i][j]);
                }
                flip = 0; 
            }
        }

        vector<int> q;
        map<int,int> visited;

        q.push_back(1);
        visited[1] = 1;

        int layer = 0;

        while(q.size() > 0)
        {   
            vector<int> t;
            layer++;
            
            for( int a: q)
            {
                for(int i = a+1; i <= a+6 && i<=n; i++)
                {  
                    if( visited[i] == 0 && nodes[i] == -1)
                    {
                        t.push_back(i);
                        visited[i] = 1;
                    }
                    else if( visited[nodes[i]] == 0)
                    {
                        t.push_back(nodes[i]);
                        visited[nodes[i]] = 1;
                    }
                    
                }
            }

            q = t;

            if(visited[n] == 1)
                return layer;

        }

        return -1;
    }
};