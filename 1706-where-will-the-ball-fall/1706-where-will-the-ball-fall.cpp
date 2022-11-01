#include<map>
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> result(n, -1);
        for(int i=0;i<n;i++)
        {
            int row = 0;
            int col = i;
            while(true)
            {
                // cout<<row<<" "<<col<<"\n";
                if(col == n-1 && grid[row][col] == 1)
                    break;
                if(col == 0 && grid[row][col] == -1)
                    break;
                if(grid[row][col + grid[row][col]] == -grid[row][col])
                    break;
                if(row == m-1)
                {
                    col += grid[row][col];
                    result[i]=col;
                    // cout<<"break "<<col<<"\n";
                    break;
                }
                col += grid[row][col];
                row++;
            }
        }
        return result;
    }
};