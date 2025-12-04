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

int t,n,h,ui,ti,li,tp,x,y, lp, up; 

bool solve(vector<vi>& v){
    forx(i,n){
        if(i==0){
            ti=0;
            li=h;
            ui=h;
        }
        tp=v[i][0]-ti;
        lp=v[i][1];
        up=v[i][2];
        li-=tp;
        ui+=tp;
        
        li = max(max(1,li), lp);
        ui = min(ui, up);
        if(li > ui) return false;
        ti=tp+ti;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr); 
    cin >> t;
    while(t--){
        cin >> n >> h;
        vector<vi> v(n,vi(3));
        forx(i,n){
            cin >> v[i][0] >> v[i][1] >> v[i][2];
        }
        if(solve(v)) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}