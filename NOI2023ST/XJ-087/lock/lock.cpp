#include<bits/stdc++.h>
using namespace std;
int a[5][10005];
int main()
{
	int t,k,n,i,j,minn[5],maxx[5],maxxx,t1[5];
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	scanf("%d %d",&t,&k);
	while(t--)
	{
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		for(i=1;i<=k;i++)
		{
			for(j=1;j<=n;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=k;j++)
			{
				t1[j]=a[j][i];
			}
			sort(t1+1,t1+k+1);
			for(j=1;j<=k;j++)
			{
				a[j][i]=t1[j];
			}
		}
		memset(minn,0x7f7f7f7f,sizeof(minn));
		memset(maxx,0,sizeof(maxx));
		for(i=1;i<=k;i++)
		{
			for(j=1;j<=n;j++)
			{
				minn[i]=min(minn[i],a[i][j]);
				maxx[i]=max(maxx[i],a[i][j]);
			}
		}
		maxxx=0;
		for(i=1;i<=k;i++)
		{
			//cout<<maxx[i]<<" "<<minn[i]<<endl;
			maxxx=max(maxxx,maxx[i]-minn[i]);
		}
		cout<<maxxx<<endl;
	}
	return 0;
}
