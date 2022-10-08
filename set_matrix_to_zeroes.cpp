# include <iostream>
#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int c0=1;
    int m=matrix.size(),n=matrix[0].size();
    for (int i=0;i<m;i++){
        if (matrix[i][0]==0)
            c0 = 0;
        for (int j=1;j<n;j++){
            if (matrix[i][j]==0){
                matrix[i][0]=0;
                matrix[0][j]=0;
            }
        }
    }
    for (int i=m-1;i>=0;i--){
        for (int j=n-1;j>0;j--){
            if (matrix[i][0]==0||matrix[0][j]==0)
                matrix[i][j]=0;
        }
        if (c0==0)
            matrix[i][0]=0;
    }
}

void answer(){
    vector<vector<int>> matrix;
    int m,n,temp;
    cin>>m>>n;
    for(int i=0;i<m;i++){
        vector<int> t;
        for(int j=0;j<n;j++){
            cin>>temp;
            t.push_back(temp);
        }
        matrix.push_back(t);
    }
    setZeroes(matrix);

    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++)
            cout<<matrix[i][j]<<" ";
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