#include<bits/stdc++.h>
using namespace std;
int a[5][50005];
int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdin);
	int n,k,i,j,T;
	cin>>T>>k;
	while(T--)
	{
		cin>>n;
		for(i=1;i<=k;i++)
		{
			for(j=1;j<=n;j++)
			{
				cin>>a[i][j];
			}
		}
	}
	return 0;
}
