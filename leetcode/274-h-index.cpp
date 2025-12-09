class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());

        int n = citations.size(),hmax = 0;


        for( int i =0; i<citations.size();i++)
        {
            if(citations[i] != 0)
            {
                if(citations[i] <= n-i)
                {
                    hmax = citations[i];
                }
                else
                {
                    hmax = max(hmax,n-i);
                }
            }
        }
        return hmax;
    }
};