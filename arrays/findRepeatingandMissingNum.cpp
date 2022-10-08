# include <iostream>
#include <bits/stdc++.h>
#include <iterator>
#include <vector>
using namespace std;



vector<int> findNumbersXOR(vector<int> nums){
    int xr=0;
    for (auto i:nums)
        xr = xr^i;
    
    for (int i=1;i<=nums.size();i++)
        xr = xr^i;

    int bit_pos = xr & ~(xr-1);

    int x=0,y=0;
    for (auto i:nums){
        if (i&bit_pos)
            x = x^i;
        else
            y = y^i;
    }
    for (int i=1;i<=nums.size();i++){
        if (i&bit_pos)
            x = x^i;
        else
            y = y^i;
    }
    // NUmbers can be swap;
    int count = 0;
    for (auto i:nums){
        if (i==x)
            count++;
    }
    if (count==0)
        return {x,y};
    
    return {y,x};
}


void answer(){
    int n,t;
    vector<int> nums;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>t;
        nums.push_back(t);
    }
    vector<int> res;
    res = findNumbersXOR(nums);
    cout<<"Repeating : "<<res[1]<<endl;
    cout<<"Missing : "<<res[0]<<endl;
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