#include <algorithm>
# include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;


int majority(vector<int>& nums){
    //  > n/2 Appearence.
    int count=0;
    int element;
    for (auto i:nums){
        if (count==0)
            element = i;
        if (element==i)
            count++;
        else
            count--;
    }
    return element;
}

vector<int> majorityB(vector<int>& nums){
    int c1=0,c2=0;
    int n1,n2;
    for (auto i:nums){
        if (i==n1)
            c1++;
        else if (i==n2)
            c2++;
        else if (c1==0)
            n1=i;
        else if (c2==0)
            n2=i;
        else{
            c1--;
            c2--;
        }
    }

    // Verify.
    c1=0;c2=0;
    for (auto i:nums){
        if (i==n1)
            c1++;
        if (i==n2)
            c2++;
    }
    vector<int> res;
    if (c1>nums.size()/3)
        res.push_back(n1);
    if (c2>nums.size()/3)
        res.push_back(n2);
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
    // int res = majority(nums);
    // cout<<res;
    vector<int> res = majorityB(nums);
    for (auto i:res)
        cout<<i<<" ";

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