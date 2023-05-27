#include<bits/stdc++.h>
using namespace std;
freopen("tree.in","r".stdin);
freopen("tree.out","w".stdout);
double ans,qp=10000000000000;
int n;int q[1000000],asd=1;int g;
struct nofe
{
	double x,y;
	double data;
}a[100000];

int dfs(int p)
{
	if(p==n)
	{
		if(ans<qp)
		{
			qp=ans;ans=0;
			q[asd]=p;
			asd++;
			return p-g;
		}
		else
		return p-g;
	}
	double z,x;
	for(int g=1;g+p<=n;g++)
	if(a[p+g].data!=0)
	{
		z=a[p].x-a[p+g].x;
		x=a[p].y-a[p+g].y;
		ans+=z*z+x*x;a[p+g].data=0;
		dfs(p+g);
	}
	
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{cin>>a[i].x>>a[i].y;
	a[i].data={1};a[1].data=0;}
	dfs(1);
	for(int dadad=1;dadad<=n;dadad++)
	cout<<q[dadad]<<" ";
}
