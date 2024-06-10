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
    int n, num; cin >> n;
    map<int, int> m;
    int cont=0;
    int mayor=0;
    int j=0;
    forx(i,n){
        cin >> num;
        if(m.count(num)){
            if(m[num]>=j){
                mayor=max(mayor,cont);
                cont=i-m[num]-1;
                j=m[num]+1;
            }
        }
        m[num]=i;
        cont++;
    }
    cout << max(mayor,cont);
    return 0;
}