#include<bits/stdc++.h>
using namespace std;
struct node
{
	int a[10005];
}r[10005];
int main()
{
	freopen("paint.in","r",stdin);
	freopen("painnt.out","w",stdout);
	
	int t,n,m,q,opt,x,c;
	
	cin>>t;
	
	while(t--)
	{
		for(int i=1;i<=n;i++)
			memset(r[i].a,0,sizeof(r[i].a));
		
		cin>>n>>m>>q;
	
		for(int i=1;i<=q;i++)
		{	
			cin>>opt>>x>>c;
		
			if(opt==0)
			{
				for(int j=1;j<=m;j++)
					r[x].a[j]=c;
			}
			else
			{
				for(int j=1;j<=n;j++)
					r[j].a[x]=c;
			}
		}
		
		cout<<"\n";
		
		for(int i=1;i<=n;i++)
		{	
			for(int j=1;j<=m;j++)
				cout<<r[i].a[j]<<" ";
			
			cout<<"\n";
		}
		
		cout<<"\n";
	}
	
	cout<<endl;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
