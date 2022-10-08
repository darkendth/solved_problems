# include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;


int findMin(vector<int> nums){
    int p=0,q=nums.size()-1;
    int mid;

    if (nums[p]<=nums[q])
        return nums[p];

    while(p<q){
        mid=(p+q)/2;
        if (nums[q]<nums[mid])
            p=mid+1;
        else if (nums[q]>nums[mid])
            q=mid;
        else
            q--;
    }
    return nums[p];
}

void answer(){
    int n,t;
    cin>>n;
    vector<int> nums;
    for (int i=0;i<n;i++){
        cin>>t;
        nums.push_back(t);
    }
    t = findMin(nums);
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