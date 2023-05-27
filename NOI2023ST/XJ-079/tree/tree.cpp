#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("tree.in","r","stdin");
	freopen("tree.out","w","stdout");
	int n,i,j;
	double a[1000][3];
	for(i=0;i<n,i++)
	{
		scanf("%lf%lf",&a[i][0],&a[i][1]);
		a[i][2]=i+1;
	}
	for(i=1;i<=n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(a[i][0]>a[i-1][0])
			{
				a[i-1][0]=a[i][0];
				a[i-1][1]=a[i][1];
				a[i-1][2]=a[i][2];
			}
		}
	}
	for(i=0;i<n;i++)
	{
		
		}
}

