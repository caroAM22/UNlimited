#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define forx(i,n) for(int i=0; i<(int)n; ++i)
#define all(x) x.begin(), x.end()
int main() {
    int n, num;
    cin >> n;
    vector<int> v;
    int k=0;
    forx(i,n){
        cin >> num;
        auto it=upper_bound(all(v),num); 
        if (it==v.end()){
            k++;
            v.PB(num);
        }else{
            v[it-v.begin()]=num;
        }
    }
    cout << k;
    return 0;
}