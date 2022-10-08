# include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;


int findDuplicate(vector<int>& nums){
    int slow=nums[0];
    int fast=nums[0];
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }while (slow!=fast);
    fast = nums[0];
    while (slow!=fast){
        slow=nums[slow];
        fast=nums[fast];        }
    return slow;
}


void answer(){
    int n,t;
    vector<int> nums1;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>t;
        nums1.push_back(t);
    }
    int r = findDuplicate(nums1);
    cout<<r<<endl;

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