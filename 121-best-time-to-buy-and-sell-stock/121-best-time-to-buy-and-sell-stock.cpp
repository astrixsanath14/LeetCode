class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
      int n = prices.size();
      vector<int> suffixMax(n);
      vector<int> profits(n);
      suffixMax[n-1] = prices[n-1];
      profits[n-1]=0;
      for(int i=n-2;i>=0;i--)
      {
        suffixMax[i] = max(prices[i],suffixMax[i+1]);
        profits[i] = max(profits[i+1],suffixMax[i+1] - prices[i]);
      }
      return profits[0];
    }
};