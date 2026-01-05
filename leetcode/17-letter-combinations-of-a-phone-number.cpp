class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        vector<string> buttons = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        vector<string> seq;

        for(int i =0; i< buttons[ digits.at(0)-48].size();i++)
        {
            seq.push_back( buttons[ digits.at(0)-48].substr(i,1));
        }

        for(int i =1; i<digits.size();i++)
        {
            vector<string> temp;
            for(int j =0; j< seq.size();j++)
            {
                for(int k =0; k< buttons[ digits.at(i)-48].size();k++)
                {
                    temp.push_back(seq[j]);
                    temp.back().push_back( buttons[digits.at(i)-48].at(k));
                }
            }
            seq = temp;
        }
        return seq;
    }
};