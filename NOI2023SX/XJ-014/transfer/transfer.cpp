//code by MisakaE
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
priority_queue<int> q;
vector<int> v[N];
int mi[N];
int spt,n,k,m;
int main()
{
    freopen("transfer.in","r",stdin);
    freopen("transfer.out","w",stdout);

    scanf("%d%d%d%d",&spt,&n,&k,&m);
    for(int i=1;i<n;++i){
        int l;
        scanf("%d",&l);
    }
    for(int i=1;i<=k;++i){
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
    }
    long long cnc=0;
    for(int i=1;i<=n;++i){
        for(int j=0;j<v[i].size();++j){
            q.push(v[i][j]);
        }
        int sk;
        if(q.empty())sk=0;
        else{
            sk=q.top();
            q.pop();
        }
        mi[i]=sk;
        cnc+=sk;
    }
    printf("%lld ",cnc);
    for(int i=n-1;i>=1;--i)
        mi[i]=min(mi[i],mi[i+1]);
    for(int i=1;i<=m;++i){
        int opt,x,vy;
        scanf("%d%d%d",&opt,&x,&vy);
        if(mi[x]<vy)printf("%lld ",cnc-mi[x]+vy);
        else printf("%lld ",cnc);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}