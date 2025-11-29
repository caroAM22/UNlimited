#include <bits/stdc++.h>
using namespace std;
 
#define PB push_back
#define F first
#define S second 
#define sz(x) ((int) x.size())
vector<vector<char>> mapa;
vector<vector<bool>> visited;
vector<vector<int>> distancias;
vector<vector<int>> distanciasH;
vector<vector<char>> path;
const int dirx [4] = {1,0,-1,0};
const int diry [4] = {0,-1,0,1};
int n, m;
 
void floodFillMonster(int x1, int y1){
    queue<pair<int, int>> q;
    q.push({x1,y1});
    visited[x1][y1]=true;
    distancias[x1][y1]=0;
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
            visited[x2][y2]=true;
            if(mapa[x2][y2]=='M'){
                distancias[x2][y2]=0;
                q.push({x2,y2});
            }else{
                if(distancias[x2][y2]==-1){
                    distancias[x2][y2]=distancias[x1][y1]+1;
                    q.push({x2,y2});
                }else{
                    if(distancias[x2][y2]<=distancias[x1][y1]+1){
                        continue;
                    }else{
                        distancias[x2][y2]=distancias[x1][y1]+1;
                        q.push({x2,y2});
                    }
                }
            }
        }
    }
}
 
bool floodFill(int x1, int y1){
    queue<pair<int, int>> q;
    q.push({x1,y1});
    visited[x1][y1]=true;
    distanciasH[x1][y1]=0;
    vector<char> camino;
    while(!q.empty()){
        auto act=q.front(); q.pop();
        x1=act.F;
        y1=act.S;
        for(int i=0; i<4; ++i){
            int x2=x1+dirx[i];
            int y2=y1+diry[i];
            if(x2<0 || x2>=n || y2<0 || y2>=m){
                cout << "YES\n";
                cout << distanciasH[x1][y1] << "\n";
                while(path[x1][y1]!='#'){
                    camino.PB(path[x1][y1]);
                    if(path[x1][y1]=='R')y1--;
                    else if(path[x1][y1]=='D')x1--;
                    else if(path[x1][y1]=='L')y1++;
                    else if(path[x1][y1]=='U') x1++;
                }
                for(int j=sz(camino)-1; j>=0; --j) cout << camino[j];
                return false;
            }
            if(visited[x2][y2] || mapa[x2][y2]=='#' || mapa[x2][y2]=='M') continue;
            visited[x2][y2]=true;
            if((distancias[x2][y2]>distanciasH[x1][y1]+1) || (distancias[x2][y2]==-1)){
                distanciasH[x2][y2]=distanciasH[x1][y1]+1;
                q.push({x2,y2});
                if(i==0) path[x2][y2]='D';
                else if(i==1) path[x2][y2]='L';
                else if(i==2) path[x2][y2]='U';
                else path[x2][y2]='R';
            }
        }
    }
    return true;
}
 
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr); 
    cin >> n >> m;
    char car;
    distancias.assign(n, vector<int>(m,-1));
    for(int i=0; i<n; ++i){ 
        vector<char> c;
        for(int j=0; j<m; ++j){
            cin >> car;
            c.PB(car);
        }
        mapa.PB(c);
    }
    vector<vector<bool>> v(n, vector<bool>(m,false));
 
    for(int i=0; i<n; ++i){ 
        for(int j=0; j<m; ++j){
            if(mapa[i][j]=='M' && distancias[i][j]==-1){
                visited=v;
                floodFillMonster(i,j);
            }
        }
    }
    distanciasH.assign(n, vector<int>(m,0));
    visited=v;
    path.assign(n, vector<char>(m,'#'));
    bool f=true;
    for(int i=0; i<n; ++i){ 
        for(int j=0; j<m; ++j){
            if(mapa[i][j]=='A'){
                f=floodFill(i,j);
            }
        }
    }
    if(f) cout << "NO";
    return 0;
}