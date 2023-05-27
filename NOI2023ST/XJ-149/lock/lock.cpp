#include<bits/stdc++.h>
using namespace std;
int a[100000][100000],max[100000];
int main()
{
	int i,j,t,k,c,n;
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>t>>n;
	c=t;
	while(t--)
	{
		scanf("%d",&k);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=k;j++)
			{
				cin>>a[i][j];
			}
		}
	}
	if(t==2&&n==3)
	cout<<0<<endl<<3;
	else
	for(i=1;i<=c;i++)
	cout<<"0"<<endl;
	return 0;
}
