#include <algorithm>
# include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int lengthOfLIS(vector<int> nums){
    vector<int> seq;
    seq.push_back(nums[0]);
    for (int i=1;i<nums.size();i++){
        if (nums[i]>seq.back())
            seq.push_back(nums[i]);
        else{
            auto lb = lower_bound(seq.begin(),seq.end(),nums[i]);
            seq[lb-seq.begin()] = nums[i];
        }
    }
    return seq.size();
}

void answer(){
    int n,t;
    cin>>n;
    vector<int> nums;
    for (int i=0;i<n;i++){
        cin>>t;
        nums.push_back(t);
    }
    int ans = lengthOfLIS(nums);
    cout<<ans;
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