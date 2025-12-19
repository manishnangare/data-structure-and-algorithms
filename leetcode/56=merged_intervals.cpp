class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        
        vector<vector<int>> m;
        
        m.push_back({intervals[0][0],intervals[0][1]});
        int p = 0,j = 1;
        while(p < m.size())
        {
            while(j<intervals.size())
            {
                if(intervals[j][0] >= m[p][0] && intervals[j][0] <= m[p][1]) //start is in range
                {
                    if(intervals[j][1] > m[p][1]) //end is greater than above range
                    {
                        m[p][1] = intervals[j][1];
                        j++;
                    }
                    else
                    {
                        j++;
                    }
                }
                else
                {
                    m.push_back({intervals[j][0],intervals[j][1]});
                    p++;
                    j++;
                    
                }
            }
            p++;
        }
        return m;

    }
};