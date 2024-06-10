#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int r=19;
    int x=6;
    int v = static_cast<int>(r/x);
    if(r%x!=0){
        v++;
    }
    cout << v;
    return 0;
}
