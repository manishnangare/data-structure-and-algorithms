class Solution {
public:
    vector<int> a = {0,1,1};

    int tribonacci(int n) {
        if(n == 0 || n == 1 || n == 2)
            return a[n];
        else
            for(int i = 3;i<=n;i++)
            {
                int l = a.size();
                a.push_back(a[l-1] + a[l-2] + a[l-3]);
            }
            return a.back();
    }
};