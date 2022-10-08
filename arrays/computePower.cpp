# include <iostream>
#include <bits/stdc++.h>
using namespace std;


double power(double n,int k){
    int m=k;
    if (k<0)
        m = -1*k;
    double ans=1.0;
    while(m){
        if (m%2){
            ans = ans*n;
            m = m-1;
        }
        else{
            n = n*n;
            m = m/2;
        }
    }
    if (k<0)
        ans = 1.0/ans;
    return ans;
}


void answer(){
    int k;
    double n;
    cin>>n>>k;
    // cout<<n<<endl;
    double res = power(n,k);
    cout<<res<<endl;
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