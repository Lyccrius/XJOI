#include<bits/stdc++.h>
using namespace std;
struct flo
{
	double x,y;
}a[2000];
double b[2000][2000];
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int n,i,j,k=1,ans=0;
	double maxy=-1.0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y;
		if(a[i].y>maxy)
		{
			maxy=a[i].y;
			k=i;
		}
	}
	/*for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(j==i) b[i][j]=0.0;
			else b[i][j]=b[j][i]=sqrt((a[j].x-a[i].x)*(a[j].x-a[i].x)+(a[j].y-a[i].y)*(a[j].y-a[i].y));
		}
	}
	*/
	cout<<k<<' ';
	for(i=1;i<=n;i++)
	{
		ans=(i+k)%(n+1);
		if(ans==0);
		else cout<<ans<<' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
