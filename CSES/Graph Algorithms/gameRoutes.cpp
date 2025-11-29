#include <bits/stdc++.h>
using namespace std;

static const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // Lista de adyacencia
    vector<vector<int>> adj(n + 1);

    // indeg[v] = cuántas aristas llegan a v
    // Esto lo necesitamos para Kahn (orden topológico)
    vector<int> indeg(n + 1, 0);

    // Leer las aristas dirigidas
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indeg[b]++; // incrementa indegree del destino
    }

    // -------------------------------
    // 1. Orden topológico (Kahn)
    // -------------------------------
    queue<int> q;

    // Encolamos todos los nodos con indegree = 0
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) q.push(i);
    }

    vector<int> topo; 
    topo.reserve(n);

    // Proceso Kahn: removemos nodos sin aristas entrantes
    // y actualizamos indegree de sus vecinos
    while (!q.empty()) {
        int u = q.front(); 
        q.pop();
        topo.push_back(u);

        for (int v : adj[u]) {
            indeg[v]--;
            if (indeg[v] == 0)
                q.push(v);
        }
    }

    // -------------------------------
    // 2. DP sobre el orden topológico
    // -------------------------------
    // dp[v] = número de formas de llegar a v desde 1
    vector<long long> dp(n + 1, 0);

    // Hay 1 forma de estar en el nivel 1: comenzar ahí
    dp[1] = 1;

    // Recorremos los nodos en topo order
    for (int u : topo) {
        for (int v : adj[u]) {
            // Si podemos llegar a u en dp[u] formas,
            // entonces también podemos llegar a v
            // añadiendo esas formas.
            dp[v] = (dp[v] + dp[u]) % MOD;
        }
    }

    // dp[n] = formas de llegar al nivel final
    cout << dp[n] << "\n";

    return 0;
}
