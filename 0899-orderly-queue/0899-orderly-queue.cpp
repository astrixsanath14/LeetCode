class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k==1)
        {
            char minChar = (char)125;
            for(char c:s)
            {
                minChar = min(minChar, c);
            }
            // cout<<minChar<<"\n";
            string minStr = s;
            for(int i=0;i<s.size();i++)
            {
                if(s[i] == minChar)
                {
                    string next = s[i] + s.substr(i+1,s.size() - (i+1)) + s.substr(0,i);
                    // cout<<next<<"\n";
                    if(next < minStr)
                        minStr = next;
                }
            }
            return minStr;
        }
        else
        {
            sort(s.begin(), s.end());
            return s;
        }
    }
};


/*
baaca
2
aacab
acaba
cabaa
cbaaa
caaab
aaabc

abadce
2
badcea
bdceaa
dceaab
deaabc
eaabcd
aabcde

abfdce
2
bfdcea
fdceab
fceabd
feabdc
abdcef
bdcefa
dcefab
defabc
efabcd
fabcde
abcdef
*/