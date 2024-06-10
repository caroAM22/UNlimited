#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n; cin >> n;
	ll sum=0; ll a;
    ll ans=-1e9-7;
    for(int i=0; i<n; ++i){
        cin >> a;
        sum=sum+a;
        ans=max(ans,sum);
        if(sum<0) sum=0;
    }
	cout << ans;
}