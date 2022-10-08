#include <algorithm>
# include <iostream>
#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> fourSum(vector<int>& nums,int target){
    int size=nums.size();
    if (size<4)
        return {};
    sort(nums.begin(),nums.end());
    vector<vector<int>> res;
    for (int i=0;i<size;i++){
        for (int j=i+1;j<size;j++){
            int p=j+1;
            int q=size-1;
            int t=target-(nums[i]+nums[j]);
            while(p<q){
                if (nums[p]+nums[q]==t){
                    int a=nums[p];
                    int b=nums[q];
                    res.push_back({nums[i],nums[j],nums[p],nums[q]});
                    // skip dupplicates.
                    while(p<q&&nums[p]==a)
                        p++;
                    while(p<q&&nums[q]==b)
                        q--;
                }
                else if (nums[p]+nums[q]<t)
                    p++;
                else
                    q--;
            }
            // skip dupplicates.
            while(j+1<size&&nums[j+1]==nums[j])
                j++;
        }
        // skip dupplicates for i:
        while (i+1<size&&nums[i+1]==nums[i])
            i++;
    }
    return res;
}


void answer(){
    int n,t;
    vector<int> nums;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>t;
        nums.push_back(t);
    }
    cin>>t;
    vector<vector<int>>res = fourSum(nums, t);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<4;j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
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