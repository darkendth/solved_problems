# include "graph.h"
#include <vector>



void topoDFS(int node,vector<int> graph[],vector<int>& visit,stack<int>& stk){
    visit[node]=1;
    for (auto it:graph[node]){
        if (!visit[node])
            topoDFS(it, graph, visit, stk);
    }
    stk.push(node);
}


void topologicalSortDFS(vector<int> graph[],int n){
    /* Topological sort using DFS */

    vector<int> visit(n+1,0);
    stack<int> stk;
    for (int i=0;i<n;i++){
        if (!visit[i])
            topoDFS(i,graph,visit,stk);
    }
    vector<int> res;
    while(!stk.empty()){
        // res.push_back(stk.top());
        cout<<stk.top()<<" ";
        stk.pop();
    }
    cout<<endl;

}


void topologicalSortBFS(vector<int> graph[],int n){
    /* Topological sort using BFS */
    vector<int> indegree(n+1,0);
    for (int i=0;i<n;i++){
        for (auto it:graph[i])
            indegree[it]++;
    }
    queue<int> q;
    for (int i=0;i<n;i++){
        if (indegree[i]==0)
            q.push(i);
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<" - ";
        for (auto it:graph[node]){
            indegree[it]--;
            if (indegree[it]==0)
                q.push(it);
        }
    }   
}

void answer(){
    vector<int> adj[6];
    make_graph(adj);
    print_graph(adj);
    topologicalSortDFS(adj, 6);
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