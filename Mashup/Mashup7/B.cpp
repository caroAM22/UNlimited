#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int h, m, s, t1, t2;
    cin >> h >> m >> s >> t1 >> t2;
    m=m%12;
    s=s%12;
    if((h>t1 && h<t2) || (m>t1 && m<t2) || (s>t1 && s<t2)){
        cout << "NO";
    }else if((h>t2 && h<t1) || (m>t2 && m<t1) || (s>t2 && s<t1)){
        cout << "NO";
    }else{
        cout << "YES";
    }
    return 0;
}