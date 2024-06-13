//Prefix Xor
vl v(n+1);
cin >> v[1];
for(int i=2; i<=n; i++){
    cin >> v[i];
    v[i]=v[i]^v[i-1];
}
forx(i,q){
    cin >> a >> b; 
    cout << (v[a-1]^v[b]) << "\n";
}

//minium range query
vi v(n+1);
for(int i=1; i<=n; i++){
    cin >> v[i];
}
vector<vi> st(n+1, vi(log2(n)+1));
for(int i=1; i<=n; i++){
    st[i][0] = i;
}
for(int j=1; (1<<j)<=n; j++){
    for(int i=1; i+(1<<j)-1<=n; i++){
        if(v[st[i][j-1]] < v[st[i+(1<<(j-1))][j-1]]){
            st[i][j] = st[i][j-1];
        }else{
            st[i][j] = st[i+(1<<(j-1))][j-1];
        }
    }
}
for(int i=0; i<q; i++){
    cin >> a >> b;
    int j = log2(b-a+1);
    cout << min(v[st[a][j]], v[st[b-(1<<j)+1][j]]) << "\n";
}

//Prefix sum 
vl v(n+1); v[0]=0;
for(int i=1; i<=n; i++){
    cin >> v[i];
    v[i]+=v[i-1];
}
forx(i,q){
    cin >> a >> b; 
    cout << v[b]-v[a-1] << "\n";
}

//prefix sum 2d
int n, k, x1, x2, y1, y2;
cin >> n >> k;
int f[n+1][n+1]={};
int prefix; 
char s;
for(int i=1; i<n+1;++i){
    for(int j=1; j<n+1;++j){
        cin >> s;
        if(s=='*') f[i][j]=1;
    }
}
for(int i=1; i<n+1;++i){
    for(int j=1; j<n+1;++j){
        f[i][j]=f[i][j]+f[i-1][j]+f[i][j-1]-f[i-1][j-1];
    }
}
for(int i=0; i<k;++i){
    cin >> x1 >> y1 >> x2 >> y2;
    prefix = f[x2][y2]-f[x1-1][y2]-f[x2][y1-1]+f[x1-1][y1-1];
    cout << prefix << "\n";
}
