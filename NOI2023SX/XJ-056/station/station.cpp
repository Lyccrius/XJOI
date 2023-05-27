#include<bits/stdc++.h>
using namespace std;
int n,m,x;
int num[200000][2];
bool mmap[20000][20000];
bool cou[200005];
int ge[500000],t=0;
void ldfs(int front)
{
	bool flag=false;
	for(int i=front-1;i>=0;i--)
	{
		if(mmap[front][i]==true)
		{
			flag=true;
			ldfs(i);
		}
	}
	if(flag==false&&x!=1)
		ge[t++]=front+1;
	return ;
}
void rdfs(int front)
{
	bool flag=false;
	for(int i=front+1;i<n;i++)
	{
		if(mmap[front][i]==true)
		{
			flag=true;
			rdfs(i);
		}	
	}
	if(flag==false&&x!=n)
		ge[t++]=front+1;
	return ;
}
int main()
{
	freopen("station.in","r",stdin);
	freopen("station.out","w",stdout);
	cin>>n>>m>>x;
	for(int i=0;i<m;i++)
	{
		cin>>num[i][0]>>num[i][1];
		cou[num[i][0]]=cou[num[i][1]]=true;
		if(num[i][0]==x)
			ge[t++]=num[i][1];
		else
		if(num[i][1]==x)
			ge[t++]=num[i][0];
	}
	for(int i=0;i<m;i++)
	{
		for(int j=num[i][0]-1;j<num[i][1];j++)
		{
			if(cou[j+1]==true)
			{
				for(int k=num[i][0]-1;k<num[i][1];k++)
				{
					if(cou[k+1]==true)
						mmap[j][k]=mmap[k][j]=true;
				}
			}
		}
	}
	
	ldfs(x-1);
	rdfs(x-1);
	sort(ge,ge+t);
	for(int i=0;i<t;i++)
		if(ge[i]!=ge[i+1])
		cout<<ge[i]<<' ';
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
