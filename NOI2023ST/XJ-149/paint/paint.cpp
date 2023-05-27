#include<bits/stdc++.h>
using namespace std;
int a[100000][100000]={0};//爆空间。                                            
int main()
{
	freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    int o,m,p,q,i,j,n,x,z;
    cin>>z;
    while(z--)
    {	
		cin>>n>>m>>q;
		for(i=1;i<=q;i++)
		{
			cin>>o>>x>>p;
			if(o==0)
			{
				for(j=1;j<=m;j++)
				a[x][j]=p;
			}
			else
			if(o==1)
			{
				for(j=1;j<=n;j++)
				a[j][x]=p;
			}
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=m;j++)
				cout<<a[i][j]<<" ";
				cout<<endl;
			}
			memset(a,0,sizeof(a));
		}
	}
return 0;
}
