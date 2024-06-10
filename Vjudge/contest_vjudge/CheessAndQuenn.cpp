#include <bits/stdc++.h>
using namespace std;

#define forx(i,n) for(int i=0; i<n; ++i)
using vc=vector<char>;
using vcc=vector<vc>;
using vi=vector<int>;

bool review(vcc tablero, int r, int c){
    forx(i,8){
        if(i!=c && tablero[r][i]=='Q'){
            return false;
        }
        if(i!=r && tablero[i][c]=='Q'){
            return false;
        }
    }
    int j=c; int i=r;
    while (i>0 && j>0){
        j--;
        i--;
        if(tablero[i][j]=='Q'){
            return false;
        }
    }
    j=c; i=r;
    while (i<7 && j<7){
        i++;
        j++;
        if(tablero[i][j]=='Q'){
            return false;
        }
    }
    j=c; i=r;
    while (i>0 && j<7){
        i--;
        j++;
        if(tablero[i][j]=='Q'){
            return false;
        }
    }
    j=c; i=r;
    while (i<7 && j>0){
        i++;
        j--;
        if(tablero[i][j]=='Q'){
            return false;
        }
    }
    return true;
}

bool valid(vi& vec, vcc tablero){
    forx(i, 8){
        if(tablero[vec[i]][i]=='*'){
            return false;
        }else{
            tablero[vec[i]][i]='Q';
        }
    }
    forx(k, 8){
        if(!review(tablero, vec[k], k))return false;
    }
    return true;
}

int main(){
    vcc tablero(8, vc(8));
    forx(i, 8){
        forx(j, 8){
            cin >> tablero[i][j];
        }
    }
    vi vec={0,1,2,3,4,5,6,7};
    int c=0;
    do{
        if(valid(vec, tablero)){
            c++;
        }
    }while(next_permutation(vec.begin(), vec.end()));
    cout << c;
    return 0;
}