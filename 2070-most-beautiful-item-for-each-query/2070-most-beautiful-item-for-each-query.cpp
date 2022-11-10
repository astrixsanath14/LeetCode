class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        // sort(items.begin(), items.end(), [&](vector<int> a, vector<int> b) { return a[0] == b[0] ? (a[1] < b[1]) : a[0] < b[0]; });
        sort(items.begin(), items.end());
        for(int i=1;i<items.size();i++)
        {
            items[i][1] = max(items[i][1], items[i-1][1]);
        }
        for(int i=0;i<queries.size();i++)
        {
            int q = queries[i];
            int left = 0;
            int right = items.size()-1;
            int ans = 0;
            while(left <= right)
            {
                int mid = (left + right)/2;
                if(items[mid][0] > q)
                {
                    right = mid-1;
                }
                else if(items[mid][0] <= q)
                {
                    ans = max(ans, items[mid][1]);
                    left = mid+1;
                }
            }
            queries[i] = ans;
        }
        return queries;
    }
};