void vector_example() {
    vector<int> v;
    // Insertar al final (O(1) amortizado)
    v.push_back(10);
    // Insertar en una posición específica (O(n))
    v.insert(v.begin() + 1, 15); 
    // Buscar un valor (O(n))
    auto it = find(v.begin(), v.end(), 20);
    if (it != v.end()) {
        cout << "Found 20 at index " << it - v.begin() << "\n";
    }
    // Búsqueda binaria (O(log n)), true o false si esta o no
    sort(v.begin(), v.end());
    bool found = binary_search(v.begin(), v.end(), 20);
    // Eliminar por valor (O(n)) elimina todas las ocurrencias
    v.erase(remove(v.begin(), v.end(), 20), v.end());
    // Eliminar por posición (O(n))
    v.erase(v.begin() + 1);
    // Acceder a un elemento (O(1))
    int val = v[1];
}

void priority_queue_example() {
    priority_queue<int> pq;
    // Insertar (O(log n))
    pq.push(10);
    pq.push(20);
    pq.push(15);
    // Obtener el máximo (O(1))
    int max = pq.top();
    // Eliminar el máximo (O(log n))
    pq.pop();
}

void deque_example() {
    deque<int> dq;
    // Insertar al final (O(1))
    dq.push_back(10);
    // Insertar al frente (O(1))
    dq.push_front(20);
    // Eliminar del final (O(1))
    dq.pop_back();
    // Eliminar del frente (O(1))
    dq.pop_front();
    // Acceder a un elemento (O(1))
    int val = dq[0];
}

void stack_example() {
    stack<int> s;
    // Insertar (O(1))
    s.push(10);
    s.push(20);
    // Obtener el elemento superior (O(1))
    int top = s.top();
    // Eliminar el elemento superior (O(1))
    s.pop();
}

void queue_example() {
    queue<int> q;
    // Insertar (O(1))
    q.push(10);
    q.push(20);
    // Obtener el elemento frontal (O(1))
    int front = q.front();
    // Eliminar el elemento frontal (O(1))
    q.pop();
}

void map_example() {
    map<int, int> m;
    // Insertar (O(log n))
    m[1] = 100;
    m[2] = 200;
    // Buscar (O(log n))
    auto it = m.find(1);
    if (it != m.end()) {
        cout << "Found key 1 with value " << it->second << "\n";
    }
    // Eliminar (O(log n))
    m.erase(1);
}

void multimap_example() {
    multimap<int, int> mm;
    // Insertar (O(log n))
    mm.insert({1, 100});
    mm.insert({1, 200});
    // Buscar (k*O(log n)) siendo k las ocurrencias
    auto it = mm.find(1);
    if (it != mm.end()) {
        cout << "Found key 1 with value " << it->second << "\n";
    }
    // Eliminar (O(log n))
    mm.erase(1);
}

void set_example() {
    set<int> s;
    // Insertar (O(log n))
    s.insert(10);
    s.insert(20);
    // Buscar (O(log n))
    auto it = s.find(10);
    if (it != s.end()) {
        std::cout << "Found 10\n";
    }
    // Eliminar (O(log n))
    s.erase(10);
}

void multiset_example() {
    multiset<int> ms;
    // Insertar (O(log n))
    ms.insert(10);
    ms.insert(10);
    // Buscar (O(log n))
    auto it = ms.find(10);
    if (it != ms.end()) {
        cout << "Found 10\n";
    }
    // Eliminar (O(log n))
    ms.erase(ms.find(10));
}

