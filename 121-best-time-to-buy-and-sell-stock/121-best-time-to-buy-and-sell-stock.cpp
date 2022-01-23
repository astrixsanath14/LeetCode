class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
      int profit = 0, highestSellingPrice = prices[prices.size() - 1];
      for(int i=prices.size()-2;i>=0;i--)
      {
        highestSellingPrice = max(highestSellingPrice, prices[i]);
        profit = max(profit, highestSellingPrice - prices[i]);
      }
      return profit;
    }
};