#include <algorithm>
# include <iostream>
#include <bits/stdc++.h>
using namespace std;

void combinationSum(int n,int index,int target,int *arr,vector<int>& c_set,vector<vector<int>>& res){
    if (index==n&&target==0){
        res.push_back(c_set);
    }
    else if (index==n)
        return ;
    else{
        if (arr[index]<=target){
            c_set.push_back(arr[index]);
            combinationSum(n, index, target-arr[index], arr, c_set, res);
            c_set.pop_back();
        }
        combinationSum(n, index+1, target, arr, c_set, res);
    }
}

void uniqueCombSum(int n,int index,int target,int *arr,vector<int>& c_set,vector<vector<int>>& res){
    if (target==0){
        res.push_back(c_set);
        return ;
    }
    for (int i=index;i<n;i++){
        if (i!=index&&arr[i]==arr[i-1]) 
            continue;
        if (arr[i]>target)
            break;
        c_set.push_back(arr[i]);
        uniqueCombSum(n, i+1, target-arr[i], arr, c_set, res);
        c_set.pop_back();
    }
}

void answer(){
    int n;
    cin>>n;
    int *arr=new int(n);
    for (int i=0;i<n;i++)
        cin>>arr[i];
    int t;
    cin>>t;

    vector<int> c_set;
    vector<vector<int>> res;
    // combinationSum(n, 0, t, arr, c_set, res);

    // for unique combination sum.
    sort(arr,arr+n);
    uniqueCombSum(n, 0, t, arr, c_set, res);

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