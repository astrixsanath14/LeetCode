class Solution {
public:
    map<char,bool> charVsBool;
    map<bool,char> boolVsChar;
    
    bool evaluateExp(vector<bool> boolVals, char operation)
    {
        bool result = boolVals[0];
        if(operation == '!')
        {
            result = !result;
        }
        else
        {
            for(int i=1;i<boolVals.size();i++)
            {
                if(operation == '&')
                    result = result && boolVals[i];
                else
                    result = result || boolVals[i];
            }
        }
        return result;
    }
    bool canEvaluate(char val)
    {
        return val == '&' || val == '|' || val == '!';
    }
    
    bool parseBoolExpr(string expression) {
        charVsBool ['t'] = true;
        charVsBool['f'] = false;
        boolVsChar[true] = 't';
        boolVsChar[false] = 'f';
        
        stack<char> vals;
        
        for(char val : expression)
        {
            if(val == ')') 
            {
                vector<bool> boolVals;
                while(vals.top()!='(')
                {
                    char currVal = vals.top();
                    boolVals.push_back(charVsBool[currVal]);
                    vals.pop();
                }
                vals.pop();
                if(canEvaluate(vals.top()))
                {
                    char evaluatedVal = boolVsChar[evaluateExp(boolVals, vals.top())];
                    vals.pop();
                    vals.push(evaluatedVal);
                }
            }
            else if(val != ',')
            {
                vals.push(val);
            }
        }
  
        return charVsBool[vals.top()];
    }
};