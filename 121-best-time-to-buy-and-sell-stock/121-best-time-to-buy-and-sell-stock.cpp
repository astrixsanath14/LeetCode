class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
      int profit = 0;
      for(int i=prices.size()-2;i>=0;i--)
      {
        profit = max(profit,prices[i+1] - prices[i]);
        prices[i] = max(prices[i],prices[i+1]);
      }
      return profit;
    }
};