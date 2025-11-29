#include <bits/stdc++.h>
using namespace std;
 
vector<vector<int>> adj;
vector<int> grade;
vector<int> visited;
vector<int> order;
 
void dfs(int u){
    order.push_back(u);
    visited[u]=true;
    for(auto& v: adj[u]){
        grade[v]--;
        if(grade[v]==0 && !visited[v]) dfs(v);
    }
}
 
int main(){
    int n, m, a, b; cin >> n >> m;
    adj.assign(n+1,vector<int>());
    grade.assign(n+1,0);
    visited.assign(n+1,false);
    for(int i=0; i<m; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        grade[b]++;
    }
    for(int i=1; i<=n; i++){
        if(grade[i]==0 && !visited[i]) dfs(i);
    }
    if((int)order.size()==n){
        for(int& x: order){
            cout << x << " ";
        }
    }else cout << "IMPOSSIBLE";
    return 0;
}