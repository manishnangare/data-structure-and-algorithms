class Solution {
public:
    void solve(vector<vector<char>>& board) {
        map<int,map<int,int>> m;

        queue<vector<int>> q;

        int r = board.size()-1;
        int c = board[0].size()-1;

        for(int i=0; i<=r;i++)
        {
            for(int j=0; j<=c;j++)
            {
                if(board[i][j] == 'O' && m[i][j] == 0)
                {
                    queue<vector<int>> q;
                    vector<vector<int>> q1;
                    bool valid = true;
                    q.push({i,j});
                    m[i][j] = 1;
                    int a,b;

                    while(q.size() > 0 )
                    {
                        q1.push_back(q.front());
                        a = q.front()[0];
                        b = q.front()[1];


                        if(a == 0 || a == r || b == 0 || b == c)
                            valid = false;
                        
                        if(a+1 <= r && board[a+1][b] == 'O' && m[a+1][b] != 1 )
                        {
                            q.push({a+1,b});
                            m[a+1][b] = 1;
                        }
                        
                        if(a-1 >= 0 && board[a-1][b] == 'O' && m[a-1][b] != 1)
                        {
                            q.push({a-1,b});
                            m[a-1][b] = 1;
                        }

                        if(b+1 <= c && board[a][b+1] == 'O' && m[a][b+1] != 1 )
                        {
                            q.push({a,b+1});
                            m[a][b+1] = 1;
                        }

                        if(b-1 >= 0 && board[a][b-1] == 'O' && m[a][b-1] != 1)
                        {
                            q.push({a,b-1});
                            m[a][b-1] = 1;
                        }

                        q.pop();
                    }

                    if(valid)
                    {
                        for( vector<int> a : q1)
                        {
                            board[a[0]][a[1]] = 'X';
                        }
                    }
                }
            }
        }

    }
};