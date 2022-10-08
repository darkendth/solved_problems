# include "graph.h"
#include <vector>


bool isCycleDFS(int node,vector<int> adj[],vector<int>& visited,vector<int>& is_neighbour){
    visited[node]=1;
    is_neighbour[node]=1;
    for (auto it:adj[node]){
        if (!visited[it]){
            if (isCycleDFS(it, adj, visited, is_neighbour))
                return true;
        }
        else if (is_neighbour[it])
            return true;
    }
    is_neighbour[node]=0;
    return false;
}


bool detectCycleDFS(vector<int> adj[],int n){
    vector<int> visited(n+1,0);
    vector<int> is_neighbour(n+1,0);
    for (int i=1;i<=n;i++){
        if (!visited[i]){
            if (isCycleDFS(i,adj,visited,is_neighbour));
                return true;
        }
    }
    return false;
}

void answer(){
    vector<int> adj[6];
    make_graph(adj);
    print_graph(adj);   

    bool cycle = detectCycleDFS(adj, 6);
    if (cycle)
        cout<<"true";
    else
        cout<<"false";
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