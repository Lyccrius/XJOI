#include<bits/stdc++.h>
using namespace std;
int a[10086][10086];
int T,n,m,q;
int opt[10086],x[10086],c[10086];
int main()
{
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		cin>>n>>m>>q;
		for(int j=1;j<=n;j++)
		for(int k=1;k<=m;k++)
		    a[j][k]=0;
		for(int j=1;j<=q;j++)
		{
			cin>>opt[j]>>x[j]>>c[j];
		}
		for(int j=1;j<=q;j++)
		{
			if(opt[j]==0)
		    {
			    for(int k=1;k<=m;k++)
			        a[x[j]][k]=c[j];
		    }
		    if(opt[j]==1)
		    {
				for(int k=1;k<=n;k++)
				    a[k][x[j]]=c[j];
			}
		}	
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=m;k++)
		    cout<<a[j][k]<<" ";
		    cout<<endl;
		}
	}
	return 0;
}
