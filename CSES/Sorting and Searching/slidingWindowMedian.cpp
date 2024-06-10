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
    int n, k; cin >> n >> k;
    vi v(n);
    forx(i,n) cin >> v[i];
    int l=0; int r=k;
    multiset<int> low;
    multiset<int> high;
    vi v1= vi(v.begin(), v.begin() + k);
    sort(all(v1));
    forx(i,(k/2)){
        low.insert(v1[i]);
    }
    for(int i=k/2; i<k; i++){
        high.insert(v1[i]);
    }
    while(r<=n){
        int median;
        if(k%2==0){
            auto it = low.end(); it--;
            median = *it;
        }else{
            median = *high.begin();
        }
        cout << median << " ";
        if(k%2!=0){
            if(v[l]<median){
                auto it=low.find(v[l]);
                if(it!=low.end()) low.erase(it);
                if(r<n && v[r]<=median){
                    low.insert(v[r]);
                }else if(r<n){
                    high.insert(v[r]);
                    low.insert(*high.begin());
                    high.erase(high.begin());
                }
            }else{
                auto it=high.find(v[l]);
                if(it!=high.end()) high.erase(it);
                if(r<n && v[r]>=median){
                    high.insert(v[r]);
                }else if(r<n){
                    low.insert(v[r]);
                    high.insert(*prev(low.end()));
                    low.erase(prev(low.end()));
                }
            }
        }else{
            if(v[l]<=median){
                auto it=low.find(v[l]);
                if(it!=low.end()) low.erase(it);
                if(r<n && v[r]<=median){
                    low.insert(v[r]);
                }else if(r<n){
                    high.insert(v[r]);
                    low.insert(*high.begin());
                    high.erase(high.begin());
                }
            }else{
                auto it=high.find(v[l]);
                if(it!=high.end()) high.erase(it);
                if(r<n && v[r]>median){
                    high.insert(v[r]);
                }else if(r<n){
                    low.insert(v[r]);
                    high.insert(*prev(low.end()));
                    low.erase(prev(low.end()));
                }
            }
        }
        r++; l++;
    }
    return 0;
}