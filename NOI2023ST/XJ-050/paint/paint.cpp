#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll T,n,m,p,a[10010][10010];
ll b1,b2,b3;
signed main()
{
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    cin>>T;
    for(int tt=1;tt<=T;tt++)
    {
        memset(a,0,sizeof(a));
        cin>>n>>m>>p;
        for(int i=1;i<=p;i++)
        {
            cin>>b1>>b2>>b3;
            if(b1==1)
            {
                for(int j=1;j<=n;j++)
                {
                    a[j][b2]=b3;
                }
            }
            else if(b1==0)
            {
                for(int j=1;j<=m;j++)
                {
                    a[b2][j]=b3;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
