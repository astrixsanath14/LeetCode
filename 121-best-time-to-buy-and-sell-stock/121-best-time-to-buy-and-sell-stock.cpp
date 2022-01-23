class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
      int profit = 0, highestSellingPrice = prices[prices.size() - 1];
      for(int i=prices.size()-2;i>=0;i--)
      {
        highestSellingPrice = highestSellingPrice>prices[i]?highestSellingPrice:prices[i];
        profit = profit>highestSellingPrice - prices[i]?profit:highestSellingPrice - prices[i];
      }
      return profit;
    }
};