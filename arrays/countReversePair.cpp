# include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;



int merge(vector<int>& nums,int p,int mid,int q){
    int i=p,j=mid+1;
    vector<int> ar;
    int count=0;
    while(i<=mid){
        while(j<=q&&nums[i]>2*nums[j])
            j++;
        count += j-(mid+1);
        i++;
    }
    i=p;j=mid+1;
    while(i<=mid&&j<=q){
        if (nums[i]<nums[j])
            ar.push_back(nums[i++]);
        else
            ar.push_back(nums[j++]);
    }
    while(i<=mid)
        ar.push_back(nums[i++]);
    
    while(j<=q)
        ar.push_back((nums[j++]));
    
    i=p;
    for (auto it:ar)
        nums[i++] = it;

    return count;
}


int mergeSort(vector<int>& nums,int p,int q){
    if (p<q){
        int mid = (p+q)/2;
        int inv1 = mergeSort(nums, p, mid);
        int inv2 = mergeSort(nums, mid+1, q);
        int inv = merge(nums,p,mid,q);
        return inv+inv1+inv2;
    }
    return 0;
}


int reversePairs(vector<int>& nums){
    return mergeSort(nums,0,nums.size()-1);
}


void answer(){
    int n,t;
    vector<int> nums;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>t;
        nums.push_back(t);
    }
    int inv = reversePairs(nums);
    cout<<inv<<endl;
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