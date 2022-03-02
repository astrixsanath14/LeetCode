class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.length(), n = t.length();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        for(int j=0; j<=n; j++)
            dp[0][j] = true;
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1] == t[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = dp[i][j-1];
            }
        }
        return dp[m][n];
    }
};