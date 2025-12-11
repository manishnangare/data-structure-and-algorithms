class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int i,count,tank;
        for( int start = 0; start < gas.size();start++)
        {
            i = start;
            count = 0;
            tank = 0;
            while(count <= cost.size())
            {
                tank += gas[i];
                if( tank < cost[i])
                {
                    if( i+1 > start)
                        start = i;
                    break;
                }
                else
                {
                    tank -= cost[i];
                    count++;
                    i = (i+1)%cost.size();
                }
            }
            if(count >= cost.size())
            {
                return start;
            }
            else if(count == cost.size()-1)
            {
                return -1;
            }
            
        }
        return -1;
    }
};