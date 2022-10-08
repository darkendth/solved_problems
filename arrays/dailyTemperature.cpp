class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> stk;
        int n=temperatures.size();
        vector<int> res(n,0);
        for (int i=n-1;i>=0;i--){
            while(!stk.empty()&&stk.top().first<=temperatures[i])
                stk.pop();
            if (!stk.empty())
                res[i]=stk.top().second-i;
            stk.push({temperatures[i],i});
        }
        return res;
    }
};