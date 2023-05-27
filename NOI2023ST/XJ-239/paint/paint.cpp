#include<bits/stdc++.h>
using namespace std;
long long n,m,q,T;
long long a[100][100];
int main()
{	cin>>T;
	for(int s=1;s<=T;s++)
	{
	cin>>n>>m>>q;
    freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	for(int i=1;i<=q;i++)
	{int x,y,z;
		cin>>x>>y>>z;
		if(x==0)
		a[y][m]=a[z][m];
		if(x==1)
		a[n][y]=a[n][z];
	}
}
   for(int i;i<=n;i++)
    for(int j;j<=m;j++)
	  cout<<a[i][j]<<endl;


return 0;
}
