# include "graph.h"


void dfs(int i,vector<pair<int,int>> adj[],vector<int> &visit,set<int> path,int d){
    visit[i]=1;
    for (auto it:adj[i]){
        if (!visit[it.first]){
            path.insert(it.second);
        }
    }
}

int minCostToReah(vector<pair<int,int>> adj[],int d){
    int n = adj->size();
    vector<int> visit(n,0);
    set<int> path;
    for (int i=0;i<n;i++){
        if (!visit[i]){
            dfs(i,adj,visit,path,int d);
        }
    }


}

void answer(){
    vector<pair<int,int>> *adj;
    make_graph_w(adj);
    print_graph_w(adj);
    int d;
    cin>>d;
    minCostToReah(adj);

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