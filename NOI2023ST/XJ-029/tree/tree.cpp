#include <bits/stdc++.h>
using namespace std;
int n;
struct node
{
	double x,y;
	int num;
}a[1005];
bool cmp(node a,node b)
{
	if (a.y>b.y) return true;
	if (a.y==b.y&&a.x<b.x) return true;
	return false;
}
int main ()
{
	int i;
	cin>>n;
	freopen("tree.in","r",stdin);
	for (i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y;
		a[i].num=i;
	}
	sort(a+1,a+1+n,cmp);
	for (i=1;i<=n;i++)
	{
		cout<<a[i].num<<" ";
	}
	freopen("tree.out","w",stdout);
	return 0;
}
