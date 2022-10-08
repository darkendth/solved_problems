#include <cstdlib>
# include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

struct Node{
    int weight;
    int profit;
    double fraction;
};
typedef struct Node Node;

bool comparator(Node i1,Node i2){
    if (i1.fraction<i2.fraction)
        return false;
    else
        return true;
}

int fractionalKnapsack(vector<int> weight,vector<int> profit, int m){
    int n=weight.size();
    vector<Node> items;
    Node item;
    for (int i=0;i<n;i++){
        item.profit=profit[i];
        item.weight=weight[i];
        item.fraction=(double)profit[i]/weight[i];
        items.push_back(item);
    }
    sort(items.begin(),items.end(),comparator);
    int total_profit=0;
    for (auto it:items){
        if (m>=it.weight){
            m = m-it.weight;
            total_profit += it.profit;
        }
        else{
            total_profit += ((double)m/it.weight)*it.profit;
            break;
        }
    }
    return total_profit;
}

void answer(){
    int n;
    cin>>n;
    vector<int> weight,profit;
    int t;
    for (int i=0;i<n;i++){
        cin>>t;
        weight.push_back(t);
    }
    for (int i=0;i<n;i++){
        cin>>t;
        profit.push_back(t);
    }
    cin>>t;
    int res=fractionalKnapsack(weight, profit, t);
    cout<<res;
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