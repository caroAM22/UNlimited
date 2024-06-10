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
typedef vector<tuple<ll, ll, double, double>> vt; 
typedef vector<ii> vii;
const int MOD = 1e9+7;

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n; cin >> n;
    string s;
    for(int i=0; i<n; ++i){
        cin >> s;
        bool b=true;
        int cont=1; 
        int z=0; int o=0;
        for(auto &x: s){
            if(b && (x=='1' && z!=0)){
                z=0;
                o++;
                b=false;
            }else if((x=='0' && o==0)){
                z++;
            }else if((x=='1' && z==0)){
                o++;
            }
            else{
                cont++;
                z=0; o=0;
                if(x=='1') o++;
                else z++;
            }
        }
        cout << cont << "\n";
    }
    return 0;
}