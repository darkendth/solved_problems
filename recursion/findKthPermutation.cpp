# include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

int factorial(int n){
    if (n==0||n==1)
        return 1;
    else
        return n*factorial(n-1);
}

void kthPermutation(int n,int k,string& res,vector<int>& nums){
    if (nums.size()==1){
        res+=to_string(nums[0]);
        return ;
    }
    int r=factorial(n-1);
    int num=k/r;
    res+=to_string(nums[num]);
    nums.erase(find(nums.begin(),nums.end(),nums[num]));
    kthPermutation(n-1,(k)%r,res,nums);
}

void answer(){
    int n,k;
    cin>>n>>k;
    string res;
    vector<int> nums;
    for (int i=1;i<=n;i++)
        nums.push_back(i);
    kthPermutation(n, k-1, res,nums);

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