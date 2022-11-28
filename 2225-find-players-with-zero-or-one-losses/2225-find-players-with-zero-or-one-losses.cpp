class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> playerVsLostMp;
        map<int,int> playerVsWonMp;
        set<int> players;
        for(vector<int> match : matches)
        {
            playerVsLostMp[match[1]]++;
            playerVsWonMp[match[0]]++;
            players.insert(match[0]);
            players.insert(match[1]);
        }
        
        vector<vector<int>> result(2, vector<int>());
        
        for(int player : players)
        {
            if(playerVsLostMp[player] == 0)
            {
                result[0].push_back(player);
            }
            if(playerVsLostMp[player] == 1)
            {
                result[1].push_back(player);
            }
        }
        
        return result;
    }
};