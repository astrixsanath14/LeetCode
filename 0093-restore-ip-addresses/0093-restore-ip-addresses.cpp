class Solution {
public:
    bool isValidIpInteger(string& s, int startInd, int endInd)
    {
        int len = endInd-startInd+1;
        if(len>3 || len<=0)
            return false;
        string temp = s.substr(startInd, len);
        if(len>1 && temp[0] == '0')
            return false;
        // cout<<startInd<<" "<<endInd<<" "<<temp<<"\n";
        int num = stoi(temp);
        
        return num >=0 && num <= 255;
    }
    
    bool isValidIpValue(string& s, vector<int>& endIndices)
    {
        return isValidIpInteger(s, 0, endIndices[0]) && isValidIpInteger(s, endIndices[0]+1, endIndices[1]) && isValidIpInteger(s, endIndices[1]+1, endIndices[2]) && isValidIpInteger(s, endIndices[2]+1, s.size()-1);
    }
    
    void restoreIpAddresses(int i, int startInd, string s, vector<string>& ips, vector<int>& endIndices) {
        if(endIndices.size() == 3)
        {
            if(!isValidIpValue(s, endIndices))
                return;
            string temp = s;
            temp.insert(endIndices[2]+1,".");
            temp.insert(endIndices[1]+1,".");
            temp.insert(endIndices[0]+1,".");
            // cout<<endIndices[0]<<" "<<endIndices[1]<<" "<<endIndices[2]<<"\n";
            ips.push_back(temp);
            return;
        }
        if(i == s.size())
            return;
        endIndices.push_back(i);
        restoreIpAddresses(i+1, i+1, s, ips, endIndices);
        endIndices.pop_back();
        if(s[startInd] != '0')
        {
            restoreIpAddresses(i+1, startInd, s, ips, endIndices);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ips;
        vector<int> endIndices;
        if(s.length()>=4 && s.length()<=12)
        {
            restoreIpAddresses(0, 0, s, ips, endIndices);
        }
        return ips;
    }
};