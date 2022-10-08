# include <iostream>
#include <bits/stdc++.h>
using namespace std;

int minimumPlatform(vector<int> arrival,vector<int> departure){
    sort(arrival.begin(),arrival.end());
    sort(departure.begin(),departure.end());

    int n=arrival.size();
    int count=1;
    int platform=0;
    int i=1,j=0;
    while(i<n&&j<n){
        if (arrival[i]<departure[j]){
            count++;
            i++;
        }
        else{
            count--;
            j++;
        }
        platform = max(platform,count);
    }
    return platform;
}


void answer(){
    int n;
    cin>>n;
    vector<int> start,end;
    int t;
    for (int i=0;i<n;i++){
        cin>>t;
        start.push_back(t);
    }
    for (int i=0;i<n;i++){
        cin>>t;
        end.push_back(t);
    }
    int res=minimumPlatform(start, end);
    cout<<res;
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