#include<bits/stdc++.h>
using namespace std;
double way[1010][3];
double juli[1010][1010];
int answ[1010];
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int n;
    double ma=0,maa;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
		cin>>way[i][1]>>way[i][2];
		if(ma<max(ma,way[i][2]))
		{
			ma=way[i][2];
			maa=i;
		}
	    for(int j=1;j<=n;j++)
	    {
			juli[i][j]=sqrt((way[i][1]-way[j][1])*(way[i][1]-way[j][1])+(way[i][2]-way[j][2])*(way[i][2]-way[j][2]));
		}
	}
	cout<<maa;	
	for(int i=1;i<=n;i++)
	{
		if(i!=maa)  cout<<' '<<i;
	}
    return 0;
}
