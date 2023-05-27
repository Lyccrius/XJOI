#include<bits/stdc++.h>
using namespace std;
int num[10010][10010];
int main()
{
    freopen("print.in","r",stdin);
    freopen("print.out","w",stdout);
    int a,n,m,q,x,y,out1;
    cin>>a;
    for(int i=0;i<a;i++)
    {
        cin>>n>>m>>q;
        
        for(int j=0;j<q;j++)
        {
            cin>>out1>>x>>y;
            if(out1==0)
            {
		    	for(int k=1;k<=m;k++)
		    	{
			    	num[x][k]=y;
			    }
			}
			else
			{
				for(int k=1;k<=n;k++)
				{
					num[k][x]=y;
				}
			}
		}
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=m;k++)
			{
				cout<<num[j][k]<<' ';
				num[j][k]=0;
			}
			cout<<endl;
		}
    }
    return 0;
}
