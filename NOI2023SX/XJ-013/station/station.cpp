#include <bits/stdc++.h>
#define _ 0
#define N 200010
#define M 50010
using namespace std;
int n,m,x;
int flag;
bool f[N];
int que[N];
struct qwq{
    int l,r;
}q[N];
bool cmp(qwq op,qwq y)
{
    return op.l<y.l;
}
bool cmf(qwq op,qwq y)
{
    return op.r<y.r;
}
int main()
{
    freopen("station.in","r",stdin);
    freopen("station.out","w",stdout);
    cin>>n>>m>>x;
    for (int i = 1; i <= m; i++)
    {
        cin>>q[i].l>>q[i].r;
    }
    sort(q+1,q+1+m,cmf);
    sort(q+1,q+1+m,cmp);
    for(int i=1;i<=m;i++)
    if(x==1)
    {
        cout<<q[1].r<<" ";
        int real=q[1].r;
        for(int i=2;i<=m;i++)
        {
            if(q[i].l<=real) {cout<<q[i].r<<" "; real=q[i].r;}
        }
        return 0;
    }
    q[m+1].l=x,q[m+1].r=x;
    m+=1;
    int cnt=0;
    sort(q+1,q+1+m,cmp);
    for(int i=1;i<=m;i++)
    {
        if(q[i].l==x&&q[i].r==x) {flag=i; break;}
    }
    int real=x,feal=flag;

    for(int i=flag;i>=1;i--)
    {
        if(q[i].r>=real) {if(f[q[i].l]!=0) continue; f[q[i].l]=1;que[++cnt]=q[i].l,real=min(real,q[i].l);}
        if(q[i].r>=x) feal=i;
    }
    real=x;
    for(int i=feal;i<=m;i++)
    {
        if(q[i].l<=real) {if(f[q[i].r]!=0) continue; f[q[i].r]=1;que[++cnt]=q[i].r,real=max(real,q[i].r);}
    }
    sort(que+1,que+1+cnt);
    for(int i=1;i<=cnt;i++)
    {
        if(que[i]==x) continue;
        cout<<que[i]<<" ";
    }
    return 0;
}