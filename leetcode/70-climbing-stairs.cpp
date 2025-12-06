class Solution {
public:
    int climbStairs(int n) {
        int a = 1;
        int b = 2;
        int c;

        if( n == 1)
            return a;
        else if (n == 2)
            return b;
        else
        {
            for( int i = 0;i<n-2;i++)
            {
                c= b;
                b = a+b;
                a = c;
            }
        }

        return b;
    }
};