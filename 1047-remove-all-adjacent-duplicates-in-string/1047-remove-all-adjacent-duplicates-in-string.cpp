class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> prev;
        prev.push(s[0]);
        for(int i=1;i<s.size();i++)
        {
            if(!prev.empty() && prev.top() == s[i])
                prev.pop();
            else
                prev.push(s[i]);
        }
        s="";
        while(!prev.empty())
        {
            s += prev.top();
            prev.pop();
        }
        reverse(s.begin(), s.end());
        return s;
    }
};