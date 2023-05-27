#include<bits/stdc++.h>
using namespace std;
int num[50010][5];
int maxi[5],mine[5],z[5];
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int a,k,n,dd;
    cin>>a>>k;
    for(int i=0;i<a;i++)
    {
		dd=100000;
		for(int i=1;i<=4;i++)
		{
			maxi[i]=0;
			mine[i]=100000;
		}
		cin>>n;
		for(int j=1;j<=k;j++)
		{
			for(int s=1;s<=n;s++)
			{
				cin>>num[s][j];
			}
		}
		for(int j=1;j<=n;j++)
		{
			int ans=100000;
			for(int s=1;s<=k;s++)
			{	
				int answ=0;
				for(int d=1;d<=k;d++)
				{
					answ=max(answ,(max(maxi[d],num[j][d])-min(num[j][d],mine[d])));
				}
				if(answ<ans)
				{
					ans=answ;
					for(int d=1;d<=k;d++)
					{
						z[d]=num[j][d];
					}
				}
				if(j==n)  dd=min(dd,ans);
				int f=num[j][1];
				for(int d=1;d<k;d++)
				{
					num[j][d]=num[j][d+1];
				}
				num[j][k]=f;
			}
			for(int d=1;d<=k;d++)
			{
				maxi[d]=max(maxi[d],z[d]);
				mine[d]=min(mine[d],z[d]);
			}
		}
		cout<<dd<<endl;
	}
    return 0;
}
