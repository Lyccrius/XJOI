#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    int n,m,q,a,b,c,i,j,f[100000][100000]={0},t,k;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>n>>m>>q;
        for(j=1;j<=q;j++)
        {
            cin>>a>>b>>c;
            if(a==0)
            {
                for(k=1;k<=n;k++)
                {
                    f[b][k]=c;
                }
            }
            else
            {
                for(k=1;k<=m;k++)
                {
                    f[k][b]=c;
                }
            }
        }
        for(j=1;j<=n;j++)
        {

            for(k=1;k<=m;k++)
            {
                cout<<f[j][k];
            }
        }
    }
    return 0;
}
