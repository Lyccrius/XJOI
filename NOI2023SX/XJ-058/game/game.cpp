#include<bits/stdc++.h>
using namespace std;

int T;
int n=1000010,m=1000010;
int s[1000010][2];
int t[1000010][2];
int x;
int a[1000010];
int b[1000010];

void init()
{
	for(int i=1;i<=n;i++)
	{
		s[i][0]=s[i][1]=t[i][0]=t[i][1]=0;
	}
	for(int i=1;i<=m;i++)
	{
		a[i]=b[i]=0;
	}
	x=0;
}
bool check()
{
	for(int i=1;i<=n;i++)
	{
		b[t[i][0]]=b[t[i][1]]=1;
	}
	for(int i=1;i<=1000010;i++)
	{
		if(b[i]>2) return false;
	}
	return true;
}
void fun()
{
	if(!check())
	{
		cout<<"-1"<<endl;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(s[i][0]==t[i][0] && (t[i][1]==0 || a[t[i][1]]))
		{
			x++;
			a[t[i][1]]=1;
		}
		if(s[i][0]==t[i][1] && a[t[i][0]])
		{
			x++;
			a[t[i][0]]=1;
		}
		if(s[i][0]==t[i][0] && (t[i][1]==0 || a[t[i][1]]))
		{
			x++;
			a[t[i][1]]=1;
		}
		if(s[i][0]==t[i][1] && a[t[i][0]])
		{
			x++;
			a[t[i][0]]=1;
		}
	}
	cout<<x<<endl;
	return;
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	
	scanf("%d",&T);
	while (T--)
	{
		init();
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			if(x==1)
			{
				scanf("%d",&s[i][0]);
			}
			else if(x==2)
			{
				scanf("%d%d",&s[i][0],&s[i][1]);
			}
		}
		for(int i=1;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			if(x==1)
			{
				scanf("%d",&t[i][0]);
			}
			else if(x==2)
			{
				scanf("%d%d",&t[i][0],&t[i][1]);
			}
		}
		fun();
	}
	

	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
