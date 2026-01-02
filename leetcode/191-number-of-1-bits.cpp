class Solution {
public:
    int hammingWeight(int n) {
        int w = 0;

        for(int i =0; i<32;i++)
        {
            if( ((n>>i) % 2) == 1)
                w++;
            
        }
        return w;
    }
};