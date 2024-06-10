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
    int t, n, m; cin >> t;
    string c;
    forx(i,t){
        cin >> n >> m >> c;
        map<char,int> s={{'A',0},{'B',0},{'C',0},{'D',0},{'E',0},{'F',0},{'G',0}};
        int cont=0;
        for(auto x: c){
            s[x]++;
        }
        for(auto x: s){
            if(m-x.S<0) continue;
            else cont+=m-x.S;
        }
        cout << cont << "\n";
    }
    return 0;
}
