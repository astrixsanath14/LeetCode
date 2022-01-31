class Solution {
public:
  int maximumWealth(vector<vector<int>>& a, int m=0) {
        for(auto i:a) 
            m=max(m,accumulate(i.begin(),i.end(),0));
        return m;
    }
    // int maximumWealth(vector<vector<int>>& accounts) {
    // return accumulate(cbegin(accounts), cend(accounts), 0, [](auto sum, const auto& money) {
    //     return max(sum, reduce(cbegin(money), cend(money)));
    // });
    // }
};