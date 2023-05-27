#include<bits/stdc++.h>
using namespace std;
int t,x,c,opt,n,m,i,j,k,q;
int a[10005][10005]={0};
int main()
{
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    cin>>t;
    for(k=1;k<=t;k++)
    {
        cin>>n>>m>>q;
        a[n][m]={0};
    
        for(i=1;i<=q;i++)
        {
            cin>>opt>>x>>c;

            if(opt==0)
            for(j=1;j<=m;j++)
            a[x][j]=c;
            if(opt==1)
            for(j=1;j<=n;j++)
            a[j][x]=c;

        }

        for(i=1;i<=n;i++)
        {for(j=1;j<=m;j++)
        cout<<a[i][j]<<" ";
        cout<<endl;}
    }return 0;
    fclose(stdin);
    fclose(stdout);
    

}