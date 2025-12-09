class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> a(m+2, vector<int>(n+2,2));

        int alive, dead;
        for( int i =0;i<m;i++)
        {
            for(int j =0; j<n;j++)
            {
                a[i+1][j+1] = board[i][j];
            }
        }

        for(int i =1;i<=m;i++)
        {
            for(int j =1;j<=n;j++)
            {
                alive = 0;
                dead = 0;

                for(int x = i-1;x<=i+1;x++)
                {

                    if( a[x][j-1] == 1)
                        alive++;

                    if(a[x][j+1] == 1)
                        alive++;
                    
                }

                if( a[i+1][j] == 1)
                    alive++;
                

                if( a[i-1][j] == 1)
                    alive++;
                

                if( a[i][j] == 1) //if alive
                {
                    if(alive < 2)
                        board[i-1][j-1] = 0;
                    else if( alive > 3)
                        board[i-1][j-1] = 0;
                    else
                        board[i-1][j-1] = 1;
                }
                else //if dead
                {
                    if(alive == 3)
                        board[i-1][j-1] = 1;
                }
            }
        }


    }
};