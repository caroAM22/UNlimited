#include <bits/stdc++.h>
using namespace std;
#define print(arr) for(auto& x:arr)cout<<x<<" ";cout<<"\n"

int main(){
    int n, sum, prom, num; cin >> n;
    vector<int> vec(n);
    for(int i=0;i<n;i++) cin >> vec[i];
    int total=0;
    for(int i=0; i<n; i++){
        set<int> s;
        s.insert(vec[i]);
        num=1;
        sum=vec[i];
        for(int j=i+1; j<n; j++){
            s.insert(vec[j]);
            sum+=vec[j];
            num++;
            if (sum % num == 0) {
                prom=sum/num;
                if(s.count(prom)>0) total++;
            }
        }
    }
    cout << total+n;
    return 0;
}