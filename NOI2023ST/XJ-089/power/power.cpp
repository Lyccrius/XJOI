#include<bits/stdc++.h>
using namespace std;
int f[100000],a[100000];
int main()
{
    freopen("power.in","r",stdin);
    freopen("power.out",'w',stdout);
    int n,m,sum=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int u=i,v=1;
        while(u<=n)
        {
            if(v>=m&&f[u]==0)
            {
                f[u]=1;
                sum++;
            }
            v++;
            u=u*u;
        }
    }
    cout<<sum;
    return 0;
}
