#include <bits/stdc++.h>
using namespace std;
#define print(arr) for(auto& x:arr)cout<<x<<" ";cout<<"\n"
#define all(x) x.begin(), x.end()
#define sz(x) ((int) x.size())
#define PB push_back
#define S second
#define F first
#define forx(i,n) for(int i=0; i<(int)n; ++i)
typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int MOD = 1e9+7;

vector<ii> operation;

void selectionSort(vector<char> &arr) {
    int n=sz(arr);
    for (int i=0; i<n-1; ++i) {
        int minIndex=i;
        for (int j=i+1; j<n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if(minIndex==i)continue;
        operation.PB({minIndex+1, i+1});
        swap(arr[minIndex], arr[i]);
    }
}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    string c; cin >> c;
    vector<char> arr(all(c));
    selectionSort(arr);
    for(int i=sz(operation)-1; i>=0; --i){
        cout << operation[i].F << " " << operation[i].S;
        if(i!=0) cout << "\n";
    }
    return 0;
}