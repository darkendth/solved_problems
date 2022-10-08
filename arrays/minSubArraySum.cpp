#include <algorithm>
#include <climits>
# include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;



int minSumA(vector<int> nums,int t){
    vector<int> sub(nums.size()+1,0);
    for (int i=0;i<nums.size();i++)
        sub[i]=sub[i-1]+nums[i];
    int req_sum=0,ans=INT_MAX;
    for (int i=0;i<nums.size();i++){
        req_sum = t+sub[i-1];
        auto lb = lower_bound(sub.begin(),sub.end(),req_sum);
        if (lb!=sub.end()){
            ans = min(ans,int(lb-(sub.begin()+i-1)));
        }
    }
    return ans==INT_MAX?0:ans;
}

int minSumB(vector<int> nums,int t){
    int sum=0,ans=INT_MAX;
    int low=0;
    for (int i=0;i<nums.size();i++){
        sum += nums[i];
        while(sum>=t){
            ans = min(ans,i-low+1);
            sum -= nums[low++];
        }
    }
    return ans==INT_MAX?0:ans;
}

void answer(){
    int n,t;
    cin>>n;
    vector<int> nums;
    for (int i=0;i<n;i++){
        cin>>t;
        nums.push_back(t);
    }
    cin>>t;
    int res;
    // res = minSumA(nums, t);
    res = minSumB(nums, t);
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