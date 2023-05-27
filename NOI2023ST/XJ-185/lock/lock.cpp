#include<bits/stdc++.h>
using namespace std;
int k,f[100010][100010],sum[100010]; 
int n,m,ans,T,num[100010][100010];
/*void DFS(int x,int y,)
{
	
	
	}*/
int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	scanf("%d%d",&T,&k);
	while(T--)
	{
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=k;i++){
			for(int j=2;j<=n;j++)
			{
				scanf("%d",&num[i][j]);
				f[i][j]=num[i-1][j]-num[i][j];
				sum[i]=max(sum[i],f[i][j]);
			}
			ans=min(ans,sum[i]);
		}
		printf("%d\n",ans);
	}
    return 0;
}
