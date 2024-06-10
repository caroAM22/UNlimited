#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, e, k; cin >> n >> k;
    deque<int> d;
    for(int i=1; i<=n; ++i) d.push_back(i); 
    int i=0;
    while(!d.empty()){
        e=d.front();
        if(i!=k){
            d.push_back(e);
            i=0;
        }else{
            cout << e << " ";
        }
        d.pop_front();
        i++;
    }
    return 0;
}