# include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

void rotate(vector<vector<int>>& matrix){
    for (int i=0;i<matrix.size();i++){
        for (int j=i;j<matrix[0].size();j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    for (int i=0;i<matrix.size();i++){
        reverse(matrix[i].begin(),matrix[i].end());
    }
}

void answer(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> mat;
    for (int i=0;i<n;i++){
        vector<int> temp;
        for (int j=0;j<m;j++){
            int t;
            cin>>t;
            temp.push_back(t);
        }
        mat.push_back(temp);
    }

    rotate(mat);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cout<<mat[i][j]<<" ";
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