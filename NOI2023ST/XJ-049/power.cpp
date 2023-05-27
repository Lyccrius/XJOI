#include<bits/stdc++.h>
using namespace std;
int i,n,m,j,t,q,sum=0,k,l,x,c,opt,a[1000005];
int main()
{
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    cin>>n>>k;
	for(i=1;i<=n;i++)
	{
		for(j=k;;j++)
		{
			l=i,x=l;
			x=0;
			for(int p=1;p<=j;p++)
			{
				x=x*l;
			}
			if(x>0&&x<=n&&a[x]==0)
			{
				sum++;
				a[x]=1;
			}
			else if(x>n)
			{
				break;
			}
		}
	}
	cout<<sum;
    fclose(stdin);
    
    fclose(stdout);
    return 0;
}
