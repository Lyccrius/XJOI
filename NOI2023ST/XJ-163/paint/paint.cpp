#include <bits/stdc++.h>
using namespace std;

const int N=10100;
int s[N][N],n,m,q;
typedef long long ll;

void np1(int x,int c) //cow
{
	for(int i=1;i<=m;i++) s[x][i]=c;
}

void np2(int x,int c) //row
{
	for(int i=1;i<=n;i++)
		for(int j=x;j<=x;j++) s[i][j]=c;
			
}

void slove()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			cout<<s[i][j]<<" ";
		cout<<"\n";
	}
}

int main()
{
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	
	
	int T;
	scanf("%d",&T);
	
	while(T--)
	{
		memset(s,0,sizeof(s));

		scanf("%d%d%d",&n,&m,&q);
		
		while(q--)
		{
			
			int x,opt,c;
			scanf("%d%d%d",&opt,&x,&c);
			
			if(opt==0) np1(x,c);
			else if(opt==1) np2(x,c);
			
		}
		
		slove();
	}
	
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
