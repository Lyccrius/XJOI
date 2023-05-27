#include<bits/stdc++.h>
using namespace std;
int main()
{
   freopen("power.in","r",stdin);
   freopen("power.out","w",stdout);
   long long n,k,i,j,q,c=0;
   int flag=0;
   cin>>n>>k;
   for(i=1;i<=n;i++)
   {
	   for(j=k;j<=100;j++)
	   {
		   for(q=1;q<=sqrt(i);q++)
	       {
		       if(i==pow(q,j)||sqrt(i)==pow(q,j)||sqrt(sqrt(i)==pow(q,j)))
		       {
				   c++;
				   flag=1;
				   break;
	           }
	       }
	       if(flag==1)
	       {
			   flag=0;
			   break;
		   }
       }
   }
   cout<<c;
   return 0;
}
