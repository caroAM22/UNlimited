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

ll area(vl& s) {
	return (s[3]-s[1]) * (s[2]-s[0]);
}

int main(){
    // freopen("billboard.in", "r", stdin);
	// freopen("billboard.out", "w", stdout);
    vl c1(4), c2(4), c3(4);
    ll area1, area2;
    for(int i=0; i<4; i++){
        cin >> c1[i];
        c1[i]+=1000;
    }
    for(int i=0; i<4; i++){
        cin >> c2[i];
        c2[i]+=1000;
    }
    for(int i=0; i<4; i++){
        cin >> c3[i];
        c3[i]+=1000;
    }
    bool f=intersect(c1, c3);
    area1=area(c1);
    if(f) area1-=inter_area(c1,c3);

    f=intersect(c2, c3);
    area2=area(c2);
    if(f) area2-=inter_area(c2,c3);
    cout << area1+area2;
    return 0;
}