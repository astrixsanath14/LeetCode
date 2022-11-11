class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target, int pos) 
    {
        vector<vector<int>> res;
        // cout<<"get combs for target: "<<target<<"\n";
        if(pos >= candidates.size())
            return res;
        for(int i=pos;i<candidates.size();i++)
        {
            if(candidates[i] && (i == pos || candidates[i] != candidates[i-1]))
            {
                // cout<<"target: "<<target<<" "<<i<<"\n"; 
                if(candidates[i] < target)
                {
                    int tempVal = candidates[i];
                    candidates[i] = 0;
                    vector<vector<int>> resForCurr = combinationSum2(candidates, target - tempVal, i+1);
                    candidates[i] = tempVal;
                    if(resForCurr.empty())
                        continue;
                    // cout<<"found for target: "<<target<<" "<<resForCurr.size()<<"\n";
                    for(vector<int> tempRes : resForCurr)
                    {
                        tempRes.push_back(tempVal);
                        res.push_back(tempRes);
                    }
                }
                else if(target == candidates[i])
                {
                    // vector<int> resForCurr(1, candidates[i]);
                    // res.push_back(resForCurr);
                    res.push_back(vector<int>(1,candidates[i]));
                }
                else
                    break;
            }
        }
        return res;
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        return combinationSum2(candidates, target, 0);
    }
};


/*
[10,1,2,7,6,1,5]
8

1 1 2 5 6 7 10

1 1 6
1 

*/