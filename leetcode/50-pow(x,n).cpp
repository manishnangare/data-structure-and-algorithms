class Solution {
public:
    double myPow(double x, int n) {
        
        if(n == 0)
        {
            return double(1);
        }
        else if(x == 1)
        {
            return x;
        }
        else if(x == -1)
        {
            if( n%2 == 1)
            {
                return -1;
            }
            else 
                return 1;
        }
        else if( n > 0)
        {
            double y = x;
            long c = 1;
            
            map<long,double> m;
            vector<int> t;

            m[c] = y;
            t.push_back(c);
            while(c<n)
            {
                if(n > 2*c)
                {
                        y *= y;
                        c *= 2;
                        m[c] = y;
                        t.push_back(c);
                }
                else
                {
                    while(t.back() > n-c)
                    {
                        t.pop_back();

                    }

                    y *= m[t.back()];
                    c += t.back();
                }
            }
            return y;
        }
        else
        {
            double y = x;
            long m = n;
            m *= -1;
            long c = 1;
            
            map<long,double> k;
            vector<int> t;

            k[c] = y;
            t.push_back(c);
            while(c<m)
            {
                if(m > 2*c)
                {
                        y *= y;
                        c *= 2;
                        k[c] = y;
                        t.push_back(c);
                }
                else
                {
                    while(t.back() > m-c)
                    {
                        t.pop_back();

                    }

                    y *= k[t.back()];
                    c += t.back();
                }
            }
            return 1/y;
        }
    }
};