#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
using t = tuple<ll, ll, int>;
using vt = vector<t>;
using st = stack<t>;

#define forx(i,n) for(int i=0; i<(int)n; ++i)

bool comparadorAscendenteX(const t& a, const t& b) {
    return get<0>(a) < get<0>(b);
}

bool comparadorAscendenteY(const t& a, const t& b) {
    return get<1>(a) < get<1>(b);
}

bool comparadorDescendenteX(const t& a, const t& b) {
    return get<0>(a) > get<0>(b);
}

bool comparadorDescendenteY(const t& a, const t& b) {
    return get<1>(a) > get<1>(b);
}

bool valid(st& p, map<int, int>& dict,vt& l){
    forx(i,l.size()){
        if(dict[get<2>(l[i])]==0){
            dict[get<2>(l[i])]++;
            p.push(l[i]);
        }else{
            auto com=p.top();
            if(get<2>(com)==get<2>(l[i])){
                p.pop();
            }else{
                return false;
            }
        } 
    }
    return true;
}

void addToCorrectList(ll x, ll y, ll i, const ll& w, const ll& h, vt& l1, vt& l2, vt& l3, vt& l4) {
    if (y == h) {
        l1.push_back({x, y, i});
    } else if (x == w) {
        l2.push_back({x, y, i});
    } else if (y == 0) {
        l3.push_back({x, y, i});
    } else if (x == 0) {
        l4.push_back({x, y, i});
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    ll w, h, x1, y1, x2, y2;
    int n;
    cin >> w >> h >> n;
    st p;
    vt l1, l2,l3,l4;
    map<int, int> dict;

    forx(i,n){
        cin >> x1 >> y1 >> x2 >> y2;
        if((x1==w || x1==0 || y1==h || y1==0) && (x2==w || x2==0 || y2==h || y2==0)){
            addToCorrectList(x1, y1, i, w, h, l1, l2, l3, l4);
            addToCorrectList(x2, y2, i, w, h, l1, l2, l3, l4);
        }
    }
    sort(l1.begin(), l1.end(), comparadorAscendenteX);
    sort(l2.begin(), l2.end(), comparadorDescendenteY);
    sort(l3.begin(), l3.end(), comparadorDescendenteX);
    sort(l4.begin(), l4.end(), comparadorAscendenteY);
    
    if (valid(p, dict, l1) && valid(p, dict, l2) && valid(p, dict, l3) && valid(p, dict, l4)) {
    cout << "Y";
    } else {
        cout << "N";
    }
    return 0;
}

