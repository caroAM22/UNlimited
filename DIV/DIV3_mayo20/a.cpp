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
    //cout<<setprecision(20)<<fixed;
    int t, a, b; cin >> t;
    forx(i,t){
        cin >> a >> b;
        if(b==0){
            int c=(a/15);
            if(a%15>0) cout << c+1;
            else cout << c;
        }else{
            int p=(b/2)+(b%2);
            int e=(15*p)-(b*4);
            if(a<=e) cout << p;
            else{
                int c=a-e;
                int c1=p+(c/15);
                if(c%15>0) cout << c1+1;
                else cout << c1;
            }
        }
        cout << "\n";
    }
    return 0;
}