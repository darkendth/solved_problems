# include <iostream>
#include <bits/stdc++.h>
using namespace std;


int uniquePathRecur(int m,int n){
    if (n==0||m==0)
        return 0;
    if (n==1&&m==1)
        return 1;
    int l1=uniquePathRecur(m-1, n);
    int l2=uniquePathRecur(m, n-1);
    return l1+l2;
}

int uniquePathDP(int m,int n,vector<vector<int>>& table){
    if (n==0||m==0)
        return 0;
    if (n==1&&m==1)
        return 1;

    if (table[m-1][n]==-1)
        table[m-1][n] = uniquePathDP(m-1, n, table);
    if (table[m][n-1]==-1)
        table[m][n-1] = uniquePathDP(m, n-1, table);
    return table[m-1][n]+table[m][n-1];
}

int uniquePathMath(int m,int n){
    int N=m+n-2;
    int r=m-1;
    int ans=1;
    for (int i=1;i<=r;i++){
        ans = ans*(N-r+i)/i;
    }
    return ans;
}

void answer(){
    int m,n;
    cin>>m>>n;
    int paths;
    // paths = uniquePathRecur(m, n);
    // vector<vector<int>> table(m+1,vector<int>(n+1,-1));
    // paths = uniquePathDP(m, n, table);
    paths = uniquePathMath(m, n);
    cout<<paths<<endl;
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