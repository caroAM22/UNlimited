#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
using vl = vector<ll>;

vl subsets(vl a){
    vl res;
    for (int i=0; i<(1<<a.size()); ++i){  
        ll sum=0;
        for (int j=0; j<a.size(); ++j){
            if (i & (1<<j)) sum+=a[j];
        }
        res.push_back(sum);
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    ll x;
    ll ans =0;
    cin >> n >> x;
    vl a1(n/2);
    vl a2(n-n/2);

    for(int i=0; i<n; i++){
        if (i<n/2) cin >> a1[i];
        else cin >> a2[i-n/2];
    }
   
    vl a3=subsets(a1);
    vl a4=subsets(a2);

    sort(a3.begin(), a3.end()); 
    sort(a4.begin(), a4.end());

    for(ll &sum1 : a3){
        ll sum2 = x - sum1;
        auto low = lower_bound(a4.begin(), a4.end(), sum2);
        auto high = upper_bound(a4.begin(), a4.end(), sum2);
        ans += high - low;
    }
    
    cout << ans;

    return 0;
}