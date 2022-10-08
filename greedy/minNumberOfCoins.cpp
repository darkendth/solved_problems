# include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Test Case :s
// 3
// 720
// 440
// 1200


vector<int> minCoins(int *coins,int n,int m){
    vector<int> res(n,0);
    int i=n-1;
    while(m>0&&i>=0){
        if (m>=coins[i]){
            res[i]++;
            m=m-coins[i];
        }
        else
            i--;
    }
    return res;
}

void answer(){
    int m;
    cin>>m;
    int coins[] = {1,2,5,10,20,50,100,500,1000};
    int n=9;
    vector<int> res = minCoins(coins, n, m);
    for (int i=n-1;i>=0;i--){
        if (res[i])
            cout<<coins[i]<<" : "<<res[i]<<endl;
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