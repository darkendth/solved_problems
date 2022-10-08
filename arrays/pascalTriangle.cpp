# include <iostream>
#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> pascal(int numRows){
    vector<vector<int>> res(numRows);
    
    for (int i=0;i<numRows;i++){
        res[i].resize(i+1);
        res[i][0]=1;
        res[i][i]=1;
        for (int j=1;j<i;j++)
            res[i][j]=res[i-1][j-1]+res[i-1][j];
    }
    return res;
}


void answer(){
    int n;
    cin>>n;
    vector<vector<int>> res = pascal(n);

    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++)
            cout<<res[i][j]<<" ";
        
    cout<<endl;
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