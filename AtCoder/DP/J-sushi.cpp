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

vi sushi;

vector<vector<vector<double>>> memo;

ll solve(int n, vi &sushi){
    memo[0][0][0]=0;
    int a=sushi[0], b=sushi[1], c=sushi[2];

    forx(i,n+1){
        forx(j,n+1){
            forx(k,n+1){
                int total = i+j+k;
                if (total == 0) continue;

                memo[i][j][k] = n/(double)total;
                if (i > 0) memo[i][j][k] += (i/(double)total) * memo[i-1][j][k];
                if (j > 0) memo[i][j][k] += (j/(double)total) * memo[i+1][j-1][k];
                if (k > 0) memo[i][j][k] += (k/(double)total) * memo[i][j+1][k-1];

                memo[i][j][k] += 1.0;
            }
        }
    }

    return memo[a][b][c];
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n; cin >> n;
    sushi.assign(n,0);
    memo.assign(n+1, vector<vector<double>>(n+1, vector<double>(n+1, 0.0)));
    forx(i,n) cin >> sushi[i];
    for(auto x: memo){
        for(auto y: x){
            print(y);
        }
    }
    cout << solve(n,sushi);
    for(auto x: memo){
        for(auto y: x){
            print(y);
        }
    }
    return 0;
}