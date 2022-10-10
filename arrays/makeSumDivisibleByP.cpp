
// Given an array of positive integers nums, remove the smallest subarray (possibly empty) such that the
//  sum of the remaining elements is divisible by p. It is not allowed to remove the whole array.
// Return the length of the smallest subarray that you need to remove, or -1 if it's impossible.


class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();
        int total=0;
        for (auto it:nums)
            total = (total+it)%p;
        if (total==0)
            return 0;
        map<int,int> hmap;
        hmap[0]=-1;
        int res=n;
        long sum=0;
        cout<<total<<endl;
        for (int i=0;i<n;i++){
            cout<<sum<<" "<<res<<endl;
            sum += nums[i];
            sum = sum%p;
            if (hmap.find((sum-total+p)%p)!=hmap.end())
                res = min(res,i-hmap[(sum-total+p)%p]);
            
            hmap[sum]=i;
        }
        return res<n?res:-1;
    }
};