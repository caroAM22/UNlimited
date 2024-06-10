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
    cout<<setprecision(6)<<fixed;
    int n,num; cin >> n;
    map<int,float> m={{1,1.0},{2,0.5},{0,2.0},{4,0.25},{8,0.125},{16,0.0625}};
    float cont=0.0;
    forx(i,n){
        cin >> num;
        cont+=m[num];
    }
    cout << cont;
    return 0;
}