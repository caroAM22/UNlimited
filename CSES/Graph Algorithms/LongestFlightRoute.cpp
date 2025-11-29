#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // Lista de adyacencia del grafo
    vector<vector<int>> adj(n+1);

    // indeg[v] = cantidad de aristas que llegan a v
    // Se usa para topological sorting (Kahn)
    vector<int> indeg(n+1, 0);

    // Leemos las m aristas dirigidas
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indeg[b]++;  // aumenta in-degree del destino
    }

    // -------------------------------
    // 1) ORDEN TOPOLOGICO (KAHN)
    // -------------------------------
    queue<int> q;

    // Insertamos todos los nodos sin aristas entrantes
    for (int i = 1; i <= n; ++i) {
        if (indeg[i] == 0) q.push(i);
    }

    vector<int> topo;
    topo.reserve(n);

    // Proceso de Kahn: sacamos nodos con indegree 0 y
    // reducimos indegree de sus vecinos
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo.push_back(u);

        for (int v : adj[u]) {
            indeg[v]--;
            if (indeg[v] == 0) q.push(v);
        }
    }

    // -------------------------------
    // 2) DP PARA CAMINO MÁS LARGO
    // -------------------------------
    const int NEG = -1;

    // dp[v] = máximo número de ciudades visitadas para llegar a v
    vector<int> dp(n+1, NEG);

    // par[v] = ciudad anterior en el mejor camino hacia v
    vector<int> par(n+1, -1);

    // El recorrido empieza en ciudad 1 → camino de tamaño 1
    dp[1] = 1;

    // Recorremos la lista topológica en orden
    // Esto garantiza que siempre procesamos primero
    // los nodos antecesores
    for (int u : topo) {
        if (dp[u] == NEG) continue;  // si u no es alcanzable, lo ignoramos

        // Relajamos las aristas u → v
        for (int v : adj[u]) {
            // Si podemos mejorar el camino más largo hacia v
            if (dp[u] + 1 > dp[v]) {
                dp[v] = dp[u] + 1;
                par[v] = u;  // guardamos el antecesor
            }
        }
    }

    // Si no hay forma de llegar a la ciudad n → no hay solución
    if (dp[n] == NEG) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    // -------------------------------
    // 3) RECONSTRUIR EL CAMINO
    // -------------------------------
    vector<int> path;
    for (int v = n; v != -1; v = par[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());  // lo invertimos para comenzar en 1

    // -------------------------------
    // 4) SALIDA
    // -------------------------------
    cout << dp[n] << "\n";  // número de ciudades en el camino

    for (int i = 0; i < (int)path.size(); ++i) {
        if (i) cout << " ";
        cout << path[i];
    }
    cout << "\n";

    return 0;
}
