#include <climits>
# include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int numberOfLIS(vector<int> nums){
    int n=nums.size();
    vector<int> dp(n,1);
    vector<int> seq(n,0);
    for (int i=0;i<n;i++){
        for (int j=0;j<i;j++){
            if (nums[i]>nums[j]){
                if (dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    seq[i]=seq[j];
                }
                else if (dp[i]==dp[j]+1)
                    seq[i]=seq[i]+seq[j];
            }
        }
    }

    int _max=INT_MIN;
    int num=0;
    for (int i=0;i<n;i++){
        if (dp[i]>_max){
            _max = dp[i];
            num = dp[i];
        }
        else if(dp[i] == _max)
            num += dp[i];
    }
    return num;
}

void answer(){
    int n,t;
    cin>>n;
    vector<int> nums;
    for (int i=0;i<n;i++){
        cin>>t;
        nums.push_back(t);
    }
    int ans = numberOfLIS(nums);
    cout<<ans;
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