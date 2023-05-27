//m==0
#include<bits/stdc++.h>
using namespace std;
int p[100010]={0},x[100010]={0},v[100010]={0};
int main()
{
	freopen("transfer.in","r",stdin);
	freopen("transfer.out","w",stdout);
	int sid,n,k,m,i,j,mo,nx,nv,id,ans=0;
	cin>>sid>>n>>k>>m;
	for(i=2;i<=n;i++)
	{
		cin>>p[i];
		ans+=p[i];
	}
	for(i=1;i<=k;i++)
	{
		scanf("%d%d",&x[i],&v[i]);
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d",&mo);
		if(mo==1)
		{
			scanf("%d%d",&nx,&nv);
		}
		else if(mo==2)
		{
			scanf("%d%d",&id);
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
