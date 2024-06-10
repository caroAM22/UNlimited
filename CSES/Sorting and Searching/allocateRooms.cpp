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


int main(){
    int n, a, b; cin >> n;
    priority_queue<ii> p;
    vector<ii> vi;
    multimap<ii,int> m; 
    for(int i=0; i<n; ++i){
        cin >> a >> b;
        vi.PB({a,b});
        m.insert({{a,b},0});
    }
    int cont=0;
    for(auto &x: m){
        if(p.empty()){
            cont++;
            x.S=cont;
            p.push({-(x.F.S),-cont});
        }else{
            ii y=p.top();
            if((-y.F)<x.F.F){
                p.pop();
                x.S=-y.S;
                p.push({-x.F.S,y.S});
            }else{
                cont++;
                x.S=cont;
                p.push({-(x.F.S),-cont});
            }
        }
    }
    cout << cont << "\n";
    for(int i=0; i<n; ++i){
        auto it=m.find(vi[i]);
        cout << it->second << " ";
        m.erase(it);
    }
    return 0;
}