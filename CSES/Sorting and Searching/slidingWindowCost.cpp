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
    int n, k, a; cin >> n >> k;
    multiset<int> s;
    vi v;
    forx(i,k){
        cin >> a; 
        v.PB(a);
        s.insert(a);
    }
    ll cost=0;
    int med=*next(s.begin(),k/2);
    for(auto &x: s){
        cost+=abs(x-med);
    }
    cout << cost;
    forx(i,n-k){
        cin >> a;
        s.insert(a);
        v.PB(a);
        s.erase(s.find(v[i]));
        int med2=*next(s.begin(),k/2);
        if(med==med2){
            cost=cost-abs(v[i]-med)+abs(a-med);
        }else{
            cost=0;
            for(auto &x: s){
                cost+=abs(x-med2);
            }
        }
        med=med2;
        cout << " " << cost;
    }
    return 0;
}