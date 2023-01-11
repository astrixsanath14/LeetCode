//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

int dx[] = {0,0,1,-1,1,1,-1,-1};
int dy[] = {1,-1,0,0,1,-1,1,-1};

class Solution {
public:
    bool solve(int x, int y, int ind, int &len, string word, int &m, int &n, vector<vector<char>>& board, vector<string>& dictionary, vector<string> &res)
    {
        if(ind == len)
        {
            return true;
        }
        for(int i=0; i<8; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(xx>=0 && xx<m && y>=0 && y<n && board[xx][yy] == word[ind])
            {
                char temp = board[xx][yy];
                board[xx][yy] = '.';
                bool isWordFound = solve(xx, yy, ind+1, len, word, m, n, board, dictionary, res);
                board[xx][yy] = temp;
                if(isWordFound)
                {
                    return true;
                }
            }
        }
        return false;
    }

	vector<string> wordBoggle(vector<vector<char>>& board, vector<string>& dictionary) {
	    int m = board.size();
	    int n = board[0].size();
	    sort(dictionary.begin(), dictionary.end());
	    
	    vector<string> res;
	    if(n == 1 && m == 1)
	    {
    	    for(string word : dictionary)
    	    {
    	        if(word.size() == 1  && word[0] == board[0][0])
    	        {
    	            res.push_back(word);
    	        }
    	    }
    	    return res;
	    }
	    for(string word : dictionary)
	    {
	        int len = word.length();
	        bool isWordFound = false;
	        for(int x=0; x<board.size(); x++)
    	    {
    	        for(int y=0; y<board[x].size(); y++)
    	        {
    	            
    	            if(solve(x, y, 0, len, word, m, n, board, dictionary, res))
    	            {
    	                isWordFound = true;
    	                res.push_back(word);
    	                break;
    	            }
    	        }
    	        if(isWordFound)
    	        {
    	            break;
    	        }
    	    }
	    }
	    
	    return res;
	}
};

/*

4
GEEKS
FOR
QUIZ
GO
3 3 
G I Z 
U E K
Q S E

*/



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int R, C;
        cin >> R >> C;
        vector<vector<char> > board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends