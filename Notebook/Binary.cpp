// Funcion monotona F F F T T (o(log n))
ll binarySearchFirstTrue(ll l, ll r) {
    while (l < r) {
        ll mid = l + (r - l) / 2;
        if (isTrue(mid)) {
            r = mid;  
        } else {
            l = mid + 1;
        }
    }
    return l;
}

// Funcion monotona T T T F F (o(log n))
ll binarySearchLastTrue(ll l, ll r) {
    while (l < r) {
        ll mid = l + (r - l) / 2;
        if (isTrue(mid)) {
            l = mid;  
        } else {
            r = mid - 1;
        }
    }
    return l;
}

//Busqueda binaria o(log n)
ll binarySearch(){
    int l = 0, r = n-1;
    while (l <= b) {
        int m=(l+r)/2;
        if (array[m]==x) return m;
        else if (array[m]>x) r=m-1;
        else l=m+1;
    }
    return -1;
}