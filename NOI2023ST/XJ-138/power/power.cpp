#include<stdio.h>
using namespace std;
int main()
{
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	int i,j,k,n,t,s=1,h,fl=0,a;
	scanf("%d%d",&n,&k);
	for(i=2;i<=n;i++)
	{
		for(j=2;j<=i;j++)
		{
			t=j;a=t;
			for(h=2;h<=k;h++) t=t*a;
			while(t<=i)
			{
				if(t==i) 
				{
					s++;
					fl=1;
					break;
				}
				t=t*a;
			}
			if(fl==1) break;
		}
		fl=0;
	}
	printf("%d",s);
	return 0;
}
