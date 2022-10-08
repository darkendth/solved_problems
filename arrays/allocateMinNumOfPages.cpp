#include <climits>
# include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

bool canAllocate(vector<int> nums,int mid,int std){
    int sum=0;
    for (auto it:nums){
        sum += it;
        if (sum>mid){
            sum=it;
            std--;
        }
    }
    if (sum<=mid)
        std--;
    return std==0;
}

int allocation(vector<int> nums,int t){
    int low=INT_MAX,high=0;
    for (auto it:nums){
        if (low>it)
            low=it;
        high += it;
    }
    int mid;
    while(low<=high){
        // cout<<low<<"  "<<high<<endl;
        mid = (low+high)/2;
        if (canAllocate(nums,mid,t))
            high=mid-1;
        else
            low=mid+1;
    }
    return low;
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
    int res=allocation(nums, t);
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