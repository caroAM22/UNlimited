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
const int INF = 1e9+7;

int dist(vector<ii> s){
    int d=s[0].F+s[0].S;
    for(int i=1; i<sz(s); i++){
        d+=abs(s[i].F-s[i-1].F)+abs(s[i].S-s[i-1].S);
    }
    return d;
}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr); 
    int n; cin >> n;
    vector<vector<char>> mapa(n, vector<char>(n));
    vector<ii> s;
    forx(i,n){
        forx(j,n){
            cin >> mapa[i][j];
            if(mapa[i][j]=='A'){
               s.PB({i,j});
            }
        }
    }
    sort(all(s));
    if(sz(s)==1 && s[0].F==0 && s[0].S==0) cout << 0;
    else{
        int minimo=INF;
        do {
            int d1=dist(s);
            if(d1<minimo){
                minimo=d1;
            }
        } while(next_permutation(all(s)));
        cout << minimo;
    }
    return 0;
}