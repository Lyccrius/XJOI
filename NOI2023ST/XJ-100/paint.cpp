#include<bits/stdc++.h>
using namespace std;
freopen("paint.in","r".stdin);
freopen("paint.out","w".stdout);
int main()
{
	int n,m,q,opti,xi,ci;
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>q;
        int a[n+5][m+5]={0};
        for(int k=1;k<=q;k++)
        {
            cin>>opti>>xi>>ci;
            if(opti==0)
            {
                for(int w=1;w<=m;w++)
                {
                    a[xi][w]=ci;
                }
            }
            if(opti==1)
            {
                for(int o=1;o<=n;o++)
                {
                    a[o][xi]=ci;
                }
            }
        }
        for(int j=1;j<=n;j++)
        {
			for(int l=1;l<=m;l++)
			{
				cout<<a[j][l]<<" ";
			}
			cout<<endl;
        }
	}
}
