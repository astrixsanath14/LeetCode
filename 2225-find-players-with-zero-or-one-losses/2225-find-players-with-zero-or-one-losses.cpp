class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> playerVsLostMp;
        for(vector<int> match : matches)
        {
            playerVsLostMp[match[1]]++;
            if(playerVsLostMp.find(match[0]) == playerVsLostMp.end())
            {
                playerVsLostMp[match[0]]=0;
            }
        }
        
        vector<vector<int>> result(2, vector<int>());
        
        for(auto& ref : playerVsLostMp)
        {
            if(ref.second <= 1)
            {
                result[ref.second].push_back(ref.first);
            }
        }
        
        return result;
    }
};