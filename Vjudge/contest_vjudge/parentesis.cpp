#include <bits/stdc++.h>
using namespace std;

#define forx(i,n) for(int i=0; i<(int)n; ++i)

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    cin >> n;
    string s;
    getline(cin, s);

    forx(i,n){
        getline(cin, s);
        stack<char> p;

        bool b=true;

        for(char c : s){
            if(c=='(' || c=='['){
                p.push(c);
            }else if(c!=' '){
                if (p.empty()) {
                    b = false;
                    break;
                }else if ((p.top() == '(' && c == ')') || (p.top() == '[' && c == ']')){
                    p.pop();
                }else{
                    b = false;
                    break;
                }
            }
        }
        if((b && p.empty())){
            cout << "Yes\n";
        } else{
            cout << "No\n";
        }
    }
    return 0;
}