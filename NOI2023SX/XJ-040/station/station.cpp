#include <iostream>
#include <algorithm>
using namespace std;
int m,n,x,ans[600010],cnt,f[200100];
struct node{
    int l,r;
}s[200100];
bool r(node x,node y)
{
    if(x.l<=y.l) return 0;
    return 1;
}
bool l(node x,node y)
{
    if(x.r>=y.r) return 0;
    return 1;
}
void a()
{
    int l1=1;
    sort(s+1,s+m+1,r);
    for(int i=1;i<=m;i++){
        if(s[i].l<=l1)
            l1=max(l1,s[i].r);
    }
    for(int i=1;i<=m;i++)
    {
        if(s[i].r!=1&&s[i].l<=l1){
            f[s[i].r]=1;
        }
    }
    sort(ans,ans+cnt);
    for(int i=0;i<n;i++)
    {
        if(f[i]==1) cout<<i<<" ";
    }
    return ;
}
void b()
{
    int l1=x,r1=x;
    sort(s+1,s+m+1,r);
    for(int i=1;i<=m;i++){
        if(s[i].l<=l1)
            l1=max(l1,s[i].r);
    }
    for(int i=1;i<=m;i++)
    {
        if(s[i].r>x&&s[i].l<=l1){
            f[s[i].r]=1;
        }
    }
    sort(s+1,s+m+1,l);
    for(int i=1;i<=m;i++){
        if(s[i].r>=r1)
            r1=min(r1,s[i].l);
    }
    for(int i=1;i<=m;i++)
    {
        if(s[i].l<x&&s[i].r>=r1){
            f[s[i].l]=1;
        }
    }
    for(int i=0;i<=n;i++)
    {
        if(f[i]==1) cout<<i<<" ";
    }
    return ;
}
int main()
{
    freopen("station.in","r",stdin);
    freopen("station.out","w",stdout);
    cin>>n>>m>>x;
    for(int i=1;i<=m;i++)
    {
        cin>>s[i].l>>s[i].r;
    }
    if(x==1) a();
    else b();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
