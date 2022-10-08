# include <iostream>
#include <bits/stdc++.h>
using namespace std;

void subsetSum(int n,int i,int *arr,int sum,vector<int>& sub_sum){
    if (i==n)
        sub_sum.push_back(sum);
    else{
        subsetSum(n,i+1,arr,sum+arr[i],sub_sum);
        subsetSum(n,i+1,arr,sum,sub_sum);
    }
}

void answer(){
    int n;
    cin>>n;
    int *arr=new int(n);
    for (int i=0;i<n;i++)
        cin>>arr[i];
    vector<int> sub_sum;
    subsetSum(n,0,arr,0,sub_sum);
    sort(sub_sum.begin(),sub_sum.end());
    for (auto it:sub_sum)
        cout<<it<<" ";
    cout<<endl;
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