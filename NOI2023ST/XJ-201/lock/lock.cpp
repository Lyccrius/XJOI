#include <bits/stdc++.h>
using namespace std;
int T;
int k;
int n;
int a[50000][5];
void ch(int q)
{
	for(int i=1;i<=k;++i)
		a[i][q]=(a[i][q]+1)%k;
	}
void f(int nw)
{
	
	for(int i=1;i<=k;++i)
	{
		
		f(nw+i);
	}
}
int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>T>>k;
	while(T--)
	{
		cin>>n;
		if(n==1)
		{cout<<0;
			return 0;
		}
		for(int i=1;i<=k;++i)
		{
			for(int j=1;j<=n;++j)
			{
				cin>>a[i][j];
			}
		}
		f(1);
	}
	return 0;
}
