#include <climits>
# include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int bsApproach(vector<int> nums1,vector<int> nums2,int n,int m,int k){
    if (n==0)
        return nums2[k];
    if (m==0)
        return nums1[k];

    int p=0,q=n;
    int mid1,mid2;
    while(p<=q){
        mid1 = (p+q)/2;
        mid2 = k-mid1;
        int l1 = mid1==0?INT_MIN:nums1[mid1-1];
        int l2 = mid2==0?INT_MIN:nums2[mid2-1];
        int r1 = mid1==n?INT_MAX:nums1[mid1+1];
        int r2 = mid2==n?INT_MAX:nums2[mid1+1];

        if (l1<=r2&&l2<=r1)
            return (max(l1,l2));
        if (l1>r2)
            q=mid1-1;
        else
            p=mid1+1;
    }
    return 1;
}

void answer(){
    int n,m,t;
    cin>>n>>m;
    vector<int> nums1,nums2;
    for (int i=0;i<n;i++){
        cin>>t;
        nums1.push_back(t);
    }
    for (int i=0;i<m;i++){
        cin>>t;
        nums2.push_back(t);
    }
    cin>>t;
    if (n<m)
        bsApproach(nums1,nums2,n,m,t);
    else
        bsApproach(nums2,nums1,m,n,t);

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