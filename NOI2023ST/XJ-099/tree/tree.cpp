#include<bits/stdc++.h>
using namespace std;
typedef double db;
const int N=1010;
int n;
db x[N],y[N];
db dis(db x1,db y1,db x2,db y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

namespace subtask1{
    const int NN=19;
    const int M=262200;
    const db inf=999999999999.0;
    db f[NN][M]; int fro[NN][M];
    bool vis[NN][M];
    int S,st; int stt[NN],top;
    void input()
    {
        db maxx=-99999999; st=-1;
        for(int i=0;i<n;i++) 
        {
            scanf("%lf%lf",&x[i],&y[i]);
            if(y[i]>maxx) maxx=y[i],st=i;
        }
    }
    db dp(int u,int sta)
    {
        db &ans=f[u][sta];
        if(vis[u][sta]) return ans;
        if(sta==(sta&(-sta))&&u!=st) 
        {
            vis[u][sta]=1;
            return inf;
        }
        vis[u][sta]=1;
        for(int i=0;i<n;i++)
        {
            if(i==u||!(sta>>i&1)) continue;
            db val=dp(i,sta^(1<<u))+dis(x[i],y[i],x[u],y[u]);
            if(val<ans)
            {
                ans=val;
                fro[u][sta]=i;
            }
        }

        return ans;
    }
    void solve()
    {
        top=0;
        input(); S=1<<n;
        for(int i=0;i<n;i++)
            for(int j=0;j<S;j++) f[i][j]=inf;
        f[st][1<<st]=0; vis[st][1<<st]=1;
        db ans=inf; int end=-1;
        for(int i=0;i<n;i++) 
            if(dp(i,S-1)<ans) ans=dp(i,S-1),end=i;
        int nowst=S-1;
        while(end!=st) 
        {
            stt[++top]=end;
            int las=fro[end][nowst];
            nowst^=(1<<end);
            end=las;
        }
        stt[++top]=st;
        for(int i=top;i>=1;i--) printf("%d ",stt[i]+1);
    }
}

namespace subtask2{
    bool check()
    {
        for(int i=1;i<n;i++) 
            if(x[i]>x[i-1]||y[i]>y[i-1]) return false;
        return true;
    }
    void solve()
    {
        for(int i=1;i<=n;i++) printf("%d ",i);
    }
}

namespace subtask3{
    struct node{
        db x,y;
    }a[N];
    int f[N],top,st;
    int ans[N],res[N],sta[N];
    db calc()
    {
        db ans=0;
        for(int i=1;i<n;i++)
            ans+=dis(a[res[i]].x,a[res[i]].y,a[res[i+1]].x,a[res[i+1]].y);
        return ans;
    }
    db check(int x)
    {
        int tot=0; int pos;
        for(int i=x;i>=1;i--) res[++tot]=i;
        res[++tot]=n;
        for(int i=n-1;i>x;i--) res[++tot]=i;
        for(int i=1;i<=n;i++) 
			if(res[i]==st) pos=i;
        for(int i=pos-1;i>=1;i--) res[i+1]=res[i];
        res[1]=st;
        for(int i=1;i<=n;i++) sta[i]=res[i];
        db ans1=calc();
        tot=0;
        for(int i=x+1;i<=n;i++) res[++tot]=i;
        res[++tot]=1;
        for(int i=2;i<=x;i++) res[++tot]=i;
        for(int i=1;i<=n;i++) 
            if(res[i]==st) pos=i;
        for(int i=pos-1;i>=1;i--) res[i+1]=res[i];
        res[1]=st;
        db ans2=calc();
        if(ans2<ans1) 
        {
            for(int i=1;i<=n;i++) sta[i]=res[i];
            return ans2;
        }
        return ans1;
    }

    void solve()
    {
        for(int i=1;i<=n;i++) scanf("%lf%lf",&a[i].x,&a[i].y);
        reverse(a+1,a+1+n);
        db ymax=-9999999999; st=-1;
        for(int i=1;i<=n;i++)
            if(a[i].y>ymax) ymax=a[i].y,st=i;
        for(int i=1;i<=n;i++) f[++top]=i;
        f[++top]=1; db answ=999999999999;
        for(int i=1;i<=n;i++) 
        {
            db val=check(i);
            if(val<answ)
                for(int j=1;j<=n;j++) ans[j]=sta[j];
        }
        for(int i=1;i<=n;i++) printf("%d ",n-ans[i]+1);
        puts("");
    }
}

int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&n);
    if(n<=18) subtask1::solve();
    else if(subtask2::check()) subtask2::solve();
    else subtask3::solve();
}
