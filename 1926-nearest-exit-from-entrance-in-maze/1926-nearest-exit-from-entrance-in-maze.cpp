class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};
        int m = maze.size();
        int n = maze[0].size();
        vector<bool> visited(m*n,false);
        // cout<<m<<" "<<n<<"\n";
        visited[entrance[0]*n + entrance[1]] = true;
        queue<pair<int,int>> nextPaths;
        nextPaths.push({entrance[0],entrance[1]});
        
        int level = 1;
        while(!nextPaths.empty())
        {
            int nextPathsCount = nextPaths.size();
            while(nextPathsCount--)
            {
                // cout<<nextPathsCount<<"\n";
                pair<int,int> nextPath = nextPaths.front();
                nextPaths.pop();
                for(int i=0;i<4;i++)
                {
                    int nextX = nextPath.first + dx[i];
                    int nextY = nextPath.second + dy[i];
                    
                    // cout<<"nextX: "<<nextX<<" nextY: "<<nextY<<"\n";
                    if(nextX>=0 && nextY>=0 && nextX<m && nextY<n && !visited[nextX*n + nextY] && maze[nextX][nextY] == '.')
                    {
                        if(nextX == 0 || nextY == 0 || nextX == m-1 || nextY == n-1)
                            return level;
                        nextPaths.push({nextX,nextY});
                        visited[nextX*n + nextY] = true;
                    }
                }
            }
            level++;
        }
        return -1;
    }
};