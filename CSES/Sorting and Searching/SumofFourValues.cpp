#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long x;
    cin >> n >> x;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    // Mapa: suma -> lista de pares (i, j) que producen esa suma
    // Guardamos varios pares porque puede haber colisiones con distintas posiciones.
    unordered_map<long long, vector<pair<int,int>>> sumPairs;

    // Recorremos todos los pares (i, j) con i < j
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            long long s = a[i] + a[j]; // suma de este par
            long long target = x - s; // lo que falta para llegar al objetivo

            // Si existe algún par previo cuya suma sea "target"
            if (sumPairs.count(target)) {
                // Revisamos cada par candidato
                for (auto &p : sumPairs[target]) {
                    int x1 = p.first;
                    int y1 = p.second;

                    // Verificamos que los 4 índices sean distintos
                    if (x1 != i && x1 != j && y1 != i && y1 != j) {
                        // Encontramos solución → imprimimos (1-based)
                        cout << x1 + 1 << " " << y1 + 1 << " " << i + 1 << " " << j + 1 << "\n";
                        return 0;
                    }
                }
            }

            // Guardamos el par actual en el mapa
            sumPairs[s].push_back({i, j});
        }
    }

    // Si no se encontró ninguna combinación válida
    cout << "IMPOSSIBLE\n";
    return 0;
}
