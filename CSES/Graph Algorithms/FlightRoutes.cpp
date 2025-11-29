#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int, ll>>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    // dist[v] = vector con las k mejores distancias
    vector<vector<ll>> dist(n + 1);
    for (int i = 1; i <= n; i++) dist[i].reserve(k);

    // min-heap de estados (distancia, nodo)
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    dist[1].push_back(0);
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [cost, u] = pq.top();
        pq.pop();

        // Si este cost no está en las k mejores, ignóralo
        if (dist[u].back() < cost) continue;

        for (auto &edge : adj[u]) {
            int v = edge.first;
            ll w = edge.second;
            ll newCost = cost + w;

            // Si aun no tenemos k distancias para v o es menor que la peor
            if ((int)dist[v].size() < k || dist[v].back() > newCost) {
                dist[v].push_back(newCost);
                sort(dist[v].begin(), dist[v].end());
                if ((int)dist[v].size() > k)
                    dist[v].pop_back();
                pq.push({newCost, v});
            }
        }
    }

    for (ll x : dist[n]) cout << x << " ";
    cout << "\n";

    return 0;
}
