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
    int t, n, m, c, cont; cin >> t;
    string a, b;
    for(int i=0; i<t; i++){
        cin >> n >> m;
        c=0; cont=0;
        cin >> a >> b;
        bool f=false;
        for(char e: a){
            for(int j=c;j<m;j++){
                if(b[j]==e){
                   cont++; 
                   c=j+1;
                   break;
                }else if(j==m-1){
                    f=true;
                }
            }
            if(f) break;
        }
        cout << cont << "\n";
    }
    return 0;
}