#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, q, num, x, y;
    cin >> n;
    for(int i=0; i<n;++i){
		cin >> q;
        int prefix[q/2+1]={};
        vector<int> prefix1;
        prefix1.push_back(0);
        int k=1;
        int k1=1;
        for(int j=1; j<q+1;++j){
            cin >> num;
            if (j%2!=0){
                prefix1.push_back(prefix1[k1-1]+num);
                k1++;
            }else{
                prefix[k]=prefix[k-1]+num;
                k++;
            }
        }
        int t = static_cast<int>(prefix1.size());
        int p=q*(q-1)/2;
        bool b=false;
        k=1, k1=1;
        int ka=1, ka1=1;
        int s=0;
        for(int j=0;j<p;++j){
            x=prefix1[k1]-prefix[ka1-1];
            y=prefix[k]-prefix[ka-1];
            cout << ka << " " << ka1 << " " << k << " " << k1 << "\n";
            if(x==y){
                b=true;
                break;
            }else if(j%2==0){
                if(k1==t){
                    if(s%2==0){
                        k1=ka1+1;
                    }else{
                        k1=ka1;
                        s++;
                    }
                    ka1++;
                }else{
                    k1++;
                }
            }else if(j%2!=0){
                if(k==q/2){
                    if(s%2!=0){
                        k=ka+1;
                    }else{
                        k=ka;
                        s++;
                    }
                    ka++;
                }else{
                    k++;
                }
            }
        }
        if(b){
            cout << "YES" << "\n";
        }else{
            cout << "NO" << "\n";
        }
        // for(int j=0; j<q/2+1;++j){
        //     cout << prefix[j] << " " << q/2+1 << "\n";
        // }

    }
    return 0;
}