#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
#define S second
#define F first

int main(){
    freopen("square.in", "r", stdin);
	freopen("square.out", "w", stdout);
    ii bla, blb, tra, trb;
    cin >> bla.F >> bla.S;
    cin >> tra.F >> tra.S;
    cin >> blb.F >> blb.S;
    cin >> trb.F >> trb.S;
    int width=max(tra.F, trb.F)-min(bla.F, blb.F);
    int length=max(tra.S, trb.S)-min(bla.S, blb.S);
    cout << max(width,length)*max(width,length);
    return 0;
}