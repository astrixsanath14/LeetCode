// // class Solution {
// // public:
// //   long long maximumScore(vector<int>& nums, vector<int>& multipliers, int mInd, int left, long long score, vector<vector<long long>> &dp){
// //     if(mInd == multipliers.size())
// //     {
// //       return score;
// //     }
// //     int leftScore = multipliers[mInd] * nums[left];
// //     if(dp[mInd][left] != -1)
// //       return dp[mInd][left];
    
// //     int right = nums.size() - (mInd - left) - 1;
// //     int rightScore = multipliers[mInd] * nums[right];
    
// //     return dp[mInd][left] = max(maximumScore(nums, multipliers, mInd+1, left+1, score + leftScore, dp), maximumScore(nums, multipliers, mInd+1, left, score + rightScore, dp));
// //   }

// //   long long maximumScore(vector<int>& nums, vector<int>& multipliers) {
// //     int mInd = 0, left = 0, right = nums.size()-1;
// //     int m = multipliers.size();
// //     vector<vector<long long>> dp(m, vector<long long>(m,-1));
// //     return maximumScore(nums, multipliers, mInd, left, 0, dp);
// //   }
// // };


// class Solution {
// public:
  
//   int dp[1000][1000];
//   int maximumScore(vector<int>& nums, vector<int>& multipliers, int mInd, int left){
//     if(mInd == multipliers.size())
//     {
//       return 0;
//     }
    
//     if(dp[mInd][left] != -1)
//       return dp[mInd][left];
    
//     int leftScore = maximumScore(nums, multipliers, mInd+1, left+1) + multipliers[mInd] * nums[left];  
//     int right = nums.size() - (mInd - left) - 1;
//     int rightScore = maximumScore(nums, multipliers, mInd+1, left) + multipliers[mInd] * nums[right];
    
//     return dp[mInd][left] = max(leftScore, rightScore);
//   }

//   int maximumScore(vector<int>& nums, vector<int>& multipliers) {
//     cin.tie(NULL);
//     cout.tie(NULL);
//     ios::sync_with_stdio(false);
//     int mInd = 0, left = 0, m = multipliers.size();
    
//     memset(dp, -1, sizeof(dp));
//     return maximumScore(nums, multipliers, mInd, left);
//   }
// };

// class Solution {
// public:
//     int m, n;
//     int memo[1001][1001];
//     int maximumScore(vector<int>& nums, vector<int>& muls) {
//         n = nums.size();
//         m = muls.size();
//         memset(memo, INT_MIN, sizeof(memo));
//         return dp(0, 0, nums, muls);
//     }
//     int dp(int l, int i, vector<int>& nums, vector<int>& muls) {
//         if (i == m) return 0; // Picked enough m elements
//         if (memo[l][i] != INT_MIN) return memo[l][i];
//         int pickLeft = dp(l+1, i+1, nums, muls) + nums[l] * muls[i]; // Pick the left side
//         int pickRight = dp(l, i+1, nums, muls) + nums[n-(i-l)-1] * muls[i]; // Pick the right side
//         return memo[l][i] = max(pickLeft, pickRight);
//     }
// };

class Solution {
public:
    vector<vector<int>> dp;
    
    int solve(int i, int n, int j, vector<int> &nums, vector<int> &M){
        
        if (j == M.size()) return 0;
        if (dp[i][j] != -1001) return dp[i][j];
        
        // Left Side
        int left = solve(i + 1, n, j + 1, nums, M) + (nums[i] * M[j]);
        
        // Right Side
        int right = solve(i, n, j + 1, nums, M) + (nums[(n - 1) - (j - i)] * M[j]);
        
        return dp[i][j] = max(left, right);
    }
    
    int maximumScore(vector<int>& nums, vector<int>& M) {   
        int n = nums.size(), m = M.size();
        dp.resize(m + 1, vector<int>(m + 1, -1001));
        return solve(0, n, 0, nums, M);
    }
};