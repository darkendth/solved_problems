
// Input: nums = [1,2,1]
// Output: [2,-1,2]
// Explanation: The first 1's next greater number is 2; 
// The number 2 can't find next greater number. 
// The second 1's next greater number needs to search circularly, which is also 2.

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int> stk;
        vector<int> res(n,-1);
        for (int i=2*n-1;i>-1;i--){
            while(!stk.empty()&&stk.top()<=nums[i%n])
                stk.pop();
            if (stk.empty())
                res[i%n]=-1;
            else
                res[i%n]=stk.top();
            stk.push(nums[i%n]);
        }
        return res;
    }
};