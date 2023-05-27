#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,j,a,b,k,m=0,s=0;
	cin>>a>>k;
	for(i=1;i<=a;i++)
	{
		s=0;
		for(j=1;j<=i;j++)
		{
		   for(b=k;b<=a;b++)
		   if(i==pow(j,b))
		   { 
			m++;s=1;
			break;
		   }
		   if(s==1)
		   break;
		}
	}
	
	cout<<m;
}
