#include<bits/stdc++.h>
using namespace std;
double f(double x1,double x2,double y1,double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
double g[105][105];
struct node
{
	double x,y;
	int num;
	bool operator<(node b)
	{
		return y>b.y;
	}
}t[105];
bool used[10000];
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
	cout<<3<<" "<<1<<" "<<2;
	int n;cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>t[i].x>>t[i].y;
		t[i].num=i;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(t[i].y<t[j].y)
			{
				swap(t[i],t[j]);
			}
		}
	}			
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j)g[i][j]=0;
			else
			{
				g[i][j]=f(t[i].x,t[j].x,t[i].y,t[j].y);
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(g[i][j]>g[i][k]+g[k][j])
				{
					g[i][j]=g[i][k]+g[k][j];
					cout<<i<<" "<<k<<" "<<j<<endl;
				}
			}
		}
	}
	cout<<g[1][t[n].num];
    return 0;
}
