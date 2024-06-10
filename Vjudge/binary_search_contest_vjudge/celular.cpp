#include <bits/stdc++.h>
using namespace std;

vector<int> city;
vector<int> tower;

bool isTrue(long long int x) {
    int i = 0;
    int j = 0;
    while (i < city.size() && j < tower.size()) {
        if (abs(city[i] - tower[j]) <= x) {
            i++;
        } else {
            j++;
        }
    }
    if (i == city.size()) return true;
    else return false;
}

int binarySearchFirstTrue(long long int l, long long int r) {
    while (l < r) {
        long long int mid = l + (r - l) / 2;
        if (isTrue(mid)) {
            r = mid;  
        } else {
            l = mid + 1;
        }
    }
    return l;
}

int main() {
    int n, k, num;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        city.push_back(num);
    }
    for (int i = 0; i < k; ++i) {
        cin >> num;
        tower.push_back(num);
    }
    cout << binarySearchFirstTrue(0, 10000000000);
    return 0;
}
