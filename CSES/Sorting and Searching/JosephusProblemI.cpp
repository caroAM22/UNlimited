#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, e; cin >> n;
    deque<int> d;
    for(int i=1; i<=n; ++i) d.push_back(i); 
    int i=0;
    while(!d.empty()){
        e=d.front();
        if(i%2==0){
            d.push_back(e);
        }else{
            cout << e << " ";
        }
        d.pop_front();
        i++;
    }
    return 0;
}