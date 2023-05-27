#include<bits/stdc++.h>
using namespace std;
int ans[10100][10100];
bool  x[10100],y[10100],opt[10100];
int n,m,q,t,hzong,lzong;
int xi[10100],ci[10100];
int main()
{
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	

	cin>>t;
	for(int i=1;i<=t;i++)
	{
		memset(ans,-1,sizeof(ans));
		memset(x,0,sizeof(x));
		memset(y,0,sizeof(y));
		cin>>n>>m>>q;
		for(int j=1;j<=q;j++)
		{
			cin>>opt[j]>>xi[j]>>ci[j];
		}
		for(int k=q;k>=1;k--)
		{
			if(opt[k]==0)
			{
				if(x[xi[k]]==1)
				{
					continue;
				}
				else
				{hzong++;}
				
			for(int h=1;h<=n;h++)
			{
				if(ans[xi[k]][h]==-1)
				{ans[xi[k]][h]=ci[k];}
				
			}
			x[xi[k]]=1;
		    }
		    if(opt[k]==1)
		    {
			   
				if(y[xi[k]]==1)
				{
					continue;
				}
				else
				{lzong++;}
				
			for(int l=1;l<=m;l++)
			{
				if(ans[l][xi[k]]==-1)
				{ans[l][xi[k]]=ci[k];}
			}
			
			y[xi[k]]=1;
		    }

		    if(hzong==n&&lzong==m)
		    {break;}
				
		}
		
		for(int r=1;r<=n;r++)
		    {
				for(int f=1;f<=m;f++)
				{
					if(ans[r][f]==-1)
					{cout<<0<<" ";}
					if(ans[r][f]!=-1)
				{cout<<ans[r][f]<<" ";}
			    }
			    cout<<endl;
			}
	}
	return 0;
}
