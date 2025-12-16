class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size(), m = matrix[0].size();
        
        int l = 1,r = m*n,a,b,mid;

        while(l<=r)
        {
            mid = (l+r)/2;
            a = (mid-1)/m;
            b = (mid-1)%m;

            if(matrix[a][b] == target)
            {
                return true;
            }
            else if( matrix[a][b] < target)
            {
                l = mid+1;
            }
            else
            {
                r = mid-1;
            }
        }
        return false;

    }
};