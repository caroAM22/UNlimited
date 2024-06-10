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
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    int n, m, c, a, b; cin >> n >> m >> c;
    vii prioridades;
    vi estudiantes;
    map<int,set<int>> escuelas;
    forx(i, m) {
        escuelas[i + 1] = set<int>(); 
    }
    forx(i,n){
        cin >> a >> b;
        prioridades.PB({a,b});
        estudiantes.PB(0);
    }
    bool f=true;
    while(f){
        f=false;
        for(int i=1; i<=m; i++){
            // cout << i << "\n";
            for(int j=n-1; j>=0; j--){
                // cout << j << "\n";
                // cout << sz(escuelas[i]) << " " << estudiantes[j] << "\n";
                if(sz(escuelas[i])<c && estudiantes[j]==0 && (prioridades[j].F==i || prioridades[j].S==i)){
                    escuelas[i].insert(j);
                    estudiantes[j]=i;
                    f=true;
                }else if(sz(escuelas[i])<c && estudiantes[j]==prioridades[j].S && prioridades[j].F==i){
                    escuelas[i].insert(j);
                    escuelas[prioridades[j].S].erase(j);
                    estudiantes[j]=i;
                    f=true;
                }else if(sz(escuelas[i])==c && estudiantes[j]==0 && (prioridades[j].F==i || prioridades[j].S==i) && *prev(escuelas[i].end())>j){
                    estudiantes[*prev(escuelas[i].end())]=0;
                    escuelas[i].erase(prev(escuelas[i].end()));
                    escuelas[i].insert(j);
                    estudiantes[j]=i;
                    f=true;
                }else if(sz(escuelas[i])==c && estudiantes[j]==prioridades[j].S && prioridades[j].F==i && *prev(escuelas[i].end())>j){
                    estudiantes[*prev(escuelas[i].end())]=0;
                    escuelas[i].erase(prev(escuelas[i].end()));
                    escuelas[i].insert(j);
                    escuelas[estudiantes[j]].erase(j);
                    estudiantes[j]=i;
                    f=true;
                }
            }
            // for(auto &y: escuelas[i]){
            //     cout << y << " ";
            // }
            cout << "\n";
        }
    }
    int p=0; int se=0;
    forx(i,n){
        if(estudiantes[i]==prioridades[i].F) p++;
        else if(estudiantes[i]==prioridades[i].S) se++;
    }

    cout << p << " " << se << "\n";
    // for(auto &x: escuelas){
    //     cout << x.F << "\n";
    //     for(auto &y: x.S){
    //         cout << y << " ";
    //     }
    //     cout << "\n";
    // }
    // forx(i,n){
    //     cout << estudiantes[i];
    // }
    return 0;
}