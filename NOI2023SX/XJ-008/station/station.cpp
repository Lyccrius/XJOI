#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1e5;

int n,m,x;
struct sta{
    int l,r;
}a[N];  int a1,a2;
bool vis[N];
bool cmpl(sta a,sta b) {return a.l<b.l;}
bool cmpr(sta a,sta b) {return a.r<b.r;}
int ans[N<<1]; int top;
int main()
{
    freopen("station.in","r",stdin);
    freopen("station.out","w",stdout);
    scanf("%d%d%d",&n,&m,&x);
    int lc=n+1,rc=0;
    for(int i=1;i<=m;i++) 
    {
        scanf("%d%d",&a1,&a2);
        a[i]=sta{a1,a2};
        if(a1<=x&&a2>=x) lc=min(lc,a1),rc=max(rc,a2);
    }
    sort(a+1,a+1+m,cmpr);
    for(int i=m;i>=1;i--)
        if(a[i].r>=lc) lc=min(lc,a[i].l); 
        else break;
    sort(a+1,a+1+m,cmpl);
    for(int i=1;i<=m;i++)
        if(a[i].l<=rc) rc=max(rc,a[i].r);
        else break;
    bool flag=0;
    for(int i=m;i>=1;i--)
    {
        if(a[i].l>=lc&&a[i].r<=rc)
        {
            if(a[i].l<=x) flag=1;
            if(flag) 
                ans[++top]=a[i].l;
        }
    }
    sort(a+1,a+1+m,cmpr);
    flag=0;
    for(int i=1;i<=m;i++)
    {
        if(a[i].l>=lc&&a[i].r<=rc)
        {
            if(a[i].r>=x) flag=1;
            if(flag) 
                ans[++top]=a[i].r;
        }
    }
    sort(ans+1,ans+1+top); top=unique(ans+1,ans+1+top)-ans-1;
    for(int i=1;i<=top;i++)
    {
        if(ans[i]==x) continue;
        printf("%d ",ans[i]);
    }
    puts("");
    return 0;
}