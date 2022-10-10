class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre(n+1);
        pre[0]=0;
        for (int i=0;i<n;i++){
            pre[i+1] = pre[i]+nums[i];
        }
        int count=0;
        unordered_map<int,int> hmap;
        for (int i=1;i<=n;i++){
            if (pre[i]==k)
                count++;
            
            if (hmap.find(pre[i]-k)!=hmap.end()){
                count += hmap[pre[i]-k];
            }
            hmap[pre[i]]++;
        }
        return count;
    }
};