#include <bits/stdc++.h>
using namespace std;

#define forx(i,n) for(int i=0; i<n; ++i)
using ll=long long int;
using vl=vector<ll>;
using vs=vector<string>;
using m=map<int, vs>;

void valid(m& dict, string& sub, int k, set<int>& flag){
    if(dict.count(k)){
        if(find(dict[k].begin(), dict[k].end(), sub)!=dict[k].end()){
            dict.erase(k);
        }else{
            dict[k].push_back(sub);
        }
    }else if(!flag.count(k)){
        vs v;
        v.push_back(sub);
        dict.insert({k, v});
        flag.insert(k);
    }
    return;
}

int main(){
    // freopen("whereami.in", "r", stdin);
    // freopen("whereami.out", "w", stdout);
    int n; cin >> n;
    string s, sub; cin >> s;
    m dict;
    set<int> flag;
    forx(i, n){
        for(int j=1; j<n; j++){
            sub = s.substr(i, j);
            valid(dict, sub, j, flag);
        }
    }
    cout << dict.begin()->first << "\n";
    return 0;
}