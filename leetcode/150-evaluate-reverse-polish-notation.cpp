class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        vector<int> a;
        int top = -1;

        for(int i =0; i< tokens.size(); i++)
        {
            string s = tokens[i];

            if(s == "+")
            {
                a[top-1] += a[top];
                top--;
                a.pop_back();
            }
            else if( s == "-")
            {
                a[top-1] -= a[top];
                top--;
                a.pop_back();
            }
            else if( s == "*")
            {
                a[top-1] *= a[top];
                top--;
                a.pop_back();
            }
            else if( s == "/")
            {
                a[top-1] /= a[top];
                top--;
                a.pop_back();
            }
            else if(s[0] == '-')
            {
                int x = 0;
                for(int i =1;i<s.size();i++)
                {
                    x += int(s.at(i)) -48;
                    x *= 10;
                }
                a.push_back( -(x/10));
                top++;
            }
            else 
            {
                int x = 0;
                for(int i =0;i<s.size();i++)
                {
                    x += int(s.at(i)) -48;
                    x *= 10;
                }
                a.push_back( x/10);
                top++;
            }

        }
        return a[top];
    }
};