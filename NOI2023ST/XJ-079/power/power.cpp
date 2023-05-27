#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("paint.in","r","stdin");
	freopen("paint.out","w","stdout");
	int n,k,i=1,j,max=0,a[10000],p=2,t=3,q=3;
	scanf("%d%d",&n,&k);
	while(i>n)
	{
		if(i%2==0)
		{
			while(i<p)
			{
				j++;
				p=p*2;
				if(i/p==1&&j>=k&&a[i]!=1)
				{
					a[i]=1;
					max++;break;
				}
			}
		}
		else
		{
			while(q>a[i])
			{
				j++;
				t=t*q;
				if(i/p==1&&j>=k&&a[i]!=1)
				{
					max++;
					j=1;
				}
				t=t+2;
				q=t+2;
			}
		}
		i++;
	}
	printf("%d",max);
	return 0;
}
