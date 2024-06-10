#include "Extremos.h"
#include <bits/stdc++.h>
using namespace std;

void Jugar(int n, int M[]) {
  int x;
  if(M[0]==n) x=-1;
  else x=1;
  for(int i=0; i<n/2; i++){
    cout<<"Seleccionar(" << x << ") --> " << Seleccionar(x)<<flush;
  }
}