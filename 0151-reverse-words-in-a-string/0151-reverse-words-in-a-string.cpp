class Solution {
public:
    string reverseWords(string s) {
        stack<string> ss;
        for(int i=0;i<s.size();)
        {
            while(i<s.size() && s[i]==' ')
                i++;
            string temp;
            while(i<s.size() && s[i]!=' '){
                temp += s[i];
                i++;
            }
            ss.push(temp);
            while(i<s.size() && s[i]==' ')
                i++;
        }
        string res;
        while(ss.size()>1){
            res += ss.top() + " ";
            ss.pop();
        }
        res += ss.top();
        return res;
    }
};