#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    int n,m,q;
    int a[100001][100001],opt[100001],x[100001],c[100001];
    cin>>n>>m>>q;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            a[i][j]=0;
        }
    }
    for(int i=0;i<=q;i++)
    {
        cin>>opt[i]>>x[i]>>c[i];
        if(opt[i]==0)
        {
            for(int l=0;l<m;l++)
            {
                a[x[i]][l]=c[i];
            }
        }
        if(opt[i]==1)
        {
            for(int k=0;k<n;k++)
            {
                a[k][x[i]]=c[i];
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<a[i][j];
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
