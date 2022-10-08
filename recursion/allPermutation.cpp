# include <iostream>
#include <bits/stdc++.h>
#include <memory>
#include <type_traits>
using namespace std;


void allPermutation(int n,int *arr,vector<int>& seq,vector<vector<int>>& ans,vector<int>& freq){
    if (seq.size()==n){
        ans.push_back(seq);
        return ;
    }
    for (int i=0;i<n;i++){
        if (!freq[i]){
            seq.push_back(arr[i]);
            freq[i]=1;
            allPermutation(n, arr, seq, ans, freq);
            seq.pop_back();
            freq[i]=0;
        }
    }
}

void answer(){
    int n;
    cin>>n;
    int *arr=new int(n);
    for (int i=0;i<n;i++)
        cin>>arr[i];

    vector<int> seq;
    vector<vector<int>> res;
    vector<int> freq(n+1,0);
    allPermutation(n, arr, seq, res,freq);

    for (int i=0;i<res.size();i++){
        cout<<"{";
        for (int j=0;j<res[i].size();j++)
            cout<<res[i][j]<<",";
        cout<<"}";
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