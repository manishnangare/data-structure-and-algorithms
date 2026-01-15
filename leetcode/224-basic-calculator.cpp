class Solution {
public:
    int calculate(string s) {

        int sum = 0;
        long num;
        stack<int> st;
        int sign = 1;

        for(int i=0;i<s.size();i++)
        {
            char x = s.at(i);

            if(isdigit(x))
            {
                num = 0;
                while (i < s.length() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--;
                
                sum += (sign * num);
                sign = 1;
            }
            else if(x == '+')
            {
                sign = 1;
            }
            else if(x == '-')
            {
                sign = -1;
            }
            else if(x == '(')
            {
                st.push(sum);
                st.push(sign);

                sum = 0;
                sign = 1;
            }
            else if(x == ')')
            {
                int prevSign = st.top(); st.pop();
                int prevSum = st.top(); st.pop();

                sum = prevSum + (sum * prevSign);
            }
        }

        return sum;
    }
};