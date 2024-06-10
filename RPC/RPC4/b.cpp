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
    std::multimap<int, string> m = {{-6,"f"},{-4, "a"},{-6, "b"}};
    m.insert({-1, "h"});
    for(const auto &p : m) {
        std::cout << "Clave: " << p.first << ", Valor: " << p.second << std::endl;
    }
    return 0;
}