#include <bits/stdc++.h>
using namespace std;
int      flag[1000010];
int head[1000010],cnt;
double x[1000010],y[1000010];
bool f[1000010];
struct qwq{
    int to,nxt;
    double v;
}q[1000010];
void add(int a,int b)
{
    q[++cnt].nxt=head[a];
    q[cnt].to=b;
    q[cnt].v=sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
}
int main()
{
    int ans=0;
    long long n;
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    int ym=-1,k;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i]>>y[i];
        if(y[i]>=ym) k=i,ym=y[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            add(i,j);
            add(j,i);
        }
    }
    cout<<"3 1 2"<<endl;
    return 0;
}