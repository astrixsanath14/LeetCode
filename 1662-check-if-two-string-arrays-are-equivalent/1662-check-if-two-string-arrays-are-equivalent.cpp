class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i1=0,j1=0,i2=0,j2=0,n1=word1.size(),n2=word2.size();
        while(i1<n1 && i2<n2)
        {
            if(word1[i1][j1] != word2[i2][j2])
                return false;
            j1++;
            j2++;
            if(j1==word1[i1].size())
            {
                j1=0;
                i1++;
            }
            if(j2==word2[i2].size())
            {
                j2=0;
                i2++;
            }
        }
        return i1 == word1.size() && i2 == word2.size();
    }
};