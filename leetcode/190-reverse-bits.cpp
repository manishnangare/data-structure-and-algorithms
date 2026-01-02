class Solution {
public:
    int reverseBits(int n) {
        long r = 0;
        for(int i =0;i<32;i++)
        {
            if( (n>>i)%2 == 1)
            {
                r++;
                r*=2;
            }
            else
            {
                r*=2;
            }
        }
        return int(r/2);
    }
};