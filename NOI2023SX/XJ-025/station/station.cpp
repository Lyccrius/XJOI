#include<bits/stdc++.h>
using namespace std;

const int N=20010;

int n,m,x;
int l,r;
int a[N],b[N];
int fa[N],son[N];
int ans[N];
int t;
int st[N];
int cnt;
int maxn;

void se(int u,int v){
    maxn=max(maxn,v);
    fa[v]=u;
}

void dfs(){
    if(fa[t]!=t&&st[t]!=1){
        ans[cnt]=fa[t];
        st[t]=1;
        cnt++;
        t=fa[t];
        dfs();
    }
    st[t]=0;
    return ;
}

void f(){
    for(int i=x;i<=maxn;i++){
        if(fa[i]=t&&st[i]!=1){

            for(int j=1;j<=maxn;j++){
                if(b[j]==i&&ans[cnt-1]!=i)ans[cnt]=i;
            }

            st[t]=1;
            cnt++;
            t=i;
            f();
        }
    }
    st[t]=0;
    return ;
}

int main(){
    freopen("station.in","r",stdin);
    freopen("station.out","w",stdout);
    cin>>n>>m>>x;//火车站的数量，火车轨道的数量,小A初始的起点
    t=x;
    fa[1]=1;

    for(int i=1;i<=m;i++){
        cin>>l>>r;
        se(l,r);
        a[i]=l;
        b[i]=r;
    }

    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            if(a[i]<a[j]&&b[i]>a[j])fa[a[j]]=a[i];
        }
    }

    dfs();
    t=x;
    f();

    for(int i=0;i<cnt;i++){
        for(int j=0;j<cnt;j++){
            if(ans[i]<ans[j]){
                int s=ans[i];
                ans[i]=ans[j];
                ans[j]=s;
            }
        }
    }

    for(int i=cnt;i>=0;i--){
        if(ans[i]==ans[i-1])ans[i]=0;
    }

    for(int i=0;i<cnt;i++){
        if(ans[i]!=0)cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}