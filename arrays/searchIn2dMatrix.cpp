# include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>> matrix,int target){
    int m=0;
    int n=matrix[0].size()-1;
    while(m<matrix.size()&&n>=0){
        if (matrix[m][n]==target)
            return true;
        if (matrix[m][n]>target)
            n=n-1;
        else 
            m=m+1;
            
    }
    return false;
}

void answer(){
    int n,t;
    cin>>n;
    vector<vector<int>> matrix;
    vector<int> nums;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin>>t;
            nums.push_back(t);
        }
        matrix.push_back(nums);
    }
    cin>>t;
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