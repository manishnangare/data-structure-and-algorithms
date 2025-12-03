class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, n = prices.size();

        if(n == 1)
            return 0;
        else
        {
            for(int i =0; i<n-1;i++)
            {
                if( prices[i+1]- prices[i] > 0)
                {
                    profit += prices[i+1]-prices[i];
                }
            }
            return profit;
        }
    }
};
