#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
using vi = vector<int>;
#define forx(i,n) for(int i=0; i<(int)n; ++i)

vi subsets(vi a, int f){
    vi res;
    for (int i=0; i<(1<<a.size()); ++i){  
        ll sum=0;
        // cout << "Subset: ";
        for (int j=0; j<a.size(); ++j){
            if (i & (1<<j))
                sum+=a[j];
                // cout << a[j] << " ";}
        }
        // cout << endl;
        if (a[0]==f) res.push_back(sum);
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int num, n;
    cin >> n;
    vi arr;
    while (cin >> num) {
        arr.push_back(num);
    }
    vi res = subsets(arr, arr[0]);
    forx(i, res.size()){
       cout << res[i] << endl;
    }
    return 0;
}