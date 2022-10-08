#include <algorithm>
# include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

void uniqueSubset(int n,int ind,int *arr,vector<int>& c_set,vector<vector<int>>& res){
    res.push_back(c_set);
    for (int i=ind;i<n;i++){
        if (i!=ind&&arr[i]==arr[i-1])
            continue;
        c_set.push_back(arr[i]);
        uniqueSubset(n, i+1, arr, c_set, res);
        c_set.pop_back();
    }
}

void answer(){
    int n;
    cin>>n;
    int *arr=new int(n);
    for (int i=0;i<n;i++)
        cin>>arr[i];

    vector<int> c_set;
    vector<vector<int>> res;
    uniqueSubset(n, 0, arr, c_set, res);
    
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