#include <bits/stdc++.h>
using namespace std;

bool sortPair(pair<int,string>& a, pair<int, string>& b) {
    if (a.first != b.first) {
        return a.first > b.first;
    }
    return a.second < b.second;
}

int main() {
	int n;
    cin >> n;
    vector<pair<int, string>> ve;
    string duendes;
    int regalos;

    for(int i=0;i<n;i++){
        cin >> duendes;
        cin >> regalos;
        ve.push_back({regalos, duendes});
    }
	sort(ve.begin(),ve.end(),sortPair);

    for(int i=0;i<n;i++){
        cout << ve[i].second << "\n";
    }
	return 0;
}
