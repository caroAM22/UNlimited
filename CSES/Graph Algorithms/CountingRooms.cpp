#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define S second
#define F first
const int dirx [4] = {0,1,0,-1};
const int diry [4] = {1,0,-1,0};
vector<vector<bool>> visited;
vector<vector<char>> mapa;
int n, m; 

void floodfill(int x1, int y1){
    queue<pair<int, int>> q;
    q.push({x1,y1});
    visited[x1][y1] = true;
    while(!q.empty()){
        auto act=q.front(); q.pop();
        x1=act.F;
        y1=act.S;
        for(int i=0; i<4; ++i){
            int x2=x1+dirx[i];
            int y2=y1+diry[i];
            if((x2<0 || x2 >= n || y2<0 || y2 >= m) 
               || (visited[x2][y2]) 
               || (mapa[x2][y2]=='#')) continue;
            visited[x2][y2]=true;
            q.push({x2,y2});
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr); 
    cin >> n >> m;
    visited.assign(n, vector<bool>(m, false));
    char c;
    for(int i=0;i<n; ++i){
        vector<char> v(m);
        for(int j=0; j<m; ++j){
            cin >> v[j];
        }
        mapa.PB(v);
    }
    int rooms=0;
    for(int i=0;i<n; ++i){
        for(int j=0; j<m; ++j){
            if(!visited[i][j] && mapa[i][j]!='#'){
               floodfill(i,j);
               rooms++;
            }
        }
    }
    cout << rooms;
    return 0;
}