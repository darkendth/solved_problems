class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> hmap;
        int sum=0;
        hmap[0]=-1;
        for (int i=0;i<n;i++){
            sum += nums[i];
            sum = sum%k;
            if (hmap.find(sum)!=hmap.end()){
                if (i-hmap[sum]>1)
                    return true;
            }
            else
                hmap[sum]=i;
        }
        return false;
    }
};