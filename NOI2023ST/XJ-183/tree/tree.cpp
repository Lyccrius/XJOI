#include<bits/stdc++.h>
using namespace std;
double x[1010],y[1010],s1,s2;
int n,k;
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(y[i]>=y[i-1])
		{
			k=y[i];
		}
	}
	int l=0;
	while(l!=k-1)
	{
		l=k;
		int p=l,q=l;
		s1+=sqrt((x[p]-x[p+1])*(x[p]-x[p+1])+(y[q]-y[q+1])*(y[q]-y[q+1]));
		l++;
		if(l>=n)
		{
			l=1;
		}
		
	}
	while(l!=k)
	{
		l=k;
		int p=l,q=l;
		s1+=sqrt((x[p]-x[p-1])*(x[p]-x[p-1])+(y[q]-y[q-1])*(y[q]-y[q-1]));
		l--;
		if(l<=0)
		{
			l=1;
		}
		
	}
	cout<<max(s1,s2);
	return 0;
}
