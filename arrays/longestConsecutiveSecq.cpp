# include <iostream>
#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;


int longestSequence(vector<int>& nums){
    unordered_set<int> hashSet;

    for (auto it:nums)
        hashSet.insert(it);
    
    int longSeq=0;
    for (auto it:nums){
        if (hashSet.find(it-1)==hashSet.end()){
            int seq=0;
            int val=it;
            while(hashSet.find(val)!=hashSet.end()){
                seq++;
                val++;
            }
            longSeq = max(longSeq,seq);
        }
    }
    return longSeq;
}


void answer(){
    int n,t;
    vector<int> nums;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>t;
        nums.push_back(t);
    }
    int res = longestSequence(nums);
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