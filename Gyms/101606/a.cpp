#include <bits/stdc++.h>
using namespace std;
#define print(arr) for(auto& x:arr)cout<<x<<" ";cout<<"\n"
#define all(x) x.begin(), x.end()
#define sz(x) ((int) x.size())
#define PB push_back
#define S second
#define F first
#define forx(i,n) for(int i=0; i<(int)n; ++i)
typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int MOD = 1e9+7;

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr); 
    int n; cin >> n;
    vector<pair<int,vector<ii>>> v;
    int maxi=0; int index;
    forx(i, n){
        int a, b, c; cin >> a >> b >> c;
        vector<ii> intervals;
        if(b<c){
            intervals.push_back({0, b});
            intervals.push_back({c, a});
        }
        else{
            intervals.push_back({c, b});
        }
        v.push_back({a, intervals});
        if(maxi<a){
            maxi=a;
            index=i;
        }
    }
    // for(auto x: v){
    //     for(auto y: x.S){
    //         cout << y.F << " " << y.S << "\n";
    //     }
    // }
    bool f=true;
    forx(x,1825*maxi){
        bool b=true;
        for(auto y: v){
            for(auto interval : y.S){
                if(x % y.F < interval.F || x % y.F > interval.S){
                    b = false;
                }else{
                    b = true;
                    break;
                }
            }
            if(!b) break;
        }
        if(b){
            cout << x;
            f=false;
        }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
        if(!f) break;
    }
    if(f) cout << "impossible";
    return 0;
}