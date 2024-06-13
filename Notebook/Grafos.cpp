//FloodFill O(n*m)
vector<vector<bool>> visited;
vector<vector<char>> mapa;
int n, m; 
void floodfill(int x1, int y1){
    queue<pair<int, int>> q;
    q.push({x1,y1});
    visited[x1][y1] = true;
    while(!q.empty()){
        auto act=q.front(); q.pop();
        x1=act.F;
        y1=act.S;
        for(int i=0; i<4; ++i){
            int x2=x1+dirx[i];
            int y2=y1+diry[i];
            if((x2<0 || x2 >= n || y2<0 || y2 >= m) 
               || (visited[x2][y2]) 
               || (mapa[x2][y2]=='#')) continue;
            visited[x2][y2]=true;
            q.push({x2,y2});
        }
    }
}
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr); 
    cin >> n >> m;
    visited.assign(n, vector<bool>(m, false));
    char c;
    for(int i=0;i<n; ++i){
        vector<char> v(m);
        for(int j=0; j<m; ++j){
            cin >> v[j];
        }
        mapa.PB(v);
    }
    int rooms=0;
    for(int i=0;i<n; ++i){
        for(int j=0; j<m; ++j){
            if(!visited[i][j] && mapa[i][j]!='#'){
               floodfill(i,j);
               rooms++;
            }
        }
    }
    cout << rooms;
    return 0;
}

//BFS O(n + m)
vector<bool> visited;
vector<vector<int>> adj;
int n, m; 
void bfs(int x){
    queue<int> q;
    q.push(x);
    visited[x] = true;
    while(!q.empty()){
        int s=q.front(); q.pop();
        for(int u: adj[s]){
            if(visited[u]) continue;
            visited[u]=true;
            q.push(u);
        }
    }
}

//Bipartito
vector<int> teams;
bool bfs(int x){
    queue<int> q;
    visited[x]=true;
    teams[x]=1;
    q.push(x);
    while(!q.empty()){
        int s=q.front(); q.pop();
        if(teams[s]==1) t=2;
        if(teams[s]==2) t=1;
        for(int u: adj[s]){
            if(visited[u] && teams[s]==teams[u]) return false;
            else if(visited[u] && teams[s]!=teams[u]) continue;
            visited[u]=true;
            teams[u]=t;
            q.push(u);
        }
    }
    return true;
}

//Camino con bfs 
vector<int> path; vector<int> distancia; vector<int> dad;
bool f=false; int n, m;
bool bfs(int x){
    queue<int> q;
    visited[x]=true;
    q.push(x);
    distancia[x]=0;
    while(!q.empty()){
        int s=q.front(); q.pop();
        for(int u: adj[s]){
            if(visited[u]) continue;
            distancia[u]=distancia[s]+1;
            dad[u]=s;
            if(u==n){
                cout << distancia[u]+1 << "\n";
                while(u!=1){
                    path.PB(u);
                    u=dad[u];
                }
                cout << 1;
                for(int i=sz(path)-1; i>=0; i--){
                    cout << " " << path[i];
                }
                return true;
            }
            visited[u]=true;
            q.push(u);
        }
    }
    return false;
}

//Ciclos grafos bidireccionados dfs O(n + m)
vector<vector<int>> adj; vector<bool> visited; vector<int> parent;
int n, m; int cycle_start, cycle_end;
bool dfs(int v, int par) { 
    visited[v] = true;
    for (int u : adj[v]) {
        if(u == par) continue; 
        if (visited[u]) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
        parent[u] = v;
        if (dfs(u, parent[u]))
            return true;
    }
    return false;
}
void find_cycle() {
    visited.assign(n+1, false);
    parent.assign(n+1, -1);
    cycle_start = -1;
 
    for (int v = 1; v < n+1; v++) {
        if (!visited[v] && dfs(v, parent[v]))
            break;
    }
 
    if (cycle_start == -1) {
        cout <<"IMPOSSIBLE";
    } else {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);
 
        cout << sz(cycle) << "\n";
        for (int v : cycle)
            cout << v << " ";
    }
}

//Ciclos grafos direccionados dfs
bool dfs(int v) { 
    visited[v] = 1;
    for (int u : adj[v]) {
       if(visited[u]==0){
          parent[u]=v;
          if(dfs(u)) return true;
       }else if(visited[u]==1){
        cycle_start=u;
        cycle_end=v;
        return true;
       }
    }
    visited[v] = 2;
    return false;
}

void find_cycle() {
    visited.assign(n+1, 0);
    parent.assign(n+1, -1);
    cycle_start = -1;

    for (int v = 1; v < n+1; v++) {
        if (visited[v]==0 && dfs(v))
            break;
    }

    if (cycle_start == -1) {
        cout <<"IMPOSSIBLE";
    } else {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());
        cout << sz(cycle) << "\n";
        for (int v : cycle)
            cout << v << " ";
    }
}

//Dijkstra O((n + m) * log(n))
void dijkstra(int s){
	priority_queue<pll, vll, greater<pll>> pq;
	pq.push({0, s});
	dist[s]=0;
	while(!pq.empty()){
		pll act=pq.top();pq.pop();
		ll d=act.F,u=act.S;
		if(d>dist[u])continue;
		for(auto v:adj[u]){
			int w=v.S,b=v.F;
			if(dist[u]+w<dist[b]){
				dist[b]=dist[u]+w;
				pq.push({dist[b],b});
			}
		}
	}
}
 
//Floyd Warshall O(n^3)
void floydWarshall(){
    forx(k,n) {
        forx(i,n) {
            forx(j,n) {
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
    return;
}
int main(){
    int q, a, b; cin >> n >> m >> q;
    ll w;
    adj.assign(n, vl(n));
    dist.assign(n, vl(n)); 
    forx(i,m){
        cin >> a >> b >> w; a--; b--;
        if(adj[a][b]){
            adj[a][b]=min(w,adj[a][b]);
            adj[b][a]=min(w,adj[b][a]);
        }else{
            adj[a][b]=w;
            adj[b][a]=w;
        }
    }
    forx(i,n) {
        forx(j,n) {
            if (i == j) dist[i][j] = 0;
            else if (adj[i][j]) dist[i][j] = adj[i][j];
            else dist[i][j] = INF;
        }
    }
    floydWarshall();
    forx(i,q){
        cin >> a >> b;
        a--; b--;
        if(dist[a][b]==INF) cout << -1;
        else cout << dist[a][b];
        cout << "\n";
    }
    return 0;
}

