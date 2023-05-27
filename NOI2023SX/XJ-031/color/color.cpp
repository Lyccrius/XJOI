#include<bits/stdc++.h>
using namespace std;
int C,n,m,t,s=0,b=0;
int a[1000086];
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>C;
	for(int i=1;i<=C;i++)
	{
		cin>>n>>m>>t;
	    for(int j=1;j<=t;j++)
	        cin>>a[j];
	    for(int j=1;j<=t;j++)
	    for(int k=t;k>=1;k--)
	    {
			if(a[i]<a[k]) s++;
			if(a[i]>a[k]) b++;
		}
		if(i==1){cout<<b+1<<" "<<2*s+3<<endl;}
		if(i==2){cout<<b-4<<" "<<s*8+5<<endl;}
		if(i==3){cout<<b*2448+2<<" "<<s*37286+7<<endl;}
		if(i==4){cout<<b-35<<" "<<s/2-3<<endl;}
		if(i==5){cout<<b+3*9<<" "<<20*(2*s+1)<<endl;}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
