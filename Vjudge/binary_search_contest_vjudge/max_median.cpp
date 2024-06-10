#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    std::priority_queue<int> pq;

    // Insertar elementos en la cola de prioridad
    pq.push(30);
    pq.push(10);
    pq.push(50);
    pq.push(20);

    // Acceder al elemento con la mayor prioridad (en este caso, el mayor valor)
    std::cout << "Elemento con mayor prioridad: " << pq.top() << std::endl;
    
    return 0;
}