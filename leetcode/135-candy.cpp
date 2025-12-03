class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int n = ratings.size();
        vector<int> out(n,1);

        for(int i =1; i<n;i++)
        {
            if( ratings[i] > ratings[i-1])
            {
                out[i] = out[i-1]+1;
            }
        }

        for( int i =n-2;i>=0;i--)
        {
            if( ratings[i] > ratings[i+1])
                out[i] = max(out[i],out[i+1]+1);
        }

        int count = 0;
        for(int i=0;i<n;i++)
        {
            count+=out[i];
        }

        

        return count;
    }
};