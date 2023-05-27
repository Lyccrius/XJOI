#include<bits/stdc++.h>
using namespace std;
int n,i,j,k,b[1005];
struct aa
{
    double x;
    double y;
};
struct aa a[1005];
struct bb
{
    double l;
    int x;
};
struct bb f[10][1005][1005];
double s(int k)
{
    double t1,t2;
    t1=(a[k].x-a[k-1].x)*(a[k].x-a[k-1].x);
    t2=(a[k].y-a[k-1].y)*(a[k].y-a[k-1].y);
    return sqrt(t1+t2);
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i].x>>a[i].y;
        f[1][1][i].x=i;
    }

    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    for(k=1;k<=n-1;k++)
    {
        f[i][j][k].l=min(min(f[i-1][j][k].l,f[i-1][j][k-1].l),min(f[i][j-1][k].l,f[i][j-1][k-1].l))+s(k);
        if(f[i][j][k].l==f[i-1][j][k].l)
        f[i][j][k].x=f[i-1][j][k].x;
        else
        if(f[i][j][k].l==f[i-1][j][k-1].l)
        f[i][j][k].x=f[i-1][j][k-1].x;
        else
        if(f[i][j][k].l==f[i][j-1][k-1].l)
        f[i][j][k].x=f[i][j-1][k-1].x;
        else
        if(f[i][j][k].l==f[i][j-1][k].l)
        f[i][j][k].x=f[i][j-1][k].x;
    }
    for(k=1;k<=n;k++)
    cout<<f[n][n][k].x<<" ";
    return 0;
}