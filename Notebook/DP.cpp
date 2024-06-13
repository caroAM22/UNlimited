//Minimizing coins
int solve(int x){
    if (x < 0) return INF;
    if (x == 0) return 0;

    if (memo[x] != -1) return memo[x];
    
    int ans = INF;
    for (auto c : coin) {
        ans = min(ans, solve(x-c)+1);
    }

    memo[x] = ans;
    return ans;
}

//Frog iterativo
ll solve(int n){
    memo[1]=0;
    memo[0]=0;
    for(int i = 2; i < n; i++) {
        ll d2=abs(costo[i-2]-costo[i])+memo[i-1];
        ll d1=abs(costo[i-2]-costo[i-1])+memo[i-2];
        memo[i]=min(d1, d2);
    }
    return memo[n];
}

//Frog recursivo
ll solve(int n){
    if(n==1) return 0;
    
    if (memo[n] != -1) return memo[n];

    ll d2=INT_MAX;
    ll d1=abs(costo[n-1]-costo[n-2])+solve(n-1);
    if(n-3>=0) d2=abs(costo[n-1]-costo[n-3])+solve(n-2);
    ll ans=min(d1,d2);
    memo[n]=ans;

    return ans;
}

//Frog 2
ll solve(int n){
    if(n==0) return 0;
    
    if (memo[n] != -1) return memo[n];

    ll ans=INF;
    for(int i=1; i<=k; i++) {
        if (n-i >= 0) ans = min(ans, abs(costo[n]-costo[n-i])+solve(n-i));
    }
    memo[n]=ans;

    return ans;
}

//Knapsack iterativo
ll solve(int k, int n){
    forx(i,k+1) memo[i][0]=0;
    forx(i,n+1) memo[0][i]=0;

    for(int i = 1; i <= k; i++) {
        for(int j = 1; j <= n; j++) {
            ll d1 = 0;
            if(i >= peso[j-1]) {
                d1 = valor[j-1] + memo[i - peso[j-1]][j-1];
            }
            ll d2 = memo[i][j-1];
            memo[i][j] = max(d1, d2);
        }
    }
    return memo[k][n];
}

//Knapsack recursivo
ll solve(int k, int n){
    if(k==0) return 0;
    if(n==0) return 0;
    if (memo[k][n] != -1) return memo[k][n];
    ll d1=0;
    if(k>=peso[n-1]) d1=valor[n-1]+solve(k-peso[n-1],n-1);
    ll d2=solve(k,n-1);
    ll ans=max(d1,d2);
    memo[k][n]=ans;
    return ans;
}

//Knapsack 2
ll solve(int k, int n, ll valorTotal){
    memo[0][0] = 0;
    ll ans=0;
    for(int i=1; i<=n; ++i){
        for(int j=0; j<=valorTotal; ++j){
           if(memo[i-1][j]!=INF && memo[i][j]==INF) memo[i][j] = memo[i-1][j];
           if(memo[i][j]!=INF){
               memo[i][j+valor[i-1]]=min(memo[i-1][j+valor[i-1]], memo[i-1][j]+peso[i-1]);
           }
        }
    }
    forx(i,valorTotal+1){
        if(memo[n][i]<=k) ans = i;
    }
    return ans;
}

//lcs
string solve(int s1, int t1){
    forx(i,s1+1) memo[i][0] = 0;
    forx(i,t1+1) memo[0][i] = 0;

    for(int i=1; i<=s1; ++i){
        for(int j=1; j<=t1; ++j){
            memo[i][j]=max(memo[i-1][j], memo[i][j-1]);
            if(s.substr(i-1,1)==t.substr(j-1,1)){
                memo[i][j]=max(memo[i][j], memo[i-1][j-1]+1);
            }
        }
    }
    int i=s1, j=t1;
    string ans = "";
    while(i>0 && j>0){
        if(memo[i][j]>memo[i][j-1]){
            i--;
            ans+=t.substr(j-1,1);
            while(s.substr(i,1)!=t.substr(j-1,1)) i--;
        }
        j--;
    }
    reverse(all(ans));
    return ans;
}

//GridPath
ll solve(int x, int y){
    if (x < 1 || y < 1) return 0;
    if(mapa[x-1][y-1]=='#') return 0;
    if (x == 1 && y == 1) return 1;

    if (memo[x][y] != -1) return memo[x][y];
    
    ll d1=solve(x-1,y);
    ll d2=solve(x,y-1);

    memo[x][y] = (d1+d2)%MOD;
    return memo[x][y];
}

//DP mochila con niveles
int n,m; cin>>n>>m;
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