class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
        map<int,int> hmap;
        hmap[0]=1;
        int count=0;
        for (int i=0;i<n;i++){
            sum += nums[i];
            sum = sum%k;

            if (sum<0)
                sum += k;
            
            if (hmap.find(sum)!=hmap.end())
                count += hmap[sum];
            hmap[sum]++;
        }
        return count;
    }
};