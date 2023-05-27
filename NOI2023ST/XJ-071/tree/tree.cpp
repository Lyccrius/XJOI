#include<bits/stdc++.h>
using namespace std;
double x[1001],y[1001];
double mins[1001];
double s[1001];
bool v[1001];
int n;
bool prime()
{
    for(int i=1;i<=n;i++)
    {
        if(!v[i])
        return 0;

    }
    return 1;
}
void dfs(int start , int cnt ,double sum,queue<int> q)
{
    if(cnt==n)
    {
        cout<<start<<" ";
        return ;
    }
    else
    {
        for(int i=start;i<=n;i++)
        {
            dfs(i,cnt+1,sum+=sqrt(pow((x[start]-x[i]),2)+pow((y[start]-y[i]),2)),q);
            dfs(i,cnt,sum,q);
        }
    }
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&x[i],&y[i]);
        s[i]=sqrt(pow((x[i]-x[i-1]),2)+pow((y[i]-y[i-1]),2));
        mins[i]=min(s[i],mins[i]);
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}