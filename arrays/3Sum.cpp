# include <iostream>
#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> threeSum(vector<int> nums){
    int size=nums.size();
    vector<vector<int>> res;
    sort(nums.begin(),nums.end());
    for (int i=0;i<size;i++){
        int p=i+1;
        int q=size-1;
        while(p<q){
            long long sum=nums[i]+nums[p]+nums[q];
            if (sum==0){
                int a=nums[p];
                int b=nums[q];
                res.push_back({nums[i],nums[p],nums[q]});

                while(p<q&&a==nums[p])
                    p++;
                while (p<q&&nums[q]==b) 
                    q--;
            }
            else if(sum<0)
                p++;
            else
                q--;
        }
        while(i<size-1&&nums[i]==nums[i+1])
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
    // cin>>t;
    vector<vector<int>>res = threeSum(nums);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<3;j++){
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