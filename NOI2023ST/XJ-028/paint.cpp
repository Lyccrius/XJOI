#include<bits/stdc++.h>
using namespace std;
long long a[100005][100005];
int main()
{
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    long long q,i,T,opt,x,c,j,n,m;
    cin>>T;
    while(T--)
    {
        memset(a,0,sizeof(a));
        cin>>n>>m>>q;
        for(i=1;i<=q;i++)
        {
            cin>>opt>>x>>c;
            for(j=1;j<=m;j++)
            {
				if(opt==0)
				{
					a[x][j]=c;
				}
			}
			for(j=1;j<=n;j++)
			{
				if(opt==1)
				{
					a[j][x]=c;
				}
			}
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
				cout<<a[i][j];
            }
        }
    }
    return 0;
}
