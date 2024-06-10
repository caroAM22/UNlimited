#include <bits/stdc++.h>
using namespace std;

#define forx(i,n) for(int i=0; i<n; ++i)
#define print(arr) for(auto& x:arr)cout<<x<<" ";
using vs=vector<string>;
using m=map<string, vs>;

bool valid(m& c, vs& nombres){
    for (const auto& par : c) {
        auto iter = find(nombres.begin(), nombres.end(), par.first);
        int posicion = distance(nombres.begin(), iter);
        for (const string& cow : par.second) {
                if (posicion==0) {
                    if(nombres[1]!=cow){
                        return false;
                    }
                }else if(posicion==7){
                    if(nombres[6]!=cow){
                        return false;
                    }
                }else{
                    if(nombres[posicion-1]!=cow && nombres[posicion+1]!=cow){
                        return false;
                    }
                }
        }
    }
    return true;
}

int main(){
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);
    int n;
    m c;
    string line, c1, c2;
    cin >> n;
    forx(i, n){
        forx(j, 6){
            cin >> line;
            if(j==0){
                c1 = line;
            }else if(j==5){
                c2 = line;
            }
        }
        vs v;
        if(c.count(c1)>0){
            c[c1].push_back(c2);
        }else{
            v.push_back(c2);
            c.insert({c1, v});
        }
    }
    vs nombres = {"Beatrice","Belinda","Bella","Bessie","Betsy","Blue","Buttercup","Sue"};
    do{
        if(valid(c, nombres)){
            forx(i, 8){
                cout << nombres[i] << "\n";
            }
            break;
        }
    }while(next_permutation(nombres.begin(), nombres.end()));
    return 0;
}