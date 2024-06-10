#include <bits/stdc++.h>
using namespace std;
#define print(arr) for(auto& x:arr)cout<<x<<"\n";
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
    int t; cin >> t;
    vector<string> nombre;
    map<string,int> n;
    vector<string> apellido;
     map<string,int> ap;
    vector<string> ciudad;
     map<string,int> ci;
    vector<string> animal;
     map<string,int> an;
    vector<string> fruta;
     map<string,int> f;
    vi puntos(t,0);
    string s;
    string s1;
    for(int i=0; i<t; i++){
        cin >> s;
        s1="";
        int j=0;
        for(char &c: s){
            if(c==','){
                if(j==0){
                    nombre.PB(s1);
                    n[s1]++;
                }
                else if(j==1){
                    apellido.PB(s1);
                    ap[s1]++;
                }
                else if(j==2){
                    ciudad.PB(s1);
                     ci[s1]++;
                }
                else if(j==3){
                    animal.PB(s1);
                    an[s1]++;
                }
                s1="";
                j++;
            }else{
                s1+=c;
            }
        }
        fruta.PB(s1);
        f[s1]++;
    }
    for(int i=0; i<t; i++){
        if(nombre[i]=="") continue;
        else if(sz(n)==2 && n.count("") && n[nombre[i]]==1) puntos[i]+=20;
        else if(n[nombre[i]]>1){
            puntos[i]+=5;
        }else{
            puntos[i]+=10;
        }
    }
    for(int i=0; i<t; i++){
        if(apellido[i]=="") continue;
        else if(sz(ap)==2 && ap.count("") && ap[apellido[i]]==1) puntos[i]+=20;
        else if(ap[apellido[i]]>1){
            puntos[i]+=5;
        }else{
            puntos[i]+=10;
        }
    }
    for(int i=0; i<t; i++){
        if(ciudad[i]=="") continue;
        else if(sz(ci)==2 && ci.count("") && ci[ciudad[i]]==1) puntos[i]+=20;
        else if(ci[ciudad[i]]>1){
            puntos[i]+=5;
        }else{
            puntos[i]+=10;
        }
    }
    for(int i=0; i<t; i++){
        if(animal[i]=="") continue;
        else if(sz(an)==2 && an.count("") && an[animal[i]]==1) puntos[i]+=20;
        else if(an[animal[i]]>1){
            puntos[i]+=5;
        }else{
            puntos[i]+=10;
        }
    }
    for(int i=0; i<t; i++){
        if(fruta[i]=="") continue;
        else if(sz(f)==2 && f.count("") && f[fruta[i]]==1) puntos[i]+=20;
        else if(f[fruta[i]]>1){
            puntos[i]+=5;
        }else{
            puntos[i]+=10;
        }
    }
    print(puntos);
    return 0;
}