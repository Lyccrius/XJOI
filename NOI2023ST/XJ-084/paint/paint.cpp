#include<bits/stdc++.h>
using namespace std;
int n,m,t,q;
long long opt[10005],x[10005],c[10005],aa[10005][10500];
int main()
{
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    cin>>t;
    while(t--)
    {
        for(int i=0;i<=n;i++)for(int j=0;j<=m;j++)aa[i][j]=0;
        cin>>n>>m>>q;
        for(int i=1;i<=q;i++)
        {
            cin>>opt[i]>>x[i]>>c[i];
            if(opt[i]==0)
            {
                for(int a=0;a<=m;a++)
                {
                    aa[x[i]][a]=c[i];
                }
            }else
            {
                for(int a=0;a<=n;a++)
                {
                   aa[a][x[i]]=c[i];
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cout<<aa[i][j]<<" ";
            }
            cout<<endl;
        }

    }
    fclose(stdin);
    fclose(stdout);
}
