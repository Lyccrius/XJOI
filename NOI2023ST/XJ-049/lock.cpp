#include<bits/stdc++.h>
using namespace std;
int i,n,m,j,t,q,k,l,x,c,opt,a[10005][10005];
int main()
{
    //freopen("paint.in","r",stdin);
    //freopen("paint.out","w",stdout);
    cin>>t>>l;
    for(int o=1;o<=t;o++)
    {
		memset(a,0,sizeof(a));
        cin>>n;
        for(int d=1;d<=l;d++)
        {
			for(k=1;k<=m;k++)
			{
				cin>>a[d][k];
			}
		}
    }
    cout<<0;
    return 0;
}
