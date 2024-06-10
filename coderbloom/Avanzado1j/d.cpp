#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	vector<vector<ll>> w(n, vector<ll>());
	vector<vector<ll>> v(n, vector<ll>());
	for(int i=0;i<n;++i){
		int n2;cin>>n2;
		w[i].assign(n2, 0);
		v[i].assign(n2, 0);
		for(int j=0;j<n2;++j)cin>>w[i][j];
		for(int j=0;j<n2;++j)cin>>v[i][j];
	}
	vector<vector<ll>> dp(n+1, vector<ll>(m+1,0));
	for(int i=0;i<n;++i){
		ll peso=0,valor=0;
		int n2=w[i].size();
		for(int k=0;k<n2;++k){
			peso+=w[i][k];
			valor+=v[i][k];
			for(int j=1;j<=m;++j){
				ll op1=0,op2=0,op3=dp[i+1][j],op4=0;
				op1=dp[i+1][j-1];
				op2=dp[i][j];
				if(j-peso>=0)op4=dp[i][j-peso]+valor;
				dp[i+1][j]=max({op1, op2, op3, op4});
			}
		}
	}
    cout << dp[n][m] << "\n";
	return 0;
}
