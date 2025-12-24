class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int n = numbers.size();
        int i =0, j = n-1;

        while(i < j)
        {
            int x = numbers[i] + numbers[j];
            if( x == target)
            {
                return {i+1,j+1};
            }
            else if( x  > target)
            {
                j--;
            }
            else 
            {
                i++;
            }
        }
        return {0,0};
    }
};