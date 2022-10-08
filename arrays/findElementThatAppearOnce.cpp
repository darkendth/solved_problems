# include <iostream>
#include <bits/stdc++.h>
using namespace std;


int BinarySearch(vector<int> nums,int p,int q){
    int mid;
    while(p<=q){
        mid=(p+q)/2;
        if (mid%2==0){
            if (nums[mid]==nums[mid+1])
                p=mid+1;
            else
                q=mid-1;
        }
        else{
            if (nums[mid]==nums[mid+1])
                q=mid-1;
            else
                p=mid+1;
        }
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
    t = BinarySearch(nums,0, n-1);
    cout<<t;

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