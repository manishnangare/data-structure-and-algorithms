class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        for(int i =0;i<board.size();i++)
        {
            map<int,int> m;

            for(int j =0;j<board.size();j++)
            {
                if( board[i][j] != '.')
                {
                    if(m[board[i][j]] == 1)
                        return false;
                    else
                    {
                        m[ board[i][j] ]++;
                    }
                }
            }
        }

        for(int i =0;i<board.size();i++)
        {
            map<int,int> m;

            for(int j =0;j<board.size();j++)
            {
                if( board[j][i] != '.')
                {
                    if(m[board[j][i]] == 1)
                        return false;
                    else
                    {
                        m[ board[j][i] ]++;
                    }
                }
            }
        }

        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                map<int,int> m;

                for(int a=0;a<3;a++)
                {
                    for(int b=0;b<3;b++)
                    {
                        if(board[a+i*3][b+j*3] != '.')
                        {
                            if(m[board[a+ i*3][b+j*3]] == 1)
                                return false;
                            else
                            {
                                m[ board[a + i*3][b + j*3] ]++;
                            }
                        }
                    }
                }
            }
        }
        
        return true;
    }
};