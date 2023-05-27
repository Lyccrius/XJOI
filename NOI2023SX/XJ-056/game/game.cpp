#include<bits/stdc++.h>
using namespace std;
int s[1000000][3],t[1000000][3];
int alicc[10000][10000],bob[10000][10000];
int c,b;
bool judge(int *rem,int a)
{
	for(int i=0;rem[i]!=0;i++)
	{
		if(a==rem[i])
			return false;
	}
	return true;
}
void comup(int deep,int n,int *rem,int ca)
{
	if(deep==n+1)
	{
		for(int i=0;i<ca;i++)
			alicc[c][i]=rem[i];
		c++;
		return ;
	}	
	for(int i=1;i<=2;i++)
	{
		if(s[deep][i]!=0)
		{
			rem[ca]=s[deep][i];
			comup(deep+1,n,rem,ca+1);
		}
	}
}
void legup(int deep,int n,int *rem,int ca)
{
	if(deep==n+1)
	{
		for(int i=0;i<ca;i++)
			bob[b][i]=rem[i];
		b++;
		return ;
	}	
	for(int i=1;i<=2;i++)
	{
		if(t[deep][i]!=0)
		{
			rem[ca]=0;
			if(judge(rem,t[deep][i]))
			{
				rem[ca]=t[deep][i];
				legup(deep+1,n,rem,ca+1);
			}
		}
	}
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int T;
	int n,m;
	cin>>T;
	while(T--)
	{
		for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
			s[i][j]=t[i][j]=0;
		for(int i=0;i<10000;i++)
		for(int j=0;j<10000;j++)
		{
			if(alicc[i][j]==0&&bob[i][j]==0)
				break;
			alicc[i][j]=bob[i][j]=0;
		}
		
			
		c=0,b=0;
		n=0,m=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			int s1;
			scanf("%d",&s1);
			for(int j=1;j<=s1;j++)
				scanf("%d",&s[i][j]);
		}
		for(int i=1;i<=n;i++)
		{
			int t1;
			scanf("%d",&t1);
			for(int j=1;j<=t1;j++)
				scanf("%d",&t[i][j]);
		}
		
		int rem[3]={0};
		comup(1,n,rem,0);
		
		int bem[3]={0};
		legup(1,n,bem,0);
		
		if(b==0)
		{
			cout<<-1<<endl;
			continue;
		}
		
		
		int lmadi=INT_MIN;
		for(int i=0;i<c;i++)
		{
			int madi=INT_MAX;
			for(int j=0;j<b;j++)
			{
				int coust=0;
				for(int t=0;t<n;t++)
				{
					if(alicc[i][t]==bob[j][t])
						coust++;
				}
				if(coust<madi)
					madi=coust;
			}
			if(madi>lmadi)
				lmadi=madi;
		}
		cout<<lmadi<<endl;
		
	}
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
