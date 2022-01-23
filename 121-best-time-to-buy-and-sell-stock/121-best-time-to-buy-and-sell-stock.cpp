class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
      int n=prices.size();
      vector<int> suffixMax(n);
      suffixMax[n-1] = prices[n-1];
      for(int i=n-2;i>=0;i--)
      {
        suffixMax[i] = max(suffixMax[i+1], prices[i]);
      }
      int profit = 0;
      for(int i=0;i<n-1;i++)
      {
        profit = max(profit, suffixMax[i+1] - prices[i]);
      }
      return profit;
    }
};