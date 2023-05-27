#include <iostream>
using namespace std;
const int N=1e5+10;
int a[N][N];
int main()
{
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		int n,m,p;
		cin>>n>>m>>p;
		for(int i=1;i<=p;i++){
		int opt,x,c;
		cin>>opt>>x>>c;
		if(opt==1)
		{
			for(int j=1;j<=n;j++)
			{
				a[j][x]=c;
			}
		}
		else
		for(int j=1;j<=m;j++)
		{
			a[x][j]=c;
		}
	}
	for(int i=1;i<=n;i++){
	for(int j=1;j<=m;j++)
	cout<<a[i][j]<<" ";
	cout<<endl;
}
for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	a[i][j]=0;
	}
	return 0;
}

