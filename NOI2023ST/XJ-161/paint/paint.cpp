#include<bits/stdc++.h>
using namespace std;
int a[100000][2]={0},b[100000][2]={0};
int main()
{
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	int t,i,j,n,m,q,opt,x,c;
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>q;//n hang m lie
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(i=1;i<=q;i++)
		{
			scanf("%d%d%d",&opt,&x,&c);
			if(opt)//lie
			{
				a[x][0]=c;
				a[x][1]=i;
			}
			else//hang
			{
				b[x][0]=c;
				b[x][1]=i;
			}
		}
		//for(i=1;i<=m;i++) printf("[%d %d] ",a[i][0],a[j][1]); cout<<endl;
		//for(j=1;j<=n;j++) printf("[%d %d] ",b[j][0],b[j][1]); cout<<endl;
		for(i=1;i<=m;i++)//(i,j)
		{
			for(j=1;j<=n;j++)
			{
				if(b[i][1]<a[j][1]) printf("%d ",a[j][0]);
				else printf("%d ",b[i][0]);
			}
			printf("\n");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
