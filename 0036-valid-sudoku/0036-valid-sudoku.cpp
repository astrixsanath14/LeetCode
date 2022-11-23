class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows = 9, cols = 9;
        vector<vector<int>> rowFreqMap(rows, vector<int>(9,0));
        vector<vector<int>> colFreqMap(cols, vector<int>(9,0));
        vector<vector<int>> subBoxFreqMap(rows, vector<int>(9,0));
        for(int row=0;row<rows;row++)
        {
            for(int col=0;col<cols;col++)
            {
                if(board[row][col] != '.')
                {
                    int val = board[row][col] - '0' - 1;
                    int subBoxNum = row/3 * 3 + col/3;
                    if(rowFreqMap[row][val] || colFreqMap[col][val] || subBoxFreqMap[subBoxNum][val])
                    {
                        return false;
                    }
                    rowFreqMap[row][val]++;
                    colFreqMap[col][val]++;
                    subBoxFreqMap[subBoxNum][val]++;
                }
            }
        }
        return true;
    }
};