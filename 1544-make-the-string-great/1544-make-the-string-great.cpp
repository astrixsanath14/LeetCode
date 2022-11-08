class Solution {
public:
    string makeGood(string s) {
        if(s.size()<2)
            return s;
        // cout<<s<<"\n";
        for(int i=0;i<s.size()-1;i++)
        {
            if(abs(s[i]-s[i+1]) == 32){
                // cout<<"found good string prop at "<<i<<" for "<<s<<"\n";
                return makeGood(s.substr(0,i) + s.substr(i+2,s.size()-(i+2)));
            }
        }
        return s;
    }
};