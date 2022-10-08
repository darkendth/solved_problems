# include <iostream>
#include <bits/stdc++.h>
using namespace std;


int longestSubarrayLength(vector<int>& nums){
    map<int,int> hmap;
    int max_len=0;
    int sum=0;
    for (int i=0;i<nums.size();i++){
        sum += nums[i];
        if (sum==0)
            max_len = i+1;
        if (hmap.find(sum)==hmap.end())
            hmap[sum]=i;
        else
            max_len = max(max_len,i-hmap[sum]);
    }
    return max_len;
}


void answer(){
    int n,t;
    vector<int> nums;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>t;
        nums.push_back(t);
    }
    int res = longestSubarrayLength(nums);
    cout<<res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef Redirect
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        answer();
    }
}