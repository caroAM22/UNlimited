#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define S second
#define F first
const int dirx [4] = {0,1,0,-1};
const int diry [4] = {1,0,-1,0};
vector<vector<char>> mapa;

bool floodfill(int x1, int y1){
    //HORIZONTAL
    int cont=0;
    int s=0;
    bool b=true;
    for(int i=1; i<4; ++i){
        int x2=x1;
        int y2=y1+i;
        if((x2<0 || x2 >= 6 || y2<0 || y2 >= 7) 
            || (mapa[x2][y2]=='A')) break;
        if(mapa[x2][y2]=='R'){
            cont++;
            if(b) s++;
        }
        if(mapa[x2][y2]=='.')b=false;
    }
    if(cont==3) return true;

    cont=0;
    b=true;
    for(int i=1; i<4; ++i){
        int x2=x1;
        int y2=y1-i;
        if((x2<0 || x2 >= 6 || y2<0 || y2 >= 7) 
            || (mapa[x2][y2]=='A')) break;
         if(mapa[x2][y2]=='R'){
            cont++;
            if(b) s++;
        }
        if(mapa[x2][y2]=='.')b=false;
    }
    if(cont==3 || s==3) return true;
    
    //VERTICAL
    cont=0;
    for(int i=1; i<4; ++i){
        int x2=x1+i;
        int y2=y1;
        if((x2<0 || x2 >= 6 || y2<0 || y2 >= 7) 
            || (mapa[x2][y2]=='A')) break;
        if(mapa[x2][y2]=='R')cont++;
    }
    if(cont==3) return true;
   
    //DIAGONAL
    cont=0;
    s=0;
    b=true;
    for(int i=1; i<4; ++i){
        int x2=x1+i;
        int y2=y1-i;
        if((x2<0 || x2 >= 6 || y2<0 || y2 >= 7) 
            || (mapa[x2][y2]=='A')) break;
        if(mapa[x2][y2]=='R'){
            cont++;
            if(b) s++;
        }
        if(mapa[x2][y2]=='.')b=false;
    }
    if(cont==3) return true;
    
    cont=0;
    for(int i=1; i<4; ++i){
        int x2=x1-i;
        int y2=y1+i;
        if((x2<0 || x2 >= 6 || y2<0 || y2 >= 7) 
            || (mapa[x2][y2]=='A')) break;
        if(mapa[x2][y2]=='R'){
            cont++;
            if(b) s++;
        }
        if(mapa[x2][y2]=='.')b=false;
    }
    if(cont==3 || s==3) return true;
    //diagonal

    cont=0;
    s=0;
    b=true;
    for(int i=1; i<4; ++i){
        int x2=x1+i;
        int y2=y1+i;
        if((x2<0 || x2 >= 6 || y2<0 || y2 >= 7) 
            || (mapa[x2][y2]=='A')) break;
        if(mapa[x2][y2]=='R'){
            cont++;
            if(b) s++;
        }
        if(mapa[x2][y2]=='.')b=false;
    }
    if(cont==3) return true;

    cont=0;
    for(int i=1; i<4; ++i){
        int x2=x1-i;
        int y2=y1-i;
        if((x2<0 || x2 >= 6 || y2<0 || y2 >= 7) 
            || (mapa[x2][y2]=='A')) break;
        if(mapa[x2][y2]=='R'){
            cont++;
            if(b) s++;
        }
        if(mapa[x2][y2]=='.')b=false;
    }
    if(cont==3 || s==3) return true;
    return false;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr); 
    char c;
    for(int i=0;i<6; ++i){
        vector<char> v(7);
        for(int j=0; j<7; ++j){
            cin >> v[j];
        }
        mapa.PB(v);
    }
    bool f=false;
    for(int i=0;i<7; ++i){
        for(int j=0; j<6; ++j){
            if(mapa[j][i]!='.' && j==0){
                break;
            }
            else if(mapa[j][i]!='.'){
                f=floodfill(j-1,i);
                break;
            }else if(j==5){
                f=floodfill(j,i);
            }
        }
        if(f) break;
    }
    if(f) cout << "Ana gana!";
    else cout << "Todavia no se acaba";
    return 0;
}