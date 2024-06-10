#include <bits/stdc++.h>
using namespace std;

#define print(arr) for(auto& x:arr)cout<<x<<" ";cout<<"\n"
typedef long long int ll;
typedef vector<ll> vl;
#define S second
#define F first

ll inter_area(vl& s1, vl& s2) {
	return ((min(s1[2], s2[2]) - max(s1[0], s2[0])) *
	        (min(s1[3], s2[3]) - max(s1[1], s2[1])));
}

bool intersect(vl& s1, vl& s2) {
	if (s1[0] >= s2[2] || s1[2] <= s2[0] || s1[1] >= s2[3] ||
	    s1[3] <= s2[1]) {
		return false;
	}
    return true;
}

int main(){
    // freopen("billboard.in", "r", stdin);
	// freopen("billboard.out", "w", stdout);
    vl c1(4), c2(4);
    for(int i=0; i<4; i++){
        cin >> c1[i];
    }
    for(int i=0; i<4; i++){
        cin >> c2[i];
    }
    bool f=intersect(c1, c2);
    ll l=c1[3]-c1[1];
    ll w=c1[2]-c1[0];
    ll area= w * l;
    if(f){
        ll inter=inter_area(c1,c2);
        if(inter%w==0 || inter%l==0){
            area-=inter;
        }
    }
    cout << area;
    return 0;
}