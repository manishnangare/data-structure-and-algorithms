class Solution {
public:
    bool isPalindrome(string s) {
        
        int i =0, j = s.size()-1;

        while( i < j)
        {
            while( i < s.size() &&  !isalnum( (int)s.at(i)) )
            {
                i++;
            }
            
            while(j > -1 &&  !isalnum( (int)s.at(j)) )
                j--;

            if( i < s.size() && j > -1)
            {
                int a = tolower( s.at(i));
                int b = tolower( s.at(j));

                if( a == b)
                {
                    i++;
                    j--;
                }
                else
                {
                    return false;
                }
            }
        }

        return true;

    }
};