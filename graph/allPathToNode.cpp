# include "graph.h"
#include <vector>



void dfsTraversal(int i,vector<vector<int>> adj,vector<int> path,vector<vector<int>>& res){
    path.push_back(i);
    if (i==adj.size()-1)
        res.push_back(path);
    for (auto it:adj[i]){
        dfsTraversal(it, adj, path, res);
    }
    path.pop_back();
}

void allPathsSourceTarget(vector<vector<int>> adj){
    vector<vector<int>> res;
    vector<int> path;
    dfsTraversal(0,adj,path,res);
    for (int i=0;i<res.size();i++){
        for (int j=0;j<res[i].size();j++)
            cout<<res[i][j]<<",";
        cout<<endl;
    }
}

void answer(){
    int n,u,v;
    cin>>n;
    vector<vector<int>> adj(n);
    /* Directed Graph. */
    for (int i=0;i<n;i++){
        cin>>u>>v;
        adj[u].push_back(v);
    }
    displayGraph(adj);

    allPathsSourceTarget(adj);
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