#include<bits/stdc++.h>
using namespace std;
int main()
{int T;
cin>>T;
for(int t=0;t<=T;t++)
{
int a[101][101],m,n,q,x,y,z;
cin>>n>>m;
for(int o=0;o<=n;o++)
{for(int p=0;p<=m;p++)
a[n][m]=0;
}
cin>>q;
for(int o=0;o<=q;o++)
{cin>>x>>y>>z;
if(x==0)
{for(int p=0;p<=y;p++)
a[y][p]=z;
}
if(x==1)
{for(int k=0;k<=y;k++)
a[k][y]=z;
}
}
cout<<a;
}
return 0 ;}
