//1~2
#include<bits/stdc++.h>
using namespace std;
int a[50010][5]={0};
int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	int t,k,n,i,j,maxi=-1,maxj=-1,minj=-1;
	cin>>t>>k;
	while(t--)
	{
		cin>>n;
		maxi=-1;
		for(i=1;i<=k;i++)
		{
			maxj=-1;minj=21474836;
			for(j=1;j<=n;j++)
			{
				scanf("%d",&a[j][i]);
				//cout<<j<<' ';
				maxj=max(maxj,a[j][i]);
				minj=min(minj,a[j][i]);
			}
			maxi=max(maxi,maxj-minj);
		}
		cout<<maxi<<endl;
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
