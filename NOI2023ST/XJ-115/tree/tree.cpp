#include<bits/stdc++.h>
using namespace std;
struct hh
{
    double x,y;
    int o=0;
}a[20005],m,n;
bool cmp(hh m,hh n)
{
    if(m.y!=n.y&&m.x!=n.x)
    {
        return m.y<n.y;
    }
    else
    {
        if(m.x!=n.x)
        {
            return m.x<n.x;
        }
    }
    return 1;
}
int main()
{
    int n,i,j,u=1;
    //freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i].x>>a[i].y;
        a[i].o=1;
    }
    sort(a+1,a+n+1,cmp);
    for(i=1;i<=n;i++)
    {
        printf("%0.10lf %0.10lf\n",a[i].x,a[i].y);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}