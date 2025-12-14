class Solution {
public:
    int trailingZeroes(int n) {
        
        int twos = 3;
        int fives = 0;

        for(int j =5;j<=n;j++)
        {
            int i = j;
            while(i >= 5 && i%5 == 0)
            {
                fives++;
                i = i/5;
            }

            while( i >=2  && i%2 == 0)
            {
                twos++;
                i = i/2;
            }
        }

        return min(twos,fives);
    }
};