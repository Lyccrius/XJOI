#include<bits/stdc++.h>
using namespace std;
struct node
{
	int from;
	int doum;
	int top;
	int next[2];
	int number;
}peo[100005];
bool cmp(node a,node b)
{
	if(a.from==b.from)
		return a.doum>b.doum;
	else
		return a.from<b.from;
}
int main()
{
	freopen("transfer.in","r",stdin);
	freopen("transfer.out","w",stdout);
	int sid;
	cin>>sid;
	int n,m,k;
	cin>>n>>k>>m;
	int top[100005];
	for(int i=2;i<=n;i++)
		cin>>top[i];
	for(int i=1;i<=k;i++)
	{
		cin>>peo[i].from>>peo[i].doum;
		peo[i].number=i;
	}	
	for(int i=1;i<=n;i++)
	{
		int falg=true;
		for(int j=1;j<=k;j++)
		{
			if(peo[j].from==j)
				falg=false;
		}
		if(falg)
		{
			k++;
			peo[k].from=i;
			peo[k].doum=0;
			peo[k].next[0]=peo[k].next[1]=0;
			peo[k].number=k;
			peo[k].top=0;
		}
	}
	
	sort(peo+1,peo+k+1,cmp);
	for(int i=2;i<=n;i++)
		peo[i].top=top[i];
	for(int i=1;i<=k;i++)
	{
		for(int j=2;j<=n;j++)
			if(peo[i].from==top[j])
			{
				if(peo[i].next[0]==0)
					peo[i].next[0]=j;
				else
					peo[i].next[1]=j;
			}
	}
	
	int sum=0;
	for(int i=1;i<=k;i++)
	{
		if(i!=1&&peo[i].from==peo[i-1].from)
		{
			int j=i;
			while((peo[j].from==peo[i].from||peo[i].next[0]!=peo[j].from)&&j<=k)
				j++;
			int h=i;
			while((peo[h].from==peo[i].from||peo[i].next[1]!=peo[h].from)&&h<=k)
				h++;
			if(j<=k&&h>=k)
			{
				if(peo[i].doum>peo[j].doum||peo[i].doum>peo[h].doum)
				{
					if(peo[i].doum-peo[j].doum>peo[i].doum-peo[h].doum)
					{
						peo[i].from=peo[j].from;
						peo[i].top=peo[j].top;
						peo[i].next[0]=peo[j].next[0];
						peo[i].next[1]=peo[j].next[1];
						sort(peo+1,peo+1+k,cmp);
					}
					else
					{
						peo[i].from=peo[h].from;
						peo[i].top=peo[h].top;
						peo[i].next[0]=peo[h].next[0];
						peo[i].next[1]=peo[h].next[1];
						sort(peo+1,peo+1+k,cmp);
					}
				}
			}
			continue;
		}	
		sum+=peo[i].doum;
	}
	cout<<sum<<' ';
	
	for(int l=0;l<m;l++)
	{
		int kind;
		cin>>kind;
		if(kind==1)
		{
			k++;
			node coust[100005];
			for(int i=0;i<=k-1;i++)
			{
				coust[i]=peo[i];
			}
			cin>>coust[k].from>>coust[k].doum;
			coust[k].number=k;
			sort(coust+1,coust+1+k,cmp);
			int sum=0;
			for(int i=1;i<=k;i++)
			{
				if(i!=1&&coust[i].from==coust[i-1].from)
				{
					int j=i;
					while((coust[j].from==coust[i].from||coust[i].next[0]!=coust[j].from)&&j<=k)
						j++;
					int h=i;
					while((coust[h].from==coust[i].from||coust[i].next[1]!=coust[h].from)&&h<=k)
						h++;
					if(j<=k&&h>=k)
					{
						if(coust[i].doum>coust[j].doum||coust[i].doum>coust[h].doum)
						{
							if(coust[i].doum-coust[j].doum>coust[i].doum-coust[h].doum)
							{
								coust[i].from=coust[j].from;
								coust[i].top=coust[j].top;
								coust[i].next[0]=coust[j].next[0];
								coust[i].next[1]=coust[j].next[1];
								sort(coust+1,coust+1+k,cmp);
							}
							else
							{
								coust[i].from=coust[h].from;
								coust[i].top=coust[h].top;
								coust[i].next[0]=coust[h].next[0];
								coust[i].next[1]=coust[h].next[1];
								sort(coust+1,coust+1+k,cmp);
							}
						}	
					}
					continue;
				}	
				sum+=coust[i].doum;
			}
			cout<<sum<<' ';
		}
		else
		if(kind==2)
		{
			int uid;
			cin>>uid;
			node coust[100005];
			for(int i=0;i<k;i++)
			{
				if(uid==k)
					continue;
				coust[i]=peo[i];
			}
			sort(coust+1,coust+1+k,cmp);
			int sum=0;
			for(int i=1;i<=k;i++)
			{
				if(i!=1&&coust[i].from==coust[i-1].from)
				{
					int j=i;
					while((coust[j].from==coust[i].from||coust[i].next[0]!=coust[j].from)&&j<=k)
						j++;
					int h=i;
					while((coust[h].from==coust[i].from||coust[i].next[1]!=coust[h].from)&&h<=k)
						h++;
					if(j<=k&&h>=k)
					{
						if(coust[i].doum>coust[j].doum||coust[i].doum>coust[h].doum)
						{
							if(coust[i].doum-coust[j].doum>coust[i].doum-coust[h].doum)
							{
								coust[i].from=coust[j].from;
								coust[i].top=coust[j].top;
								coust[i].next[0]=coust[j].next[0];
								coust[i].next[1]=coust[j].next[1];
								sort(coust+1,coust+1+k,cmp);
							}
							else
							{
								coust[i].from=coust[h].from;
								coust[i].top=coust[h].top;
								coust[i].next[0]=coust[h].next[0];
								coust[i].next[1]=coust[h].next[1];
								sort(coust+1,coust+1+k,cmp);
							}
						}	
					}
					continue;
				}	
				sum+=coust[i].doum;
			}
			cout<<sum<<' ';
		}
	}
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
