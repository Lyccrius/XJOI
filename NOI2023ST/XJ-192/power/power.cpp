#include<stdio.h>
int main()
{
	freopen("power.in","r",stdin);
	freopen("power.out","r",stdout);
	int a[1000005]={0},i,n,k,s,l,ans=0;
	scanf("%d%d",&n,&k);
	a[1]=1;
	for(i=2;i<=n;i++)
	{
		s=1;
		if(i*i<=n && k>=2)
		{
			for(l=1;l<=k;l++)
			{
				s=s*i;
			}		
			a[s]=1;
			while(s*i<=n)
			{
				s=s*i;
				a[s]=1;
			}
		}
		if(k==1)
		{
			for(l=1;l<=k;l++)
			{
				s=s*i;
			}		
			a[s]=1;
			while(s*i<=n)
			{
				s=s*i;
				a[s]=1;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		if(a[i]==1)
		{
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
