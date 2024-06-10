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
    map<char, int> ma={{'A',1},{'E',1}, {'I',1}, {'L',1}, {'N',1}, {'O',1}, {'R',1}, {'S',1}, {'T',1}, {'U',1},{'D',2},{'G',2}, {'B',3}, {'C',3}, {'M',3} ,{'P',3}, {'F',4}, {'H',4}, {'V',4},{'W',4}, {'Y',4}, {'K',5},{'J',8}, {'X',8},{'Q',10}, {'Z',10}};
    int t; cin >> t;
    string s;
    int puntos=0;
    for(int i=0; i<t; i++){
        cin >> s;
        for(char &c: s){
            puntos+=ma[c];
        }
    }
    cout << puntos;
    return 0;
}