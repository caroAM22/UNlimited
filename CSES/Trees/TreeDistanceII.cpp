#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100005; // Ajusta el tamaño según sea necesario
vector<int> tree[MAXN];
int maxLength1[MAXN], maxLength2[MAXN], maxLength[MAXN];

// Primera DFS para calcular maxLength1 y maxLength2
void dfs1(int node, int parent) {
    int max1 = 0, max2 = 0;
    for (int child : tree[node]) {
        if (child == parent) continue;
        dfs1(child, node);
        int length = maxLength1[child];
        if (length > max1) {
            max2 = max1;
            max1 = length;
        } else if (length > max2) {
            max2 = length;
        }
    }
    maxLength1[node] = max1 + 1;
    maxLength2[node] = max2 + 1;
}

// Segunda DFS para calcular maxLength con caminos hacia el padre
void dfs2(int node, int parent) {
    for (int child : tree[node]) {
        if (child == parent) continue;
        if (maxLength1[child] + 1 == maxLength1[node]) {
            maxLength[child] = max(maxLength2[node] + 1, maxLength1[parent] + 1);
        } else {
            maxLength[child] = max(maxLength1[node], maxLength1[parent] + 1);
        }
        dfs2(child, node);
    }
}

int main() {
    int n; 
    cin >> n;

    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs1(1, -1);
    maxLength[1] = maxLength1[1];
    dfs2(1, -1);

    for (int i = 1; i <= n; ++i) {
        cout << "maxLength(" << i << ") = " << maxLength[i] << endl;
    }

    return 0;
}
