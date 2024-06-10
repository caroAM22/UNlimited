#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define F first
#define S second 
#define sz(x) ((int) x.size())
vector<vector<bool>> visited;
vector<vector<int>> distancias;
vector<vector<char>> mapa;
vector<vector<char>> path;
const int dirx [4] = {0,1,0,-1};
const int diry [4] = {1,0,-1,0};
int n, m; 

bool floodfill(int x1, int y1){
    queue<pair<int, int>> q;
    q.push({x1,y1});
    visited[x1][y1] = true;
    distancias[x1][y1]=0;
    vector<char> camino;
    while(!q.empty()){
        auto act=q.front(); q.pop();
        x1=act.F;
        y1=act.S;
        for(int i=0; i<4; ++i){
            int x2=x1+dirx[i];
            int y2=y1+diry[i];
            if((x2<0 || x2>=n || y2<0 || y2>=m)
               || visited[x2][y2] 
               || mapa[x2][y2]=='#') continue;
           if(mapa[x2][y2]=='B'){
                cout << "YES\n";
                cout << distancias[x1][y1]+1 << "\n";
                while(path[x1][y1]!='#'){
                    camino.PB(path[x1][y1]);
                    if(path[x1][y1]=='R')y1--;
                    else if(path[x1][y1]=='D')x1--;
                    else if(path[x1][y1]=='L')y1++;
                    else if(path[x1][y1]=='U') x1++;
                }
                for(int j=sz(camino)-1; j>=0; --j) cout << camino[j];
                if(i==0) cout << 'R';
                else if(i==1) cout <<'D';
                else if(i==2) cout <<'L';
                else cout <<'U';
                return false;
            }
            if(distancias[x2][y2]==-1){
                distancias[x2][y2]=distancias[x1][y1]+1;
                q.push({x2,y2});
                if(i==0) path[x2][y2]='R';
                else if(i==1) path[x2][y2]='D';
                else if(i==2) path[x2][y2]='L';
                else path[x2][y2]='U';
            }
            visited[x2][y2]=true;
            q.push({x2,y2});
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr); 
    cin >> n >> m;
    visited.assign(n, vector<bool>(m, false));
    distancias.assign(n, vector<int>(m, -1));
    path.assign(n, vector<char>(m,'#'));
    char c;
    for(int i=0;i<n; ++i){
        vector<char> v(m);
        for(int j=0; j<m; ++j){
            cin >> v[j];
        }
        mapa.PB(v);
    }
    bool f=true;
    for(int i=0;i<n; ++i){
        for(int j=0; j<m; ++j){
            if(mapa[i][j]=='A'){
               f=floodfill(i,j);
            }
        }
    }
    if(f) cout << "NO";
    return 0;
}