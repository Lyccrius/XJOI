#include<bits/stdc++.h>
using namespace std;
int p[100005][100005];
int main()
{
   freopen("paint.in","r",stdin);
   freopen("paint.out","w",stdout);
   long long m,n,T,q,o,x,c;
   long long i,j,ts;
   cin>>T;
   for(ts=1;ts<=T;ts++)
   {
	   cin>>n>>m>>q;
       for(i=1;i<=q;i++)
       {
	       cin>>o>>x>>c;
	       if(o==0)
	       {
	           for(j=1;j<=m;j++)
	           {
				   p[x][j]=c;
			   }
	       }
	       if(o==1)
	       {
	           for(j=1;j<=n;j++)
	           {
			       p[j][x]=c;
		        }
           }
       }
       for(i=1;i<=n;i++)
       {
		    for(j=1;j<=m;j++)
		    {
		         cout<<p[i][j]<<" ";
		         p[i][j]=0;
		    }
		    cout<<endl;
       }
   }
   return 0;
}
