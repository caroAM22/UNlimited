#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
    int n; cin >> n;
    stack<int> s1, s2;
    ll sum1=0; ll sum2=0;
    ll suma=(n*(n+1))/2;
    if(suma%2==0){
        for(int i=n;i>0;i--){
            if(sum1<=sum2){
                s1.push(i);
                sum1+=i;
            }else if(sum1>sum2){
                s2.push(i);
                sum2+=i;
            }
        }
        if(sum1==sum2){
            cout << "YES\n";
            int t1=s1.size();
            cout << t1 << "\n";
            for(int i=0; i<t1; ++i){
                cout << s1.top() << " "; 
                s1.pop();
            }
            int t2=s2.size();
            cout << "\n"<<t2<< "\n";
            for(int i=0; i<t2; ++i){
                cout << s2.top() << " "; 
                s2.pop();
            }
        }else{
            cout << "NO";
        }
    }else{
        cout << "NO";
    }
    return 0;
}