class Solution {
public:
    void generateParenthesis(int &n, int i, int l, int r, char* p, vector<string>& comb)
    {
        if(r == n)
        {
            string pp(p);
            comb.push_back(pp);
            return;
        }
        if(l == n)
        {
            //only closing left
            p[i] = ')';
            generateParenthesis(n, i+1, l, r+1, p, comb);
            return;
        }
        p[i] = '(';
        generateParenthesis(n, i+1, l+1, r, p, comb);
        if(l>r)
        {
            p[i] = ')';
            generateParenthesis(n, i+1, l, r+1, p, comb);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        char p[2*n + 1];
        p[2*n] = '\0';
        vector<string> comb;
        generateParenthesis(n, 0, 0, 0, p, comb);
        return comb;
    }
};