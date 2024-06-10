#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int n, num, ant;
    cin >> n;
    vector<int> arr;
    cin >> ant;
    cout << ant << " ";
    for(int i=0; i<n-1; ++i){
        cin >> num;
        if(num > ant){
            cout << num << " ";
            ant = num;
        }else{
            arr.push_back(num);
        }
    }
    cout << "\n";
    int i=0;
    ant=0;
    while(!arr.empty()){
        if(i==arr.size()){
            i=0;
            ant=0;
            cout << "\n";
        } else if(arr[i] > ant){
            cout << arr[i] << " ";
            ant =  arr[i];
            arr.erase(arr.begin()+i);
        }else {
            i++;
        }
    }
    return 0;
}