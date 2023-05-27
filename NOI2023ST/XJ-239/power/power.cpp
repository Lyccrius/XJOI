#include<bits/stdc++.h>
using namespace std;

int main()
{int n,k,a[100001],c=0;
	cin>>n;
	cin>>k;

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int l=k;l<=n;l++)
			{j=j*l;
			if(j==i)
			a[i]=j;
		    }
		}
	}
    for(int i=1;i<=n;i++)
    {   if(a[i]!=0)
	    {c++;
		}
    }
cout<<c<<endl;

return 0;
}
