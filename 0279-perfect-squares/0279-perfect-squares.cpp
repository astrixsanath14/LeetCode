class Solution {
public:
    int solve(int n, vector<int>& squares, vector<int>& dp)
    {
        if(dp[n] != INT_MAX)
            return dp[n];
        int minCount = INT_MAX;
        for(int i:squares)
        {
            if(i>n)
            {
                break;
            }
            minCount = min(minCount, 1 + solve(n-i, squares, dp));
        }
        return dp[n] = minCount;
    }
    
    int numSquares(int n) {
        vector<int> squares;
        squares.push_back(1);
        for(int i=2;i*i<=n;i++)
            squares.push_back(i*i);
        int ind = squares.size()-1;
        int count = 0;
        int temp = n;
        while(ind>0 && n>0)
        {
            int sq = squares[ind--];
            int countForSq = temp/sq;
            count += countForSq;
            temp-= sq * countForSq;
        }
        vector<int> dp(n+1,INT_MAX);
        dp[1] = 1;
        dp[0] = 0;
        solve(n, squares, dp);
        return dp[n];
    }
};