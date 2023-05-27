#include<bits/stdc++.h>
using namespace std;
const long long manx=10e+5;
bool as[manx];
int main()
{
	long long n,k,ans,anns,kkk=0;
	
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	cin>>n>>k;
	if(k==1)
	{
		cout<<n;
	}
	else
	{
		for(long long  i=2;i<=n/k;i++)
		{
			if(as[i]==0)
	{
			for(int j=1;;j++)
	{
				ans=i;
				anns=1;
	      long long  b=j;
	      while(b!=1)
	    {
		if(b%2==0)
		{ans=ans*ans;b=b/2;
		}
		else
		{
			b=b-1;
			anns=anns*ans;}
	    }
	    anns=anns*ans;
	    as[anns]=1;
	    if(anns>n)
	    {break;}
	    if(j>=k)
	    {kkk++;}
	}
	 		
		
   }
		}
	cout<<kkk+1;
	}
	
	return 0;
	
}
