#include<bits/stdc++.h>
using namespace std;
int mp[100010][100010],num[100010],sum[100010],a[100010],b[100010],c[100010];
int n,m,ans,T,l;
int main()
{
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	cin>>n;

	while(T--)
	{
		scanf("%d%d%d",&l,&m,&n);
		for(int i=1;i<=m;i++)
            num[i]=0;
        for(int i=1;i<=l;i++)
            sum[i]=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
		}
		for(int i=n;i;i--)
		{
			if(a[i]==0)
			{
				if(num[b[i]]==1)
				continue;
				num[b[i]]=1;
				for(int j=1;j<=m;j++)
				{
					if(mp[b[i]][j]==0)mp[b[i]][j]=c[i];
				}
			}
			if(a[i]==1)
			{
				if(sum[b[i]]==1)
				continue;
				sum[b[i]]=1;
				for(int j=1;j<=l;j++)
				{
					if(mp[j][b[i]]==0)mp[j][b[i]]=c[i];
				}
			}
		}
		for(int i=1;i<=l;i++)
		{
		for(int j=1;j<=m;j++)
		{
			printf("%d ",mp[i][j]);
			mp[i][j]=0;
		}
		printf("\n");
		}
		}
    return 0;
}
