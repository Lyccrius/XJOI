#include <bis/stdc++/h>
using namespace std;
int n,m,q,t,tu[100010][100010],opt,c,x;
int main()
{
    freopen("paint.in""r",stdin);
    freopen("paint.out""w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>m>>q;
        for(int a=1;a<=n;a++)
        {
            for(int b=1;b<=m;b++)
            {
                tu[a][b]=0;
            }
        }

        for(int j=1;j<=p;j++)
        {
            cin>>opt>>x>>c;
            if(opt==1)
            {
                for(int k=1;k<=m;k++)
                {
                    tu[x][k]=c;
                }
            }
            else if(opt==0)
            {
                for(int k=1;k<=n;k++)
                {
                    tu[k][x]=c;
                }
            }
        }
        for(int a=1;a<=n;a++)
        {
            for(int b=1;b<=m;b++)
            {
                cout<<tu[a][b];
                if(b!=m)
                {
                    cout<<" ";
                }
            }
            if(a!=n)
            {
               cout<<"\n";
            }
        }
    }
    return 0;
}
