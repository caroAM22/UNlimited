#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define forx(i,n) for(int i=0; i<(int)n; ++i)
#define all(x) x.begin(), x.end()
typedef long long int ll;

vector<int> v;
int n, t;

bool isTrue(int x) {
    int time = 0;
    priority_queue<int> s;
    for (int i = 0; i < n; i++) {
        if (s.size() == x) {
            time = -s.top();
            s.pop();
        }
        if (time + v[i] > t) return false;
        else s.push(-time - v[i]);
    }
    return true;
}

int binarySearchft(int l, int r) {
    while (l < r) {
        int mid = (l + r) / 2;
        if (isTrue(mid)) {
            r = mid;  
        } else {
            l = mid + 1;
        }
    }
    return l;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);
    int num;
    cin >> n >> t;
    forx(i,n){
        cin >> num;
        v.PB(num);
    }
    cout << binarySearchft(1,n);
    return 0;
}