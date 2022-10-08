#include <algorithm>
# include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;


vector<vector<int>> merge(vector<vector<int>>& intervals){
    sort(intervals.begin(),intervals.end());
    int i=0;
    for (int j=1;j<intervals.size();j++){
        if (intervals[i][1]>=intervals[j][0])
            intervals[i][1] = max(intervals[i][1],intervals[j][1]);
        else{
            i++;
            intervals[i]=intervals[j];
        }
    }
    intervals.erase(intervals.begin()+i+1,intervals.end());
    return intervals;
}


void answer(){
    int m,t1,t2;
    cin>>m;
    vector<vector<int>> intervals;
    for (int i=0;i<m;i++){
        cin>>t1>>t2;
        intervals.push_back({t1,t2});
    }
    intervals = merge(intervals);
    for(int i=0;i<intervals.size();i++){
        for(int j=0;j<2;j++){
            cout<<intervals[i][j]<<" ";
        }
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