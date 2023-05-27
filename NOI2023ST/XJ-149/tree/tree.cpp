#include<bits/stdc++.h>//超时
using namespace std;
struct node
{
	int x,y,d,front[100000],f;
}p[1000000];
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int i,j,m,ans[100000]={0},t,sd=0;
	double s=0,min[100000]={2099999999};
	cin>>m;
	for(i=1;i<=m;i++)
	{
		cin>>p[i].x>>p[i].y;
		p[i].d=i;
		for(j=1;j<=m;j++)
		p[i].front[j]=0;
	}
	for(i=1;i<m;i++)
	{
		for(j=1;j<m;j++)
		{
			sd=0;
			s=sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y));
			for(t=1;t<=m||p[j].front!=0;t++)
			if(p[i].front[t]==p[j].d)
			{
				sd=1;
				break;
			}
			if(s<min[i]&&sd!=1)
			{
				min[i]=s;
				p[i].f++;
				p[i].front[p[i].f]=p[j].d;
				p[j].front[p[j].f]=p[i].d;
				ans[i]=p[i].d;
			}
		}
	}
	for(i=1;i<m;i++)
	cout<<ans[i]<<" ";
	return 0;
}
