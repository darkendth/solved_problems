# include "graph.h"
#include <vector>


void dfsTraversal(vector<vector<int>> isConnected,int ind,vector<int>& visit){
    visit[ind]=1;
    for (int i=0;i<isConnected.size();i++){
        if (!visit[i]&&isConnected[ind][i])
            dfsTraversal(isConnected, i, visit);
    }
}

int numOfConnectedComponent(vector<vector<int>>& isConnected){
    int count=0;
    vector<int> visit(isConnected.size()+1,0);
    for (int i=0;i<isConnected.size();i++){
        if (!visit[i]){
            dfsTraversal(isConnected,i,visit);
            count++;
        }
    }
    return count;
}

void answer(){
    int n,t;
    cin>>n;
    vector<vector<int>> isConnected(n,vector<int>(n));
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin>>t;
            isConnected[i][j]=t;
        }
    }
    int r = numOfConnectedComponent(isConnected);
    cout<<r;
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