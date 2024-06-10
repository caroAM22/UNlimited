#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, num;
    cin >> n;
    vector<int> arr;
    cin >> num;
    arr.push_back(num);
    int k=1;
    for(int i=0; i<n-1; ++i){
        cin >> num;
        int upper = static_cast<int>(upper_bound(arr.begin(), arr.end(), num) - arr.begin());
        if (upper==k){
            k++;
            arr.push_back(num);
        }else{
            arr[upper]=num;
        }
    }
    cout << k;
    return 0;
}