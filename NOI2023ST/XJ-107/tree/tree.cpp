#include <bits/stdc++.h>
using namespace std;
double check[10005][10005];
double x[1000005];
double y[1000005];
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int n;
	cin >>n;
	for(int i=1;i<=n;i++)
	{
		cin >>x[i];
		cin >>y[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j)
			continue;
			check[i][j]=sqrt(abs(x[i]-x[j])+abs(y[i]-y[j]));
		}
	}		
	int a=1;
	for(int i=1;i<=n;i++)
	{

		for(int j=1;j<=n;j++)
		{
			if(y[a]<y[j])
			a=j;
		}
	}
	int k=0;
	for(int i=a;k<n;i++)
	{
		k++;
		int look=0,maxx=100000;
		for(int j=1;j<=n;j++)
		{
		if(check[i][j]<maxx)
		maxx=check[i][j],look=j;
		}
		i=look;
		cout <<look<< " ";
	}
	fclose(stdin);
	return 0;
}
