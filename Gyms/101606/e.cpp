#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<pair<int,int>> department(n);
    for(int i=0; i<n; i++){
        cin >> department[i].first;
        department[i].second = i;
    }
    sort(department.begin(), department.end());

    vector<pair<int,pair<int,int>>> building(m);
    for(int i=0; i<m; i++){
        cin >> building[i].second.first;
    }
    for(int i=0; i<m; i++){
        cin >> building[i].first;
        building[i].second.second = i+1;
    }
    sort(building.begin(), building.end());

    vector<int> assignment(n, -1);
    int j = 0;
    for(int i=0; i<n; i++){
        while(j < m && building[j].second.first < department[i].first){
            j++;
        }
        if(j == m){
            cout << "impossible\n";
            return 0;
        }
        assignment[department[i].second] = building[j].second.second;
        j++;
    }

    for(int i=0; i<n; i++){
        cout << assignment[i] << " ";
    }
    cout << "\n";

    return 0;
}