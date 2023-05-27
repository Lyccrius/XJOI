#include<stdio.h>
using namespace std;
int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	int T,n,i,j,k,a[1005],cmax=-1,cmin=2147480000,c;
	scanf("%d%d",&T,&k);
	for(i=1;i<=T;i++)
	{
		scanf("%d",&n);
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[j]);
			if(a[j]<cmin) cmin=a[j];
			if(a[j]>cmax) cmax=a[j];
		}
		c=cmax-cmin;
		printf("%d\n",c);
		c=0;cmax=-1;cmin=2147480000;
	}
	return 0;
}
