#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int h1, d1, t1; cin >> h1 >> d1 >> t1;
    int h2, d2, t2; cin >> h2 >> d2 >> t2;
    double i=0.5;
    double p1=0.5;
    double p2=0.5;
    while(h1>0 and h2>0){
        if(i==p1){
            h2-=d1;
            p1+=t1;
        }
        if(i==p2){
            h1-=d2;
            p2+=t2;
        }
        i+=0.5;
    } 
    if(h1<=0 and h2<=0){
        cout << "draw";
    }else if(h1<=0){
        cout << "player two";
    }else{
        cout << "player one";
    }
    return 0;
}