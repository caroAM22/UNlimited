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
    int n; cin >> n;
    string s, f;
    vi meses={31,28,31,30,31,30,31,31,30,31,30,31};
    vi v;
    forx(i,n){
        cin >> s >> f;
        int dia=stoi(f.substr(3,5));
        int mes=stoi(f.substr(0,2));
        forx(j,mes-1){
            dia+=meses[j];
        }
        v.PB(dia);
    }
    sort(all(v));
    int mayor=0;
    int dias=0;
    forx(j,sz(v)-1){
        int sp=v[j+1]-v[j];
        if(sp>=mayor && dias<301){
            dias=v[j+1]-1;
            mayor=sp;
        }
    }
    if((365-v[sz(v)-1])+(v[0]-0)>=mayor && dias<301){
        dias=v[0]-1;
    }
    int j=0;
    while(dias>meses[j]){
        dias-=meses[j];
        j++;
    }
    if(j+1<10 && dias<10){
        cout << "0" << j+1 << "-0" << dias;
    }else if(j+1<10){
        cout << "0" << j+1 << "-" << dias;
    }else if(dias<10){
        cout << j+1 << "-0" << dias;
    } else cout << j+1 << "-" << dias;
    return 0;
}