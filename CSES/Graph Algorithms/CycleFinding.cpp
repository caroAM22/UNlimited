#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int a, b;
    long long c;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].a >> edges[i].b >> edges[i].c;
    }

    const long long INF = 1e18;
    vector<long long> dist(n+1, 0);   // <-- IMPORTANT : tous à 0
    vector<int> parent(n+1, -1);

    int x = -1;

    // Bellman–Ford n fois
    for (int i = 0; i < n; i++) {
        x = -1;
        for (auto &e : edges) {
            if (dist[e.a] + e.c < dist[e.b]) {
                dist[e.b] = dist[e.a] + e.c;
                parent[e.b] = e.a;
                x = e.b;
            }
        }
    }

    if (x == -1) {
        cout << "NO\n";
        return 0;
    }

    // Remonter n fois pour entrer dans le cycle
    for (int i = 0; i < n; i++)
        x = parent[x];

    vector<int> cycle;
    int v = x;
    while (true) {
        cycle.push_back(v);
        v = parent[v];
        if (v == x) break;
    }
    cycle.push_back(x);
    reverse(cycle.begin(), cycle.end());

    cout << "YES\n";
    for (int node : cycle) cout << node << " ";
    cout << "\n";

    return 0;
}
