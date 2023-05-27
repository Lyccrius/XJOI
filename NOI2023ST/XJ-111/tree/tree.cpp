#include<bits/stdc++.h>
using namespace std;
double z,d,Max=-1000,x[1000],y[1000],v[1000];
int ans[1000],hh,dyh=1,k;
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int i,j,n,t;
	cin>>n;
	for(i=1;i<=n;i++)
		{
			cin>>x[i]>>y[i];
		}
	for(i=1;i<=n;i++)
		for(j=1;j<n;j++)
		{
			if(x[j]<x[j+1])
			{
				t=x[j];
				x[j]=x[j+1];
				x[j+1]=t;
				t=y[j];
				y[j]=y[j+1];
				y[j+1]=t;
			}
		}
	for(int i=1;i<=n;i++)
		if(Max<y[i])
		{
			Max=y[i];
			k=i;
		}
	ans[0]=k;
	for(i=1;i<=n-1;i++)
	{
		double Min=99999;
		for(j=1;j<=n;j++)
		{
			v[k]=1;
			if(v[j]==0)
			{
				z=(x[k]-x[j])*(x[k]-x[j])+(y[k]-y[j])*(y[k]-y[j]);
				d=sqrt(z);
				if(Min>d)
				{
					Min=d;
					hh=j;
				}
			}	
		}
		//cout<<endl<<Min<<" "<<hh;
		ans[dyh++]=hh;
		v[hh]=1;
		k=hh;
		
	}
	for(i=0;i<n;i++)
		cout<<ans[i]<<" ";
	return 0;
}
