#include <cmath>
# include <iostream>
#include <bits/stdc++.h>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

vector<int> mergeTwoArrays(vector<int> nums1,vector<int> nums2){
    /* merge without extra space */
    int m = nums1.size();
    int n = nums2.size();
    int gap = (m+n)/2;
    int i,j;
    while(gap>0){
        for (int i=0,j=gap;j<(m+n);i++,j++){
            if (j<m && nums1[i]>nums1[j])
                swap(nums1[i],nums1[j]);
            if (i<m && j>=m && nums1[i]>nums2[j-m])
                swap(nums1[i], nums2[j-m]);
            if (i>=m && nums2[i-m]>nums2[j-m])
                swap(nums2[i-m],nums2[j-m]);
        }
        if (gap==1)
            gap = 0;
        else
            gap=ceil((float)gap/2);
        
    }
    nums1.insert(nums1.end(),nums2.begin(),nums2.end());
    return nums1;
}


void answer(){
    int m,n;
    int t;
    vector<int> nums1,nums2;
    cin>>m>>n;
    for (int i=0;i<m;i++){
        cin>>t;
        nums1.push_back(t);
    }
    for (int i=0;i<n;i++){
        cin>>t;
        nums2.push_back(t);
    }    
    vector<int> res;
    res = mergeTwoArrays(nums1,nums2);

    for(int i=0;i<res.size();i++)
        cout<<res[i]<<" ";
    cout<<endl;
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