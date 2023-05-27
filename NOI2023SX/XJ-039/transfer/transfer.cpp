#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,m;
int p[100005],x[100005],v[100005];
int ans = 0;
vector<int> ch[100005];
priority_queue<int,vector<int>> pr[100005];
int sid6[100005];
int dfs(int r){
    int sum = 0;
    if(!pr[r].empty())sum += pr[r].top(),pr[r].pop();
    for(int i = 0; i < ch[r].size(); i++){
        int next = ch[r][i];
        if(!pr[r].empty()) pr[next].push(pr[r].top()),pr[r].pop();
        sum += dfs(next);
    }
    return sum;
}
signed main(){
    freopen("transfer.in","r",stdin);
    freopen("transfer.out","w",stdout);
    int sid;
    scanf("%lld",&sid);
    scanf("%lld%lld%lld",&n,&k,&m);
    for(int i = 2; i <= n; i++){
        scanf("%lld",&p[i]);
        ch[p[i]].push_back(i);
    }
    for(int i = 1; i <= k; i++){
        scanf("%lld%lld",&x[i],&v[i]);
        pr[x[i]].push(v[i]);
    }
    
    if(sid == 6){
        int ans = 0;
        for(int i = 1; i < n; i++){
            if(!pr[i].empty()) ans += pr[i].top(),pr[i].pop();
            while(!pr[i].empty()){
                pr[i+1].push(pr[i].top()),pr[i].pop();
            }
        }
        if(!pr[n].empty()) ans += pr[n].top();
        printf("%lld",ans);
    }
    else if(m == 0){
        printf("%lld",dfs(1));
    }
    else{
        int ans = 0;
        for(int i = 1; i <= k; i++){
            ans += v[i];
        }
        printf("%lld",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}