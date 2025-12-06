class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        cout<<m<<" "<<n;
        if(obstacleGrid[m-1][n-1] == 1)
            return 0;

        vector<vector<long long>> temp(m,vector<long long>(n,0));

        temp[m-1][n-1] = 1;

        for( int i = m-1; i>=0;i--)
        {
            for(int j = n-1; j>=0;j--)
            {
                int right = 0, down = 0;
                if(obstacleGrid[i][j] != 1)
                {
                    if( i != m-1)
                        down = temp[i+1][j];

                    if( j != n-1)
                        right = temp[i][j+1];
                    
                    temp[i][j] += ((long)down + right);
                }
            }

        }

        return (int)temp[0][0];
    }
};