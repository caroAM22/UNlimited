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
    ll min_surface_area = 1e18;
    for(int a=1; a<int(pow(n,1/3))+2; a++){
        if(n%a==0){
            for(int b=a; int(sqrt(n/a))+1; b++){
                if((n/a)%b == 0){
                    int c = n/(a*b);
                    ll surface_area = 2 * (a * b + b * c + c * a);
                    min_surface_area = min(min_surface_area, surface_area);
                }
            }
        }
    }
    cout << min_surface_area; 
    return 0;
}