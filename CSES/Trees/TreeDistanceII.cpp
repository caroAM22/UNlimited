#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200000;
vector<int> adj[MAXN + 1];

long long sub[MAXN + 1];      // tamaño del subárbol
long long ans[MAXN + 1];      // respuesta final: suma de distancias
int n;

// Primer DFS: calcula sub[u] y ans[1] = suma de distancias desde 1
void dfs1(int u, int parent) {
    sub[u] = 1;  // cada nodo cuenta como 1
    ans[u] = 0;  // aquí ans[u] se usa para acumular distancias parciales

    for (int v : adj[u]) {
        if (v == parent) continue;
        dfs1(v, u);

        sub[u] += sub[v];
        ans[u] += ans[v] + sub[v];  
        // ans[v] = suma distancias dentro del subárbol de v
        // sub[v] = número de nodos del subárbol, todos a dist+1
    }
}

// Segundo DFS: re-rooting DP para calcular ans[v] desde ans[u]
void dfs2(int u, int parent) {
    for (int v : adj[u]) {
        if (v == parent) continue;

        // Fórmula de re-rooting:
        // al mover la raíz de u a v:
        // ans[v] = ans[u] - sub[v] + (n - sub[v])
        ans[v] = ans[u] - sub[v] + (n - sub[v]);

        dfs2(v, u);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Primer DFS: raíz = 1
    dfs1(1, 0);

    // Segundo DFS: propagamos la respuesta
    dfs2(1, 0);

    // Imprimir resultados
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";

    return 0;
}
