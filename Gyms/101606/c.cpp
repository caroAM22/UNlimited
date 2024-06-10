#include <bits/stdc++.h>
using namespace std;

#define print(arr) for(auto& x:arr)cout<<x<<" ";
#define forx(i,n) for(int i=0; i<(int)n; ++i)
#define sz(x) ((int) x.size())
#define PB push_back
#define F first
#define S second
typedef long long int ll;
typedef vector<ll> vl;
typedef pair<int, int> ii;
typedef pair<ll, int> pli;
typedef vector<pli> vli;
typedef vector<vector<ii>> vii;
const ll INF=1e18;

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n; cin >> n;
    map<string, int> m={{"red",1},{"yellow",2},{"green",3},{"brown",4},{"blue",5},{"pink",6},{"black",7}};
    multiset<int> s;
    forx(i,n){
        string x; cin >> x;
        s.insert(m[x]);
    }
    int cont=0;
    int i=0;
    bool f=true;
    while(!s.empty()){
        if(i%2==0){
            if(*prev(s.end())!=1 && s.count(1)){
                cont+=*prev(s.end());
                f=true;
            }else if(*prev(s.end())==1 && f){
                cont+=*prev(s.end());
                s.erase(prev(s.end()));
                f=false;
            }else if(*prev(s.end())==1){
                break;
            }
        }else{
            if(*s.begin()==1 && f){
                cont+=*s.begin();
                s.erase(s.begin());
                f=false;
            }else if(*s.begin()==1){
                break;
            }else{
                cont+=*s.begin();
                s.erase(s.begin());
                f=true;
            }
        }
        i++;
    }
    cout << cont;
    return 0;
}