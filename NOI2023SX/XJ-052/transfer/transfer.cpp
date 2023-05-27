#include<bits/stdc++.h>
using namespace std;
int p[100005],x[1000005],v[100005];

int main()
{
	freopen("transfer.in","r",stdin);
	freopen("transfer.out","w",stdout);
	int sid,n,m,k;
	int th,x1,v1,id;
	cin>>sid;
	cin>>n>>m>>k;
	for(int i=0;i<n-1;i++)
	{
		cin>>p[i];
	}
	for(int i=0;i<k;i++)
	{
		cin>>x[i]>>v[i];
	}
	for(int i=0;i<m;i++)
	{
		cin>>th;
		if(th==1)
		{
			cin>>x1>>v1;
			k=k+1;
			x[k]=x1;
			v[k]=v1;
		}
		if(th==2)
		{
			cin>>id;
			for(int j=i;j<m;j++)
			{
				x[j]=x[j+1];
				v[j]=v[j+1];
			}
		}
	}
	return 0;
}
