#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef tuple<int, int, ll> edge;
const ll INF = 1e18;
#define print(arr) for(auto& x:arr)cout<<x<<" ";cout<<"\n"

vector<edge> edges;   
vl dist;        
int n, m;

bool bellmanFord(int x) {
    dist[x] = 0;
    for (int i = 1; i <= n - 1; i++) {
        for (auto e : edges) {
            int a, b;
            ll w;
            tie(a, b, w) = e;
            if (dist[a] != INF && dist[a] + w > dist[b]) {
                dist[b] = dist[a] + w;
            }
        }
    }

    // Verificar la presencia de ciclos positivos
    vector<bool> reachable(n, false), reachable_from_last(n, false);
    reachable[0] = true;

    // Encontrar nodos alcanzables desde el inicio
    for (int i = 0; i < n; i++) {
        for (auto e : edges) {
            int a, b;
            ll w;
            tie(a, b, w) = e;
            if (reachable[a]) reachable[b] = true;
        }
    }

    // Encontrar nodos que pueden alcanzar el nodo final
    reachable_from_last[n-1] = true;
    for (int i = 0; i < n; i++) {
        for (auto e : edges) {
            int a, b;
            ll w;
            tie(a, b, w) = e;
            if (reachable_from_last[b]) reachable_from_last[a] = true;
        }
    }

    // Verificar ciclos positivos que afecten el camino al nodo final
    for (int i = 0; i < n; i++) {
        for (auto e : edges) {
            int a, b;
            ll w;
            tie(a, b, w) = e;
            if (dist[a] != INF && dist[a] + w > dist[b]) {
                if (reachable[a] && reachable_from_last[b]) {
                    return true; // Se encontró un ciclo positivo que afecta el camino al destino
                }
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    dist.assign(n, -INF); 
    for (int i = 0; i < m; ++i) {
        int a, b;
        ll c;
        cin >> a >> b >> c; 
        a--; b--;
        edges.push_back({a, b, c});
    }
    if (bellmanFord(0)) {
        cout << -1 << endl;
    } else {
        cout << dist[n-1] << endl;
    }
    print(dist);
    return 0;
}
