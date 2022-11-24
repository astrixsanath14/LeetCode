int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
class Solution {
public:
    bool exist(vector<vector<char>>& board, int i, int j, string& word, int wi) {
        // cout<<i<<" "<<j<<" "<<wi<<"\n";
        if(wi == word.size())
        {
            // cout<<"yes!"<<"\n";
            return true;
        }
        if(i<0 || j<0 || i >= board.size() || j >= board[0].size())
        {
            return false;
        }
        if(board[i][j] != word[wi])
            return false;
        
        board[i][j] = '.';
        for(int ind=0;ind<4;ind++)
        {
            int nextI = i + dx[ind];
            int nextJ = j + dy[ind];
            if(exist(board, nextI, nextJ, word, wi+1))
                return true;
        }
        board[i][j] = word[wi];
        
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(exist(board,i,j,word,0))
                    return true;
            }
        }
        return false;
    }
};