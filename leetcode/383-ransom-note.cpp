class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        map<char,int> m;

        for(int i =0; i<magazine.size();i++)
        {
            m[magazine.at(i)]++;
        }

        for( int i =0; i<ransomNote.size();i++)
        {
            if( m[ransomNote.at(i)] == 0)
            {
                return false;
            }
            else
            {
                m[ransomNote.at(i)]--;
            }
        }
        return true;
    }
};