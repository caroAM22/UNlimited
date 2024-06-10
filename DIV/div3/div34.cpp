#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, num;
    cin >> n;
    for(int i=0;i<n;++i){
        cin >> k;
        vector<pair<int, int>> u;
        vector<pair<int, int>> d;
        vector<pair<int, int>> t;
        priority_queue<pair<int, int>> max_heap1;
        for(int j=0;j<k;++j){
            cin >> num;
            max_heap1.push({num, j});
        }
        priority_queue<pair<int, int>> max_heap2;
        for(int j=0;j<k;++j){
            cin >> num;
            max_heap2.push({num, j});
        }
        priority_queue<pair<int, int>> max_heap3;
        for(int j=0;j<k;++j){
            cin >> num;
            max_heap3.push({num, j});
        }
        for(int j=0; j<3; ++j){
            u.push_back(max_heap1.top()); max_heap1.pop();
            d.push_back(max_heap2.top()); max_heap2.pop();
            t.push_back(max_heap3.top()); max_heap3.pop();
        }
        int mayor=0;
        for(int j=0; j<3; ++j){
           int uf=u[j].first; 
           int us=u[j].second; 
           for(int k=0; k<3; ++k){
              int df=d[k].first; 
              int ds=d[k].second; 
              for(int l=0; l<3; ++l){
                int tf=t[l].first; 
                int ts=t[l].second; 
                if(us!=ds && us!=ts && ts!=ds){
                    int suma=uf+df+tf;
                    mayor=max(mayor,suma);
                }
              }
           }
        }
        cout << mayor << "\n";
    }
    return 0;
}
