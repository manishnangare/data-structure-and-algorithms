class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());

        int i=0,j;
        int count = 0;

        while( i < points.size())
        {
            count++;
            j = i+1;

            while( j< points.size() && points[j][0] <= points[i][1] )
            {
                points[i][1] = min(points[i][1], points[j][1]);
                j++;
            }
            i = j;
        }

        return count;
    }
};